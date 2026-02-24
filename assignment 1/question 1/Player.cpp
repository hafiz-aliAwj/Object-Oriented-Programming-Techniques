#include "Player.hpp"

// Constructor definition
Player::Player(int id, string name, int level, string type, int arrivalOrder)
    : id(id), name(name), level(level), type(type), arrivalOrder(arrivalOrder) {}

// getters and setters definition
int Player::getId() const { return id; }
string Player::getName() const { return name; }
int Player::getLevel() const { return level; }
string Player::getType() const { return type; }
int Player::getArrivalOrder() const { return arrivalOrder; }

void Player::setLevel(int lvl) { level = lvl; }