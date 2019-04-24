add $s2, $s0, $s1
sll $t1, $s2, 2
or $t2, $s2, $s1
andi $t2, $t1, 16
addi $t3, $t2, -243
lw $s1, 34($t1)
sw $t4, 32($s1)
nor $s2, $s0, $s1
srl $t1, $s2, 2
sub $s2, $s0, $s1
and $t1, $s6, $s2
ori $t2, $t1, 16
move $s1, $s2
beq $s1, $t3, -83
bne $s4, $s5, 43
