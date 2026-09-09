CC=gcc
OBJ=droites.o utils.o
CFLAGS=-std=c11 -Wall -Wextra -pedantic -ggdb -I/usr/include/SDL2 -D_REENTRANT -lSDL2 -lSDL2_gfx -lm
main: $(OBJ)
	$(CC)  $^ -o $@ $(CFLAGS)
%.o: %.c 
	$(CC) -c $< -o $@ $(CFLAGS)
.PHONY : clean
clean:
	rm -f main *.o