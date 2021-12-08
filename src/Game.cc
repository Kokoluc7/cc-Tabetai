#include "ComonHeaders.hh"
#include "Character.hh"
#include "TileGroup.hh"

Character* character1{};
//Comida
GameObject *egg{};
GameObject *Naruto{};
GameObject *Alga{};
GameObject *Meat{};
GameObject *Water{};
GameObject *Chop{};
GameObject *Ramen{};

TileGroup *tileGroup{};

//Objetos de cocina
GameObject *Table1{};
GameObject *Table2{};
GameObject *TableRed{};
GameObject *chair1{};
GameObject *chair2{};
GameObject *chair3{};
GameObject *chair4{};
GameObject *stove{};
GameObject *Dishwasher{};
GameObject *fridge{};



Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  gameClock = new sf::Clock();
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  

  tileGroup = new TileGroup(window, ASSETS_SPRITES, 16, 16, GAME_SCALE, 11, 10, ASSETS_SPRITES);

  gameObjects = new std::vector<GameObject*>();
  gameObjectsDeleteList = new std::vector<GameObject*>();
  contactEventManager = new ContactEventManager(gameObjectsDeleteList);

  character1 = new Character(ASSETS_SPRITES, sf::Vector2f(100.f, 100.f), GAME_SCALE, 0, 15, 4, 200.f,  window, world);
  egg = new GameObject(ASSETS_SPRITES, sf::Vector2f(300.f, 190.f), GAME_SCALE, 4, 4, 8, 13, b2BodyType::b2_staticBody, window, world);
  Naruto = new GameObject(ASSETS_SPRITES, sf::Vector2f(350.f, 750.f), GAME_SCALE, 4, 4, 10, 13, b2BodyType::b2_staticBody, window, world);
  Alga = new GameObject(ASSETS_SPRITES, sf::Vector2f(100.f, 100.f), GAME_SCALE, 4, 4, 10, 15, b2BodyType::b2_staticBody, window, world);
  Meat = new GameObject(ASSETS_SPRITES, sf::Vector2f(100.f, 580.f), GAME_SCALE, 4, 4, 8, 17, b2BodyType::b2_staticBody, window, world);
  Water = new GameObject(ASSETS_SPRITES, sf::Vector2f(600.f, 270.f), GAME_SCALE, 4, 4, 8, 15, b2BodyType::b2_staticBody, window, world);
  Chop = new GameObject(ASSETS_SPRITES, sf::Vector2f(800.f, 800.f), GAME_SCALE, 4, 4, 10, 17, b2BodyType::b2_staticBody, window, world);
  Ramen = new GameObject(ASSETS_SPRITES, sf::Vector2f(120.f, 820.f), GAME_SCALE, 4, 4, 8, 19, b2BodyType::b2_staticBody, window, world);

  //Objetos de cocina
  TableRed = new GameObject(ASSETS_SPRITES, sf::Vector2f(800.f, 800.f), GAME_SCALE, 8, 16, 8, 2, b2BodyType::b2_staticBody, window, world);
  stove = new GameObject(ASSETS_SPRITES, sf::Vector2f(120.f, 820.f), GAME_SCALE, 8, 16, 0, 7, b2BodyType::b2_staticBody, window, world);
  Dishwasher = new GameObject(ASSETS_SPRITES, sf::Vector2f(120.f, 820.f), GAME_SCALE, 8, 8, 0, 9, b2BodyType::b2_staticBody, window, world);
  fridge = new GameObject(ASSETS_SPRITES, sf::Vector2f(120.f, 820.f), GAME_SCALE, 8, 16, 2, 11, b2BodyType::b2_staticBody, window, world);

  //Mesa que mira a la izquierda
  Table1 = new GameObject(ASSETS_SPRITES, sf::Vector2f(300.f, 190.f), GAME_SCALE, 12, 12, 12, 4, b2BodyType::b2_staticBody, window, world);

  //Mesa que mira a la derecha
  Table2 = new GameObject(ASSETS_SPRITES, sf::Vector2f(300.f, 190.f), GAME_SCALE, 12, 12, 4, 7, b2BodyType::b2_staticBody, window, world);
  
  //silla que mira a la izquierda
  chair1 = new GameObject(ASSETS_SPRITES, sf::Vector2f(120.f, 820.f), GAME_SCALE, 8, 16, 8, 4, b2BodyType::b2_staticBody, window, world);
  chair2 = new GameObject(ASSETS_SPRITES, sf::Vector2f(120.f, 820.f), GAME_SCALE, 8, 16, 8, 4, b2BodyType::b2_staticBody, window, world);

  //silla que mira a la derecha
  chair3 = new GameObject(ASSETS_SPRITES, sf::Vector2f(120.f, 820.f), GAME_SCALE, 8, 16, 23, 4, b2BodyType::b2_staticBody, window, world);
  chair4 = new GameObject(ASSETS_SPRITES, sf::Vector2f(120.f, 820.f), GAME_SCALE, 8, 16, 23, 4, b2BodyType::b2_staticBody, window, world);

  

  //text1 = new TextAsset(window, ASSETS_FONT, "Tabetai = Quiero comer: Ayuda a Touma Dombory a completar su plato", 
  //14, sf::Color::White, sf::Vector2f(50.f, 50.f));



}

Game::~Game()
{
}


void Game::Start()
{
  character1->SetTagtName("Plato:Touma");
  egg->SetTagtName("Egg");
  Naruto->SetTagtName("Naruto");
  Alga->SetTagtName("Alga");
  Meat->SetTagtName("Meat");
  Water->SetTagtName("Water");
  Chop->SetTagtName("Chop");
  Ramen->SetTagtName("Ramen");

  gameObjects->push_back(character1);
  gameObjects->push_back(egg);
  gameObjects->push_back(Naruto);
  gameObjects->push_back(Alga);
  gameObjects->push_back(Meat);
  gameObjects->push_back(Water);
  gameObjects->push_back(Chop);
  gameObjects->push_back(Ramen);


  uint32 flags{};
  flags += b2Draw::e_shapeBit;

  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(flags);

  world->SetContactListener(contactEventManager);
}

void Game::Run()
{
  Start();
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
     
     UpdatePhysics();
     InputHandle();
     Update();
     Render();
  }


}

void Game::UpdatePhysics()
{
  world->Step(deltaTime, 8, 8);
  world->ClearForces();
}

void Game::Update()
{

}


void Game::Render()
{
  for(auto& gameObjectPendingDelete : *gameObjectsDeleteList)
  {
    gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameObjectPendingDelete), gameObjects->end());
    delete gameObjectPendingDelete;
  }
  gameObjectsDeleteList->clear();

  window->clear(sf::Color{0, 0, 0, 0});
  Draw();
  window->display();
 
}

void Game::Draw()
{ 

}

void InputHandle()
{
  
}
