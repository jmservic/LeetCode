CXXFLAGS := -Wall -std=c++20
TARGET := HappyNumber
SRC := $(addsuffix .cpp,$(TARGET))

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(TARGET)