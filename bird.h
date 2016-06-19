#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QString>
#define BIRD_DENSITY 15.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class Bird : public GameItem
{
public:
    Bird(float x,float y,float radius,QTimer* timer, b2World *world,QGraphicsScene *scene);
    virtual ~Bird();
    void setLinearVelocity(b2Vec2 velocity);
    virtual void showFeature() =0 ;
    virtual int charIdentify();
    virtual void hitEffect() ;
    QString pic_path;
protected:
    QTimer *timer_b;
    QGraphicsScene *scene_b;
private:
    bool been_hit;
};

#endif // BIRD_H
