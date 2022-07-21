//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#ifndef _RENDERABLEENTITY_H_
#define _RENDERABLEENTITY_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "TextureLoader.h"


class RenderableEntity {
  protected:
    sf::Texture *m_texture{};
    sf::Sprite m_sprite;
    sf::Vector2i m_position;
  public:
    RenderableEntity();

    virtual void load(const sf::Texture* texture) {
        m_sprite = sf::Sprite(*texture);
    };
    virtual void render(sf::RenderWindow *window) {
        window->draw(this->m_sprite);
    };
    void setPosition(const sf::Vector2i& position);
    virtual ~RenderableEntity();
};

#endif //_RENDERABLEENTITY_H_
