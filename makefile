CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = unionfind

SRCS = experiment.cpp UnionFind_class.cpp UnionFind_methods.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
