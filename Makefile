###########################################################
# Filename: Makefile
#
# CS480 Summer 2026
# Programming Assignment #3 - Disk Arm Simulation
#
# Angela Lee (cssc3130)
# Caitlin Corpus (cssc3114)
###########################################################

EXEC = simarm
FILES = main.cpp algorithms.cpp
CC = g++
LFLAGS =
CFLAGS = -c

OBJECTS = $(FILES:.cpp=.o)

$(EXEC): $(OBJECTS)
	g++ $(LFLAGS) -o $(EXEC) $(OBJECTS)
	rm -f *.o

.cpp.o:
	g++ $(CFLAGS) $<

clean:
	rm -f *.o $(EXEC)

#######################[ EOF: Makefile ]###################
