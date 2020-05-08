g = g++
CFLAGS = -Wall -Werror -MP -MMD

.PHONY: clean run all

all: 		./bin/xod.exe

-include build/*.d

./bin/xod.exe: ./build/main.o ./build/print.o ./build/xod.o ./build/peshki.o
		$(g) $(CFLAGS) -o ./bin/xod ./build/main.o ./build/xod.o ./build/print.o ./build/peshki.o

./build/main.o: ./src/main.cpp ./src/chess.h
		$(g) $(CFLAGS) -o build/main.o -c src/main.cpp

./build/print.o: ./src/print.cpp ./src/chess.h
		$(g) $(CFLAGS) -o ./build/print.o -c src/print.cpp

./build/xod.o: ./src/xod.cpp ./src/chess.h
		$(g) $(CFLAGS) -o ./build/xod.o -c ./src/xod.cpp

./build/peshki.o: ./src/peshki.cpp ./src/chess.h
		$(g) $(CFLAGS) -o ./build/peshki.o -c ./src/peshki.cpp

clean:
		rm -rf build/*.o build/*.d

run:
		./bin/xod
