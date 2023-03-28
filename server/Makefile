TARGET = aesdsocket

all: ${TARGET}

CC = $(CROSS_COMPILE)gcc
CFLAGS  += -g -Wall

${TARGET}: ${TARGET}.c
	$(CC) ${CFLAGS} ${TARGET}.c -lpthread -lrt -o ${TARGET}

clean:
	rm -rf *.o ${TARGET}
	rm -rf /var/tmp/aesdsocketdata
