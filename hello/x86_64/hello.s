.intel_syntax noprefix

.section .text
.global _start

_start:
        mov rdi, 1				# fd: stdout
        mov rsi, offset message			# buffer address
        mov rdx, message_end - message		# length
        mov rax, 1				# syscall: write
        syscall
        xor rdi, rdi				# exit status: 0
        mov rax, 60				# syscall: exit
        syscall
