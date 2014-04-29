#ifndef SUB_INLINE_CLONE_OP_H
#define SUB_INLINE_CLONE_OP_H

OP * clone_op(OP *o);

static bool cloneable_op(const OP * const o)
{
    assert(o);
    switch (o->op_type) {
        case OP_NEXTSTATE:
        case OP_LEAVESUB:
        case OP_PUSHMARK:
        case OP_CONST:
        case OP_PRINT:
            return TRUE;
        default:
            return FALSE;
    }
}

#endif
