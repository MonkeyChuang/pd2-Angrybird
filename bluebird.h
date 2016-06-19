#ifndef BLUEBIRD_H
#define BLUEBIRD_H

#include "bird.h"
#include "redbird.h"
class BlueBird : public Bird
{
public:
    BlueBird(float x, float y, float radius,QTimer* timer,b2World *world, QGraphicsScene *scene);
    virtual ~BlueBird();
    virtual void showFeature();
private:
    //used to construct copies of this bluebird object if its showFeature() is called.
    //Its replicas, obj.s of copy1 & copy2, no need to have showFeature(), and thereby
    //we define its replicas with type RedBird.
    //Also, with this means, we can avoid recrusive defn of BlueBird while every BlueBird
    //obj contains two BlueBird pointer variables.
    RedBird *copy1,*copy2;
    float radius_b;
    bool been_show;
};

#endif // BLUEBIRD_H
