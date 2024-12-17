CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = program

# Source files
SRCS = main.cpp \
       Diap/Diap.cpp \
       Freq/Freq.cpp \
       SFile/SFile.cpp \
       SKbrd/SKbrd.cpp \
       SQueue/SQueue.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files for dependency tracking
DEPS = Diap/Diap.h \
       Freq/Freq.h \
       SBase/SBase.h \
       SFile/SFile.h \
       SKbrd/SKbrd.h \
       SQueue/SQueue.h

# default target
all: $(TARGET)

# linking the final executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# compilation rule for object files
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean target
clean:
	rm -f $(OBJS) $(TARGET)

# rebuild target
rebuild: clean all