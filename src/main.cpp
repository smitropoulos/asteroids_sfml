#include "Game.h"
#include "TextureRepository.h"

int main() {

    TextureRepository::getInstance().initialLoading("/Users/smitropoulos/CLionProjects/sfml_asteroids/Configuration.ini");

    Game asteroids;
    asteroids.run();

    return 0;
}
