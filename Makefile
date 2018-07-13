CC = g++ -g
STDFLAGS = -std=c++11

all: prog2

prog2:
	$(CC) kruskal.cc main.cc -o $@ $(STDFLAGS)

.PHONY: clean

clean:
	rm -rf prog2