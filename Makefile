CC=gcc
CFLAGS= -Wall -Werror -pedantic
SOURCES=klib_vector.h
CFILES=klib_vector.c
BINS=test klib_vector.so

all: $(BINS)

klib_vector.so: klib_vector.c klib_vector.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ klib_vector.c

test: test.c
	$(CC) $(CFLAGS) test test.c
