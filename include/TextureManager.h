#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>


class TextureManager
{
    public:
        TextureManager();
        ~TextureManager();
        sf::Texture* getTexture(std::string path);
        static TextureManager& getInstance();
    protected:
    private:
        std::map<std::string, sf::Texture*> textures;
        static TextureManager instance;
};

#endif // TEXTUREMANAGER_H
