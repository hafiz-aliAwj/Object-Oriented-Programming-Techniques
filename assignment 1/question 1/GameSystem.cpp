#include "GameSystem.hpp"
#include <iostream>
using namespace std;



// constructor definition
GameSystem::GameSystem() {
    capacity = 4;
    size = 0;
    arrivalCounter = 0;
    players = new Player[capacity];
}

// destructor definition
GameSystem::~GameSystem() {
    delete[] players;
}

// resize function definition
void GameSystem::resize(int newCapacity) {

    Player* newArr = new Player[newCapacity];

    for (int i = 0; i < size; i++) {
        newArr[i] = players[i];
    }

    delete[] players;
    players = newArr;
    capacity = newCapacity;
}


// findIndexById function definition
int GameSystem::findIndexById(int id) {

    for (int i = 0; i < size; i++) {
        if (players[i].getId() == id)
            return i;
    }

    return -1;
}


// registerPlayer function definition
void GameSystem::registerPlayer(int id, string name, int level, string type) {

    if (findIndexById(id) != -1)
        return;

    if (size == capacity)
        resize(capacity * 2);

    Player p(id, name, level, type, arrivalCounter++);
    players[size++] = p;

    if (type == "VIP")
        vipQueue.push(p);
    else
        normalQueue.enqueue(p);

    Action a;
    a.type = "REGISTER";
    a.player = p;
    undoStack.push(a);
}

// play function definition
void GameSystem::play() {

    Player p;

    if (!vipQueue.empty()) {
        p = vipQueue.pop();
    }
    else if (!normalQueue.empty()) {
        p = normalQueue.dequeue();
    }
    else {
        cout << "NO PLAYERS" << endl;
        return;
    }

    int index = findIndexById(p.getId());

    if (index != -1) {
        players[index] = players[size - 1];
        size--;
        if (size > 0 && size == capacity / 4)
            resize(capacity / 2);
    }

    cout << p.getId() << " " << p.getName() << endl;

    Action a;
    a.type = "PLAY";
    a.player = p;
    undoStack.push(a);
}

// boost function definition

void GameSystem::boost(int id, int x) {

    int index = findIndexById(id);

    if (index == -1)
        return;

    if (players[index].getType() != "VIP")
        return;

    Action a;
    a.type = "BOOST";
    a.player = players[index];
    a.previousLevel = players[index].getLevel();

    players[index].setLevel(players[index].getLevel() + x);

    vipQueue.removeById(id);
    vipQueue.push(players[index]);

    undoStack.push(a);
}


// withdraw function definition

void GameSystem::withdraw(int id) {

    int index = findIndexById(id);

    if (index == -1)
        return;

    Player p = players[index];

    if (p.getType() == "VIP")
        vipQueue.removeById(id);
    else
        normalQueue.removeById(id);

    players[index] = players[size - 1];
    size--;

    if (size > 0 && size == capacity / 4)
        resize(capacity / 2);

    Action a;
    a.type = "WITHDRAW";
    a.player = p;

    undoStack.push(a);
}


// undo function definition
void GameSystem::undo() {

    if (undoStack.empty())
        return;

    Action a = undoStack.pop();

    if (a.type == "REGISTER") {

        int index = findIndexById(a.player.getId());

        if (index != -1) {
            if (a.player.getType() == "VIP")
                vipQueue.removeById(a.player.getId());
            else
                normalQueue.removeById(a.player.getId());

            players[index] = players[size - 1];
            size--;
        }
    }

    else if (a.type == "PLAY") {

        if (size == capacity)
            resize(capacity * 2);

        players[size++] = a.player;

        if (a.player.getType() == "VIP")
            vipQueue.push(a.player);
        else
            normalQueue.enqueue(a.player);
    }

    else if (a.type == "BOOST") {

        int index = findIndexById(a.player.getId());

        if (index != -1) {
            players[index].setLevel(a.previousLevel);
            vipQueue.removeById(a.player.getId());
            vipQueue.push(players[index]);
        }
    }

    else if (a.type == "WITHDRAW") {

        if (size == capacity)
            resize(capacity * 2);

        players[size++] = a.player;

        if (a.player.getType() == "VIP")
            vipQueue.push(a.player);
        else
            normalQueue.enqueue(a.player);
    }
}


// status function definition
void GameSystem::status() {
    cout << vipQueue.getSize() << " " << normalQueue.getSize() << endl;

    // Print VIP queue in priority order (level desc, then arrival)
    int vipSize = vipQueue.getSize();
    bool printed[vipSize];
    for (int i = 0; i < vipSize; i++) printed[i] = false;

    for (int count = 0; count < vipSize; count++) {
        int maxIndex = -1;
        for (int i = 0; i < vipSize; i++) {
            if (printed[i]) continue;
            if (maxIndex == -1) maxIndex = i;
            else {
                Player a = vipQueue.peek(i);
                Player b = vipQueue.peek(maxIndex);
                if (a.getLevel() > b.getLevel() ||
                   (a.getLevel() == b.getLevel() && a.getArrivalOrder() < b.getArrivalOrder())) {
                    maxIndex = i;
                }
            }
        }
        if (maxIndex != -1) {
            cout << vipQueue.peek(maxIndex).getId() << " ";
            printed[maxIndex] = true;
        }
    }
    cout << endl;

    // Normal queue in arrival order
    for (int i = 0; i < normalQueue.getSize(); i++) {
        cout << normalQueue.peek(i).getId() << " ";
    }
    cout << endl;
}