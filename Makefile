SHELL    = /bin/sh
CXX      = g++
CXXFLAGS = -Wall
RM       = rm -f

TARGETS = gradecalc

gradecalc : studentrecord.o main.cpp
	$(CXX) $(CXXFLAGS) studentrecord.o main.cpp -o gradecalc

studentrecord.o : StudentRecord.hpp StudentRecord.cpp
	$(CXX) $(CXXFLAGS) -c StudentRecord.cpp -o studentrecord.o

clean :
	$(RM) $(TARGETS) *.o
.PHONY : clean
