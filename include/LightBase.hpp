#ifndef LIGHTBASE_HPP
#define LIGHTBASE_HPP

#include <memory>
#include "qbLinAlg/qbVector.h"
#include "Ray.hpp"
#include "ObjectBase.hpp"

namespace RT{
class LightBase{
public:
virtual ~LightBase();

virtual bool ComputeIllumination(const qbVector<double> &int_point, const qbVector<double> &local_normal, const std::vector<std::shared_ptr<RT::ObjectBase>> & obj_list,
    const std::shared_ptr<RT::ObjectBase> &current_obj, qbVector<double> &color, double &intensity);

public:
qbVector<double> m_color {3};
qbVector<double> m_location {3};
double m_intensity;
};
}

#endif // LIGHTBASE_HPP