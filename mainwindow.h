#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QDebug>
#include <iostream>

#include "minimaxagent.h"
#include "alphabetaagent.h"
#include "agent.h"
#include "boardstate.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void buttonWasClicked(int id);
private slots:
    void on_boardBox_currentIndexChanged(int index);

    void on_botSelectionBox_currentIndexChanged(int index);

    void on_actionNew_Game_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    QButtonGroup bGroup = new QButtonGroup();

    QString BLUE_STYLESHEET;
    QString GREEN_STYLESHEET;
    QString EMPTY_STYLESHEET;

    std::vector<vector<int> > gameBoards;
    //Methods
    void init();
    void addToButtonGroup();
    void initBoard();
    void constructGameBoards();
    void concludeGame();
    void resetGame();
    void conquer(int y, int x, BoardState *state);
    bool isBlitz(int y, int x);

    Agent *bot;
    int board[6][6]; //Current game board
    BoardState *bestState;

    int alpha = -999999999;
    int beta = 999999999;
    int move = 1;





};

#endif // MAINWINDOW_H
