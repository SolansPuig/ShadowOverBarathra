CC = gcc
CFLAGS = -g
LIBS = -lSDL2 -lSDL2_image -lm
OBJ = graphics.o input.o loop.o
DEBUG = -g

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

sob: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f *.o *.out
