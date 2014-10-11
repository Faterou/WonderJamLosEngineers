#ifndef ZOMBIE_H
#define ZOMBIE_H


class Zombie
{
    public:
        sf::Vector2i getPosition() const;
        void setPosition(sf::Vector2i);
        void draw();

        Zombie();
        virtual ~Zombie();
    protected:
    private:
        sf::Vector2i position;
        sf::Texture zombieTexture;
        sf::Sprite zombieSprite;
};

#endif // ZOMBIE_H
