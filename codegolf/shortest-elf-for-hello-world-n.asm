; Is it possible to write (pack) a shorter than 145 bytes version of a program with "Hello world" (plus new line) output if the length of the program is measured as a number of bytes in program's ELF (x86) representation? Reduction technique in mind is described here:
;
; http://timelessname.com/elfbin/
; http://www.muppetlabs.com/~breadbox/software/tiny/teensy.html
; Please reply with providing a code example. Note, 1 says "Hi world" and [2] returns 42 instead of an output, hence I assume current solution to be 142 + (len("Hello") - len("Hi")) which is 145.
;
;
; Limits of ELF: syntactically a program translated into ELF is determined by its interpreter (libc), which is a combination of:
;
; Target architecture (Generic, AMD64, ARM, IA-32, MIPS, etc.)
; OS kernel (which communicates with implementation of ELF interpreter and often is itself packed into an ELF binary)
; From TIS spec. 1.2
;
; There is one valid program interpreter for programs conforming to the ELF specification for the Intel architecture: /usr/lib/libc.so.1
;
; In theory - all clear - multiple combinations times version differences (Arch, OS) are possible. In practice - because standard is less strict than any BNF for CFG or other finer (smaller) formal language - there can be implementation differences (options) including shorter length of the program.
;
; On one hand, because ELF is not that precise (one naturally expects) it is much more difficult to do code-golf with it. Hence a "Hello world\n" program is expected to be by default in TIS ELF 1.2, x86 (Generic Intel), Linux 2.6.(20+). On the other hand having a shorter ELF that runs e.g. on *BSD seems like an extremely valuable knowledge to me!
;
; For example ELF64 (latest draft) is much more interesting incl. the differences with ELF(x86). So, please share a solution that can be accepted with correction to specific configuration.
;
; Motivation: It is the practical part that is interesting for me and code-golf is a very nice way to show how tricky it is to come up with any machine- (or even byte) code in general and why ELF does apparently such a good job (in my understanding). Thus a golf solution is not only cool per say but also can provide a practical knowledge of unexpected interpretation differences of ELF (if an alternative combination is given).

; nasm -fbin hello.asm
; chmod +x hello
; ./hello

BITS 32
        org     0x05000000
        db      0x7F, "ELF"
        dd      1
        dd      0
        dd      $$
        dw      2
        dw      3
        dd      0x0500001B
        dd      0x0500001B
        dd      4
        mov     dl, 12
        mov     ecx, msg
        int     0x80
        db      0x25
        dw      0x20
        dw      0x01
        inc     eax
        int     0x80
msg     db      'Hello world', 10
