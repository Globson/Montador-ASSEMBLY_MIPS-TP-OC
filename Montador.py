arq = open('MIPS.txt', 'r')
texto = arq.readlines()
#a=int(input()).split(' ')
for linha in texto :
    print(linha)
print(texto[0])
arq.close()
