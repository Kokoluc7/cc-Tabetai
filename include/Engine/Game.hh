#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Game
{
private:
   sf::RenderWindow* window{};
   sf::Event* event{};
   void MainLoop();
public:
    Game();
    ~Game();

    void Run();
};

