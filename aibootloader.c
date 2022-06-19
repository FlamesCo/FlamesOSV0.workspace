; load the kernel

loadkernel:

mov ax, 0x1000
mov ds, ax
mov es, ax
mov ss, ax
mov sp, 0xfffe
cld
lgdt [gdtr]
mov eax, cr0
or eax, 1 ; set protected mode bit
mov cr0, eax 
jmp code:flamesos_pm32 ; jump to code in protected mode (flat model)


; code segment definition for protected mode


code:flamesos_pm32:


; set up a flat model stack


mov ax, data ; set up data segment register(es)
mov ds, ax ; this is redundant since we are in flat model and ds=es=cs but just in case...


; zero out all segment registers except cs, ss to make sure we don't accidentally use bad selectors later


xor eax, eax ; zero out ax for use later


mov fs, ax ; zero out fs and gs segment registers too just in case...


mov gs, ax


; set up the rest of the registers (fs is used by Linux later)


mov ebp, esp ; set up the base pointer


mov ebx, 0x0 ; clear out general purpose registers for use later...


mov edi, 0x0 

  mov esi, 0x0 

  mov ecx, 0x0 

  mov edx, 0x0 

   mov eax, 0x10 ; set up 32-bit code segment selector in eax (cs) - this is a flat model so it's easy!

    call init_descriptor_tables ; call C function to set up GDT and IDT (interrupt descriptor table) - this will never return
