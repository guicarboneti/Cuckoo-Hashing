CFLAGS  = -std=c99 -g \
	-W -Wall -Wextra \

LFLAGS = -lm

#------------------------------------------------------------------------------
.PHONY : all clean

#------------------------------------------------------------------------------
all : myht

hash: hash.o
	$(CC) $(CFLAGS) -o $@ $^

utils: utils.o
	$(CC) $(CFLAGS) -o $@ $^

myht : myht.o hash.o utils.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

#------------------------------------------------------------------------------
clean :
	$(RM) *.o

purge :
	$(RM) myht *.o
