CC=gcc
CFLAGS=-I.
DEPS = chat.c
OBJ = chat.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

chat: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: clean

clean:
	rm  *.o 