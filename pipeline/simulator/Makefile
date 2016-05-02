CC = gcc -Wall
SRCS = ./*.c
OBS = ./*.o


pipeline: SRC
	$(CC) -o $@ $(OBS)

SRC: $(SRCS)
	$(CC) -c $(SRCS)

clean: $(OBS)
	rm $(OBS) pipeline
