CXXFLAGS := -Wall -std=c++17
TARGET := GroupAnagrams
SRC := $(addsuffix .cpp,$(TARGET))

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(TARGET)