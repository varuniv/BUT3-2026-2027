CC=gcc
OBJ=ballons.o utils.o
CFLAGS=-std=c11 -Wall -Wextra -pedantic -ggdb -I/usr/include/SDL2 -D_REENTRANT -lSDL2 -lSDL2_image -lm
ballons: $(OBJ)
	$(CC)  $^ -o $@ $(CFLAGS)
%.o: %.c 
	$(CC) -c $< -o $@ $(CFLAGS)
.PHONY : clean
clean:
	rm -f ballons *.o