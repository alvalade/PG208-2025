CC=g++
DBGFLAGS=-O0 -g

INCDIR=.
SRCDIR=.
BINDIR=bin
OBJDIR=.obj
CFLAGS=-Wall -std=c++17
MKDIR_P := mkdir -p
EXEC_FILE=$(BINDIR)/main
OBJECTSFILES := main.o \
                ofstream_exc.o \
				ifstream_exc.o \

OBJECTS := $(OBJECTSFILES:%=$(OBJDIR)/%)

# export LD_LIBRARY_PATH := $(LD_LIBRARY_PATH):$(LIBDIR)

.PHONY: directories all

all: $(EXEC_FILE) run

run:
	@$(BINDIR)/main

directories: $(BINDIR) $(OBJDIR)

$(BINDIR):
	${MKDIR_P} $(BINDIR)

$(OBJDIR):
	${MKDIR_P} $(OBJDIR)

$(EXEC_FILE): $(OBJECTS) | directories
	$(CC) $(CFLAGS) -o $(BINDIR)/main $(OBJECTS) -I$(INCDIR)
	

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | directories
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

clean:
	@rm -rf $(BINDIR)
	@rm -rf $(OBJDIR)
