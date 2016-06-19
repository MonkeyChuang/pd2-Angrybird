#include "brick.h"

Brick::Brick(float x, float y, float w, float h, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Create body
    b2BodyDef bodyDef;
    bodyDef.type=b2_dynamicBody;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);
}
