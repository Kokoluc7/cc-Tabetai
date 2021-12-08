#pragma once

#include<SFML/Graphics.hpp>
#include "Drawable.hh"
#include<fstream>

class Animation
{
private:
  float delay{};
  int row{};
  int startFrame{};
  int endFrame{};
  int currentFrame{};
  Drawable* drawable;
  float timer{};

  std::ifstream* reader{};
public:
  Animation(float delay, int row, int startFrame, int endFrame, float width, float height, Drawable*& drawable);
  ~Animation();
  void Play(float& deltaTime);
};