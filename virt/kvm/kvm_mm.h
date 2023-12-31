/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __KVM_MM_H__
#define __KVM_MM_H__ 1

/*
 * Architectures can choose whether to use an rwlock or spinlock
 * for the mmu_lock.  These macros, for use in common code
 * only, avoids using #ifdefs in places that must deal with
 * multiple architectures.
 */

#ifdef KVM_HAVE_MMU_RWLOCK
#define KVM_MMU_LOCK_INIT(kvm)		rwlock_init(&(kvm)->mmu_lock)
#define KVM_MMU_LOCK(kvm)		write_lock(&(kvm)->mmu_lock)
#define KVM_MMU_UNLOCK(kvm)		write_unlock(&(kvm)->mmu_lock)
#define KVM_MMU_READ_LOCK(kvm)		read_lock(&(kvm)->mmu_lock)
#define KVM_MMU_READ_UNLOCK(kvm)	read_unlock(&(kvm)->mmu_lock)
#else
#define KVM_MMU_LOCK_INIT(kvm)		spin_lock_init(&(kvm)->mmu_lock)
#define KVM_MMU_LOCK(kvm)		spin_lock(&(kvm)->mmu_lock)
#define KVM_MMU_UNLOCK(kvm)		spin_unlock(&(kvm)->mmu_lock)
#define KVM_MMU_READ_LOCK(kvm)		spin_lock(&(kvm)->mmu_lock)
#define KVM_MMU_READ_UNLOCK(kvm)	spin_unlock(&(kvm)->mmu_lock)
#endif /* KVM_HAVE_MMU_RWLOCK */

kvm_pfn_t hva_to_pfn(unsigned long addr, bool atomic, bool *async,
		     bool write_fault, bool *writable);

#ifdef CONFIG_HAVE_KVM_PFNCACHE
void gfn_to_pfn_cache_invalidate_start(struct kvm *kvm,
				       unsigned long start,
				       unsigned long end,
				       bool may_block);
#else
static inline void gfn_to_pfn_cache_invalidate_start(struct kvm *kvm,
						     unsigned long start,
						     unsigned long end,
						     bool may_block)
{
}
#endif /* HAVE_KVM_PFNCACHE */

#ifdef CONFIG_KVM_PRIVATE_MEM
int kvm_gmem_init(void);
void kvm_gmem_exit(void);
int kvm_gmem_create(struct kvm *kvm, struct kvm_create_guest_memfd *args);
int kvm_gmem_bind(struct kvm *kvm, struct kvm_memory_slot *slot,
		 unsigned int fd, loff_t offset);
void kvm_gmem_unbind(struct kvm_memory_slot *slot);
#else
static inline int kvm_gmem_init(void)
{
	return 0;
}

static inline void kvm_gmem_exit(void)
{
 
}

static inline int kvm_gmem_create(struct kvm *kvm,
                                struct kvm_create_guest_memfd *args)
{
	return -EOPNOTSUPP;
}

static inline int kvm_gmem_bind(struct kvm *kvm,
				struct kvm_memory_slot *slot,
				unsigned int fd, loff_t offset)
{
	WARN_ON_ONCE(1);
	return -EIO;
}

static inline void kvm_gmem_unbind(struct kvm_memory_slot *slot)
{
	WARN_ON_ONCE(1);
}
#endif /* CONFIG_KVM_PRIVATE_MEM */

#endif /* __KVM_MM_H__ */
