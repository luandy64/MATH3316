###################################################################
#  Makefile for Project 1 of MATH 3316
#
#  Andy Lu
#  SMU Mathematics
#  MATH 3316 Fall 2016
###################################################################

# compiler & flags
CXX = g++
CXXFLAGS = -O0 -std=c++11

# makefile targets
all : proj1_a.exe proj1_b.exe

proj1_a.exe : proj1_a.cpp matrix.o nest.o
	$(CXX) $(CXXFLAGS) $^ -o $@

proj1_b.exe : proj1_b.cpp matrix.o nest.o
	$(CXX) $(CXXFLAGS) $^ -o $@

test.exe : test.cpp nest.o matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@

matrix.o : matrix.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

nest.o : nest.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean :
	\rm -f *.txt *.o

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######
