#ifndef OBJSPHERE_HPP
#define OBJSPHERE_HPP

#include "ObjectBase.hpp"

namespace RT{
class ObjSphere : public ObjectBase
{
public:
ObjSphere();
virtual ~ObjSphere();
virtual bool TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor) override;
};

}

#endif // OBJSPHERE_HPP