#ifndef WOODBAR_H
#define WOODBAR_H

#include "wood.h"
#include <QGraphicsScene>
class WoodBar : public Wood
{
public:
    WoodBar(float x, float y, float w, float h,QTimer* timer ,b2World *world, QGraphicsScene *scene);
    virtual~WoodBar();
};

#endif // WOODBAR_H
