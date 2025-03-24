CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = program

SRCS =	main.cpp \
		Participant/Participant.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = Participant/Participant.h \
       Sort/Sort.h 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) *.txt

rebuild: clean all