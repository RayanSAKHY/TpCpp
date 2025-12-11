# les tests
SRC1=Pile.cpp tests_catch.cpp main_test.cpp
# programme
SRC2=Pile.cpp main.cpp
#SRC=$(wildcard *.cpp)  
CXX=g++
EXE1=cpp6_test
EXE2=cpp6

CXXFLAGS+=-Wall -Wextra -MMD -g -O2 -Werror
LDFLAGS= 

OBJ1=$(addprefix build/,$(SRC1:.cpp=.o))
DEP1=$(addprefix build/,$(SRC1:.cpp=.d))

OBJ2=$(addprefix build/,$(SRC2:.cpp=.o))
DEP2=$(addprefix build/,$(SRC2:.cpp=.d))

all: catch.hpp $(EXE1) $(EXE2)

$(EXE1): $(OBJ1)
	$(CXX) -o $(EXE1) $^ $(LDFLAGS)

$(EXE2): $(OBJ2)
	$(CXX) -o $(EXE2) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

catch.hpp:
	wget https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp

-include $(DEP1)
-include $(DEP2)
