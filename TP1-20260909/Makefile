CC=gcc
OBJ=main.o bonjour.o 

main: $(OBJ)

main.o: main.c bonjour.h

bonjour.o: bonjour.c bonjour.h

.PHONY : clean
clean:
	rm -f main *.o