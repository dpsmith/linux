// SPDX-License-Identifier: GPL-2.0
/*
 * Secure Launch early measurement and validation routines.
 *
 * Copyright (c) 2025, Oracle and/or its affiliates.
 */

#include <linux/init.h>
#include <linux/string.h>
#include <linux/linkage.h>
#include <asm/segment.h>
#include <asm/boot.h>
#include <asm/msr.h>
#include <asm/mtrr.h>
#include <asm/processor-flags.h>
#include <asm/asm-offsets.h>
#include <asm/bootparam.h>
#include <asm/bootparam_utils.h>
#include <crypto/sha1.h>
#include <crypto/sha2.h>

#include <linux/tpm_common.h>
#include <linux/tpm1.h>
#include <linux/tpm2.h>
#include <linux/tpm_ptp.h>
#include <linux/tpm_buf.h>

#include "../../../../drivers/char/tpm/tpm1_structs.h"
#include "../../../../drivers/char/tpm/tpm2_structs.h"

#undef __get_free_page
#define __get_free_page(a) (NULL)
#undef free_page
#define free_page(a)
#undef EXPORT_SYMBOL_GPL
#define EXPORT_SYMBOL_GPL(a)
#include "../../../../drivers/char/tpm/tpm-buf.c"

void __cold __noreturn __fortify_panic(const u8 reason, const size_t avail, const size_t size)
{
	asm volatile ("ud2");

	unreachable();
}

asmlinkage __visible void sl_main(void *bootparams)
{
	struct boot_params *bp  = (struct boot_params *)bootparams;

	/* TODO this is just test framework running in the correct context */
}
