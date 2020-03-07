OBJDIR=obj
BINDIR=bin
BIN=tests

INCDIRS += trompeloeil
INCDIRS += doctest
SRC += doctest/doctest.cpp

INCDIRS += mocks 
INCDIRS += ../src

SRC += tests/string/test_string.cpp
SRC += ../src/utilities/string.cpp

SRC += tests/led/test_led.cpp
SRC += ../src/utilities/led.cpp
SRC += mocks/peripherals/mock_gpioOutput.cpp
#SRC += ../src/utilities/string.cpp

CXX = g++

CXXFLAGS= -Wall -Wextra -std=c++14 -Os -g

OBJ = $(addsuffix .o ,$(basename $(patsubst %,$(OBJDIR)/%,$(SRC))))
INC = $(addprefix -I , $(INCDIRS))
INCF = $(addprefix -include , $(INCFILES))

all: $(BINDIR)/$(BIN) runTests

runTests:
	@./$(BINDIR)/$(BIN)

clean:
	@rm -rf $(OBJDIR)
	@rm -rf	$(BINDIR)

$(BINDIR)/$(BIN): $(SRC)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(INCF) $(INC) $(SRC) -o $@ 

print-%  : ; @echo $* = $($*)
