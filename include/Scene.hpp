#ifndef SCENE_HPP
#define SCENE_HPP

#include "Image.hpp"
#include <vector>
#include <SDL2/SDL.h>

namespace RT{
    class Scene {
    public:
    Scene();

    bool Render(Image &OutputImage);

    
    };
}

#endif // SCENE_HPP