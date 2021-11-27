#include "Character.hh"

character::character(const char* textureUrl, sf::Vector2f position,
float scale, float width, float height, int col, int row, sf::RenderWindow*& window)
{
  this->position = position;
  this->scale = scale;
  this->width = width;
  this->height = height;
  this->width = width;
  this->col = col;
  this->row = row;
  texture = new sf::Texture();
  texture->loadFromFile(textureUrl);
  sprite = new sf::Sprite(*texture, sf::IntRect(col * width, row * height, width, height));
  sprite->setPosition(position);
  sprite->setScale(sf::Vector2f(scale, scale));
  sprite->setColor(sf::Color::White);
}

character::~character()
{

}

void character::Update()
{
  window->draw(*sprite);
} 
