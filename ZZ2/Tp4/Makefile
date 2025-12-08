SRC = Bavarde.cpp Program.cpp
EXE = Program

CXXFLAGS+=-Wall -Wextra -g -Werror -O2

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) -o $(EXE) $^

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

-include $(DEP)