#ifndef PIG_H
#define PIG_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QString>
#define PIG_DENSITY 10.0f
#define PIG_FRICTION 0.2f
#define PIG_RESTITUTION 0.5f

class Pig : public GameItem
{
public:
    Pig(float x,float y,float radius,QTimer* timer, b2World *world,QGraphicsScene *scene);
    virtual ~Pig();
    virtual int charIdentify();
    virtual void hitEffect() ;
    void hitByWood();
    bool beenHit();
protected:
    QTimer *timer_p;
    QGraphicsScene *scene_p;
    QString pic_path;
private:
    bool been_hit;
    int hit_by_wood;
};

#endif // PIG_H
