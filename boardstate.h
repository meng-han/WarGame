#ifndef BOARDSTATE_H
#define BOARDSTATE_H

class BoardState
{
public:
    BoardState();
    BoardState(int currentoccupancy[6][6]);

    int currentOccupancy[6][6];
    int nextState[6][6];

    int sumOfGreenPlayer = 0; //GREEN is agent
    int sumOfBluePlayer = 0; //BLUE is human being

    int getUtility(int board[6][6], int currentOccupancy[6][6], int player);

    //bool isTerminal();

};

#endif // BOARDSTATE_H
