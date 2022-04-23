CC=cc
CFLAGS=-g
OBJ_D=obj

TGT=main
SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,$(OBJ_D)/%.o,$(SRC))
HDR=$(wildcard *.h)

$(TGT): $(OBJ) $(HDR)
	$(CC) -o $@ $(OBJ) $(CFLAGS)

$(OBJ_D)/%.o: %.c $(HDR)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf obj/* $(TGT)
