#include "wood.h"

Wood::Wood(float x, float y, float w, float h, QTimer* timer , b2World *world, QGraphicsScene *scene):GameItem(world),timer_w(timer),scene_w(scene)
{
    // Create Body
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);

    b2PolygonShape bodyshape;
    bodyshape.SetAsBox(w/1.9,h/1.9);

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = WOOD_DENSITY;
    fixturedef.friction = WOOD_FRICTION;
    fixturedef.restitution = WOOD_RESTITUTION;
    g_body->CreateFixture(&fixturedef);

    connect(timer_w, SIGNAL(timeout()), this,SLOT(paint()));
}
Wood::~Wood()
{
    disconnect(timer_w, SIGNAL(timeout()), this,SLOT(paint()));
}

int Wood::charIdentify()
{
    return ISWOOD;
}
void Wood::hitEffect()
{
    std::cout<<"Wood is hit."<<std::endl;
}
