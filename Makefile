CC=g++
CFLAGS=-Wall -Wextra -fopenmp
CFLAGS+=-g3
INCLUDEPATH=-I./ext/T-SPLINE
LIBRARYPATH=-L./ext/T-SPLINE/build
LDFLAGS=-ltspline -lnewmat

SRC_DIR=./src

DEMO1_SRC=$(SRC_DIR)/demo1/main.cpp $(SRC_DIR)/demo1/mesh.cpp

all: demo1

demo1: $(DEMO1_SRC)
	$(CC) $(CFLAGS) -o demo1.out $^ $(INCLUDEPATH) $(LIBRARYPATH) $(LDFLAGS)

clean:
	rm -f *.out
