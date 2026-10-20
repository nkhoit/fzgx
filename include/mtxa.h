#ifndef MTXA_H
#define MTXA_H

#include "types.h"
#include "dolphin/hw_regs.h"

/* Locked-cache matrix kernels recovered from retail code.
 *
 * mathutil keeps "mtxA" at LC_BASE (the locked cache). Retail loads every
 * element a kernel reads before it stores any of them. This plain C version
 * gets that instruction order but not retail's FPR assignment, so callers
 * that use it (fn_1_D27B8) stay non-matching. */

/* mtxA[i][3] += mtxA[i][2] * z */
static inline void mtxa_translate_z(f32 z) {
    f32 *m = (f32 *)LC_BASE;
    f32 m23;
    f32 m22;
    f32 m13;
    f32 m03;
    f32 m02;
    f32 m12;

    m02 = m[2];
    m03 = m[3];
    m12 = m[6];
    m13 = m[7];
    m22 = m[10];
    m23 = m[11];
    m02 = m02 * z + m03;
    m12 = m12 * z + m13;
    m22 = m22 * z + m23;
    m[3] = m02;
    m[7] = m12;
    m[11] = m22;
}

#endif  // MTXA_H
