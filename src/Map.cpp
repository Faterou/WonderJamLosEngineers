#include "Map.h"

Map::Map()
{
std::ifstream OpenFile("Map1.txt");
if(OpenFile.is_open())
    {
        std::string tileLocation;
        OpenFile >> tileLocation;
        tileTexture.loadFromFile(tileLocation);
        tiles.setTexture(tileTexture);
        while(!OpenFile.eof())
        {
            std::string str;
            OpenFile >> str;
            char x = str[0], y = str[2];
            if(!isdigit(x) || !isdigit(y))
            {
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1,-1);
            }
            else
            {
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(x-'0',y - '0');
            }
            if(OpenFile.peek() == '\n')
            {
                loadCounter.x = 0;
                loadCounter.y++;
            }
            else
            {
                loadCounter.x++;
            }

        }
        loadCounter.y++;
    }
}

Map::~Map()
{}

void Map::draw()
{
   for(int i = 0; i < loadCounter.x; i++)
        {
             for(int j = 0; j < loadCounter.y; j++)
             {
                 if(map[i][j].x != -1 && map[i][j].y != -1)
                 {
                     tiles.setPosition(i*32, j*32);
                     tiles.setTextureRect(sf::IntRect(map[i][j].x*32, map[i][j].y * 32, 32 , 32));
                     window.draw(tiles);
                 }
             }
        }
}

TypeTerrain Map::getTileStatus(float x, float y)
{
    int coinGaucheX;
    int coinHautY;

    sf::Vector2i vecteurA = sf::Vector2i(-1,-1);
    sf::Vector2i vecteurB = sf::Vector2i(0,0);
    sf::Vector2i vecteurC = sf::Vector2i(0,1);
    sf::Vector2i vecteurD = sf::Vector2i(1,0);
    sf::Vector2i vecteurE = sf::Vector2i(1,1);

    coinGaucheX = (x - (int)x%32)/32;
    coinHautY = (y - (int)y%32)/32;

    if(map[coinGaucheX][coinHautY] == vecteurA)
    {
        return RIEN;
    }
    else if(map[coinGaucheX][coinHautY] == vecteurB)
    {
        return ROAD;
    }
    else if(map[coinGaucheX][coinHautY] == vecteurC)
    {
        return TREE;
    }
    else if(map[coinGaucheX][coinHautY] == vecteurD)
    {
        return GRASS;
    }
    else if(map[coinGaucheX][coinHautY] == vecteurE)
    {
        return FINISH;
    }

}
