#include "alphabetaagent.h"

alphaBetaAgent::alphaBetaAgent()
{
}


int alphaBetaAgent::play(int board[6][6], BoardState *state, int depth, int player, int opponent, int alpha, int beta)
{

    if(depth == 3)
    {
        return state->getUtility(board, state->currentOccupancy, player);
    }

    if(depth % 2== 0){

        int bestValue = -99999;
        std::vector<vector<int> > children = listOfPossibleMoves(state,player);
        BoardState *childState;
        for(int i = 0; i < children.size(); i++){

            childState = new BoardState();
            for(int x = 0; x < 6; x++)
            {
                for(int y = 0; y < 6; y++)
                {
                    childState->currentOccupancy[x][y] = children[i][6*x+y];
                    //qDebug() << "child state " << childState->currentOccupancy[x][y];
                }
            }

            int val = play(board, childState, depth+1, player, opponent, alpha, beta);
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
            alpha = max(alpha, bestValue);
            if(beta <= alpha)
            {
                break;
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
            int val = play(board, childState, depth+1, player, opponent, alpha, beta);

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
            beta = min(beta, bestValue);
            if(beta <= alpha)
            {
                break;
            }
            //bestValue = Math.min(bestValue, val);
        }

        return bestValue;
    }
}
