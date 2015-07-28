#include "agent.h"

#include <QDebug>
#include <iostream>
using namespace std;

//Agent::Agent()
//{//
//}


vector<vector<int> > Agent::listOfPossibleMoves(BoardState *state, int player)
{
    vector<vector<int> > possibleMoves;

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(state->currentOccupancy[i][j] == 0)
            {

                vector<int> temp;
                for(int k = 0; k < 6; k++)
                {
                    for(int l = 0; l < 6; l++)
                    {
                        temp.push_back(state->currentOccupancy[k][l]);

                    }
                }


                if(player == 2)
                {
                    temp[6*i + j] = 2;
                } else
                    temp[6*i + j] = 1;

                if(isBlitzPossible(i,j,player,state))
                {
                    temp = this->deathBlitz(temp, i, j, player, state);
                }
                possibleMoves.push_back(temp);
            }
        }
    }
    return possibleMoves;
}

bool Agent::isBlitzPossible(int y, int x, int player, BoardState* state)
{
    int up = y - 1;
    int right = x + 1;
    int down = y + 1;
    int left = x - 1;

    int currentPlayer;
    if(player == 2)
    {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }

    if(up >= 0){
        if(state->currentOccupancy[up][x] == currentPlayer)
        {
            return true;
        }
    }

    if(right < 6){
        if(state->currentOccupancy[y][right] == currentPlayer)
        {
            return true;
        }
    }

    if(down < 6){
        if(state->currentOccupancy[down][x] == currentPlayer)
        {
            return true;
        }
    }

    if(left >= 0){
        if(state->currentOccupancy[y][left] == currentPlayer)
        {
            return true;
        }
    }
    return false;
}

vector<int> Agent::deathBlitz(vector<int> result, int y, int x,int player, BoardState* state){
    int up = y - 1;
    int right = x + 1;
    int down = y + 1;
    int left = x - 1;

    int PLAYERONE, PLAYERTWO;
    if(player == 2)
    {
        PLAYERONE = 2;
        PLAYERTWO = 1;
    }else{
        PLAYERONE = 1;
        PLAYERTWO = 2;
    }
    if(up >= 0)
    {
        if(state->currentOccupancy[up][x] == PLAYERTWO)
        {
            result[up*6 + x] = PLAYERONE;
        }
    }
    if(right < 6){
        if(state->currentOccupancy[y][right] == PLAYERTWO)
        {
            result[y*6 + right] = PLAYERONE;
        }
    }

    if(down < 6)
    {
        if(state->currentOccupancy[down][x] == PLAYERTWO)
        {
            result[down*6 + x] = PLAYERONE;
        }
    }

    if(left >= 0)
    {
        if(state->currentOccupancy[y][left] == PLAYERTWO)
        {
            result[y* 6 + left] = PLAYERONE;
        }
    }
    return result;
}
