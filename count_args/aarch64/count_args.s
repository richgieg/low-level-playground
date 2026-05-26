.section .text
.global _start

_start:
	ldr x0, [sp]
	mov x8, #93				// syscall: exit
	svc #0
