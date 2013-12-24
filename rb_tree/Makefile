default: rb_tree

rb_tree.o: rb_tree.c
	gcc -c rb_tree.c -o rb_tree.o

ll: ll.o
	gcc rb_tree.o -o rb_tree 

clean:
	-rm -rf rb_tree.o
	-rm -rf rb_tree
