#ifndef SCENE_HPP
#define SCENE_HPP

#include "Image.hpp"
#include <vector>
#include <SDL2/SDL.h>
#include "Camera.hpp"
#include "ObjSphere.hpp"
#include <memory>
#include "PointLight.hpp"

namespace RT{
    class Scene {
    public:
    Scene();
    ~Scene() = default;

    bool Render(Image &OutputImage);

    private:
    RT::Camera m_camera;
    
    //list of objects in the scene
    std::vector<std::shared_ptr<RT::ObjectBase>> m_objs;
    
    //list of lights in the scene
    std::vector<std::shared_ptr<RT::LightBase>> m_lights;
    };
}

#endif // SCENE_HPP