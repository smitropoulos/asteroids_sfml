//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#include "../include/Game.h"
#include "../include/Player.h"


void Game::update() {
}

void Game::render() {

    m_window->clear();
    for ( const auto& entity: m_entitiesRepository.entities())
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

    auto player = std::make_unique<Player>();
    player->load("/Users/smitropoulos/CLionProjects/sfml_asteroids/images/background.jpg");
    m_entitiesRepository.addEntity(std::move(player));

    initialized = true;
}

Game::Game() {

    m_configurationLoader = std::make_unique<Configuration::ConfigurationLoaderIni>();
}
