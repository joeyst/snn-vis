CC := g++
CFLAGS := -Wall -g
TARGET := main
TARGET_TEST := tests
TEST_FLAGS := -DCTEST_ENABLE

SRCS := $(wildcard *.cpp)
OBJS_MAIN := $(filter-out tests.o, $(patsubst %.cpp,%.o,$(SRCS)))
OBJS_TESTS := $(filter-out main.o, $(patsubst %.cpp,%.o,$(SRCS)))

.SILENT:
all: $(TARGET) $(TARGET_TEST)

$(TARGET): $(OBJS_MAIN)
	$(CC) -o $@ $^

.SILENT:
%.o: %.cpp
	$(CC) $(CFLAGS) $(TEST_FLAGS) -c $<

.SILENT:
clean:
	rm -f *.o $(TARGET) $(TARGET_TEST)

.SILENT:
run:
	make all
	./$(TARGET)
	make clean

.SILENT:
test_bin: $(TARGET_TEST)
$(TARGET_TEST): $(OBJS_TESTS)
	$(CC) $(TEST_FLAGS) -o $@ $^

.SILENT:
test:
	make test_bin --no-print-directory
	-./$(TARGET_TEST)
	make clean --no-print-directory

.PHONY: all clean test
