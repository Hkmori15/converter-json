cmake_minimum_required(VERSION 3.15)
project(converter-json VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
      yaml-cpp
      GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
      GIT_TAG 0.8.0
)

FetchContent_Declare(
      nlohmann_json
      GIT_REPOSITORY https://github.com/nlohmann/json.git
      GIT_TAG v3.11.3
)

FetchContent_MakeAvailable(yaml-cpp nlohmann_json)

add_executable(converter main.cpp)
target_link_libraries(converter PRIVATE 
    yaml-cpp
    nlohmann_json::nlohmann_json
)