/* SPDX-License-Identifier: GPL-2.0 */
/*
 * AMD Secure Encrypted Virtualization
 *
 * Author: Brijesh Singh <brijesh.singh@amd.com>
 */

#ifndef __LINUX_SEV_H
#define __LINUX_SEV_H

/* RMUPDATE detected 4K page and 2MB page overlap. */
#define RMPUPDATE_FAIL_OVERLAP         7

#ifdef CONFIG_AMD_MEM_ENCRYPT
int psmash(u64 pfn);
int rmp_make_private(u64 pfn, u64 gpa, enum pg_level level, int asid, bool immutable);
int rmp_make_shared(u64 pfn, enum pg_level level);
#else
static inline int psmash(u64 pfn) { return -ENXIO; }
static inline int rmp_make_private(u64 pfn, u64 gpa, enum pg_level level, int asid,
                                   bool immutable)
{
        return -ENODEV;
}
static inline int rmp_make_shared(u64 pfn, enum pg_level level) { return -ENODEV; }
 
#endif /* CONFIG_AMD_MEM_ENCRYPT */
#endif /* __LINUX_SEV_H */
