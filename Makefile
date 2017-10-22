CC= g++
CFLAGS = -Wall -c

#directories
MODE= Release
OBJDIR=$(MODE)
BINDIR=$(MODE)

$(BINDIR)/encoder: makeFolders $(OBJDIR)/main.o $(OBJDIR)/InputParser.o
	$(CC) $(OBJDIR)/main.o $(OBJDIR)/InputParser.o -o $(BINDIR)/encoder
	
$(OBJDIR)/main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/InputParser.o: InputParser.cpp InputParser.h
	$(CC) $(CFLAGS) InputParser.cpp -o $(OBJDIR)/InputParser.o
	
makeFolders:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)
	
clean:
	rm $(OBJDIR)/*.o encoder $(BINDIR)/encoder 