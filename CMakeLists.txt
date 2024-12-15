# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.15)

# Set the project name and version
project(RayTracingAlgo)
# project(MyExample VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

# Find SDL2 package
find_package(SDL2 REQUIRED PATHS /usr/lib/x86_64-linux-gnu/cmake/SDL2 NO_DEFAULT_PATH)

set(SOURCES 
    src/main.cpp
    src/ObjectBase.cpp
    src/ObjSphere.cpp
    src/Ray.cpp
    src/Camera.cpp
    src/LightBase.cpp
    src/PointLight.cpp
    src/Scene.cpp
    src/Image.cpp
    src/CApp.cpp

)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${SDL2_LIBRARIES}
)
