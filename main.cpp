#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <ctime>
#include <iostream>
#include<fstream>
#include<string>
#include<cctype>
#include <Map.h>


enum GameState {MENU, GAME};
enum RaceState {STATS, RACE};


GameState gameState = MENU;
RaceState raceState = STATS;

sf::RenderWindow window;

/**
    Function to handle events of the main loop, like the one to close the window.
*/
void processGlobalEvents()
{
    sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
}

/**
    Function to handle the inputs during the menu.
*/
void processMenuInputs()
{
    // Handle mouse move
    // Handle mouse click
}

/**
    Function to draw things in the menu
*/
void drawMenu()
{
    // Draw things
}

void processMenu()
{
    processMenuInputs();
    drawMenu();
}

/**
    Function to process the inputs during the Stats choice
*/
void processStatsInputs()
{
    //Handle Keyboard inputs
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            // Player 1 controls
            if(event.key.code == sf::Keyboard::Left)
            {

            }
            if(event.key.code == sf::Keyboard::Right)
            {

            }
            if(event.key.code == sf::Keyboard::Up)
            {

            }
            if(event.key.code == sf::Keyboard::Down)
            {

            }
            if(event.key.code == sf::Keyboard::RControl)
            {

            }

            // Player 2 controls
            if(event.key.code == sf::Keyboard::A)
            {

            }
            if(event.key.code == sf::Keyboard::D)
            {

            }
            if(event.key.code == sf::Keyboard::W)
            {

            }
            if(event.key.code == sf::Keyboard::S)
            {

            }
            if(event.key.code == sf::Keyboard::LControl)
            {

            }
        }
    }
}

/**
    Function to draw thing during the Stats choice
*/
void drawStats()
{
    // Draw things
}


void processStats()
{
    processStatsInputs();
    drawStats();
}

/**
    Function to process the inputs during the race phase
*/
void processRaceInputs()
{
    //Handle Keyboard inputs for both players
    //Handle Keyboard inputs
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            // Player 1 controls
            if(event.key.code == sf::Keyboard::Left)
            {

            }
            if(event.key.code == sf::Keyboard::Right)
            {

            }
            if(event.key.code == sf::Keyboard::Up)
            {

            }
            if(event.key.code == sf::Keyboard::Down)
            {

            }
            if(event.key.code == sf::Keyboard::RControl)
            {

            }

            // Player 2 controls
            if(event.key.code == sf::Keyboard::A)
            {

            }
            if(event.key.code == sf::Keyboard::D)
            {

            }
            if(event.key.code == sf::Keyboard::W)
            {

            }
            if(event.key.code == sf::Keyboard::S)
            {

            }
            if(event.key.code == sf::Keyboard::LControl)
            {

            }
        }
    }
}

/**
    Function to update the world during the race phase
*/
void updateRace()
{
    // Each loop, update the zombies and the players positions.
    // Also, check for victory condition.
}

/**
    Function to draw things during the race phase
*/
void drawRace()
{
    // Draw map, zombies and players
}

void processRace()
{
    processRaceInputs();
    updateRace();
    drawRace();
}

void processGame()
{
    switch(raceState)
    {
    case STATS:
        processStats();
        break;
    case RACE:
        processRace();
        break;
    }
}

void processGameState()
{
    switch(gameState)
    {
    case MENU:
        processMenu();
        break;
    case GAME:
        processGame();
        break;
    }
}

int main()
{
    Map map1;
    int window_width = 1000;
    int window_height = 500;
    window.create(sf::VideoMode(window_width, window_height), "SFML works!");

    while (window.isOpen())
    {
        processGlobalEvents();
        processGameState();
    }

    return 0;
}
