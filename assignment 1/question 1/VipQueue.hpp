#ifndef VIPQUEUE_HPP
#define VIPQUEUE_HPP

#include "Player.hpp"

class VIPQueue {
private:
    Player* arr;      
    int capacity;     
    int size;         

    // helper functions declarations
    void resize(int newCapacity);
    void heapifyUp(int index);
    void heapifyDown(int index);
    bool higherPriority(const Player& a, const Player& b);
    void manualSwap(Player &a, Player &b);

public:

    // constructor declaration
    VIPQueue();

    // destructor declaration
    ~VIPQueue();

    // operations declarations
    void push(const Player& p);
    Player pop();
    Player peek(int index) const;
    
    // other member functions declarations
    bool empty() const;
    int getSize() const;

    // additional functions declarations
    void removeById(int id);
    void rebuildHeap();
};

#endif