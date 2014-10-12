#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

class GameObject
{
    public:
        enum Type {ZOMBIE, CAR, DESTINATION, MENU_ITEM, TREE};
        GameObject();
        GameObject(sf::Sprite, Type);
        virtual void onCollision(GameObject*);
        virtual void draw();
        void setSprite(sf::Sprite sprite) { this->sprite = sprite;}
        sf::Sprite* getSprite() {return &sprite;};
        void setType(Type type) {this->type = type;};
        Type getType() {return type;};
        void setTexture(sf::Texture* texture) {this->texture = texture; sprite.setTexture(*this->texture,true);}
        sf::Texture* getTexture() {return this->texture;}
        virtual ~GameObject();
    protected:
    private:
        sf::Sprite sprite;
        sf::Texture* texture;
        Type type;
};

#endif // GAMEOBJECT_H
