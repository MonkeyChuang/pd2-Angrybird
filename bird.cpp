#include "bird.h"
#include <iostream>
Bird::Bird(float x, float y ,float radius,QTimer* timer,b2World *world,QGraphicsScene *scene):GameItem(world),timer_b(timer),scene_b(scene)
{
    been_hit=false;
    show_b=false;
    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;

    g_body = world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    //Set initial velocity & gravity
    setLinearVelocity(b2Vec2(0,0));
    g_body->SetGravityScale(0);

    // Bound timer
    connect(timer_b, SIGNAL(timeout()), this,SLOT(paint()));

}
Bird::~Bird()
{
    disconnect(timer_b, SIGNAL(timeout()), this,SLOT(paint()));
}

void Bird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}
int Bird::charIdentify()
{
    return ISBIRD;
}
void Bird::hitEffect()
{
    if(!been_hit)
    {
        pic_path=pic_path.insert(pic_path.length() - 4 ,QString("_h"));
        g_pixmap.setPixmap(QPixmap(pic_path).scaled(g_windowsize.height()/9.0,g_windowsize.height()/9.0));
        been_hit=true;
    }
    //std::cout<<"bird is hit."<<std::endl;
}
