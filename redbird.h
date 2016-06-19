#ifndef REDBIRD_H
#define REDBIRD_H

#include "bird.h"

class RedBird : public Bird
{
public:
    RedBird(float x, float y, float radius,QTimer* timer,b2World *world, QGraphicsScene *scene);
    virtual ~RedBird();
    void showFeature();

};

#endif // REDBIRD_H
