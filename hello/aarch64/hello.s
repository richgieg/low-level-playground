.section .text
.global _start

_start:
        mov x0, #1				// fd: stdout
        ldr x1, =message			// buffer address
        mov x2, message_end - message		// length
        mov x8, #64				// syscall: write
        svc #0
        mov x0, #0				// exit status: 0
        mov x8, #93				// syscall: exit
        svc #0
