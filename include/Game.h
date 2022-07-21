//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include "EventHandler.h"
#include "ConfigurationLoaderIni.h"
#include "EntitiesRepository.h"


class Game {
  private:
    bool initialized{false};
    std::unique_ptr<sf::RenderWindow>(m_window);
    std::unique_ptr<EventHandler>(m_eventHandler);
    std::unique_ptr<Configuration::ConfigurationLoaderIni>(m_configurationLoader);
    EntitiesRepository m_entitiesRepository;
    void update();
    void render();
  public:
    Game();
    void initialize();
    void run();
};

#endif //_GAME_H_
