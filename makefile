all:
	gcc -o picmaker picmaker.c

run: all
	./picmaker

clean:
	rm picmaker
	rm *~
	clear
