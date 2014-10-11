#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>
#include<fstream>
#include<string>
#include<cctype>
#include <vector>
#include <Tree.h>
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
        std::vector<GameObject*>* getTreeVector() {return &treeVector;}
        TypeTerrain getTileStatus(float x, float y);
        std::vector<GameObject*>* getTreeVector();
    private:
        sf::Texture tileTexture;
        sf::Sprite tiles;
        sf::Vector2i map[250][250];
        sf::Vector2i loadCounter = sf::Vector2i(0,0);

        std::vector<GameObject*> treeVector;

};

#endif // MAP_H
