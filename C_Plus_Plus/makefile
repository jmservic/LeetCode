CXXFLAGS := -g -Wall -std=c++20
TARGET ?= TwoSums
SRC := $(wildcard \
			$(addprefix */,			\
				$(addsuffix .cpp,$(TARGET))))
DIR := $(dir $(SRC))
FULLTARGET = $(addprefix $(DIR),$(TARGET))

$(FULLTARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean print

clean:
	rm -f $(DIR)*.o $(FULLTARGET)

printVars:
	@echo $(SRC)
	@echo $(FULLTARGET)
	@echo $(TARGET) 