CXXFLAGS := -ggdb -Wall -std=c++20 -O0
TARGET ?= TwoSums
lowercase = $(shell echo $(1) | tr '[:upper:]' '[:lower:]')

#If the target contains test in the name, append google_test to the CXXFLAGS
ifeq '$(findstring test,$(call lowercase,$(TARGET)))' "test"
	INCLUDES := -I C:/msys64/usr/local/include
	LDFLAGS := -lgtest -lgtest_main
	LIBINCLUDES := -L C:/msys64/usr/local/lib
endif

SRC := $(wildcard \
			$(addprefix */,			\
				$(addsuffix .cpp,$(TARGET))))
DIR := $(dir $(SRC))
FULLTARGET = $(addprefix $(DIR),$(TARGET))


$(FULLTARGET): $(SRC)
	$(CXX) $(INCLUDES) $(LIBINCLUDES) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

.PHONY: clean print

clean:
	rm -f $(DIR)*.o $(FULLTARGET)

printVars:
	@echo $(SRC)
	@echo $(FULLTARGET)
	@echo $(TARGET)
	@echo $(CXXFLAGS)
	@echo $(INCLUDES)
	@echo $(LDFLAGS)
	@echo $(LIBINCLUDES)