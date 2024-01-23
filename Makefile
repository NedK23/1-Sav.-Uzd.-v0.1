#variables
#compileris
COMP = g++
#nustatom compilerio versija
COMPINFO = -std=c++20 -Wall -Wextra -pedantic
#nustatome i kintamaji cpp failus
CPP = main.cpp mylib.cpp fileRead.cpp
OBJS = $(SRCS:.cpp=.obj)
EXE = main

all: $(EXE)

$(EXE): $(CPP)
	$(COMP) $(COMPINFO) $(CPP) -o $(EXE)

%.obj: %.cpp mylib.h fileRead.h
	$(COMP) $(COMPINFO) /c $< -o $@

clean:
	del *.obj $(EXE).exe
