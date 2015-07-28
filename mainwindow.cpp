#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();

    connect(&this->bGroup, SIGNAL(buttonClicked(int)), this, SLOT(buttonWasClicked(int)));

    this->bot = new minimaxAgent();
    //this->bot = new alphaBetaAgent();
    this->bestState = new BoardState();
    this->move = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    this->BLUE_STYLESHEET = "background: #70AFB8;";
    this->GREEN_STYLESHEET =  "background:#8BB870;";
    this->EMPTY_STYLESHEET = "";
    this->addToButtonGroup();
    this->constructGameBoards();
    this->initBoard();
}

void MainWindow::constructGameBoards()
{
    vector<int> board1 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    this->gameBoards.push_back(board1);
    vector<int> board2 = {99,1,99,1,99,1,1,99,1,99,1,99,99,1,99,1,99,1,1,99,1,99,1,99,99,1,99,1,99,1,1,99,1,99,1,99};
    this->gameBoards.push_back(board2);
    vector<int> board3 = {1,1,1,1,1,1,2,2,2,2,2,2,4,4,4,4,4,4,8,8,8,8,8,8,16,16,16,16,16,16,32,32,32,32,32,32};
    this->gameBoards.push_back(board3);
    vector<int> board4 = {66,76,28,66,11,9,31,9,50,8,33,14,80,76,39,59,2,48,50,73,43,3,13,3,99,45,72,87,49,4,80,63,92,28,61,53};
    this->gameBoards.push_back(board4);
    vector<int> board5 = {1,1,1,1,1,1,1,3,4,4,3,1,1,4,2,2,4,1,1,4,2,2,4,1,1,3,4,4,3,1,1,1,1,1,1,1};
    this->gameBoards.push_back(board5);
}

void MainWindow::initBoard()
{
    for(int i = 0; i < 36; i++)
    {
        this->bGroup.button(i + 1)->setText(QString::number(this->gameBoards[0][i]));
        this->board[i/6][i%6] = this->gameBoards[0][i];
    }
}

void MainWindow::addToButtonGroup(){
    this->bGroup.addButton(ui->button11, 1);
    this->bGroup.addButton(ui->button12, 2);
    this->bGroup.addButton(ui->button13, 3);
    this->bGroup.addButton(ui->button14, 4);
    this->bGroup.addButton(ui->button15, 5);
    this->bGroup.addButton(ui->button16, 6);
    this->bGroup.addButton(ui->button21, 7);
    this->bGroup.addButton(ui->button22, 8);
    this->bGroup.addButton(ui->button23, 9);
    this->bGroup.addButton(ui->button24, 10);
    this->bGroup.addButton(ui->button25, 11);
    this->bGroup.addButton(ui->button26, 12);
    this->bGroup.addButton(ui->button31, 13);
    this->bGroup.addButton(ui->button32, 14);
    this->bGroup.addButton(ui->button33, 15);
    this->bGroup.addButton(ui->button34, 16);
    this->bGroup.addButton(ui->button35, 17);
    this->bGroup.addButton(ui->button36, 18);
    this->bGroup.addButton(ui->button41, 19);
    this->bGroup.addButton(ui->button42, 20);
    this->bGroup.addButton(ui->button43, 21);
    this->bGroup.addButton(ui->button44, 22);
    this->bGroup.addButton(ui->button45, 23);
    this->bGroup.addButton(ui->button46, 24);
    this->bGroup.addButton(ui->button51, 25);
    this->bGroup.addButton(ui->button52, 26);
    this->bGroup.addButton(ui->button53, 27);
    this->bGroup.addButton(ui->button54, 28);
    this->bGroup.addButton(ui->button55, 29);
    this->bGroup.addButton(ui->button56, 30);
    this->bGroup.addButton(ui->button61, 31);
    this->bGroup.addButton(ui->button62, 32);
    this->bGroup.addButton(ui->button63, 33);
    this->bGroup.addButton(ui->button64, 34);
    this->bGroup.addButton(ui->button65, 35);
    this->bGroup.addButton(ui->button66, 36);
}

bool MainWindow::isBlitz(int y, int x)
{
    int up = y - 1;
    int right = x + 1;
    int down = y + 1;
    int left = x - 1;

    int currentPlayer = 2;

    if(up >= 0){
        if(this->bestState->currentOccupancy[up][x] == currentPlayer)
        {
            return true;
        }
    }

    if(right < 6){
        if(this->bestState->currentOccupancy[y][right] == currentPlayer)
        {
            return true;
        }
    }

    if(down < 6){
        if(this->bestState->currentOccupancy[down][x] == currentPlayer)
        {
            return true;
        }
    }

    if(left >= 0){
        if(this->bestState->currentOccupancy[y][left] == currentPlayer)
        {
            return true;
        }
    }
    return false;
}


