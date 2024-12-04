#include "Camera.hpp"
#include "Ray.hpp"
#include "math.h"

RT::Camera::Camera(){
    m_position = qbVector<double> {std::vector<double>{0.0, -10.0, 0.0}};
    m_lookat = qbVector<double> {std::vector<double>{0.0, 0.0, 0.0}};
    m_up = qbVector<double> {std::vector<double>{0.0, 0.0, 1.0}};
    m_length = 1.0;
    m_horsize = 1.0;
    m_aspectratio = 1.0;
}


void RT::Camera::UpdateCameraGeometry()
{
    // compute the vector from the camera position to the look at position
    m_alignmentvector = m_lookat - m_position;
    m_alignmentvector.Normalize();

    // compute u and v vectors
    m_projectionscreen_u = qbVector<double>::cross(m_alignmentvector, m_up);
    m_projectionscreen_u.Normalize();
    m_projectionscreen_v = qbVector<double>::cross(m_projectionscreen_u, m_alignmentvector);
    m_projectionscreen_v.Normalize();

    // compute the position of the centre point of the screen
    m_projectionscreen_centre = m_position + (m_length * m_alignmentvector);

    // modify the u and v vectors to match the size and aspect ratio
    m_projectionscreen_u = m_projectionscreen_u * m_horsize;
    m_projectionscreen_v = m_projectionscreen_v * (m_horsize / m_aspectratio);
}

RT::Ray RT::Camera::GenerateRay(float proScreenX, float proScreenY){
    qbVector<double> screen_world_part1 = m_projectionscreen_centre + (m_projectionscreen_u * proScreenX);
    qbVector<double> screen_world_coord = screen_world_part1 + (m_projectionscreen_v * proScreenY);

    return RT::Ray(m_position, screen_world_coord);
    
}