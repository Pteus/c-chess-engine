run: build
	./engine
	
build:
	gcc engine.c init.c bitboards.c hashkeys.c board.c data.c -o engine