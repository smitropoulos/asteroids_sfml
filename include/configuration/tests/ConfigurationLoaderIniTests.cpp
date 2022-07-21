//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#include <gtest/gtest.h>
#include "mini/ini.h"

// Demonstrate some basic assertions.
TEST(iniConfiguration, load) {

    // first, create a file instance
    mINI::INIFile file("/Users/smitropoulos/CLionProjects/sfml_asteroids/include/configuration/samples/sample.ini");

    // next, create a structure that will hold data
    mINI::INIStructure ini;

    // now we can read the file
    file.read(ini);

    std::string& resolutionX = ini["system"]["resolutionX"];
    EXPECT_STREQ(resolutionX.c_str(), "1920");

    // read a value
    std::string& resolutionY = ini["system"]["resolutionY"];
    EXPECT_STREQ(resolutionY.c_str(), "1080");
}
