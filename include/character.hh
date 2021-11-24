#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

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
    sf::Window* window{};
public:
    character(std::string textureUrl, sf::Vector2f position,
     float scale, float width, float height,  int col, int row, sf::Window*& window);
    ~character();
    
    void Update()
    {
        
    }
};

