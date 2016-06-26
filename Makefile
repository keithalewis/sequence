CXXFLAGS += -I.. -Wall --std=c++14 -D_DEBUG -g
HDRS = $(wildcard *.h)

sequence: sequence.cpp $(HDRS)
