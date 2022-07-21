//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#ifndef _CONFIGURATIONLOADER_H_
#define _CONFIGURATIONLOADER_H_
#include <string>
#include <map>


namespace Configuration {
class ConfigurationLoader {
  public:
    std::map<std::string, std::string> m_configuration;
    virtual void loadConfiguration(std::string filePath) = 0;

    virtual ~ConfigurationLoader() {
    }
};
}
#endif //_CONFIGURATIONLOADER_H_
