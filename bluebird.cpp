#include "bluebird.h"

BlueBird::BlueBird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,world,scene),radius_b(radius)
{
    been_show=false;
    pic_path=":image/blue.png";
    g_pixmap.setPixmap(QPixmap(pic_path).scaled(g_windowsize.height()/9.0,g_windowsize.height()/9.0));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSizeF(radius*2,radius*2);

    scene_b->addItem(&g_pixmap);
    paint();
}
BlueBird::~BlueBird()
{
    scene_b->removeItem(&g_pixmap);
    if(been_show)
    {
        delete copy1;
        delete copy2;
    }
}
void BlueBird::showFeature()
{
    show_b=false;
    been_show=true;
    copy1 = new RedBird(this->g_body->GetPosition().x,this->g_body->GetPosition().y + 1.0,radius_b,timer_b,g_world,scene_b);
    copy1->pic_path = pic_path;
    copy1->g_pixmap.setPixmap(QPixmap(pic_path).scaled(g_windowsize.height()/9.0,g_windowsize.height()/9.0));
    copy1->g_body->SetGravityScale(1);
    copy1->setLinearVelocity(b2Vec2(this->g_body->GetLinearVelocity().x*1.2,this->g_body->GetLinearVelocity().y / 2));

    copy2 = new RedBird(this->g_body->GetPosition().x,this->g_body->GetPosition().y - 1.0,radius_b,timer_b,g_world,scene_b);
    copy2->pic_path = pic_path;
    copy2->g_pixmap.setPixmap(QPixmap(pic_path).scaled(g_windowsize.height()/9.0,g_windowsize.height()/9.0));
    copy2->g_body->SetGravityScale(1);
    copy2->setLinearVelocity(b2Vec2(this->g_body->GetLinearVelocity().x / 2,this->g_body->GetLinearVelocity().y*1.2));
}
