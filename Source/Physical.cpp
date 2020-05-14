#include "Physical.hpp"

#include <cmath>

Physical::Physical(const Model* model)
:_model(model)
{
	_rotation = Vector3d();
	_position = Vector3d();
	_velocity = Vector3d();
	_angleVelocity = Vector3d();
    _scale = Vector3d(1.0, 1.0, 1.0);
}

Model* Physical::getModel()
{
    return _model;
}

void Physical::tickPhysics()
{
	_position += _velocity;
	_rotation += _angleVelocity;
}

void Physical::setPosition(double X, double Y, double Z)
{
	_position.x = X;
	_position.y = Y;
	_position.z = Z;
}

void Physical::setPosition(const Vector3d &V)
{
	_position = V;
}

Vector3d Physical::getPosition() const
{
	return _position;
}

void Physical::setRotation(double X, double Y, double Z)
{
	_rotation.x = X;
	_rotation.y = Y;
	_rotation.z = Z;
}

void Physical::setRotation(const Vector3d &V)
{
	_rotation = V;
}

Vector3d Physical::getRotation() const
{
	return _rotation;
}

void Physical::setVelocity(double X, double Y, double Z)
{
	_velocity.x = X;
	_velocity.y = Y;
	_velocity.z = Z;
}

void Physical::setVelocity(const Vector3d &V)
{
	_velocity = V;
}

Vector3d Physical::getVelocity() const
{
	return _velocity;
}

Matrix4x4 Physical::getTransformMatrix() const
{
    Matrix4x4 matrixScaling;
    matrixScaling.mat[0][0] = _scale.x;
    matrixScaling.mat[1][1] = _scale.y;
    matrixScaling.mat[2][2] = _scale.z;
    Matrix4x4 matrixFinal = matrixScaling;
    
    Matrix4x4 matrixRotationX;
    matrixRotationX.mat[1][1] = cos(_rotation.x);
    matrixRotationX.mat[2][1] = -sin(_rotation.x);
    matrixRotationX.mat[1][2] = sin(_rotation.x);
    matrixRotationX.mat[2][2] = cos(_rotation.x);
    matrixFinal = matrixFinal.multiplyByMatrix(matrixRotationX);
    
    Matrix4x4 matrixRotationY;
    matrixRotationY.mat[0][0] = cos(_rotation.y);
    matrixRotationY.mat[0][2] = -sin(_rotation.y);
    matrixRotationY.mat[2][0] = sin(_rotation.y);
    matrixRotationY.mat[2][2] = cos(_rotation.y);
    matrixFinal = matrixFinal.multiplyByMatrix(matrixRotationY);
    
    Matrix4x4 matrixRotationZ;
    matrixRotationZ.mat[0][0] = cos(_rotation.z);
    matrixRotationZ.mat[1][0] = -sin(_rotation.z);
    matrixRotationZ.mat[0][1] = sin(_rotation.z);
    matrixRotationZ.mat[1][1] = cos(_rotation.z);
    matrixFinal = matrixFinal.multiplyByMatrix(matrixRotationZ);
    
    Matrix4x4 matrixTranslation;
    matrixTranslation.mat[3][0] = _position.x;
    matrixTranslation.mat[3][1] = _position.y;
    matrixTranslation.mat[3][2] = _position.z;
    matrixFinal = matrixFinal.multiplyByMatrix(matrixTranslation);
    
    return matrixFinal;
}