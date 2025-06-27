# @@Variables
SRCDIR := src
OBJDIR := $(SRCDIR)/obj
BINDIR := .

# @@Files
MAIN := main
GRID := grid
RULE := rule
ARGS := args

# @@Commands
all: $(OBJDIR)
    # Creates src/lib/*.cpp object files
	g++ -c $(SRCDIR)/lib/grid.cpp -o $(OBJDIR)/$(GRID).o
	g++ -c $(SRCDIR)/lib/rule.cpp -o $(OBJDIR)/$(RULE).o
	g++ -c $(SRCDIR)/lib/args.cpp -o $(OBJDIR)/$(ARGS).o

    # Creates src/main.cpp object file
	g++ -c $(SRCDIR)/main.cpp -o $(OBJDIR)/$(MAIN).o

    # Assembles the object files into the final executable
	g++ -O2 -Wall $(OBJDIR)/$(MAIN).o \
        $(OBJDIR)/$(GRID).o \
        $(OBJDIR)/$(RULE).o \
        $(OBJDIR)/$(ARGS).o \
        -o $(BINDIR)/$(MAIN)

clean:
	rm -rf $(BINDIR)/$(MAIN) $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)
