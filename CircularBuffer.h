
#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H

// SOURCE: ChatGPT. 
#include <vector>

template <typename T>
class CircularBuffer {
public:
    CircularBuffer(std::size_t size) : buffer(size), currentIndex(0) {}

    // Function to add an element to the buffer
    void push(const T& item) {
        buffer[currentIndex] = item;
        currentIndex = (currentIndex + 1) % buffer.size();
    }

    // Function to access elements
    T& operator[](std::size_t index) {
        return buffer[(currentIndex + index) % buffer.size()];
    }

private:
    std::vector<T> buffer;
    std::size_t currentIndex;
};

#endif
