/* SPDX-License-Identifier: Apache-2.0 */
#include <nuttx/config.h>
#include <nuttx/sched.h>
#include <arch/irq.h>
#include <string.h>

/* Newly created tasks must not inherit another task's live hardware loops. */
void riscv_initial_extctx_state(struct tcb_s *tcb)
{
  memset(&tcb->xcp.regs[REG_INT_CTX_NDX + 1], 0,
         CONFIG_ARCH_RISCV_INTXCPT_EXTREGS * sizeof(uintreg_t));
}
