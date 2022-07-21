//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#ifndef _RENDERABLEENTITY_H_
#define _RENDERABLEENTITY_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class RenderableEntity {
  protected:
    sf::Texture *m_texture{};
    sf::Sprite m_sprite;
  public:
    RenderableEntity();

    virtual void load(const std::string& texturePath) {

        if ( !m_texture->loadFromFile(texturePath))
        {
            // Handle loading error
        }
        m_sprite = sf::Sprite(*m_texture);
        m_sprite.setPosition(100.f, 100.f);
    };
    virtual void render(sf::RenderWindow *window) = 0;
    virtual ~RenderableEntity();
};

#endif //_RENDERABLEENTITY_H_
