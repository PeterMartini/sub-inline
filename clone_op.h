#ifndef SUB_INLINE_CLONE_OP_H
#define SUB_INLINE_CLONE_OP_H

OP * clone_op(OP *o);

static const SV * const clone_check(pTHX_ const OP * const o)
{
    assert(o);
    switch (o->op_type) {
        case OP_NEXTSTATE:
        case OP_LEAVESUB:
        case OP_PUSHMARK:
        case OP_CONST:
        case OP_PRINT:
            return NULL;
        default:
            return sv_2mortal(newSVpvf("Unsupported op type: %s", PL_op_name[o->op_type]));
    }
}

#endif
