CC=gcc
CFLAGS=-lpthread
#place all *.h files 
DEPS =  server.h chat.c 
#place all *.o files 
OBJ = chat.o server.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

chat: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: clean

clean:
	rm  *.o 