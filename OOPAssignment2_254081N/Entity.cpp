#include "Entity.h"

Entity::Entity()
{
    for (int i = 0; i < MAX_OBJECTS; i++) {
        gameObjects[i] = nullptr;
    }
}

Entity::~Entity()
{
    for (int i = 0; i < MAX_OBJECTS; i++) {
        delete gameObjects[i];
    }
}
