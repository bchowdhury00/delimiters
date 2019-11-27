all: run.o
	gcc -o program run.o
run.o: run.c
	gcc -c run.c
clean:
	rm *.o
	rm *.out
	rm *~
run:
	./program "ls -a -l"
