;LBYARCH S11
;FETALVERO, KENSHIN GAMBOA
;GUTIERREZ, CARLOS KRISTOFFER PABALAN
section .data

section .text
bits 64
default rel

global sdotASM

sdotASM:
	;rcx -> starting addr of A
	;rdx -> starting addr of B
	;R8 -> size

	;initial setup
	dec r8
	mov r10, 0
	movss xmm0, [rcx + r10]
	mulss xmm0, [rdx + r10]

	L1:
		; move to next element
		inc r10
		inc r10
		inc r10
		inc r10

		; multiply the corresponding element
		movss xmm3, [rcx + r10]
		mulss xmm3, [rdx + r10]

		; add the product to result 
		addss xmm0, xmm3

		; decrement loop counter
		dec r8
		jnz L1

	ret