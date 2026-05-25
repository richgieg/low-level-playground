.global _start

.section .text

#if defined(__x86_64__)

.intel_syntax noprefix

_start:
        mov rdi, [rsp]
	mov rax, 60				# syscall: exit
        syscall

#elif defined(__aarch64__)

_start:
	ldr x0, [sp]
	mov x8, #93				// syscall: exit
	svc #0

#endif
