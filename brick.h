#ifndef BRICK_H
#define BRICK_H

#include "gameitem.h"

#define WOOD_DENSITY 10.0f
#define WOOD_FRICTION 0.2f
#define WOOD_RESTITUTION 0.0f

class Brick : public GameItem
{
public:
    Brick(float x, float y, float w, float h, b2World *world, QGraphicsScene *scene);
};

#endif // BRICK_H
