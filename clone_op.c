#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "lexicals.h"
#include "clone_op.h"

/*
 *   This is not meant to truly clone an OP tree, it's meant to create a userland
 *   equivalent.  This means that 'nextstate', 'lineseq', etc OPs do not need to
 *   be preserved, and it also means that any declared variables have to be
 *   strictly lexical as cloning a reference leads to headaches that we don't want.
 *
 */

OP * clone_op(pTHX_ OP *o)
{
    OP * clone = NULL;

    if (o->op_type == OP_LEAVESUB)
        return clone_op(cUNOPo->op_first);
    else if (o->op_flags & OPf_KIDS) {
        OP *kid = cUNOPo->op_first;
        OP *first = NULL;
        OP *last = NULL;
        do {
            OP * child = clone_op(kid);
            if (!child) continue;
            clone = op_append_elem(o->op_type, clone, child);
        } while (kid = kid->op_sibling);
        return clone;
    } else switch (o->op_type) {
        case OP_CONST:
            return newSVOP(o->op_type, 0, cSVOPo_sv);
        case OP_PUSHMARK:
            return newOP(o->op_type, 0);
        case OP_NEXTSTATE:
            return newSTATEOP((U8)o->op_flags, NULL, NULL);
        case OP_NULL:
            return NULL;
        default:
            croak("Unsupported op type: %s", PL_op_name[o->op_type]);
    }
}
