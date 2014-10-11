#include "TextureManager.h"

#include <stdexcept>
#include <iostream>

TextureManager TextureManager::instance;

TextureManager::TextureManager()
{
    //ctor
}

TextureManager::~TextureManager()
{
    //Should delete textures
}

sf::Texture* TextureManager::getTexture(std::string path)
{
    try
    {
        sf::Texture* texture = textures.at(path);
        return texture;
    }
    catch(const std::out_of_range& e)
    {
        sf::Texture* texture = new sf::Texture();
        if (!texture->loadFromFile(path))
        {
            std::cout << "Erreur chargement d'arbre" << std::endl;
        }
        textures[path] = texture;
        return texture;
    }
}

TextureManager& TextureManager::getInstance()
{
    return instance;
}
