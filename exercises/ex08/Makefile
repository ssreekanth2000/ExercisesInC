CFLAGS=-Wall -Wpedantic -O2

all: ex_compile word_count

ex_compile: ex_compile.c
	gcc -o ex_compile  ex_compile.c  $(CFLAGS) `pkg-config --cflags --libs glib-2.0`

word_count: word_count.c
	gcc -o word_count word_count.c  $(CFLAGS) `pkg-config --cflags --libs glib-2.0`

