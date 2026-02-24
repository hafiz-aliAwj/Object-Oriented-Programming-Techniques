#include "GameSystem.hpp"
#include <iostream>
using namespace std;

int main() {

    GameSystem system;

    system.registerPlayer(1,"Arin",90,"VIP");
    system.registerPlayer(2,"Ameen",10,"NORMAL");
    system.registerPlayer(3,"Mehran",85,"VIP");
    system.registerPlayer(4,"Wasir",5,"NORMAL");
    system.registerPlayer(5,"Faris",80,"VIP");
    system.registerPlayer(6,"Alaric",12,"NORMAL");

    system.status();

    system.play();
    system.play();

    system.boost(5,20);
    system.status();

    system.withdraw(4);
    system.status();

    system.undo();
    system.status();

    system.undo();
    system.status();

    system.play();
    system.play();
    system.play();
    system.play();

    system.registerPlayer(7,"Player7",50,"VIP");
    system.registerPlayer(8,"Player8",30,"VIP");
    system.registerPlayer(9,"Player9",25,"NORMAL");
    system.registerPlayer(10,"Player10",40,"VIP");
    system.registerPlayer(11,"Player11",15,"NORMAL");

    system.status();

    system.play();
    system.play();
    system.play();

    system.undo();
    system.undo();

    system.status();

    return 0;
}