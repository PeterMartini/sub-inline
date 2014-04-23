#ifndef SUB_INLINE_LEXICALS_H
#define SUB_INLINE_LEXICALS_H

#include "perl.h"

static inline void add_lexical(pTHX_ const char * name)
{
#if PERL_VERSION < 15
    const int ix = Perl_pad_add_name(aTHX_ name, 0, 0, NULL, NULL);
#else
    const int ix = pad_add_name_pv(name, 0, NULL, NULL);
#endif
    const SV * pad_name = AvARRAY(PL_comppad_name)[ix];
    ((XPVNV*)SvANY(pad_name))->xnv_u.xpad_cop_seq.xlow = PL_cop_seqmax;
    ((XPVNV*)SvANY(pad_name))->xnv_u.xpad_cop_seq.xhigh = PERL_PADSEQ_INTRO;
    switch (name[0]) {
        case '@': sv_upgrade(PAD_SVl(ix), SVt_PVAV); break;
        case '%': sv_upgrade(PAD_SVl(ix), SVt_PVHV); break;
        case '$': break;
        default: croak("Only scalars, arrays, and hashes allowed, got '%s'", name);
    }
    PL_cop_seqmax++;
}

#endif
