CXX = g++

CXXFLAGS = -std=c++11 -Wall

TARGET = industriais

SRCS = controlador_motor.cpp main.cpp sensor_temperatura.cpp utils.cpp robo_manipulador.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

