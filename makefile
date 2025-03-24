run: build
	./engine
	
build:
	gcc engine.c init.c bitboards.c hashkeys.c -o engine