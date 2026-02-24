#ifndef UNDOSTACK_HPP
#define UNDOSTACK_HPP

#include "Player.hpp"

struct Action {
    string type;
    Player player;
    int previousLevel;
};

class UndoStack {
private:
    Action* arr;
    int capacity;
    int topIndex;

    // resize function declaration
    void resize(int newCapacity);

public:
// constructor and destructor declarations
    UndoStack();
    ~UndoStack();

    // member functions declarations
    void push(const Action& a);
    Action pop();
    bool empty() const;
};

#endif