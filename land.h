#ifndef LAND_H
#define LAND_H

#include <gameitem.h>
#include <QGraphicsScene>

class Land : public GameItem
{
public:
    Land(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual ~Land();
    virtual int charIdentify();
    virtual void hitEffect();
protected:
    QGraphicsScene *scene_L;
};

#endif // LAND_H
