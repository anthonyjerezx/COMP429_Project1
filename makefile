CC=gcc
CFLAGS=-lpthread
#place all *.h files 
DEPS =  utils.h chat.c 
#place all *.o files 
OBJ = chat.o utils.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

chat: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: clean

clean:
	rm  *.o chat