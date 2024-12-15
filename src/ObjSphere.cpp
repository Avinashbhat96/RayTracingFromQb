#include "ObjSphere.hpp"
#include <cmath>

RT::ObjSphere::ObjSphere(){

}
RT::ObjSphere::~ObjSphere(){
    
}

bool RT::ObjSphere::TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor){
    qbVector<double> vhat = castRay.m_lab;
    vhat.Normalize();

    double b = 2.0 * qbVector<double>::dot(castRay.m_point1, vhat);

    double c = qbVector<double>::dot(castRay.m_point1, castRay.m_point1) - 1.0;

    double intTest = (b*b) - 4.0 * c;

    if(intTest > 0.0){
        double num_sqrt = sqrt(intTest);
        double t1 = (-b + num_sqrt) / 2.0;
        double t2 = (-b - num_sqrt) / 2.0;

        if((t1 < 0.0) || (t2 < 0.0))
            return false;
        else{
            if(t1 < t2){
                intPoint = castRay.m_point1 + (vhat * t1);
            }
            else {
                intPoint = castRay.m_point1 + (vhat * t2); 
            }

            // local normal
            localNormal = intPoint;
            localNormal.Normalize();
        }
        return true;
    }
    else
        return false;
}
