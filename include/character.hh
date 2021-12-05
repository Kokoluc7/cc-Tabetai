#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>

class character
{
private:
  sf::Sprite* sprite{};
  sf::Vector2f position{};
  float scale{};
  float width{};
  float height{};
  sf::Texture* texture;
  std::string textureUrl;
  sf::RenderWindow* window{};

public:
  character();
  character(std::string textureUrl, sf::Vector2f position,
  float scale, float width, float height,  int col, int row, sf::RenderWindow*& window);
  ~character();

    void Update()
    {

    }
};