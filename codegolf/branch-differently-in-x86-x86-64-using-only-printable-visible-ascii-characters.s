/*
The task is simple: write a program that branches differently in x86 (32-bit) and x86-64 (64-bit) using only printable visible ASCII characters 0x21...0x7e (space and del are not allowed) in the machine code.

Conditional assembly is not allowed.
Using API calls in not allowed.
Using kernel-mode (ring 0) code is not allowed.
The code must run without causing exceptions in both IA-32 and x86-64 in Linux or in some other protected mode OS.
The functioning must not depend on command line parameters.
All instructions must be encoded in machine code using only ASCII characters in the range 0x21...0x7e (33...126 decimal). So eg. cpuid is out of limits (it's 0f a2), unless you use self-modifying code.
The same binary code must run in x86 and x86-64, but as file headers (ELF/ELF64/etc.) may be different, you may need to assemble and link it again. However, the binary code must not change.
Solutions should work on all processors between i386...Core i7, but I'm interested also in more limited solutions.
The code must branch in 32-bit x86 but not in x86-64, or vice versa, but using conditional jumps is not a requirement (indirect jump or call is also accepted). The branch target address must be such that there is space for some code, at least 2 bytes of space in which a short jump (jmp rel8) fits in.
The winning answer is the one that uses least bytes in the machine code. The bytes in the file header (ELF/ELF64 for example) are not counted, and any bytes of code after the branch (for testing purposes etc.) aren't counted neither.

Please present your answer as ASCII, as hexadecimal bytes and as commented code.

My solution, 39 bytes:

ASCII: fhotfhatfhitfhutfhotfhatfhitfhut_H3<$t!

hexadecimal: 66 68 6F 74  66 68 61 74 66 68 69 74  66 68 75 74 66 68 6F 74  66 68 61 74 66 68 69 74  66 68 75 74 5F 48 33 3C 24 74 21.

Code:

; can be compiled eg. with yasm.
; yasm & ld:
; yasm -f elf64 -m amd64 -g dwarf2 x86_x86_64_branch.asm -o x86_x86_64_branch.o; ld x86_x86_64_branch.o -o x86_x86_64_branch
; yasm & gcc:
; yasm -f elf64 -m amd64 -g dwarf2 x86_x86_64_branch.asm -o x86_x86_64_branch.o; gcc -o x86_x86_64_branch x86_x86_64_branch.o

section .text
global main
extern printf

main:
    push    word 0x746f     ; 66 68 6f 74 (x86, x86-64)
    push    word 0x7461     ; 66 68 61 74 (x86, x86-64)
    push    word 0x7469     ; 66 68 69 74 (x86, x86-64)
    push    word 0x7475     ; 66 68 75 74 (x86, x86-64)

    push    word 0x746f     ; 66 68 6f 74 (x86, x86-64)
    push    word 0x7461     ; 66 68 61 74 (x86, x86-64)
    push    word 0x7469     ; 66 68 69 74 (x86, x86-64)
    push    word 0x7475     ; 66 68 75 74 (x86, x86-64)

    db      0x5f            ; x86:    pop edi
                            ; x86-64: pop rdi

    db      0x48, 0x33, 0x3c, 0x24
                            ; x86:
                            ; 48          dec eax
                            ; 33 3c 24    xor edi,[esp]

                            ; x86-64:
                            ; 48 33 3c 24 xor rdi,[rsp]

    jz      @bits_64        ; 0x74 0x21
                            ; branch only if running in 64-bit mode.

; the code golf part ends here, 39 bytes so far.

; the rest is for testing only, and does not affect the answer.

    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop

    jmp     @bits_32

@bits_64:
    db      0x55                    ; push rbp

    db      0x48, 0x89, 0xe5        ; mov rbp,rsp
    db      0x48, 0x8d, 0x3c, 0x25  ; lea rdi,
    dd      printf_msg              ; [printf_msg]
    xor     eax,eax
    mov     esi,64

    call    printf
    db      0x5d                    ; pop rbp

    NR_exit equ 60

    xor     edi,edi
    mov     eax,NR_exit     ; number of syscall (60)
    syscall

@bits_32:
    lea     edi,[printf_msg]
    mov     esi,32
    call    printf

    mov     eax,NR_exit
    int     0x80

section .data

printf_msg: db "running in %d-bit system", 0x0a, 0

*/

/*

@Geoff Reedy

0000000: 6641 2521 2173 21                        fA%!!s!
As 32 bit

00000000  6641              inc cx
00000002  2521217321        and eax,0x21732121
As 64 bit

00000000  6641252121        and ax,0x2121
00000005  7321              jnc 0x28
and clears the carry flag so the 64 bit version always jumps. For 64-bit the 6641 is the operand size override followed by rex.b so the operand size for the and comes out as 16 bit. On 32-bit the 6641 is a complete instruction so the and has no prefix and has a 32-bit operand size. This changes the number of immediate bytes consumed by the and giving two bytes of instructions that are only executed in 64-bit mode.

*/

.byte 'f', 'A', '%', '!', '!', 's', '!'

