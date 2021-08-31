CXX = g++
INC_DIR = ./src
OBJ_DIR = ./obj


CC = g++
OBJ = $(OBJ_DIR)/SingletonBenchMark.o
HEADER = $(INC_DIR)/SingletonAcqRel.h $(INC_DIR)/SingletonCallOnceSafe.h $(INC_DIR)/SingletonClassical.h $(INC_DIR)/SingletonDoubleLock.h $(INC_DIR)/SingletonLock.h $(INC_DIR)/SingletonLockGuard.h $(INC_DIR)/SingletonSeqConsistency.h
CFLAGS = -c -std=c++11 -Wall -Isrc

SingletonBenchMark: $(OBJ) 
	$(CC) $(OBJ) -o $@ -lpthread
$(OBJ_DIR)/SingletonBenchMark.o: src/SingletonBenchMark.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJ_DIR)/*.o SingletonBenchMark
