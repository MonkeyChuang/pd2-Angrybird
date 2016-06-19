#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H
#include "bird.h"

class YellowBird : public Bird
{
public:
    YellowBird(float x, float y, float radius,QTimer* timer,b2World *world, QGraphicsScene *scene);
    virtual ~YellowBird();
    void showFeature();

};

#endif // YELLOWBIRD_H
