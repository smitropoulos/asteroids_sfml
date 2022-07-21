//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#include "ConfigurationLoaderIni.h"
#include "mini/ini.h"


void Configuration::ConfigurationLoaderIni::loadConfiguration(std::string filePath) {
    // first, create a file instance
    mINI::INIFile file(filePath);

    // next, create a structure that will hold data
    mINI::INIStructure ini;

    // now we can read the file
    file.read(ini);

    std::string resolutionX = ini["system"]["resolutionX"];
    std::string resolutionY = ini["system"]["resolutionY"];

    m_configuration.insert(std::make_pair("resolutionX", resolutionX));
    m_configuration.insert(std::make_pair("resolutionY", resolutionY));
}
