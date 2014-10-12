#ifndef MENUSCENE_H
#define MENUSCENE_H
#include <Scene.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>

#define MAX_NUMBER_OF_ITEMS 4


class MenuScene : public Scene
{
    public:
        MenuScene();
        virtual ~MenuScene();
        virtual void inputs();
        virtual void update();
        virtual void draw();

        int GetPressedItem() { return selectedItemIndex; }

    protected:
    private:
        int selectedItemIndex = 0;
        sf::Font font;

        sf::Text menu[4];

};

#endif // MENUSCENE_H
