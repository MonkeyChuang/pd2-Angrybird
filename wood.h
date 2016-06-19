#ifndef WOOD_H
#define WOOD_H

#include "gameitem.h"
#include <QTimer>
#include <QGraphicsScene>

#define WOOD_DENSITY 1.0f
#define WOOD_FRICTION 0.3f
#define WOOD_RESTITUTION 0.0f

class Wood : public GameItem
{
public:
    Wood(float x, float y, float w, float h,QTimer* timer ,b2World *world,QGraphicsScene *scene);
    virtual~Wood();
    virtual int charIdentify();
    virtual void hitEffect();
protected:
    QTimer *timer_w;
    QGraphicsScene *scene_w;
};

#endif // WOOD_H
