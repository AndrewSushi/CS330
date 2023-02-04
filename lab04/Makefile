#
# CIS330: Lab 3
#
# Makefile to build libraries and test applications.
#

CC=gcc
AR=ar

CFLAGS=-g -O2 -I./include -L./lib
LIBS=-llab4 -lm

all: lab4

obj:
	mkdir -p obj

lib:
	mkdir -p lib

obj/stats.o: src/stats.c include/stats.h obj
	$(CC) $(CFLAGS) -c -o $@ $<

obj/ohno.o: src/ohno.c include/ohno.h obj
	$(CC) $(CFLAGS) -c -o $@ $<

lib/liblab4.a: obj/stats.o obj/ohno.o lib
	$(AR) rc lib/liblab4.a obj/stats.o obj/ohno.o

lib/liblab4_dyn_so: obj/stats.c obj/ohno.o lib
	$(CC) -shared $(CFLAGS) -o $@ obj.stats.o obj/ohno.o

lab4: src/lab4.c lib/liblab4.a
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

lab4_dyn: src/lab4.c lib/lab4_dyn.so
	$(CC) $(CFLAGS) -o $@ $< -llab4_dyn $(LIBS)

clean:
	rm lab4 lab4_dyn lib/liblab4.a obj/ohno.o obj/stats.o lib/liblab4_dyn_so
	rmdir obj
	rmdir lib
