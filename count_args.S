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
	// TODO: implement

#endif
