#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
using namespace std;

class Player {
private:
    int id = 0;
    string name = "";
    int level = 0;
    string type = "";
    int arrivalOrder = 0;

public:
    // Constructors and assignment operators
    Player() = default;
    Player(int id, string name, int level, string type, int arrivalOrder);

    Player(const Player&) = default;
    Player& operator=(const Player&) = default;

    // getters declaration
    int getId() const;
    string getName() const;
    int getLevel() const;
    string getType() const;
    int getArrivalOrder() const;

    // setters declaration
    void setLevel(int level);
};

#endif