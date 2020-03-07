IDIR=./include
SFML=/usr/include/SFML/include
CC=g++

CFLAGS=-I$(IDIR) -I$(SFML)

ODIR=obj
LDIR =../lib

LIBS=-lm -lsfml-graphics -lsfml-window -lsfml-system

_DEPS = \
	common.h \
	char.h \
	player.h \
	eng.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = \
	main.o \
	char.o \
	player.o \
	eng.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

SimEng: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
