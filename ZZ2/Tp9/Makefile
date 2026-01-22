# utilise le compilo par defaut de la machine
#CXX=g++-12
SRC=ZZ.cpp ComparateurZZ.cpp main.cpp Rand_0_100.cpp
#SRC=$(wildcard *.cpp)
EXE=ZZexe

CXXFLAGS+=-Wall -Wextra -MMD -g -fdiagnostics-color=auto -Werror
LDFLAGS= #-lSDL

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

-include $(DEP)