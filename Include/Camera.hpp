#pragma once

#include "Matrix4x4.hpp"

class Camera
{
public:
    Camera(sf:View &view, Vector3d position, Vector3d direction, double fov, double znear, double zfar);
    
    const Matrix4x4& getProjectionMatrix() const;
private:
    sf::View _view;
    
    Vector3d _position;
    Vector3d _direction;

    Matrix4x4 _projectionMatrix;
    
    double _fieldOfView;
    double _aspectRatio;
    double _zNear;
    double _zFar;
}