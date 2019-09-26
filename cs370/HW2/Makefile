#Source files
C_SRCS = Starter.c Red.c Green.c Blue.c
C_OBJS = Starter.o Red.o Green.o Blue.o
#Headers
OBJS = ${C_OBJS}
EXE = Starter
EXE1 = Red
EXE2 = Green
EXE3 = Blue
#Complier Options
GCC = gcc
GCC_FLAGS = -std=c11 -g -Wall -c 
LD_FLAGS = -std=c11 -g -Wall 
#compile
.c.o:
	$(GCC) $(GCC_FLAGS) $<
build: Starter Red Green Blue
Starter: Starter.o
	$(GCC) $(LD_FLAGS) Starter.o -o $(EXE)
Red: Red.o
	$(GCC) $(LD_FLAGS) Red.o -o $(EXE1)
Green: Green.o
	$(GCC) $(LD_FLAGS) Green.o -o $(EXE2)
Blue: Blue.o
	$(GCC) $(LD_FLAGS) Blue.o -o $(EXE3)
#recompile
$(C_OBJS):${C_HEADERS}

clean:
	rm -f *.o *~$(EXE)$(EXE1)$(EXE2)$(EXE3)
packadge:
	tar -cvzf $(name) *.c *.txt Makefile
