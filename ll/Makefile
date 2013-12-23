default: llist

llist.o: llist.c
	gcc -c llist.c -o llist.o

ll: ll.o
	gcc llist.o -o llist

clean:
	-rm -rf llist.o
	-rm -rf llist
