#include "minimaxagent.h"
#include <QDebug>
#include <iostream>

using namespace std;

minimaxAgent::minimaxAgent()
{
}


int minimaxAgent::play(int board[6][6], BoardState *state, int depth, int player, int opponent, int alpha, int beta)
{

    if(depth == 3)
    {
        return state->getUtility(board, state->currentOccupancy, player);
    }

    if(depth % 2== 0){

        int bestValue = -99999;
        std::vector<vector<int> > children = listOfPossibleMoves(state,player);

        /*qDebug() << "CHILDREN";
        for(int i = 0; i < children.size(); i++)
        {
            for(int j = 0; j < 36; j++)
            {

                cout << children[i][j] << " ";
            }

            cout << endl << endl;
        }*/


        BoardState *childState;

        for(int i = 0; i < children.size(); i++){
            //nodes_expanded++;
            /*int child[6][6];
            for(int j = 0; j < 36; j++)
            {
                child[j/6][j%6] = children[i][j];
                //qDebug() << "child state " << child[j/6][j%6];
            }*/

            childState = new BoardState();
            for(int x = 0; x < 6; x++)
            {
                for(int y = 0; y < 6; y++)
                {
                    childState->currentOccupancy[x][y] = children[i][6*x+y];
                    //qDebug() << "child state " << childState->currentOccupancy[x][y];
                }
            }

            int val = play(board, childState, depth+1, player, opponent, 0, 0);
            if(val > bestValue){
                //state.nextState = childState->currentOccupancy;
                cout << "val changed" <<val<< endl;

                cout << "best state changed" << endl;

                for(int n = 0; n < 6; n++)
                {
                    for(int j = 0; j < 6; j++)
                    {
                        state->nextState[n][j] = childState->currentOccupancy[n][j];
                        cout << state->nextState[n][j] << " ";
                        this->nextState[n][j] = childState->currentOccupancy[n][j];
                    }
                }
                cout << endl;

                bestValue = val;
            }
            //bestValue = Math.max(bestValue, val);
        }

        return bestValue;
    }

    else{
        int bestValue = 999999;
        vector<vector<int> > children = listOfPossibleMoves(state,opponent);
        BoardState *childState;

        for(int i = 0; i < children.size(); i++){
            int child[6][6];
            for(int j = 0; j < 6; j++)
            {
                child[j/6][j%6] = children[i][j];
            }

            //childState = new BoardState(child);
            childState = new BoardState();
            for(int x = 0; x < 6; x++)
            {
                for(int y = 0; y < 6; y++)
                {
                    childState->currentOccupancy[x][y] = children[i][6*x+y];
                    //qDebug() << "child state " << childState->currentOccupancy[x][y];
                }
            }
            int val = play(board, childState, depth+1, player, opponent, 0, 0);

            if(val < bestValue){
                for(int n = 0; n < 6; n++)
                {
                    for(int j = 0; j < 6; j++)
                    {
                        state->nextState[n][j] = childState->currentOccupancy[n][j];
                    }
                }
                bestValue = val;
            }
            //bestValue = Math.min(bestValue, val);
        }

        return bestValue;
    }
}
