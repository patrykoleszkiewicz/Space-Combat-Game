#include "Camera.hpp"

Camera::Camera(sf::View &view, Vector3d position, Vector3d direction, double fov, double znear, double zfar)
:_view(view), _position(position), _direction(direction), _fieldOfView(fov), _zNear(znear), _zFar(zfar)
{
    _aspectRatio = view.getSize().y / view.getSize().x;
    double fovTan = 1.0 / tan(_fieldOfView * 0.5 / 180.0 * 3.14159265);
    
    _projectionMatrix[0][0] = _aspectRatio * fovTan;
    _projectionMatrix[1][1] = fovTan;
    _projectionMatrix[2][2] = _zFar / (_zFar - _zNear);
    _projectionMatrix[3][2] = -_zFar * _zNear / (_zFar - _zNear);
    _projectionMatrix[2][3] = 1.0;
}