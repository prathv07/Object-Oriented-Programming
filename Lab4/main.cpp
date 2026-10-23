#include <iostream>
#include "RPG.h"
#include "Game.h"

using namespace std;

int main()
{
    Game game;

    int num_players = 10;

    game.generatePlayers(num_players);

    game.gameLoop();

    game.printFinalResults();

    return 0;
}