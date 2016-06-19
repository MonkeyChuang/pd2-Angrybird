#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <unistd.h>

#include <angrybirdcontactlistener.h>
#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <wood.h>

#include "redbird.h"
#include "yellowbird.h"
#include "greenbird.h"
#include "bluebird.h"

#include "woodbar.h"
#include "pig.h"

#define RED 1
#define YELLOW 2
#define GREEN 3
#define BLUE 4

#define max_bird 4
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void genBird();

    static void addScore(int incre);
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QList<Bird*> birdList;
    Pig* pig1;
    QTimer timer;

    QGraphicsPixmapItem shooter,endof_game;
    int bird_count;
    bool shoot_b,ready_b,moved_b,set_newB,stopped,game_over;
    float ini_x,ini_y,end_x,end_y;
    static int score;
};

#endif // MAINWINDOW_H
