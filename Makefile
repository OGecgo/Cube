EXEC = Run 
FILE = $(EXEC)
OBJECTC = $(wildcard src/*.cpp) $(wildcard res/*.cpp) main.cpp
CHANGES = $(OBJECTC) 

CFLAGS = -g


$(EXEC): $(CHANGES)
	rm -f $(EXEC)
	g++ $(OBJECTC) -o $(FILE)
	rm -f $(OBJECTO)

clean:
	rm -f $(OBJECTO) $(FILE)

run:
	./$(FILE)

rungdb:
	gdb ./$(FILE)

runvalgrind:
	valgrind --leak-check=full ./$(FILE)