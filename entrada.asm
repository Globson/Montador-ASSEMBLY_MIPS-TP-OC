add $s2, $s0, $s1
sll $t1, $s2, 2
or $t2, $s2, $s1
andi $t2, $t1, 16
addi $t3, $t2, -243
move $s1, $s2
lw $t0, 24($s2)
sw $t0, 24($s2)
