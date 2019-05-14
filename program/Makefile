SRCS = $(TARGET).cc
OBJS = $(TARGET).o

ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS   = $(shell root-config --libs)
ROOTGLIBS = $(shell root-config --glibs)

CXXFLAGS   = $(ROOTCFLAGS) -Wall -fPIC
CXXLIBS    = $(ROOTLIBS)
CC = g++ 

all:macroTemplete

macroTemplete: macroTemplete.o src/tutorialAnalysis.cpp include/templeteFlow.h include/FitFunction.h
	$(CC) $(CXXLIBS) macroTemplete.o -o $@
	rm -f *~
	rm -f include/*~
	rm -f src/*~

# suffix rule
.cc.o:
	$(CC) $(CXXFLAGS) -c $<

# clean
.PHONY: clean
clean:
	rm -f macroTemplete
	rm -f macroTemplete.o

