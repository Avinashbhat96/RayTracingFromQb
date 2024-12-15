#include "LightBase.hpp"

RT::LightBase::~LightBase(){

}

bool RT::LightBase::ComputeIllumination(const qbVector<double> &int_point, const qbVector<double> &local_normal, 
    const std::vector<std::shared_ptr<RT::ObjectBase>> &obj_list,
    const std::shared_ptr<RT::ObjectBase> &current_obj, qbVector<double> &color, double &intensity)
{
    return false;
}
