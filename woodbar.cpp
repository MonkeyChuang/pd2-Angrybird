#include "woodbar.h"

WoodBar::WoodBar(float x, float y, float w, float h,QTimer *timer ,b2World *world, QGraphicsScene *scene):Wood(x,y,w,h,timer,world,scene)
{
    if(w >= h)
    {
        g_pixmap.setPixmap(QPixmap(":image/woodbar_2.jpg").scaled(h*g_windowsize.height()/g_worldsize.height(),w*g_windowsize.height()/g_worldsize.height()));
        g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
        g_size = QSizeF(w/10.0,h/10.0);
        g_body->SetTransform(g_body->GetPosition(),1.57079633);
    }
    else
    {
        g_pixmap.setPixmap(QPixmap(":image/woodbar_2.jpg").scaled(w*g_windowsize.height()/g_worldsize.height(),h*g_windowsize.height()/g_worldsize.height()));
        g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
        g_size = QSizeF(w/7.0,h/7.0);
    }

    scene_w->addItem(&g_pixmap);
    paint();

}
WoodBar::~WoodBar()
{
    scene_w->removeItem(&g_pixmap);
}
