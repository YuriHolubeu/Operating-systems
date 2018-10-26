all: sem1 sem2
	touch 09-1a.c
	touch 08-1a.c
	strace ./sem1 2> sem1.log &
	ipcs sem > ipcs.log &
	strace ./sem2 2> sem2.log &
	cat sem1.log ipcs.log sem2.log
sem1: sem1.c Makefile
	gcc -Wall -Wextra -g sem1.c -o sem1
sem2: sem2.c Makefile
	gcc -Wall -Wextra -g sem2.c -o sem2
clean:
	rm sem1 || true
	rm sem2 || true
