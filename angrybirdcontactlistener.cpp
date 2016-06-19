#include "angrybirdcontactlistener.h"

AngryBirdContactListener::AngryBirdContactListener()
{

}
void AngryBirdContactListener::BeginContact(b2Contact *contact)
{
    b2Body *bodyA,*bodyB;
    bodyA = contact->GetFixtureA()->GetBody();
    bodyB = contact->GetFixtureB()->GetBody();
    GameItem* itemA = static_cast<GameItem*>(bodyA->GetUserData());
    GameItem* itemB = static_cast<GameItem*>(bodyB->GetUserData());
    if(itemA->charIdentify() == ISBIRD && itemB->charIdentify() != ISBIRD)
    {
        itemA->hitEffect();
        itemA->show_b=false;
    }
    if(itemB->charIdentify() == ISBIRD && itemA->charIdentify() != ISBIRD)
    {
        itemB->hitEffect();
        itemB->show_b=false;
    }
    if(itemA->charIdentify() == ISBIRD && itemB->charIdentify() == ISWOOD)
    {
        itemA->hitEffect();
        itemB->hitEffect();
        MainWindow::addScore(10);
    }
    if(itemB->charIdentify() == ISBIRD && itemA->charIdentify() == ISWOOD)
    {
        itemA->hitEffect();
        itemB->hitEffect();
        MainWindow::addScore(10);
    }
    if(itemA->charIdentify() == ISBIRD && itemB->charIdentify() == ISPIG)
    {
        itemA->hitEffect();
        itemB->hitEffect();
        MainWindow::addScore(100);
    }
    if(itemB->charIdentify() == ISBIRD && itemA->charIdentify() == ISPIG)
    {
        itemA->hitEffect();
        itemB->hitEffect();
        MainWindow::addScore(100);
    }
    if(itemA->charIdentify() == ISWOOD && itemB->charIdentify() == ISPIG)
    {
        itemA->hitEffect();
        Pig* itemB2=static_cast<Pig*>(itemB);
        itemB2->hitByWood();
        MainWindow::addScore(50);
    }
    if(itemB->charIdentify() == ISWOOD && itemA->charIdentify() == ISPIG)
    {
        Pig* itemA2=static_cast<Pig*>(itemA);
        itemA2->hitByWood();
        itemB->hitEffect();
        MainWindow::addScore(50);
    }
}
