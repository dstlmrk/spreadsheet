# MAREK_DOSTAL
# dostam12@fit.cvut.cz

CXXFLAGS = -Wall -pedantic -Wno-long-long -g -O0 -ggdb
CLIBS    = -lncurses
CC       = g++
RM       = rm -rf
ODIR     = obj
SDIR     = src
DDIR     = doc
BIN      = ./dostam12
DOXY     = Doxyfile

OBJ_FILES = $(ODIR)/main.o $(ODIR)/cwindow.o $(ODIR)/cmenu.o $(ODIR)/cprinttable.o $(ODIR)/cmove.o $(ODIR)/chelp.o $(ODIR)/ccell.o $(ODIR)/cstringcell.o $(ODIR)/ctable.o $(ODIR)/cintcell.o

all:
	make clean
	make compile
	make doc

compile: $(OBJ_FILES)
	$(CC) $(CXXFLAGS) $(OBJ_FILES) $(CLIBS) -o $(BIN)

run: $(BIN)
	$(BIN)

doc:
	doxygen $(DOXY) >/dev/null 2>/dev/null # uncomment to hide doxygen output

clean:
	$(RM) $(ODIR)
	$(RM) $(DDIR)

$(ODIR)/%.o: $(SDIR)/%.cpp
	mkdir -p $(ODIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

$(ODIR)/%.o: $(SDIR)/class/cell/%.cpp
	mkdir -p $(ODIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

$(ODIR)/%.o: $(SDIR)/class/layout/%.cpp
	mkdir -p $(ODIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

$(ODIR)/%.o: $(SDIR)/class/table/%.cpp
	mkdir -p $(ODIR)
	$(CC) $(CXXFLAGS) -c $< -o $@