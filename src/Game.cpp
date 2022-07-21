//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#include <iostream>
#include "Game.h"
#include "Player.h"
#include "EntitiesFactory.h"
#include "RockEventHandler.h"


void Game::update() {

    for ( const auto& entity: EntitiesRepository::getInstance().entities())
    {
        entity.second->update();
    }
}

void Game::render() {

    m_window->clear();
    for ( const auto& entity: EntitiesRepository::getInstance().entities())
    {
        entity.second->render(m_window.get());
    }
    m_window->display();
}

void Game::run() {

    if ( !initialized )
    {
        initialize();
    }

    while ( m_window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while ( m_window->pollEvent(event))
        {
            switch ( event.type )
            {
                case sf::Event::KeyPressed:
                {
                    m_playerEventHandler->handleKeyboardEvent(event, true);
                    break;
                }
                case sf::Event::KeyReleased:
                {
                    m_playerEventHandler->handleKeyboardEvent(event, false);
                    break;
                }
                case sf::Event::Closed:
                {
                    m_window->close();
                    break;
                }
            }
        }

        update();
        render();
    }
}

void Game::initialize() {

    m_configurationLoader->loadConfiguration("/Users/smitropoulos/CLionProjects/sfml_asteroids/Configuration.ini");
    auto resolutionX = std::stol(m_configurationLoader->m_configuration.at("resolutionX"));
    auto resolutionY = std::stol(m_configurationLoader->m_configuration.at("resolutionY"));
    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(resolutionX, resolutionY), "Asteroids");

    m_playerEventHandler = std::make_shared<PlayerEventHandler>();

    EntitiesFactory entitiesFactory;
    entitiesFactory.makeEntity(EntityType::Player, m_playerEventHandler.get());
    entitiesFactory.makeEntity(EntityType::Rock, nullptr);

    initialized = true;
}

Game::Game() {

    m_configurationLoader = std::make_unique<Configuration::ConfigurationLoaderIni>();
}
