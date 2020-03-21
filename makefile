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
	eng.h \
	pghost.h \
	phuman.h \
	player.h \
	stage.h \
	quad.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = \
	main.o \
	char.o \
	eng.o \
	phuman.o \
	pghost.o \
	player.o \
	stage.o \
	quad.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

SimEng: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
