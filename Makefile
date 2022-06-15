CXX ?= g++                                                                                                                                                                                                    

CXXFLAGS += -c -Wall -std=c++11 $(shell pkg-config --cflags opencv4)
LDFLAGS += $(shell pkg-config --libs --static opencv4)

all: readvideo

readvideo: main.o ReadFromVideo.o 
	$(CXX) $^  -g -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS)

clean:
	rm -f *.o readvideo

