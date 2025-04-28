CXX := g++
CXXFLAGS := -std=c++17
CXXFLAGS += -Wall -Wextra -pedantic
CXXFLAGS += -g
CXXFLAGS += -MMD
CXXFLAGS += -MP

BUILD_DIR := build

SRC_MIN := min_heap.cc
SRC_MAX := max_heap.cc
HELP := helper_functions.cc

OBJS_MIN := $(addprefix $(BUILD_DIR)/, $(notdir $(SRC_MIN:.cc=.o))) \
	$(addprefix $(BUILD_DIR)/, $(notdir $(HELP:.cc=.o)))

OBJS_MAX := $(addprefix $(BUILD_DIR)/, $(notdir $(SRC_MAX:.cc=.o))) \
	$(addprefix $(BUILD_DIR)/, $(notdir $(HELP:.cc=.o)))

DEPS := $(OBJS:.o=.d) $(SERVER_OBJS:.o=.d)

EXEC_MIN := min_heap
EXEC_MAX := max_heap

all: $(EXEC_MIN) $(EXEC_MAX)

$(EXEC_MIN): $(OBJS_MIN)
	$(CXX) $(OBJS_MIN) -o $@

$(EXEC_MAX): $(OBJS_MAX)
	$(CXX) $(OBJS_MAX) -o $@

$(BUILD_DIR)/%.o:%.cc
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXEC_MIN) $(EXEC_MAX)

-include $(DEPS)

.PHONY: all clean
