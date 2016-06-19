#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>
#include <iostream>

#define ISLAND 1
#define ISWOOD 2
#define ISBIRD 3
#define ISPIG  4
class GameItem : public QObject
{
    Q_OBJECT
public:
    GameItem(b2World *world);
    virtual ~GameItem();
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);
    b2Body *g_body;
    QGraphicsPixmapItem g_pixmap;

    virtual int charIdentify() = 0 ;
    virtual void hitEffect() = 0 ;
    //used for birds
    bool show_b;

public slots:
    void paint();
    // TODO virtual void collide();

protected:
    QSizeF g_size;
    b2World *g_world;
    static QSizeF g_worldsize, g_windowsize;
};

#endif // GAMEITEM_H
