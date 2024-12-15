#ifndef POINTLIGHT_HPP
#define POINTLIGHT_HPP

#include "LightBase.hpp"

namespace RT
{
class PointLight : public LightBase
{
    public:
    PointLight();
    virtual ~PointLight();
    virtual bool ComputeIllumination(const qbVector<double> &int_point, const qbVector<double> &local_normal, const std::vector<std::shared_ptr<RT::ObjectBase>> & obj_list,
    const std::shared_ptr<RT::ObjectBase> &current_obj, qbVector<double> &color, double &intensity);
};
}

#endif // POINTLIGHT_HPP