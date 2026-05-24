.global _start

.section .data
message:
	.ascii "hello, world!\n"

.section .text

#if defined(__x86_64__)

.intel_syntax noprefix

_start:
        mov rdi, 1			# fd: stdout
        mov rsi, offset message		# buffer address
        mov rdx, 14			# length
        mov rax, 1			# syscall: write
        syscall
        xor rdi, rdi			# exit status: 0
        mov rax, 60			# syscall: exit
        syscall

#elif defined(__aarch64__)

_start:
        mov x0, #1			# fd: stdout
        ldr x1, =message		# buffer address
        mov x2, #14			# length
        mov x8, #64			# syscall: write
        svc #0
        mov x0, #0			# exit status: 0
        mov x8, #93			# syscall: exit
        svc #0

#endif
