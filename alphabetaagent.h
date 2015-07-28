#ifndef ALPHABETAAGENT_H
#define ALPHABETAAGENT_H

#include "agent.h"
#include "boardstate.h"

class alphaBetaAgent : public Agent
{
public:
    alphaBetaAgent();
    int play(int board[6][6], BoardState *state, int depth, int player, int oppo, int alpha, int beta);
    int nextState[6][6];
};

#endif // ALPHABETAAGENT_H
