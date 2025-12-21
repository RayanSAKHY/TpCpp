# les tests des piles
SRC1=testPile.cpp main_test.cpp
#les test des agregateur
SRC3=testAgregateur.cpp main_test.cpp
# programme
SRC2=main.cpp
#SRC=$(wildcard *.cpp)  
CXX=g++
EXE1=cpp7_testPile
EXE2=cpp7
EXE3=cpp7_testAgregateur

CXXFLAGS+=-Wall -Wextra -MMD -g -O2 -Werror
LDFLAGS= 

OBJ1=$(addprefix build/,$(SRC1:.cpp=.o))
DEP1=$(addprefix build/,$(SRC1:.cpp=.d))

OBJ2=$(addprefix build/,$(SRC2:.cpp=.o))
DEP2=$(addprefix build/,$(SRC2:.cpp=.d))

OBJ3=$(addprefix build/,$(SRC3:.cpp=.o))
DEP3=$(addprefix build/,$(SRC3:.cpp=.d))

all: catch.hpp $(EXE1) $(EXE2) $(EXE3)

$(EXE1): $(OBJ1)
	$(CXX) -o $(EXE1) $^ $(LDFLAGS)

$(EXE2): $(OBJ2)
	$(CXX) -o $(EXE2) $^ $(LDFLAGS)

$(EXE3): $(OBJ3)
	$(CXX) -o $(EXE3) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

catch.hpp:
	wget https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp

-include $(DEP1)
-include $(DEP2)
-include $(DEP3)