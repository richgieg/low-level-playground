.intel_syntax noprefix

.section .text
.global _start

_start:
        mov rdi, [rsp]
	mov rax, 60				# syscall: exit
        syscall
