#ifndef AGENT_H
#define AGENT_H

#include "boardstate.h"
#include <QList>
#include <iostream>
#include <QVector>

using namespace std;

class Agent
{
public:
    //Agent();
    virtual int play(int board[6][6], BoardState *state, int depth, int player, int oppo, int alpha, int beta) = 0;

    vector<vector<int> > listOfPossibleMoves(BoardState *state, int player);

    bool isBlitzPossible(int y, int x, int player, BoardState *state);

    vector<int> deathBlitz(vector<int> result, int y, int x, int player, BoardState *state);

};

#endif // AGENT_H
