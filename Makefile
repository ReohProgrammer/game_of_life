GameOfLife: GameOfLife.o main.o
	gcc -o GameOfLife main.o GameOfLife.o -lncurses

GameOfLife.o: GameOfLife.c GameOfLife.h 
	gcc -c GameOfLife.c 


main.o: main.c GameOfLife.h
	gcc -c main.c

clean: 
	rm -f *.o