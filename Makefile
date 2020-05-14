g = g++
CFLAGS = -Wall -Werror -MP -MMD

.PHONY: clean run all

all: 		./bin/broad.exe	./bin/test.out

-include build/*.d

./bin/broad.exe: ./build/main.o ./build/broad_print.o ./build/broad.o 
		$(g) $(CFLAGS) -o ./bin/broad ./build/main.o ./build/broad.o ./build/broad_print.o 

./build/main.o: ./src/main.cpp ./src/chess.h
		$(g) $(CFLAGS) -o build/main.o -c src/main.cpp

./build/broad_print.o: ./src/broad_print.cpp ./src/chess.h
		$(g) $(CFLAGS) -o ./build/broad_print.o -c src/broad_print.cpp

./build/broad.o: ./src/broad.cpp ./src/chess.h
		$(g) $(CFLAGS) -o ./build/broad.o -c ./src/broad.cpp

./bin/test.out: build/test.o build/board.o
	g++ $(CFLAGS) -L thirdparty/lib -l gtest_main -l gtest -l pthread build/test.o build/board.o -o bin/test.out

./build/test.o: test/test.cpp
	g++ $(CFLAGS) -isystem thirdparty/googletest/include -l pthread -I thirdparty/googletest/include -I src -c test/test.cpp -o build/test.o

clean:
		rm -rf build/*.o build/*.d

run:
		./bin/broad
