#pragma once
#include <vector>


class Player;

class RenderWindow;

int gameLoop();

int endOfGame(const Player& p1, const Player& p2, std::vector<std::vector<int>>& field);

void handleEndOfGame(RenderWindow& window, int whoLose);
