all: Montador.c Conversores.c
	gcc Montador.c -o EXEC Conversores.c

clear: EXEC
	rm EXEC

run: EXEC
	./EXEC
