#include "pig.h"

Pig::Pig(float x,float y,float radius,QTimer *timer,b2World *world,QGraphicsScene *scene):timer_p(timer),GameItem(world),scene_p(scene)
{
    been_hit=false;
    hit_by_wood=0;
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
    fixturedef.density = PIG_DENSITY;
    fixturedef.friction = PIG_FRICTION;
    fixturedef.restitution = PIG_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    pic_path=":image/pig.png";
    g_pixmap.setPixmap(QPixmap(pic_path).scaled(g_windowsize.height()/9.0,g_windowsize.height()/9.0));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSizeF(radius*2,radius*2);

    scene_p->addItem(&g_pixmap);
    paint();

    // Bound timer
    connect(timer_p, SIGNAL(timeout()), this,SLOT(paint()));

}
Pig::~Pig()
{
    disconnect(timer_p, SIGNAL(timeout()), this,SLOT(paint()));
    scene_p->removeItem(&g_pixmap);
}
int Pig::charIdentify()
{
    return ISPIG;
}
void Pig::hitByWood()
{
    if(++hit_by_wood == 7)
        hitEffect();
}

void Pig::hitEffect()
{
    if(!been_hit)
    {
        pic_path=pic_path.insert(pic_path.length() - 4 ,QString("_h"));
        g_pixmap.setPixmap(QPixmap(pic_path).scaled(g_windowsize.height()/9.0,g_windowsize.height()/9.0));
        been_hit=true;
    }
    std::cout<<"bird is hit."<<std::endl;
}
bool Pig::beenHit()
{
    return been_hit;
}
