CXXFLAGS=-std=c++17 -g -Wall -Wextra -Wfatal-errors -rdynamic
LDFLAGS=-lboost_regex -ldl

SRC_DIR = src
BUILD_DIR = build

CXX_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
CXX_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o, $(CXX_SOURCES))

.PHONY:all
all: testlog

testlog: testlog.cpp liblogging.a
	$(CXX) $(CXXFLAGS) -I./src $^ $(LDFLAGS) -o $@

liblogging.a : $(CXX_OBJS)
	ar -rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.hpp
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	$(RM) -r ./build/
	$(RM) -r ./log/
