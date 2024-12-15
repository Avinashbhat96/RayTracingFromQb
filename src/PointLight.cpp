#include "PointLight.hpp"

RT::PointLight::PointLight(){
    m_color = qbVector<double>{std::vector<double>{1.0, 1.0, 1.0}};
    m_intensity = 1.0;
}

RT::PointLight::~PointLight(){

}

bool RT::PointLight::ComputeIllumination(const qbVector<double> &int_point, const qbVector<double> &local_normal, 
                                        const std::vector<std::shared_ptr<RT::ObjectBase>> & obj_list, 
                                        const std::shared_ptr<RT::ObjectBase> &current_obj, 
                                        qbVector<double> &color, double &intensity)
{
    qbVector<double> light_dir = (m_location - int_point).Normalized();

    qbVector<double> start_point = int_point;

    double angle = acos(qbVector<double>::dot(local_normal, light_dir));

    if(angle > 1.5708){
        color = m_color;
        intensity = 0.0;
        return false;
    }
    else {
        color = m_color;
        intensity = m_intensity * (1.0 - (angle / 1.5708));
        return true;
    }
}