CC=gcc
CFLAGS=-I.
#place all *.h files 
DEPS = chat.c server.h
#place all *.o files 
OBJ = chat.o server.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

chat: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: clean

clean:
	rm  *.o 