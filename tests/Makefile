BINDIR=bin
BIN=tests

# Required includes
INCDIRS += trompeloeil doctest mocks
SRC += doctest/doctest.cpp

# Add extra include files, these have last search path, so mocks will overwrite them.
INCDIRS += 

# Add extra source files
SRC+=tests/exampleTests.cpp

CXX = g++

CXXFLAGS= -Wall -Wextra -std=c++14 -Os -g

INC = $(addprefix -I , $(INCDIRS))

all: $(BINDIR)/$(BIN) runTests

runTests:
	@./$(BINDIR)/$(BIN)

clean:
	@rm -rf	$(BINDIR)

$(BINDIR)/$(BIN): $(SRC)
	@mkdir -p $(BINDIR)
	@$(CXX) $(CXXFLAGS) $(INC) $(SRC) -o $@ 

print-%  : ; @echo $* = $($*)
