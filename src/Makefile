CC = g++ 
VERSION = -g -std=c++11 -Wall
INCLUDE = -I../include -lglut -lGL -lsqlite3
TARGET = ../bin/PlaneWars
SRCS = $(wildcard *.cc)
OBJS = $(patsubst %cc,%o,$(SRCS))

all:$(TARGET)
	
$(TARGET):$(OBJS)
	$(CC) $(OBJS) $(VERSION) $(INCLUDE) -o $(TARGET)

%.o:%.cc
	$(CC) $(VERSION) $(INCLUDE) -c $<

.PHONY:clean
clean:
	rm -rf $(OBJS) $(TARGET)