#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

class GameObject
{
    public:
        GameObject();
        GameObject(sf::Sprite);
        virtual void onCollision(GameObject*);
        void setSprite(sf::Sprite);
        sf::Sprite* getSprite() {return &sprite;};
        void setName(std::string name);
        std::string getName() {return name;};
        virtual ~GameObject();
    protected:
    private:
        sf::Sprite sprite;
        std::string name;
};

#endif // GAMEOBJECT_H
