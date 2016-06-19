#include "yellowbird.h"

YellowBird::YellowBird(float x, float y, float radius,QTimer* timer,b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,world,scene)
{
    pic_path=":image/chuck.png";
    g_pixmap.setPixmap(QPixmap(pic_path).scaled(g_windowsize.height()/9.0,g_windowsize.height()/9.0));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSizeF(radius*2,radius*2);

    scene_b->addItem(&g_pixmap);
    paint();
}
YellowBird::~YellowBird()
{
    scene_b->removeItem(&g_pixmap);
}

void YellowBird::showFeature()
{
    show_b=false;
    b2Vec2 speed = g_body->GetLinearVelocity();
    speed=b2Vec2(3.0f*speed.x,5.0f*speed.y);
    setLinearVelocity(speed);
}
