#ifndef MINIMAXAGENT_H
#define MINIMAXAGENT_H

#include "boardstate.h"
#include <iostream>
#include "agent.h"

using namespace std;

class minimaxAgent : public Agent
{
public:
    minimaxAgent();
    int play(int board[6][6], BoardState *state, int depth, int player, int oppo, int alpha, int beta);
    int nextState[6][6];

};

#endif // MINIMAXAGENT_H
