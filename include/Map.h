#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <ctime>
#include <iostream>
#include<fstream>
#include<string>
#include<cctype>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


extern sf::RenderWindow window;
enum TypeTerrain { GRASS, ROAD, TREE, FINISH, RIEN};

class Map
{
    public:
        Map();
        virtual ~Map();
        void draw();
        TypeTerrain getTileStatus(float x, float y);

    private:
        sf::Texture tileTexture;
        sf::Sprite tiles;
        sf::Vector2i map[250][250];
        sf::Vector2i loadCounter = sf::Vector2i(0,0);

};

#endif // MAP_H
