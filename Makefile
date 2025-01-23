CXX = g++
CXXFLAGS = -Wall -Wextra -g3
SRC_DIR = src
OUTPUT_DIR = $(SRC_DIR)/output

SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/controllers/IniciarJogo.cpp \
      $(SRC_DIR)/views/MenuInicial.cpp \
      $(SRC_DIR)/Personagens/Eleven.cpp \
      $(SRC_DIR)/Personagens/Mike.cpp \
      $(SRC_DIR)/Personagens/Will.cpp \
      $(SRC_DIR)/Personagens/Dustin.cpp \
      $(SRC_DIR)/Personagens/Lucas.cpp \
      $(SRC_DIR)/Personagens/Max.cpp \
      $(SRC_DIR)/items/Item.cpp

TARGET = $(OUTPUT_DIR)/main.exe

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
