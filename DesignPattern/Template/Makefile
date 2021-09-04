CXX = g++
INC_DIR = ./src
OBJ_DIR = ./obj


CC = g++
OBJ = $(OBJ_DIR)/TemplateMethodMain.o
HEADER = $(INC_DIR)/ReconBase.h $(INC_DIR)/ReconAxial.h $(INC_DIR)/ReconHelical.h $(INC_DIR)/ReconScout.h
CFLAGS = -c -std=c++17 -Wall -Isrc

TemplateMethodMain: $(OBJ) 
	$(CC) $(OBJ) -o $@ -lpthread
$(OBJ_DIR)/TemplateMethodMain.o: src/TemplateMethodMain.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJ_DIR)/*.o TemplateMethodMain
