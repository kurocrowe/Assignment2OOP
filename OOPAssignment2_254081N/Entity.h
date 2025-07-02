#pragma once
class Entity
{
public:
    static const int MAX_OBJECTS = 8;

    Entity* gameObjects[MAX_OBJECTS];
     Entity();
    virtual ~Entity();
};

