all:
	gcc -g adivinha.c -o exec
	./exec

clear:
	rm exec
