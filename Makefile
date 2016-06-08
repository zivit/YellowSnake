CXX=clang++
CXXFLAGS=-std=c++14 -O2 -pipe -fomit-frame-pointer -march=native
TARGET=$(shell basename `pwd`)
SOURCES=src/*.c++

LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: $(TARGET)

$(TARGET):
	$(CXX) -o $(TARGET) $(LDFLAGS) $(SOURCES) $(LOADLIBES) $(LDLIBS) $(CXXFLAGS)

debug: CXXFLAGS=-std=c++14 -g -O0 -Werror -pedantic -pipe
debug: all

prof: CXXFLAGS=-std=c++14 -O0 -pg
prof: all
prof: run
prof:
	gprof -b $(TARGET) gmon.out > analysis.txt

clean:
	$(RM) $(TARGET) *.o gmon.out analysis.txt

run:
	./$(TARGET)

.PHONY: all clean debug prof run
