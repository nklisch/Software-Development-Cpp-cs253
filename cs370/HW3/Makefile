#Source files
C_SRCS = Starter.c Red.c Green.c Blue.c FileReader.c
C_OBJS = Starter.o Red.o Green.o Blue.o FileReader.o
#Headers
OBJS = ${C_OBJS}
EXE = Starter
EXE1 = Red
EXE2 = Green
EXE3 = Blue
EXE4 = FileReader
#Complier Options
GCC = gcc
GCC_FLAGS = -std=gnu99 -g -Wall -c -lrt -g
LD_FLAGS = -std=gnu99 -g -Wall -lrt -g
#compile
.c.o:
	$(GCC) $(GCC_FLAGS) $<
build: Starter Red Green Blue FileReader
Starter: Starter.o
	$(GCC) $(LD_FLAGS) Starter.o -o $(EXE)
Red: Red.o
	$(GCC) $(LD_FLAGS) Red.o -o $(EXE1)
Green: Green.o
	$(GCC) $(LD_FLAGS) Green.o -o $(EXE2)
Blue: Blue.o
	$(GCC) $(LD_FLAGS) Blue.o -o $(EXE3)
FileReader: FileReader.o
	$(GCC) $(LD_FLAGS) FileReader.o -o $(EXE4)
#recompile
$(C_OBJS):${C_HEADERS}

clean:
	rm -f *.o *~$(EXE)$(EXE1)$(EXE2)$(EXE3)$(EXE4)
packadge:
	tar -cvzf Nathan-Klisch-HW3.tar *.c *.txt Makefile
