#include "ComonHeaders.hh"
#include "character.hh"

sf::RectangleShape* rectangle{new sf::RectangleShape(sf::Vector2f(100.f, 100.f))};
character* character1{new character()};

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  gameClock = new sf::Clock();
  character1 = new character(ASSETS_SPRITES, sf::Vector2f(100.f, 100.f), GAME_SCALE,
  16, 16, 7, 0, 200.f, window);
}

Game::~Game()
{
}

void Game::Run()
{
    start();
    MainLoop();
}

void Game::MainLoop()
{
  while (window->isOpen())
  {
    while (window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }

     deltaTime = gameClock->getElapsedTime().asSeconds();
     gameClock->restart(); 

     InputHandle();
     Update();
     Render();
  }


}

   void Game::Update()
   {
     //std::cout << "deltaTime: " << deltaTime << std::endl;
     character1->Update();

   }

   void Game::start()
   {

   }

   void Game::Render()
   {
       window->clear(sf::Color::Black);
       Draw();
       window->display();
   }

   void Game::Draw()
   {
     //window->draw(*rectangle);

   }

   void InputHandle()
   {
     character1->Movement(deltaTime);
   }
