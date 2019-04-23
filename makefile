all: Montador.c
	gcc Montador.c -o EXEC

clear: EXEC
	rm EXEC

run: EXEC
	./EXEC

py: Montador.py
	python3 Montador.py
