#include "Scene.hpp"
// <string>
RT::Scene::Scene(){
    m_camera.SetPosition(qbVector<double>{std::vector<double>{0.0,-10.0,0.0}});
    m_camera.SetLookAt(qbVector<double>{std::vector<double>{0.0,0.0,0.0}});
    m_camera.SetUp(qbVector<double>{std::vector<double>{0.0,0.0,1.0}});
    m_camera.SetHorizontalSize(0.25);
    m_camera.SetAspect(16.0/9.0);
    m_camera.UpdateCameraGeometry();

    // test sphere
    m_objs.push_back(std::make_shared<RT::ObjSphere> (RT::ObjSphere()));

    // light source
    m_lights.push_back(std::make_shared<RT::PointLight> (RT::PointLight()));
    m_lights.at(0)->m_location = qbVector<double>{std::vector<double>{5.0, -10.0, 5.0}};
    m_lights.at(0)->m_color = qbVector<double>{std::vector<double>{255.0, 255.0, 255.0}};
}

bool RT::Scene::Render(Image& outputImage){
    int xSize = outputImage.GetXSize();
    int ySize = outputImage.GetYSize();

    qbVector<double> int_point {3};
    qbVector<double> local_normal {3};
    qbVector<double> local_color {3};
    double x_fact = 1.0 / (static_cast<double>(xSize) / 2.0);
    double y_fact = 1.0 / (static_cast<double>(ySize) / 2.0);
    double min_dist = 1e6;
    double max_dist = 0.0;
    for(int x=0; x < xSize; ++x){
        for(int y=0; y < ySize; ++y){
            RT::Ray camera_ray;
            double norm_x = (static_cast<double>(x) * x_fact) - 1.0;
            double norm_y = (static_cast<double>(y) * y_fact) - 1.0;
            
            m_camera.GenerateRay(norm_x, norm_y, camera_ray);
            
            for(auto current_obj : m_objs){
                bool valid_int = current_obj->TestIntersection(camera_ray, int_point, local_normal, local_color);
                if(valid_int){
                    double intensity;
                    qbVector<double> color {3};
                    bool validIllum = false;
                    for(auto currentLight : m_lights){
                        validIllum = currentLight->ComputeIllumination(int_point, local_normal, m_objs, current_obj, color, intensity);
                    }

                    double dist = (int_point - camera_ray.m_point1).norm();
                    if(dist > max_dist)
                        max_dist = dist;
                    if(dist < min_dist)
                        min_dist = dist;
                    if(validIllum){
                        outputImage.SetPixel(x, y, 255.0 * intensity, 0.0, 0.0);    
                    } else {
                        outputImage.SetPixel(x, y, 0.0, 0.0, 0.0);
                    }
                }
                else{
                    outputImage.SetPixel(x, y, 0, 0, 0);
                }
            }

        }
    }
}