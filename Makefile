CC = gcc

DCFLAGS = -Wall -Wextra -Wpedantic -std=c99 -Wformat=2 -Wformat-overflow -Wformat-truncation -O2 -Wconversion -D_FORTIFY_SOURCE=2 -fstack-clash-protection -fstack-protector-strong -fstack-protector-all -Wdouble-promotion -pipe -D_FORTIFY_SOURCE=2 -fcf-protection -fpie -pedantic-errors -m64 -g3

CFLAGS= -O2 -std=c99 -m64 -pipe -fcf-protection -fstack-protector-strong -fstack-protector-all -s -fpic -shared -fpie -Wl,-pie -Wl,-z,now -Wl,-z,relro -Wl,-z,defs

.PHONY: default all clean

enum: enum.o
enum.o: enum.c
	$(CC) $(CFLAGS) -c enum.c

clean:
	-rm -rf *.o *.s enum enum_debug
debug: 
	$(CC) $(DCFLAGS) enum.c -o enum_debug