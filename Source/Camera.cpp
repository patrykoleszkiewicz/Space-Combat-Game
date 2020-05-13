#include "Camera.hpp"

#include <cmath>

Camera::Camera(sf::View &view, Vector3d position, Vector3d direction, double fov, double znear, double zfar)
:_view(view), _position(position), _direction(direction), _fieldOfView(fov), _zNear(znear), _zFar(zfar)
{
    _aspectRatio = _view.getSize().y / _view.getSize().x;
    double fovTan = 1.0 / tan(_fieldOfView * 0.5 / 180.0 * 3.14159265);
    
    _projectionMatrix.mat[0][0] = _aspectRatio * fovTan;
    _projectionMatrix.mat[1][1] = fovTan;
    _projectionMatrix.mat[2][2] = _zFar / (_zFar - _zNear);
    _projectionMatrix.mat[3][2] = -_zFar * _zNear / (_zFar - _zNear);
    _projectionMatrix.mat[2][3] = 1.0;
}

const Matrix4x4& Camera::getProjectionMatrix() const
{
    return _projectionMatrix;
}

sf::View Camera::getView()
{
    return _view;
}