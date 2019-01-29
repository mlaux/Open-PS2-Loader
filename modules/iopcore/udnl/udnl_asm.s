.set noat
.set noreorder

.text

.globl func_00001440
.ent func_00001440
func_00001440:
	mfc0		$t0, $12
	nop
	la		$a4, func_00001440_main
	lui		$at, 0xA000
	or		$a4, $a4, $at
	jr		$a4
func_00001440_main:
	mtc0		$zero, $12
	nop
	nop
	lui		$a6, 0xbf80
	lw		$a6, 0x1450($t6)
	nop
	addiu		$a7, $zero, 0xfffe
	and		$t1, $a6, $a7
	lui		$at, 0xbf80
	sw		$t1, 0x1450($at)
	lui		$at, 0xbf80
	lw		$zero, 0x1450($at)
	lui		$a7, 0xbf80
	lw		$a7, 0x1578($t7)
	lui		$at, 0xbf80
	sw		$zero, 0x1578($at)
	lui		$at, 0xbf80
	lw		$zero, 0x1578($at)
	lui		$a5, 0xfffe
	lw		$a5, 0x0130($t5)
	addiu		$t1, $zero, 0x0c04
	lui		$at, 0xfffe
	sw		$t1, 0x0130($at)
	lui		$a4, 0x0001
	mtc0		$a4, $12
	nop
	nop
	addiu		$t2, $zero, 0x0000
	addiu		$t3, $zero, 0x0f80
func_00001440_loop:
	sw		$zero, 0x0000($t2)
	sw		$zero, 0x0010($t2)
	sw		$zero, 0x0020($t2)
	sw		$zero, 0x0030($t2)
	sw		$zero, 0x0040($t2)
	sw		$zero, 0x0050($t2)
	sw		$zero, 0x0060($t2)
	sw		$zero, 0x0070($t2)
	bne		$t2, $t3, func_00001440_loop
	addi		$t2, $t2, 0x0080
	mtc0		$zero, $12
	nop
	lui		$at, 0xfffe
	sw		$a5, 0x0130($at)
	lui		$at, 0xfffe
	lw		$zero, 0x0130($at)
	nop
	lui		$at, 0xbf80
	sw		$a7, 0x1578($at)
	lui		$at, 0xbf80
	lw		$zero, 0x1578($at)
	lui		$at, 0xbf80
	sw		$a6, 0x1450($at)
	lui		$at, 0xbf80
	lw		$zero, 0x1450($at)
	mtc0		$t0, $12
	nop
	jr		$ra
	nop
.end func_00001440

#Note: This doesn't seem to be used.
#.globl	func_00001544
#.ent	func_00001544
#func_00001544:
#	mfc0		$t0, $12
#	nop
#	la		$a4, func_00001544_main
#	lui		$at, 0xa000
#	or		$a4, $a4, $at
#	jr		$a4
#func_00001544_main:
#	mtc0		$zero, $12
#	nop
#	nop
#	lui		$a6, 0xbf80
#	lw		$a6, 0x1450($t6)
#	nop
#	addiu		$a7, $zero, 0xfffe
#	and		$t1, $a6, $a7
#	lui		$at, 0xbf80
#	sw		$t1, 0x1450($at)
#	lui		$at, 0xbf80
#	lw		$zero, 0x1450($at)
#	lui		$a7, 0xbf80
#	lw		$a7, 0x1578($t7)
#	lui		$at, 0xbf80
#	sw		$zero, 0x1578($at)
#	lui		$at, 0xbf80
#	lw		$zero, 0x1578($at)
#	lui		$a5, 0xfffe
#	lw		$a5, 0x0130($t5)
#	addiu		$t1, $zero, 0x00c4
#	lui		$at, 0xfffe
#	sw		$t1, 0x0130($at)
#	lui		$a4, 0x0001
#	mtc0		$a4, $12
#	nop
#	nop
#	addiu		$t2, $zero, 0x0000
#	addiu		$t3, $zero, 0x0380
#func_00001544_loop:
#	sw		$zero, 0x0000($t2)
#	sw		$zero, 0x0010($t2)
#	sw		$zero, 0x0020($t2)
#	sw		$zero, 0x0030($t2)
#	sw		$zero, 0x0040($t2)
#	sw		$zero, 0x0050($t2)
#	sw		$zero, 0x0060($t2)
#	sw		$zero, 0x0070($t2)
#	bne		$t2, $t3, func_00001544_loop
#	addi		$t2, $t2, 0x0080
#	mtc0		$zero, $12
#	nop
#	lui		$at, 0xfffe
#	sw		$a5, 0x0130($at)
#	lui		$at, 0xfffe
#	lw		$zero, 0x0130($at)
#	nop
#	lui		$at, 0xbf80
#	sw		$a7, 0x1578($at)
#	lui		$at, 0xbf80
#	lw		$zero, 0x1578($at)
#	lui		$at, 0xbf80
#	sw		$a6, 0x1450($at)
#	lui		$at, 0xbf80
#	lw		$zero, 0x1450($at)
#	mtc0		$t0, $12
#	nop
#	jr		$ra
#	nop
#.end	func_00001544
