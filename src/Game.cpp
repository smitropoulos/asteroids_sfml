//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#include "Game.h"
#include "Player.h"
#include "TextureRepository.h"
#include "EntitiesFactory.h"


void Game::update() {
}

void Game::render() {

    m_window->clear();
    for ( const auto& entity: EntitiesRepository::getInstance().entities())
    {
        entity->render(m_window.get());
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
            // "close requested" event: we close the window
            if ( event.type == sf::Event::Closed )
            {
                m_window->close();
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

    EntitiesFactory entitiesFactory;
    entitiesFactory.makeEntity(EntityType::Player);
    entitiesFactory.makeEntity(EntityType::Rock);
    initialized = true;
}

Game::Game() {

    m_configurationLoader = std::make_unique<Configuration::ConfigurationLoaderIni>();
}
