#
# Makefile for Employee Hierachy Assignment
#

#
# Define variables and flags
#
CC = g++
CXXFLAGS = -c
BINARY   = simple_test

SOURCES  = Administrator.cpp CommissionEmployee.cpp Employee.cpp HourlyEmployee.cpp SalariedEmployee.cpp simple_test.cpp

OBJECTS  = Administrator.o CommissionEmployee.o Employee.o HourlyEmployee.o SalariedEmployee.o

INCLUDES = Administrator.h CommissionEmployee.h Employee.h HourlyEmployee.h SalariedEmployee.h



#
# default rule all builds BINARY which is simple_test
#
all: simple_test

#
# Rule to build BINARY - links all objects (*.o) into the BINARY
# 	
simple_test: $(OBJECTS) $(INCLUDES) $(BINARY).o
	$(CC) $(BINARY).o $(OBJECTS) -o $(BINARY)

#
# Rules to build *.o files from their *.cpp files.
#
Administrator.o: Administrator.cpp Administrator.h
	$(CC) $(CXXFLAGS) Administrator.cpp -o Administrator.o

CommissionEmployee.o: CommissionEmployee.cpp CommissionEmployee.h
	$(CC) $(CXXFLAGS) CommissionEmployee.cpp -o CommissionEmployee.o

Employee.o: Employee.cpp Employee.h
	$(CC) $(CXXFLAGS) Employee.cpp -o Employee.o

HourlyEmployee.o: HourlyEmployee.cpp HourlyEmployee.h
	$(CC) $(CXXFLAGS) HourlyEmployee.cpp -o HourlyEmployee.o

SalariedEmployee.o: SalariedEmployee.cpp SalariedEmployee.h
	$(CC) $(CXXFLAGS) SalariedEmployee.cpp -o SalariedEmployee.o

#
# Rule to build main program object file with dependencies
#
#$(BINARY).o: $(BINARY).cpp $(INCLUDES)
#	$(CC) $(CXXFLAGS) $< -o $@

#
# Rule to clean everything so that only source files remain.
#
clean:
	-rm -f *.o simple_test

