default: rb_tree

rb_tree.o: rb_tree.c
	gcc -c rb_tree.c -o rb_tree.o

rb_helper.o: rb_helper.c
	gcc -c rb_helper.c -o rb_helper.o

rb_tree: rb_tree.o rb_helper.o
	gcc rb_tree.o rb_helper.o -o rb_tree

clean:
	-rm -rf rb_tree.o
	-rm -rf rb_helper.o
	-rm -rf rb_tree
