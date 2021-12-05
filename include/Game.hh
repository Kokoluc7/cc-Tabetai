#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Game
{
private:
   sf::RenderWindow* window{};
   sf::Event* event{};

   float deltaTime{};
   sf::Clock* gameClock{};

   void MainLoop();
   void Update();
   void start();
   void Render();
   void Draw();
   void InputHandle();
   
public:
    Game();
    ~Game();

    void Run();
};

