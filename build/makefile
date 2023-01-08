GCC=g++
SRC=../lib/src
BIN=.
INC=../lib/include
EXE=BuffonNeedleSimulator
DEB=-Wall -O0 -g -pthread -std=c++17
PRO=-Wall -O3 -march=native -pthread -std=c++17
GPROF=-Wall -pg -pthread -std=c++17
INT=icpx
INTP=-Wall -03 -pthread -std=c++17

all_intel:
	source /opt/intel/oneapi/setvars.sh intel64
	$(INT) $(INTP) -I $(INC)/ $(SRC)/*.cpp ./*.cpp -o $(BIN)/$(EXE)
	
run_intel:
	sudo nice -n -19 $(BIN)/$(EXE)

all: compile run

all_d: compile_d run_d

compile_d:
	$(GCC) $(DEB) -I $(INC) $(SRC)/*.cpp ./*.cpp -o $(BIN)/$(EXE)

run_d:
	gdb $(BIN)/$(EXE)

compile:
	$(GCC) $(PRO) -I $(INC)/ $(SRC)/*.cpp ./*.cpp -o $(BIN)/$(EXE)

run:
	sudo nice -n -19 $(BIN)/$(EXE)

.PHONY: clean
	rm $(BIN)/$(EXE)
