a.out: main.o base.o extras.o
	gcc -o a.out main.o base.o extras.o

main.o: main.c base.h extras.h record.h
	gcc -c -o main.o main.c

base.o: base.h base.c
	gcc -c -o base.o base.c

extras.o: extras.h extras.c
	gcc -c -o extras.o extras.c

clean:
	rm a.out main.o base.o extras.o