void MainWindow::conquer(int y, int x, BoardState *state)
{
    int up = y - 1;
    int right = x + 1;
    int down = y + 1;
    int left = x - 1;

    int PLAYERONE, PLAYERTWO;
        PLAYERONE = 2;
        PLAYERTWO = 1;

    if(up >= 0)
    {
        if(state->currentOccupancy[up][x] == PLAYERTWO)
        {
            state->currentOccupancy[up][x] = PLAYERONE;
        }
    }
    if(right < 6){
        if(state->currentOccupancy[y][right] == PLAYERTWO)
        {
            state->currentOccupancy[y][right] = PLAYERONE;
        }
    }

    if(down < 6)
    {
        if(state->currentOccupancy[down][x] == PLAYERTWO)
        {
            state->currentOccupancy[down][x] = PLAYERONE;
        }
    }

    if(left >= 0)
    {
        if(state->currentOccupancy[y][left] == PLAYERTWO)
        {
            state->currentOccupancy[y][left] = PLAYERONE;
        }
    }
}
/*
void MainWindow::buttonWasClicked(int id){
    if(this->move%2==1)
        this->bGroup.button(id)->setStyleSheet(this->BLUE_STYLESHEET);
    if(this->move%2==0)
        this->bGroup.button(id)->setStyleSheet(this->GREEN_STYLESHEET);

    this->move++;
}*/


void MainWindow::buttonWasClicked(int id){
    this->bGroup.button(id)->setStyleSheet(this->BLUE_STYLESHEET);
    this->bGroup.button(id)->setEnabled(false);
    /*for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            //bestState->currentOccupancy[i][j] = bestState->nextState[i][j];
            qDebug() << bestState->currentOccupancy[i][j];
        }
    }*/
    //human turn
    bestState->currentOccupancy[(id-1)/6][(id-1)%6] = 2;
    bool isBlitzMove = isBlitz((id-1)/6, (id-1)%6);
    if(isBlitzMove) conquer((id-1)/6, (id-1)%6, bestState);
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(bestState->nextState[i][j] == 1)
            {
                this->bGroup.button(i*6 + j + 1)->setStyleSheet(this->GREEN_STYLESHEET);
                this->bGroup.button(i*6 + j + 1)->setEnabled(false);
            }
            else if(bestState->nextState[i][j] == 2)
            {
                this->bGroup.button(i*6 + j + 1)->setStyleSheet(this->BLUE_STYLESHEET);
                this->bGroup.button(i*6 + j + 1)->setEnabled(false);
            }
        }
    }




    //Bot turn
    int utility = this->bot->play(this->board, bestState, 0, 1, 2, this->alpha, this->beta);
    //qDebug() << utility;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            bestState->currentOccupancy[i][j] = bestState->nextState[i][j];
        }
    }
    int countForZero = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(bestState->nextState[i][j] == 1)
            {
                this->bGroup.button(i*6 + j + 1)->setStyleSheet(this->GREEN_STYLESHEET);
                this->bGroup.button(i*6 + j + 1)->setEnabled(false);
            }
            else if(bestState->nextState[i][j] == 2)
            {
                this->bGroup.button(i*6 + j + 1)->setStyleSheet(this->BLUE_STYLESHEET);
                this->bGroup.button(i*6 + j + 1)->setEnabled(false);
            }else
                countForZero++;
        }
    }
    qDebug() << countForZero;
    if(countForZero == 0)
    {
        concludeGame();
    }
}





void MainWindow::concludeGame()
{
    int humanScore = 0;
    int botScore = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(this->bestState->currentOccupancy[i][j] == 2)
            {
                humanScore += this->board[i][j];
            }else if(this->bestState->currentOccupancy[i][j] == 1){
                botScore += this->board[i][j];
            }
        }
    }
    qDebug() << humanScore << " " << botScore;
    QString score = "\nYour Score: " + QString::number(humanScore) + "\n" + "Bot Score: " + QString::number(botScore);
    if(humanScore > botScore)
    {
        QMessageBox::information(this, "Result", "You Win!" + score);
    }else if(humanScore == botScore){
        QMessageBox::information(this, "Result", "Draw!" + score);
    }else{
        QMessageBox::information(this,"Result", "You Lose!" + score);
    }

    resetGame();
}

void MainWindow::resetGame()
{
    for(int i = 1; i <= 36; i++)
    {
        this->bGroup.button(i)->setStyleSheet(this->EMPTY_STYLESHEET);
        this->bGroup.button(i)->setEnabled(true);
    }
    this->bestState = new BoardState();
    this->move = 1;
}


void MainWindow::on_boardBox_currentIndexChanged(int index)
{
    for(int i = 0; i < 36; i++)
    {
        this->bGroup.button(i + 1)->setText(QString::number(this->gameBoards[index][i]));
        this->board[i/6][i%6] = this->gameBoards[index][i];
    }
}

void MainWindow::on_botSelectionBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        this->bot = new minimaxAgent();
    }else
        this->bot = new alphaBetaAgent();
}

void MainWindow::on_actionNew_Game_triggered()
{
    this->resetGame();
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QString about = "This is the GUI of WarGame, as part of the assignment bonus in CS440 MP2 Part2. \n\nGroup: Meng, Haoyan, Pranjal.";

    QMessageBox::information(this, "About", about);
}
