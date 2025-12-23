
CXX = g++

CXXFLAGS = -std=c++11 -Wall -Iinclude

BIN_DIR = bin

OBJ_DIR = obj

SRC_DIR = src

INCLUDE_DIR = include

EXECUTABLE = $(BIN_DIR)/tp1.out

SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/objeto.cpp $(SRC_DIR)/cena.cpp $(SRC_DIR)/ordenacao.cpp

OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN_DIR) # Cria o diretório 'bin' se ele não existir
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR) # Cria o diretório 'obj' se ele não existir
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean