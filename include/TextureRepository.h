//
// Created by Stefanos Mitropoulos on 21/7/22.
//

#ifndef _TEXTUREREPOSITORY_H_
#define _TEXTUREREPOSITORY_H_

#include <vector>
#include <sstream>
#include "TextureRepositoryEntry.h"


class TextureRepository {
    std::vector<TextureRepositoryEntry> m_repository;

  public:
    //Singleton
    static TextureRepository& getInstance() {

        static TextureRepository xInstance = TextureRepository();
        return xInstance;
    }

    void initialLoading(const std::string& filepathToConfiguration) {

        std::string imageFilepath = "/Users/smitropoulos/CLionProjects/sfml_asteroids/images/spaceship.png";

        TextureRepositoryEntry player{"player", 40, 0, 40, 40, imageFilepath};
        TextureRepositoryEntry rock{"rock", 40, 0, 40, 40, imageFilepath};
        TextureRepositoryEntry smallRock{"smallrock", 40, 0, 40, 40, imageFilepath};

        m_repository.emplace_back(std::move(player));
        m_repository.emplace_back(std::move(rock));
        m_repository.emplace_back(std::move(smallRock));
    }

    sf::Texture *provideTexture(std::string entityName) {

        for ( const auto& entity: m_repository )
        {
            if ( entity.m_name == entityName )
            {
                return entity.m_texture.get();
            }
        }

        std::stringstream ss;
        ss << "Could not provide texture for entity: " << entityName;
        throw std::runtime_error(ss.str());
    }
};

#endif //_TEXTUREREPOSITORY_H_
