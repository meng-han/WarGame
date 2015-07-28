#include "boardstate.h"
#include <QDebug>
#include <iostream>
using namespace std;

BoardState::BoardState()
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            this->currentOccupancy[i][j] = 0;
            this->nextState[i][j] = 0;
        }
    }
}

BoardState::BoardState(int currentoccupancy[6][6])
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            this->currentOccupancy[i][j] = currentoccupancy[i][j];
        }
    }
}

int BoardState::getUtility(int board[6][6], int currentoccpancy[6][6],int player)
{
    /*cout << "BOARD" << endl;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }*/
    int utility = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(currentoccpancy[i][j] == 1)   // AGENT as 1, human as 2, no occupation as 0
            {
                this->sumOfGreenPlayer += board[i][j];

            } else if(currentoccpancy[i][j] == 2) {
                this->sumOfBluePlayer += board[i][j];
            }
        }
    }
    //qDebug() << "Blue " << this->sumOfBluePlayer << " green " << this->sumOfGreenPlayer;
    if(player == 2)
    {
        utility = this->sumOfBluePlayer - this->sumOfGreenPlayer;
    }else{
        utility = this->sumOfGreenPlayer - this->sumOfBluePlayer;
    }

    return utility;

}
