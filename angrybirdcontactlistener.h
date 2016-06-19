#ifndef ANGRYBIRDCONTACTLISTENER_H
#define ANGRYBIRDCONTACTLISTENER_H

#include <Box2D/Dynamics/b2WorldCallbacks.h>
#include <Box2D/Dynamics/Contacts/b2Contact.h>
#include <iostream>

#include "mainwindow.h"
#include "gameitem.h"
#include "pig.h"
class AngryBirdContactListener : public b2ContactListener
{
public:
    AngryBirdContactListener();
    void BeginContact(b2Contact* contact);
};

#endif // ANGRYBIRDCONTACTLISTENER_H
