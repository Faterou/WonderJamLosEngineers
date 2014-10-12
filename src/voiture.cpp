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
    m_vitesse_max_m = 1;
    m_acceleration_m = 1;
    m_maniabilite_m = 1;
    m_suspension_m = 1;
    m_machineEssence_m = 1;
    m_penetrationZombie_m = 0;

    m_vitesse_courante = 0.01;

    petrole = 0;
    money =0;


    GameObject::setTexture(TextureManager::getInstance().getTexture(nomPhoto));
}

Voiture::~Voiture()
{
    //dtor
}

void Voiture::miseAJourVoiture()
{
    m_vitesse_max = (m_vitesse_max_m * 4);
    m_acceleration = (m_acceleration_m  / 4 );
    m_maniabilite = (m_maniabilite_m * 2 );
    m_machineEssence = (m_machineEssence_m);
    m_suspension = (m_suspension_m);
    m_penetrationZombie = (m_penetrationZombie_m);
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

void Voiture::setVitesseMax_m(float vitesseMax)
{
    m_vitesse_max_m = vitesseMax;
}
float Voiture::getVitesseMax_m()
{
    return m_vitesse_max_m;
}

void Voiture::setAcceleration_m(float acceleration)
{
    m_acceleration_m = acceleration;
}
float Voiture::getAcceleration_m()
{
    return m_acceleration_m;
}

void Voiture::setManiabilite_m(float maniabilite)
{
    m_maniabilite_m = maniabilite;
}
float Voiture::getManiabilite_m()
{
    return m_maniabilite_m;
}

void Voiture::setMachineEssence_m(float machineEssence)
{
    m_machineEssence_m = machineEssence;
}
float Voiture::getMachineEssence_m()
{
    return m_machineEssence_m;
}

void Voiture::setSuspension_m(float suspension)
{
    m_suspension_m = suspension;
}
float Voiture::getSuspension_m()
{
    return m_suspension_m;
}

void Voiture::setPenetrationZombie_m(float penetrationZombie)
{
    m_penetrationZombie_m = penetrationZombie;
}
float Voiture::getPenetrationZombie_m()
{
    return m_penetrationZombie_m;
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
        m_vitesse_courante = m_vitesse_courante - m_acceleration * 2;
    }
    else if(m_vitesse_courante < 0)
    {
        m_vitesse_courante = m_vitesse_courante + m_acceleration * 2;
    }
}
void Voiture::onCollision(GameObject* object)
{
    if(object->getType() == GameObject::TREE || object->getType() == GameObject::CAR)
    {
        bool negatif = m_vitesse_courante < 0;
        m_vitesse_courante = 0;
        if(negatif)
        {
            GameObject::getSprite()->move(-2.0f*getHeading());
        }
        else
        {
            GameObject::getSprite()->move(2.0f*getHeading());
        }
    }
    else if (object->getType() == GameObject::ZOMBIE)
    {
        m_vitesse_courante = m_vitesse_courante / (7-m_penetrationZombie);
        petrole++;
    }

}

