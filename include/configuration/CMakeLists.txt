
add_library(ConfigurationLib
            src/ConfigurationLoaderIni.cpp
            )

target_include_directories(ConfigurationLib PUBLIC include)
add_subdirectory(tests)

