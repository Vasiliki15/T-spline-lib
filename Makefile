CC=g++
CFLAGS=-Wall -Wextra -fopenmp
CFLAGS+=-g3
LIBRARYPATH=-L./ext/T-SPLINE/build
LDFLAGS=-ltspline -lnewmat

SRC_DIR=./src

#DEMO1_SRC=$(SRC_DIR)/demo1/main.cpp $(SRC_DIR)/demo1/mesh.cpp
DEMO2_SRC=$(SRC_DIR)/demo2/main.cpp $(SRC_DIR)/demo2/square.cpp
#DEMO3_SRC=$(SRC_DIR)/demo3/main.cpp $(SRC_DIR)/demo3/trial.cpp

all: demo2

#demo1: $(DEMO1_SRC)
#	$(CC) $(CFLAGS) -o demo1.out $^ $(LIBRARYPATH) $(LDFLAGS)

demo2: $(DEMO2_SRC)
	$(CC) $(CFLAGS) -o demo2.out $^ $(LIBRARYPATH) $(LDFLAGS)

#demo3: $(DEMO3_SRC)
#	$(CC) $(CFLAGS) -o demo3.out $^ $(LIBRARYPATH) $(LDFLAGS)

clean:
	rm -f *.out
