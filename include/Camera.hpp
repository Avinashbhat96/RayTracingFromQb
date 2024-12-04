#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "./qbLinAlg/qbVector.h"
#include "Ray.hpp"

namespace RT 
{
    class Camera
    {
        public:
        Camera();

        inline void SetPosition(const qbVector<double> &newPosition){
            m_position = newPosition;
        }
        inline void SetLookAt(const qbVector<double> &newLookAt){
            m_lookat = newLookAt;
        }
        inline void SetUp(const qbVector<double> &newUp){
            m_up = newUp;
        }
        inline void SetLength(double newLength){
            m_length = newLength;
        }
        inline void SetHorizontalSize(double newSize){
            m_horsize = newSize;
        }
        inline void SetAspect(double newAspect){
            m_aspectratio = newAspect;
        }

        inline qbVector<double> GetPosition(){
            return m_position;
        }
        inline qbVector<double> GetLookAt(){
            return m_lookat;
        }
        inline qbVector<double> GetUp(){
            return m_up;
        }
        inline qbVector<double> GetU(){
            return m_projectionscreen_u;
        }
        inline qbVector<double> GetV(){
            return m_projectionscreen_v;
        }
        inline qbVector<double> GetScreenCentre(){
            return m_projectionscreen_centre;
        }
        inline double GetLength(){
            return m_length;
        }
        inline double GetHorizontalSize(){
            return m_horsize;
        }
        inline double GetAspect(){
            return m_aspectratio;
        }

        Ray GenerateRay(float proScreenX, float proScreenY);

        void UpdateCameraGeometry();

        private:
        qbVector<double> m_position {3};
        qbVector<double> m_lookat {3};
        qbVector<double> m_up {3};
        double m_length;
        double m_horsize;
        double m_aspectratio;

        qbVector<double> m_alignmentvector {3};
        qbVector<double> m_projectionscreen_u {3};
        qbVector<double> m_projectionscreen_v {3};
        qbVector<double> m_projectionscreen_centre {3};

    };
}

#endif // CAMERA_HPP