	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 4
	.globl	_EvenOrOdd                      ; -- Begin function EvenOrOdd
	.p2align	2
_EvenOrOdd:                             ; @EvenOrOdd
	.cfi_startproc
; %bb.0:
	mov	w8, #1
	bic	w0, w8, w0
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	mov w0, #5     
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
