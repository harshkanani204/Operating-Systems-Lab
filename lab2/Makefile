all : build



build: lib/scalar.a lib/matrix.so src/main.cpp src/exceptions.cpp src/log.cpp src/Matrix.cpp src/Scalar.cpp 
	mkdir -p bin
	mkdir -p build
	g++ src/*.cpp -o ./bin/main.exe -L ./lib/scalar.a ./lib/matrix.so  -I ./include

lib/scalar.a : build/main.o build/exceptions.o build/log.o build/Matrix.o build/Scalar.o include/logger.h include/Scalar.h include/Matrix.h
	mkdir -p lib
	ar rcs ./lib/scalar.a ./build/main.o
	ar rcs ./lib/scalar.a ./build/exceptions.o
	ar rcs ./lib/scalar.a ./build/log.o
	ar rcs ./lib/scalar.a ./build/Scalar.o
	ar rcs ./lib/scalar.a ./include/logger.h
	ar rcs ./lib/scalar.a ./include/Scalar.h
	g++ -fPIC ./include/logger.h -o ./lib/matrix.so
	g++ -fPIC ./include/Matrix.h -o ./lib/matrix.so
	g++ -fPIC ./src/*.cpp -o ./lib/matrix.so

build/main.o : src/main.cpp src/exceptions.cpp src/log.cpp src/Matrix.cpp src/Scalar.cpp
	mkdir -p build
	g++ -c ./src/main.cpp  -o ./build/main.o
	g++ -c ./src/exceptions.cpp  -o ./build/exceptions.o
	g++ -c ./src/log.cpp  -o ./build/log.o
	g++ -c ./src/Matrix.cpp  -o ./build/Matrix.o
	g++ -c ./src/Scalar.cpp  -o ./build/Scalar.o

libs: build/main.o build/exceptions.o build/log.o build/Matrix.o build/Scalar.o include/logger.h include/Scalar.h include/Matrix.h
	mkdir -p lib
	ar rcs ./lib/scalar.a ./build/main.o
	ar rcs ./lib/scalar.a ./build/exceptions.o
	ar rcs ./lib/scalar.a ./build/log.o
	ar rcs ./lib/scalar.a ./build/Scalar.o
	ar rcs ./lib/scalar.a ./include/logger.h
	ar rcs ./lib/scalar.a ./include/Scalar.h
	g++ -fPIC ./include/logger.h -o ./lib/matrix.so
	g++ -fPIC ./include/Matrix.h -o ./lib/matrix.so
	g++ -fPIC ./src/*.cpp -o ./lib/matrix.so
	

run:
	@echo "Program Started..."
	@read Operation ; \
 	./bin/main.exe $$Operation < ./run.in  > ./run.out
	@echo "Run Successful"
	echo "./bin/main.exe " "$$Operation" " < ./run.in  > ./run.out " 
	cat ./run.out

test1: 
	@./bin/main.exe  < ./tests/test1.in  DO -A > ./tests/test1.out
	@./check.sh ./tests/test1.out  ./tests/test1.exp 1

test2: 
	@./bin/main.exe  < ./tests/test2.in  DO -M -d > ./tests/test2.out
	@./check.sh ./tests/test2.out  ./tests/test2.exp 2
	

test3: 
	@./bin/main.exe  < ./tests/test3.in  DO -m -X > ./tests/test3.out
	@./check.sh ./tests/test3.out  ./tests/test3.exp 3

test4: 
	@./bin/main.exe  < ./tests/test4.in  DO -T -a -s  > ./tests/test4.out
	@./check.sh ./tests/test4.out  ./tests/test4.exp 4
test5: 
	@./bin/main.exe  < ./tests/test5.in  DO -S -X > ./tests/test5.out
	@./check.sh ./tests/test5.out  ./tests/test5.exp 5

tests: test1 test2 test3 test4 test5

clean:
	@rm -rf build bin lib tests/*.out Console.log