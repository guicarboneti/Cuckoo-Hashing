CFLAGS  = -std=c99 -g \
#	-pipe \
	-ggdb3 -Wstrict-overflow=5 -fstack-protector-all \
	-W -Wall -Wextra \
	-Wbad-function-cast \
	-Wcast-align \
	-Wcast-qual \
	-Wconversion \
	-Wfloat-equal \
	-Wformat-y2k \
	-Winit-self \
	-Winline \
	-Winvalid-pch \
	-Wmissing-declarations \
	-Wmissing-field-initializers \
	-Wmissing-format-attribute \
	-Wmissing-include-dirs \
	-Wmissing-noreturn \
	-Wmissing-prototypes \
	-Wnested-externs \
	-Wnormalized=nfc \
	-Wold-style-definition \
	-Woverlength-strings \
	-Wpacked \
	-Wpadded \
	-Wpointer-arith \
	-Wredundant-decls \
	-Wshadow \
	-Wsign-compare \
	-Wstack-protector \
	-Wstrict-aliasing=2 \
	-Wstrict-prototypes \
	-Wundef \
	-Wunsafe-loop-optimizations \
	-Wvolatile-register-var \
	-Wwrite-strings

LFLAGS = -lm

#------------------------------------------------------------------------------
.PHONY : all clean

#------------------------------------------------------------------------------
all : myth

hash: hash.o
	$(CC) $(CFLAGS) -o $@ $^

utils: utils.o
	$(CC) $(CFLAGS) -o $@ $^

myth : myth.o hash.o utils.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

#------------------------------------------------------------------------------
clean :
	$(RM) *.o

purge :
	$(RM) myth *.o
