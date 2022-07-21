//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#ifndef _CONFIGURATIONLOADERINI_H_
#define _CONFIGURATIONLOADERINI_H_

#include "ConfigurationLoader.h"

namespace Configuration {

class ConfigurationLoaderIni : public ConfigurationLoader {
  public:
    void loadConfiguration(std::string filePath) override;
};
}
#endif //_CONFIGURATIONLOADERINI_H_
