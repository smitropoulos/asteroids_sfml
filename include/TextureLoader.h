//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#ifndef _TEXTURELOADER_H_
#define _TEXTURELOADER_H_
#include <SFML/Graphics/Texture.hpp>

class TextureLoader {
    virtual sf::Texture loadTexture(std::string pathToFile);
};

#endif //_TEXTURELOADER_H_
