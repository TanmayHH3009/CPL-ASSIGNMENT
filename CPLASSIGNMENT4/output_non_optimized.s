	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 4
	.globl	_EvenOrOdd                      ; -- Begin function EvenOrOdd
	.p2align	2
_EvenOrOdd:                             ; @EvenOrOdd
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	str	w0, [sp, #12]
	ldr	w8, [sp, #12]
	mov	w10, #2
	sdiv	w9, w8, w10
	mul	w9, w9, w10
	subs	w8, w8, w9
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:                          ;even
	mov	w8, #1
	str	w8, [sp, #8]
	b	LBB0_3
LBB0_2:                          ;odd
	str	wzr, [sp, #8]
	b	LBB0_3
LBB0_3:
	ldr	w0, [sp, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded 
	add	x29, sp, #16
	mov	w8, #0
	str	w8, [sp]                        ; 4-byte Folded 
	stur	wzr, [x29, #-4]
	mov	w8, #5
	str	w8, [sp, #8]
	ldr	w0, [sp, #8]
	bl	_EvenOrOdd
	mov	x8, x0
	ldr	w0, [sp]                        ; 4-byte Folded Reload
	str	w8, [sp, #4]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
