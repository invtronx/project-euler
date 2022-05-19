FLAGS := -Wall -Wpedantic -Wextra -Wno-sign-compare -g
VER := -std=c++11

OUTPUT := bin/exec

prob := prob63.cpp

all: $(prob)
	clang++ $(VER) $(FLAGS) -o $(OUTPUT) $(prob)
