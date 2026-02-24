#include "NormalQueue.hpp"
#include <iostream>

// constructor definition
NormalQueue::NormalQueue() {
    capacity = 4;
    size = 0;
    frontIndex = 0;
    arr = new Player[capacity];
}

// destructor definition
NormalQueue::~NormalQueue() {
    delete[] arr;
}

// resize function definition
void NormalQueue::resize(int newCapacity) {
    Player* newArr = new Player[newCapacity];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[(frontIndex + i) % capacity];
    }

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
    frontIndex = 0;
}

// enqueue function definition
void NormalQueue::enqueue(const Player& p) {

    if (size == capacity)
        resize(capacity * 2);

    int index = (frontIndex + size) % capacity;
    arr[index] = p;
    size++;
}

// dequeue function definition
Player NormalQueue::dequeue() {

    Player temp = arr[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    size--;

    if (size > 0 && size == capacity / 4)
        resize(capacity / 2);

    return temp;
}

// peek function definition
Player NormalQueue::peek(int index) const {
    if (index >= 0 && index < size)
        return arr[(frontIndex + index) % capacity];
    return Player(); // return default player if invalid
}

// empty function definition
bool NormalQueue::empty() const {
    return size == 0;
}

// getSize function definition
int NormalQueue::getSize() const {
    return size;
}

// removeById function definition
void NormalQueue::removeById(int id) {

    for (int i = 0; i < size; i++) {
        int idx = (frontIndex + i) % capacity;

        if (arr[idx].getId() == id) {

            for (int j = i; j < size - 1; j++) {
                int cur = (frontIndex + j) % capacity;
                int next = (frontIndex + j + 1) % capacity;
                arr[cur] = arr[next];
            }

            size--;

            if (size > 0 && size == capacity / 4)
                resize(capacity / 2);

            return;
        }
    }
}