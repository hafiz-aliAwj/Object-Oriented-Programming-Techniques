#include "VIPQueue.hpp"

// constructor definition
VIPQueue::VIPQueue() {
    capacity = 4;
    size = 0;
    arr = new Player[capacity];
}

// destructor definition
VIPQueue::~VIPQueue() {
    delete[] arr;
}

// resize function definition
void VIPQueue::resize(int newCapacity) {

    Player* newArr = new Player[newCapacity];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

// manual swap function definition
void VIPQueue::manualSwap(Player &a, Player &b) {
    Player temp = a;
    a = b;
    b = temp;
}

// higher priority function definition
bool VIPQueue::higherPriority(const Player& a, const Player& b) {

    if (a.getLevel() == b.getLevel()) {
        return a.getArrivalOrder() < b.getArrivalOrder();
    }

    return a.getLevel() > b.getLevel();
}

// heapify up function definition
void VIPQueue::heapifyUp(int index) {

    while (index > 0) {

        int parent = (index - 1) / 2;

        if (higherPriority(arr[index], arr[parent])) {
            manualSwap(arr[index], arr[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}

// heapify down function definition
void VIPQueue::heapifyDown(int index) {

    while (true) {

        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && higherPriority(arr[left], arr[largest])) {
            largest = left;
        }

        if (right < size && higherPriority(arr[right], arr[largest])) {
            largest = right;
        }

        if (largest != index) {
            manualSwap(arr[index], arr[largest]);
            index = largest;
        }
        else {
            break;
        }
    }
}

// push function definition
void VIPQueue::push(const Player& p) {

    if (size == capacity) {
        resize(capacity * 2);
    }

    arr[size] = p;
    heapifyUp(size);
    size++;
}

// pop function definition
Player VIPQueue::pop() {

    Player topPlayer = arr[0];

    arr[0] = arr[size - 1];
    size--;

    heapifyDown(0);

    if (size > 0 && size == capacity / 4) {
        resize(capacity / 2);
    }

    return topPlayer;
}

// peek function definition
Player VIPQueue::peek(int index) const {
    if (index >= 0 && index < size)
        return arr[index];
    return Player(); // return default player if invalid
}

// removeById function definition
void VIPQueue::removeById(int id) {

    for (int i = 0; i < size; i++) {

        if (arr[i].getId() == id) {

            arr[i] = arr[size - 1];
            size--;

            heapifyDown(i);
            heapifyUp(i);

            if (size > 0 && size == capacity / 4) {
                resize(capacity / 2);
            }

            return;
        }
    }
}


// rebuildHeap function definition
void VIPQueue::rebuildHeap() {

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyDown(i);
    }
}

// empty function definition
bool VIPQueue::empty() const {
    return size == 0;
}

// getSize function definition
int VIPQueue::getSize() const {
    return size;
}