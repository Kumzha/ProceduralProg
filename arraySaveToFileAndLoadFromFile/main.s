	.file	"main.c"
	.text
	.globl	saveCount
	.bss
	.align 4
saveCount:
	.space 4
	.globl	loadCount
	.align 4
loadCount:
	.space 4
	.section .rdata,"dr"
.LC0:
	.ascii "w\0"
.LC1:
	.ascii "\12Error opening data file!\0"
.LC2:
	.ascii "\12%i\12\0"
.LC3:
	.ascii "\12%i\0"
	.text
	.globl	saveToFile
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.seh_proc	saveToFile
saveToFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	32(%rbp), %rax
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	.L2
	leaq	.LC1(%rip), %rcx
	call	puts
	movl	$1, %ecx
	call	exit
.L2:
	movl	$0, -4(%rbp)
	movl	24(%rbp), %eax
	leal	1(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %r8d
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	jmp	.L3
.L4:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %r8d
	leaq	.LC3(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	addl	$1, -4(%rbp)
.L3:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jle	.L4
	movl	saveCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, saveCount(%rip)
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC4:
	.ascii "r\0"
.LC5:
	.ascii "%i\0"
	.text
	.globl	loadFromFile
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.seh_proc	loadFromFile
loadFromFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	.LC4(%rip), %rdx
	movq	16(%rbp), %rcx
	call	fopen
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	.L6
	leaq	.LC1(%rip), %rcx
	call	puts
	movl	$1, %ecx
	call	exit
.L6:
	leaq	-32(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %r8
	leaq	.LC5(%rip), %rdx
	movq	%rax, %rcx
	call	fscanf
	movl	-32(%rbp), %eax
	addl	$1, %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L7
.L8:
	leaq	-28(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %r8
	leaq	.LC5(%rip), %rdx
	movq	%rax, %rcx
	call	fscanf
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-28(%rbp), %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
.L7:
	movl	-32(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jle	.L8
	movl	loadCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, loadCount(%rip)
	movq	-24(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	fillArray
	.def	fillArray;	.scl	2;	.type	32;	.endef
	.seh_proc	fillArray
fillArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, %ecx
	call	time
	movl	%eax, %ecx
	call	srand
	jmp	.L11
.L12:
	call	rand
	movl	%eax, %ecx
	movl	$274877907, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$6, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$1000, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	24(%rbp), %rdx
	addq	%rcx, %rdx
	addl	$1, %eax
	movl	%eax, (%rdx)
	addl	$1, -4(%rbp)
.L11:
	movl	-4(%rbp), %eax
	cmpl	16(%rbp), %eax
	jle	.L12
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC6:
	.ascii "\12PRINTED ARRAY:\0"
.LC7:
	.ascii "\12arr[%i]=%i\0"
	.text
	.globl	printArray
	.def	printArray;	.scl	2;	.type	32;	.endef
	.seh_proc	printArray
printArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$0, -4(%rbp)
	leaq	.LC6(%rip), %rcx
	call	puts
	jmp	.L14
.L15:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC7(%rip), %rcx
	call	printf
	addl	$1, -4(%rbp)
.L14:
	movl	-4(%rbp), %eax
	cmpl	16(%rbp), %eax
	jle	.L15
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC8:
	.ascii "\12something's wrong!\0"
.LC9:
	.ascii "\12NOT GOOD...\0"
.LC10:
	.ascii "\12\12ALL GOOD MY MAN!\0"
	.text
	.globl	compareArray
	.def	compareArray;	.scl	2;	.type	32;	.endef
	.seh_proc	compareArray
compareArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movl	%r9d, 40(%rbp)
	movl	24(%rbp), %eax
	cmpl	40(%rbp), %eax
	je	.L17
	leaq	.LC8(%rip), %rcx
	call	puts
	jmp	.L23
.L17:
	movl	$0, -4(%rbp)
	jmp	.L19
.L22:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	32(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jne	.L20
	addl	$1, -4(%rbp)
	jmp	.L19
.L20:
	leaq	.LC9(%rip), %rcx
	call	puts
	jmp	.L21
.L19:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jle	.L22
.L21:
	leaq	.LC10(%rip), %rcx
	call	puts
.L23:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	nullCount
	.def	nullCount;	.scl	2;	.type	32;	.endef
	.seh_proc	nullCount
nullCount:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	$0, (%rax)
	movq	24(%rbp), %rax
	movl	$0, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC11:
	.ascii "Memory not allocated.\0"
.LC12:
	.ascii "inout.txt\0"
	.align 8
.LC13:
	.ascii "\12\12SECOND ARRAY TAKEN FROM THE FILE:\0"
.LC14:
	.ascii "\12arr2[%i] = %i\0"
.LC15:
	.ascii "inout2.txt\0"
	.align 8
.LC16:
	.ascii "\12Save count: %i\12Load count: %i\12\0"
.LC17:
	.ascii "\12ALL GOOD TWICE MAN!\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	movl	$44, %ecx
	call	malloc
	movq	%rax, -16(%rbp)
	movl	$44, %ecx
	call	malloc
	movq	%rax, -24(%rbp)
	movl	$44, %ecx
	call	malloc
	movq	%rax, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L26
	cmpq	$0, -24(%rbp)
	je	.L26
	cmpq	$0, -32(%rbp)
	jne	.L27
.L26:
	leaq	.LC11(%rip), %rcx
	call	puts
	movl	$0, %ecx
	call	exit
.L27:
	movl	$0, -4(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdx
	movl	$10, %ecx
	call	fillArray
	movq	-16(%rbp), %rax
	movq	%rax, %rdx
	movl	$10, %ecx
	call	printArray
	movq	-16(%rbp), %rax
	leaq	.LC12(%rip), %r8
	movl	$10, %edx
	movq	%rax, %rcx
	call	saveToFile
	leaq	.LC13(%rip), %rcx
	call	puts
	leaq	.LC12(%rip), %rcx
	call	loadFromFile
	movq	%rax, -24(%rbp)
	jmp	.L28
.L29:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC14(%rip), %rcx
	call	printf
	addl	$1, -4(%rbp)
.L28:
	cmpl	$10, -4(%rbp)
	jle	.L29
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movl	$10, %r9d
	movq	%rdx, %r8
	movl	$10, %edx
	movq	%rax, %rcx
	call	compareArray
	movq	-16(%rbp), %rax
	movq	%rax, %rdx
	movl	$10, %ecx
	call	fillArray
	movq	-24(%rbp), %rax
	movq	%rax, %rdx
	movl	$10, %ecx
	call	fillArray
	movq	-32(%rbp), %rax
	movq	%rax, %rdx
	movl	$10, %ecx
	call	fillArray
	movq	-16(%rbp), %rax
	leaq	.LC12(%rip), %r8
	movl	$10, %edx
	movq	%rax, %rcx
	call	saveToFile
	movq	-32(%rbp), %rax
	leaq	.LC12(%rip), %r8
	movl	$10, %edx
	movq	%rax, %rcx
	call	saveToFile
	leaq	.LC12(%rip), %rcx
	call	loadFromFile
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	leaq	.LC15(%rip), %r8
	movl	$10, %edx
	movq	%rax, %rcx
	call	saveToFile
	leaq	.LC15(%rip), %rcx
	call	loadFromFile
	movq	%rax, -32(%rbp)
	leaq	.LC12(%rip), %rcx
	call	loadFromFile
	movq	%rax, -24(%rbp)
	movl	loadCount(%rip), %edx
	movl	saveCount(%rip), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC16(%rip), %rcx
	call	printf
	movl	saveCount(%rip), %edx
	movl	loadCount(%rip), %eax
	cmpl	%eax, %edx
	jne	.L30
	leaq	.LC17(%rip), %rcx
	call	puts
.L30:
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef
	.def	fprintf;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	fscanf;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	time;	.scl	2;	.type	32;	.endef
	.def	srand;	.scl	2;	.type	32;	.endef
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
