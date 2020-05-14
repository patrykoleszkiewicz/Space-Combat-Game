#pragma once

#include "Texture.hpp"
#include "Matrix4x4.hpp"

class Physical
{
public:
	Physical();
	
	void tickPhysics();
	
	void setTexture(Texture* texture);
	
	void setPosition(double X, double Y, double Z);
	void setPosition(const Vector3d &V);
	Vector3d getPosition() const;
	
	void setRotation(double X, double Y, double Z);
	void setRotation(const Vector3d &V);
	Vector3d getRotation() const;
	
	void setVelocity(double X, double Y, double Z);
	void setVelocity(const Vector3d &V);
	Vector3d getVelocity() const;
    
    Matrix4x4 getTransformMatrix() const;
	
protected:
	Texture* _texture;
	
	Vector3d _position;
	Vector3d _velocity;
	
	Vector3d _rotation;
	Vector3d _angleVelocity;
    
    Vector3d _scale;
};