#include <iostream>
#include "RPG.h"

using namespace std;

int main()
{
    RPG p1("Wiz", 0, 0.2, 60.0, 1);
    RPG p2;

    cout << p1.getName() << endl;
    cout << p2.getName() << endl;
    cout << p1.getHitsTaken() << endl;
    cout << p1.getLuck() << endl;
    cout << p1.getExp() << endl;
    cout << p1.getLevel() << endl;

    p1.setHitsTaken(3);
    cout << p1.getHitsTaken() << endl;
    cout << p1.isAlive() << endl;
    cout << p2.isAlive() << endl;
    return 0;
}