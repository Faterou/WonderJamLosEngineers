#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

#include "Voiture.h"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "math.h"
#include <cctype>
#include "TextureManager.h"

using namespace std;

Voiture::Voiture(std::string nomPhoto) : GameObject(sf::Sprite(),CAR)
{
    m_vitesse_courante = 0.01;
    m_vitesse_max = 10;
    m_acceleration = 0.01;
    m_maniabilite = 2;
    m_suspension = 1;
    m_machineEssence = 1;
    m_penetrationZombie = 0;
    petrole = 0;
    money =0;

    GameObject::setTexture(TextureManager::getInstance().getTexture(nomPhoto));
}

Voiture::~Voiture()
{
    //dtor
}

sf::Vector2f Voiture::getHeading()
{
    float teta = GameObject::getSprite()->getRotation() + 90;
    float x = cos(teta*M_PI/180);
    float y = sin(teta*M_PI/180);

    return sf::Vector2f(x,y);
}

void Voiture::setVitesse_max(float vitesse)
{
    m_vitesse_max = vitesse;
}
float Voiture::getVitesse_max()
{
    return m_vitesse_max;
}

void Voiture::setAcceleration(float acceleration)
{
    m_acceleration = acceleration;
}
float Voiture::getAcceleration()
{
    return m_acceleration;
}

void Voiture::setManiabilite(float maniabilite)
{
    m_maniabilite = maniabilite;
}
float Voiture::getManiabilite()
{
    return m_maniabilite;
}

void Voiture::setSuspension(float suspension)
{
    m_suspension = suspension;
}
float Voiture::getSuspension()
{
    return m_suspension;
}

void Voiture::setMachineEssence(float machineEssence)
{
    m_machineEssence = machineEssence;
}
float Voiture::getMachineEssence()
{
    return m_machineEssence;
}

void Voiture::setPenetrationZombie(float penetrationZombie)
{
    m_penetrationZombie = penetrationZombie;
}
float Voiture::getPenetrationZombie()
{
    return m_penetrationZombie;
}

void Voiture::moveForward()
{
    if(m_vitesse_courante < 0)
    {
        m_vitesse_courante = m_vitesse_courante + m_maniabilite / 10;
    }
    if(m_vitesse_courante < m_vitesse_max)
        m_vitesse_courante = m_vitesse_courante + m_acceleration;
}

void Voiture::moveBackward()
{
    if(m_vitesse_courante > 0)
    {
        m_vitesse_courante = m_vitesse_courante - m_maniabilite /10;
    }
    else if(m_vitesse_courante > -m_vitesse_max)
        m_vitesse_courante = m_vitesse_courante - m_acceleration;
}

void Voiture::rotateLeft()
{
    GameObject::getSprite()->rotate(-m_maniabilite);
}

void Voiture::rotateRight()
{
    GameObject::getSprite()->rotate(m_maniabilite);
}

void Voiture::move()
{
    GameObject::getSprite()->move(-(m_vitesse_courante*getHeading()));
}

void Voiture::idle()
{
    if(m_vitesse_courante > 0)
    {
        m_vitesse_courante = m_vitesse_courante - 0.01;
    }
    else if(m_vitesse_courante < 0)
    {
        m_vitesse_courante = m_vitesse_courante + 0.01;
    }
}
void Voiture::onCollision(GameObject* object)
{
    if(object->getType() == GameObject::TREE || object->getType() == GameObject::CAR)
    {
        m_vitesse_courante = 0;
        GameObject::getSprite()->move(m_vitesse_courante*getHeading());
    }
    else if (object->getType() == GameObject::ZOMBIE)
    {
        m_vitesse_courante = m_vitesse_courante / (7-m_penetrationZombie);
        petrole++;
    }

}

