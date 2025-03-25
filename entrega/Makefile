# Nome do compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -std=c++11 -Wall

# Nome do executável
TARGET = industriais

# Arquivos fonte
SRCS = controlador_motor.cpp main.cpp sensor_temperatura.cpp utils.cpp robo_manipulador.cpp

# Arquivos objeto (serão criados automaticamente)
OBJS = $(SRCS:.cpp=.o)

# Regra para compilar o executável
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Regra para compilar os arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

