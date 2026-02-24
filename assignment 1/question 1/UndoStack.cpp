#include "UndoStack.hpp"

// constructor definition
UndoStack::UndoStack() {
    capacity = 4;
    topIndex = -1;
    arr = new Action[capacity];
}

// destructor definition
UndoStack::~UndoStack() {
    delete[] arr;
}

// resize function definition
void UndoStack::resize(int newCapacity) {

    Action* newArr = new Action[newCapacity];

    for (int i = 0; i <= topIndex; i++)
        newArr[i] = arr[i];

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}


// push function definition
void UndoStack::push(const Action& a) {

    if (topIndex + 1 == capacity)
        resize(capacity * 2);

    arr[++topIndex] = a;
}


//
Action UndoStack::pop() {

    Action temp = arr[topIndex--];

    if (topIndex > 0 && topIndex == capacity / 4)
        resize(capacity / 2);

    return temp;
}

bool UndoStack::empty() const {
    return topIndex == -1;
}