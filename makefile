all: Montador.c Conversor.c
	gcc Montador.c -o EXEC Conversor.c

clear: EXEC
	rm EXEC

run: EXEC
	./EXEC

py: Montador.py
	python3 Montador.py
