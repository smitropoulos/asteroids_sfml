//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#ifndef _EVENTHANDLER_H_
#define _EVENTHANDLER_H_

#include <SFML/Window/Event.hpp>
#include <SFML/Window.hpp>


class EventHandler {
    virtual void handleEvent(sf::Event event) = 0;
};

#endif //_EVENTHANDLER_H_
