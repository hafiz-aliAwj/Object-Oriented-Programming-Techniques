#ifndef GAMESYSTEM_HPP
#define GAMESYSTEM_HPP

#include "NormalQueue.hpp"
#include "VIPQueue.hpp"
#include "UndoStack.hpp"

class GameSystem {
private:

    // two separate queues for VIP and NORMAL players
    NormalQueue normalQueue;
    VIPQueue vipQueue;
    UndoStack undoStack;

    // array to store all players for easy access by ID
    Player* players;
    int capacity;
    int size;

    int arrivalCounter;

    // helper functions declarations
    void resize(int newCapacity);
    int findIndexById(int id);

public:

    // constructor declaration
    GameSystem();

    // destructor declaration
    ~GameSystem();

    // operations declarations
    void registerPlayer(int id, string name, int level, string type);
    void play();
    void boost(int id, int x);
    void withdraw(int id);
    void undo();
    void status();
};

#endif