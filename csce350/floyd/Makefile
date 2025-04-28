# Compiler & flags
CXX := g++
CXXFLAGS := -std=c++17
CXXFLAGS += -Wall -Wextra -pedantic
CXXFLAGS += -g
CXXFLAGS += -MMD
CXXFLAGS += -MP

BUILD_DIR := build

SRC := floyd.cc

OBJS := $(addprefix $(BUILD_DIR)/, $(notdir $(SRC:.cc=.o)))

DEPS := $(OBJS:.o=.d) $(SERVER_OBJS:.o=.d)

EXEC := floyd

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(BUILD_DIR)/%.o: %.cc
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXEC)

-include $(DEPS)

.PHONY: all clean
