all: aesdsocket

CROSS_COMPILE = 
CC ?= $(CROSS_COMPILE)gcc

aesdsocket: aesdsocket.c
	$(CC) aesdsocket.c -lpthread -lrt -o aesdsocket

clean:
	rm -rf *.o aesdsocket 
