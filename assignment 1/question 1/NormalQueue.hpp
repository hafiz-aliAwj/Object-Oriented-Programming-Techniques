#ifndef NORMALQUEUE_HPP
#define NORMALQUEUE_HPP

#include "Player.hpp"

class NormalQueue {
private:
    Player* arr;
    int capacity;
    int size;
    int frontIndex;

    void resize(int newCapacity);

public:
    // constructor
    NormalQueue();

    // destructor
    ~NormalQueue();

    // operations declarations
    void enqueue(const Player& p);
    Player dequeue();
    Player peek(int index) const;
    bool empty() const;
    int getSize() const;
    void removeById(int id);
};

#endif