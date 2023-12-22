/* SPDX-License-Identifier: GPL-2.0 */
#if !defined(KVM_X86_OP) || !defined(KVM_X86_OP_OPTIONAL)
BUILD_BUG_ON(1)
#endif

/*
 * KVM_X86_OP() and KVM_X86_OP_OPTIONAL() are used to help generate
 * both DECLARE/DEFINE_STATIC_CALL() invocations and
 * "static_call_update()" calls.
 *
 * KVM_X86_OP_OPTIONAL() can be used for those functions that can have
 * a NULL definition, for example if "static_call_cond()" will be used
 * at the call sites.  KVM_X86_OP_OPTIONAL_RET0() can be used likewise
 * to make a definition optional, but in this case the default will
 * be __static_call_return0.
 */
KVM_X86_OP(hardware_enable)
KVM_X86_OP(hardware_disable)
KVM_X86_OP(hardware_unsetup)
KVM_X86_OP(has_emulated_msr)
KVM_X86_OP(vcpu_after_set_cpuid)
KVM_X86_OP(vm_init)
KVM_X86_OP_OPTIONAL(vm_destroy)
KVM_X86_OP_OPTIONAL_RET0(vcpu_precreate)
KVM_X86_OP(vcpu_create)
KVM_X86_OP(vcpu_free)
KVM_X86_OP(vcpu_reset)
KVM_X86_OP(prepare_switch_to_guest)
KVM_X86_OP(vcpu_load)
KVM_X86_OP(vcpu_put)
KVM_X86_OP(update_exception_bitmap)
KVM_X86_OP(get_msr)
KVM_X86_OP(set_msr)
KVM_X86_OP(get_segment_base)
KVM_X86_OP(get_segment)
KVM_X86_OP(get_cpl)
KVM_X86_OP(set_segment)
KVM_X86_OP(get_cs_db_l_bits)
KVM_X86_OP(is_valid_cr0)
KVM_X86_OP(set_cr0)
KVM_X86_OP_OPTIONAL(post_set_cr3)
KVM_X86_OP(is_valid_cr4)
KVM_X86_OP(set_cr4)
KVM_X86_OP(set_efer)
KVM_X86_OP(get_idt)
KVM_X86_OP(set_idt)
KVM_X86_OP(get_gdt)
KVM_X86_OP(set_gdt)
KVM_X86_OP(sync_dirty_debug_regs)
KVM_X86_OP(set_dr7)
KVM_X86_OP(cache_reg)
KVM_X86_OP(get_rflags)
KVM_X86_OP(set_rflags)
KVM_X86_OP(get_if_flag)
KVM_X86_OP(flush_tlb_all)
KVM_X86_OP(flush_tlb_current)
KVM_X86_OP_OPTIONAL(tlb_remote_flush)
KVM_X86_OP_OPTIONAL(tlb_remote_flush_with_range)
KVM_X86_OP(flush_tlb_gva)
KVM_X86_OP(flush_tlb_guest)
KVM_X86_OP(vcpu_pre_run)
KVM_X86_OP(vcpu_run)
KVM_X86_OP(handle_exit)
KVM_X86_OP(skip_emulated_instruction)
KVM_X86_OP_OPTIONAL(update_emulated_instruction)
KVM_X86_OP(set_interrupt_shadow)
KVM_X86_OP(get_interrupt_shadow)
KVM_X86_OP(patch_hypercall)
KVM_X86_OP(inject_irq)
KVM_X86_OP(inject_nmi)
KVM_X86_OP(inject_exception)
KVM_X86_OP(cancel_injection)
KVM_X86_OP(interrupt_allowed)
KVM_X86_OP(nmi_allowed)
KVM_X86_OP(get_nmi_mask)
KVM_X86_OP(set_nmi_mask)
KVM_X86_OP(enable_nmi_window)
KVM_X86_OP(enable_irq_window)
KVM_X86_OP_OPTIONAL(update_cr8_intercept)
KVM_X86_OP(check_apicv_inhibit_reasons)
KVM_X86_OP(refresh_apicv_exec_ctrl)
KVM_X86_OP_OPTIONAL(hwapic_irr_update)
KVM_X86_OP_OPTIONAL(hwapic_isr_update)
KVM_X86_OP_OPTIONAL_RET0(guest_apic_has_interrupt)
KVM_X86_OP_OPTIONAL(load_eoi_exitmap)
KVM_X86_OP_OPTIONAL(set_virtual_apic_mode)
KVM_X86_OP_OPTIONAL(set_apic_access_page_addr)
KVM_X86_OP(deliver_interrupt)
KVM_X86_OP_OPTIONAL(sync_pir_to_irr)
KVM_X86_OP_OPTIONAL_RET0(set_tss_addr)
KVM_X86_OP_OPTIONAL_RET0(set_identity_map_addr)
KVM_X86_OP_OPTIONAL_RET0(get_mt_mask)
KVM_X86_OP(load_mmu_pgd)
KVM_X86_OP(has_wbinvd_exit)
KVM_X86_OP(get_l2_tsc_offset)
KVM_X86_OP(get_l2_tsc_multiplier)
KVM_X86_OP(write_tsc_offset)
KVM_X86_OP(write_tsc_multiplier)
KVM_X86_OP(get_exit_info)
KVM_X86_OP(check_intercept)
KVM_X86_OP(handle_exit_irqoff)
KVM_X86_OP(request_immediate_exit)
KVM_X86_OP(sched_in)
KVM_X86_OP_OPTIONAL(update_cpu_dirty_logging)
KVM_X86_OP_OPTIONAL(vcpu_blocking)
KVM_X86_OP_OPTIONAL(vcpu_unblocking)
KVM_X86_OP_OPTIONAL(pi_update_irte)
KVM_X86_OP_OPTIONAL(pi_start_assignment)
KVM_X86_OP_OPTIONAL(apicv_post_state_restore)
KVM_X86_OP_OPTIONAL_RET0(dy_apicv_has_pending_interrupt)
KVM_X86_OP_OPTIONAL(set_hv_timer)
KVM_X86_OP_OPTIONAL(cancel_hv_timer)
KVM_X86_OP(setup_mce)
KVM_X86_OP(smi_allowed)
KVM_X86_OP(enter_smm)
KVM_X86_OP(leave_smm)
KVM_X86_OP(enable_smi_window)
KVM_X86_OP_OPTIONAL(mem_enc_ioctl)
KVM_X86_OP_OPTIONAL(mem_enc_register_region)
KVM_X86_OP_OPTIONAL(mem_enc_unregister_region)
KVM_X86_OP_OPTIONAL(vm_copy_enc_context_from)
KVM_X86_OP_OPTIONAL(vm_move_enc_context_from)
KVM_X86_OP_OPTIONAL(guest_memory_reclaimed)
KVM_X86_OP(get_msr_feature)
KVM_X86_OP(can_emulate_instruction)
KVM_X86_OP(apic_init_signal_blocked)
KVM_X86_OP_OPTIONAL(enable_direct_tlbflush)
KVM_X86_OP_OPTIONAL(migrate_timers)
KVM_X86_OP(msr_filter_changed)
KVM_X86_OP(complete_emulated_msr)
KVM_X86_OP(vcpu_deliver_sipi_vector)
KVM_X86_OP_OPTIONAL_RET0(vcpu_get_apicv_inhibit_reasons);
KVM_X86_OP_OPTIONAL(alloc_apic_backing_page)
KVM_X86_OP_OPTIONAL_RET0(gmem_prepare)

#undef KVM_X86_OP
#undef KVM_X86_OP_OPTIONAL
#undef KVM_X86_OP_OPTIONAL_RET0
