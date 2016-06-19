#include "land.h"
#include <iostream>
Land::Land(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world),scene_L(scene)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_size = QSizeF(w,h);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);
    g_body->CreateFixture(&bodyBox,9.0f);

    scene_L->addItem(&g_pixmap);
    paint();
}
Land::~Land()
{
    scene_L->removeItem(&g_pixmap);
}

int Land::charIdentify()
{
    return ISLAND;
}
void Land::hitEffect()
{
    std::cout<<"Land is hit."<<std::endl;
}
