	.file	"mtmFlixTest.c"
	.text
	.globl	_copyInt
	.def	_copyInt;	.scl	2;	.type	32;	.endef
_copyInt:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$4, (%esp)
	call	_malloc
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.globl	_copyString
	.def	_copyString;	.scl	2;	.type	32;	.endef
_copyString:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	addl	$1, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.globl	_freeInt
	.def	_freeInt;	.scl	2;	.type	32;	.endef
_freeInt:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.globl	_freeString
	.def	_freeString;	.scl	2;	.type	32;	.endef
_freeString:
LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.globl	_compareString
	.def	_compareString;	.scl	2;	.type	32;	.endef
_compareString:
LFB21:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE21:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "atomer\0"
LC1:
	.ascii "gaia\0"
LC2:
	.ascii "elad\0"
LC3:
	.ascii "yaara\0"
LC4:
	.ascii "%s : %d\12\0"
LC5:
	.ascii "def\0"
LC6:
	.ascii "xyz\0"
LC7:
	.ascii "abv\0"
LC8:
	.ascii "%s :\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$64, %esp
	call	___main
	movl	$_compareString, 16(%esp)
	movl	$_freeString, 12(%esp)
	movl	$_freeInt, 8(%esp)
	movl	$_copyString, 4(%esp)
	movl	$_copyInt, (%esp)
	call	_mapCreate
	movl	%eax, 52(%esp)
	movl	$_compareString, 8(%esp)
	movl	$_freeString, 4(%esp)
	movl	$_copyString, (%esp)
	call	_setCreate
	movl	%eax, 48(%esp)
	movl	$21, 32(%esp)
	movl	$18, 36(%esp)
	movl	$9, 40(%esp)
	movl	$15, 44(%esp)
	leal	32(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	_mapPut
	leal	32(%esp), %eax
	addl	$4, %eax
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	_mapPut
	leal	32(%esp), %eax
	addl	$8, %eax
	movl	%eax, 8(%esp)
	movl	$LC2, 4(%esp)
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	_mapPut
	leal	32(%esp), %eax
	addl	$12, %eax
	movl	%eax, 8(%esp)
	movl	$LC3, 4(%esp)
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	_mapPut
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	_mapGetFirst
	movl	%eax, 60(%esp)
	jmp	L10
L11:
	movl	60(%esp), %eax
	movl	%eax, 4(%esp)
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	_mapGet
	movl	(%eax), %eax
	movl	%eax, 8(%esp)
	movl	60(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	_mapGetNext
	movl	%eax, 60(%esp)
L10:
	cmpl	$0, 60(%esp)
	jne	L11
	movl	$LC5, 4(%esp)
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	_setAdd
	movl	$LC6, 4(%esp)
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	_setAdd
	movl	$LC7, 4(%esp)
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	_setAdd
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	_setGetFirst
	movl	%eax, 56(%esp)
	jmp	L12
L13:
	movl	56(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	_setGetNext
	movl	%eax, 56(%esp)
L12:
	cmpl	$0, 56(%esp)
	jne	L13
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE22:
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 7.3.0"
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_strcpy;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_strcmp;	.scl	2;	.type	32;	.endef
	.def	_mapCreate;	.scl	2;	.type	32;	.endef
	.def	_setCreate;	.scl	2;	.type	32;	.endef
	.def	_mapPut;	.scl	2;	.type	32;	.endef
	.def	_mapGetFirst;	.scl	2;	.type	32;	.endef
	.def	_mapGet;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_mapGetNext;	.scl	2;	.type	32;	.endef
	.def	_setAdd;	.scl	2;	.type	32;	.endef
	.def	_setGetFirst;	.scl	2;	.type	32;	.endef
	.def	_setGetNext;	.scl	2;	.type	32;	.endef
