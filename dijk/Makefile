default: dijk

dijk.o: dijk.c
	gcc -c -g dijk.c -o dijk.o

dijk_helper.o: dijk_helper.c
	gcc -c -g dijk_helper.c -o dijk_helper.o

dijk: dijk.o dijk_helper.o
	gcc -g dijk.o dijk_helper.o -o dijk

clean:
	-rm -rf dijk.o
	-rm -rf dijk_helper.o
	-rm -rf dijk
