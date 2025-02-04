/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _UAPI__LINUX_KVM_PARA_H
#define _UAPI__LINUX_KVM_PARA_H

/*
 * This header file provides a method for making a hypercall to the host
 * Architectures should define:
 * - kvm_hypercall0, kvm_hypercall1...
 * - kvm_arch_para_features
 * - kvm_para_available
 */

/* Return values for hypercalls */
#define KVM_ENOSYS		1000
#define KVM_EFAULT		EFAULT
#define KVM_E2BIG		E2BIG
#define KVM_EPERM		EPERM
#define KVM_EOPNOTSUPP		95

#define KVM_HC_VAPIC_POLL_IRQ		1
#define KVM_HC_MMU_OP			2
#define KVM_HC_FEATURES			3
#define KVM_HC_PPC_MAP_MAGIC_PAGE	4
#define KVM_HC_KICK_CPU			5
#define KVM_HC_MIPS_GET_CLOCK_FREQ	6
#define KVM_HC_MIPS_EXIT_VM		7
#define KVM_HC_MIPS_CONSOLE_OUTPUT	8
#define KVM_HC_CLOCK_PAIRING		9

/* eCS */
#ifdef CONFIG_PARAVIRT_IPI
#define KVM_HC_IPI_DELIVERY             10

#ifdef CONFIG_PARAVIRT_TLB
#define KVM_HC_TLB                      11
#endif

DECLARE_PER_CPU(struct kvm_ipi_cpu_list, ipi_cpu_list);

#endif

#ifdef CONFIG_PARAVIRT_WAIT_HYPERCALL
#define KVM_HC_WAIT                     12
#endif
/*******/

/*
 * hypercalls use architecture specific
 */
#include <asm/kvm_para.h>

#endif /* _UAPI__LINUX_KVM_PARA_H */
