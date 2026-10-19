#ifndef MTXA_H
#define MTXA_H

#include "types.h"

/* Locked-cache matrix kernels recovered from retail code (2026-10-19).
 *
 * mathutil keeps "mtxA" at 0xE0000000 (the locked cache). Retail loads every
 * element a kernel reads before it stores any of them; MWCC treats the constant
 * addresses as possibly aliasing and interleaves loads and stores for plain C,
 * so, as with include/psvec.h, the retail stream only comes from an asm block
 * inlined into the caller. Registers are declared in the order retail assigns
 * them (fn_1_D27B8). */

/* mtxA[i][3] += mtxA[i][2] * z */
static inline void mtxa_translate_z(register f32 z) {
    register f32 *m = (f32 *)0xE0000000;
    register f32 m02, m03, m12, m22, m13, m23;
    asm {
        lfs m02, 0x8(m)
        lfs m03, 0xc(m)
        lfs m12, 0x18(m)
        lfs m13, 0x1c(m)
        fmadds m02, m02, z, m03
        lfs m22, 0x28(m)
        lfs m23, 0x2c(m)
        fmadds m12, m12, z, m13
        stfs m02, 0xc(m)
        fmadds m22, m22, z, m23
        stfs m12, 0x1c(m)
        stfs m22, 0x2c(m)
    }
}

#endif  // MTXA_H
