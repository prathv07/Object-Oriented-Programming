#include "RPG.h"
#include <random>
#include <iostream>
#include <iomanip>

RPG::RPG()
{
    name = "NPC";
    hits_taken = 0;
    luck = 0.1;
    exp = 50.0;
    level = 1;
}
RPG::RPG(string name, int hits_taken, float luck, float exp, int level)
{
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}
RPG::~RPG()
{
}
string RPG::getName() const
{
    return name;
}
int RPG::getHitsTaken() const
{
    return hits_taken;
}

float RPG::getLuck() const
{
    return luck;
}

float RPG::getExp() const
{
    return exp;
}

int RPG::getLevel() const
{
    return level;
}

void RPG::setHitsTaken(int new_hits)
{
    hits_taken = new_hits;
}

bool RPG::isAlive() const
{
    return hits_taken < MAX_HITS_TAKEN;
}
void RPG::setName(string name)
{
    this->name = name;
}

void RPG::updateExpLevel()
{
    exp += 50.0;
 if (exp >= 100.0)
   {
        level += 1;
        exp = 0.0;
        luck += 0.1;
   }
}
void RPG::attack(RPG* opponent)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = dis(gen);

    bool hit = random_num > HIT_FACTOR * opponent->getLuck();

    if (hit)
    {
        opponent->setHitsTaken(opponent->getHitsTaken() + 1);
    }
}
void RPG::printStats()
{
 cout << fixed << setprecision(6);
 cout << "Name: " << name
        << "\tHits Taken: " << hits_taken
        << "\tLuck: " << luck
        << "\tExp: " << exp
        << "\tLevel: " << level
        << "\tStatus: ";

if (isAlive())
    {
        cout << "Alive" << endl;
    }
else
    {
        cout << "Dead" << endl;
    }
}
