//
// Created by Stefanos Mitropoulos on 21/7/22.
//

#ifndef _TEXTUREREPOSITORYENTRY_H_
#define _TEXTUREREPOSITORYENTRY_H_

#include <string>
#include <SFML/Graphics/Texture.hpp>

class TextureRepositoryEntry {
  public:
    std::string m_name;
    std::string m_textureFilepath;
    unsigned int m_startingX;
    unsigned int m_startingY;
    unsigned int m_sizeX;
    unsigned int m_sizeY;
    std::unique_ptr<sf::Texture> m_texture;
  public:
    TextureRepositoryEntry(const std::string& name,
                           unsigned int startingX,
                           unsigned int startingY,
                           unsigned int sizeX,
                           unsigned int sizeY,
                           const std::string& textureFilepath) :
        m_name(name),
        m_startingX(startingX),
        m_startingY(startingY),
        m_sizeX(sizeX),
        m_sizeY(sizeY),
        m_textureFilepath(textureFilepath) {
        m_texture = std::make_unique<sf::Texture>();
        m_texture->loadFromFile(textureFilepath, sf::IntRect(startingX, startingY, sizeX, sizeY));
    }
};
#endif //_TEXTUREREPOSITORYENTRY_H_
