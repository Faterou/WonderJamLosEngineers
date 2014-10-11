#include "voiture.h"
#include <SFML/Graphics.hpp>
#include <windows.h>

extern sf::RenderWindow window;

voiture::voiture(std::string nomPhoto)
{
    m_vitesse = 1;
    m_acceleration = 1;
    m_maniabilite = 1;
    m_suspension = 1;
    m_machineEssence = 1;
    m_penetrationZombie = 1;

    if (!m_texture.loadFromFile(nomPhoto))
    {
        std::cout << "Erreur chargement de personnage" << std::endl;
    }

    m_sprite.setPosition(32,32);
    m_sprite.setTexture(m_texture);

}

voiture::~voiture()
{
    //dtor
}

void voiture::drawCar()
{
    std::cout << "123" << std::endl;
    //window.display();
    window.draw(m_sprite);
    //window.display();

}

sf::Texture voiture::getTexture()
{
    return m_texture;
}
void voiture::setTexture(std::string nomTexture)
{

}

sf::Sprite* voiture::getSprite()
{
    return &m_sprite;
}
void voiture::setSprite(std::string nomSprite)
{

}

void voiture::setVitesse(float vitesse)
{
    m_vitesse = vitesse;
}
float voiture::getVitesse()
{
    return m_vitesse;
}

void voiture::setAcceleration(float acceleration)
{
    m_acceleration = acceleration;
}
float voiture::getAcceleration()
{
    return m_acceleration;
}

void voiture::setManiabilite(float maniabilite)
{
    m_maniabilite = maniabilite;
}
float voiture::getManiabilite()
{
    return m_maniabilite;
}

void voiture::setSuspension(float suspension)
{

}
float voiture::getSuspension()
{
    return m_suspension;
}

void voiture::setMachineEssence(float machineEssence)
{
    m_machineEssence = machineEssence;
}
float voiture::getMachineEssence()
{
    return m_machineEssence;
}

void voiture::setPenetrationZombie(float penetrationZombie)
{
    m_penetrationZombie = penetrationZombie;
}
float voiture::getPenetrationZombie()
{
    return m_penetrationZombie;
}

