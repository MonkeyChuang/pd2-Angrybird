#ifndef GREENBIRD_H
#define GREENBIRD_H

#include "bird.h"
class GreenBird : public Bird
{
public:
    GreenBird(float x, float y, float radius,QTimer* timer,b2World *world, QGraphicsScene *scene);
    virtual ~GreenBird();
    virtual void showFeature();
};

#endif // GREENBIRD_H
