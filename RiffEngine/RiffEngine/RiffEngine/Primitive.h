
#pragma once
#include "glmath.h"
#include "Color.h"

enum PrimitiveTypes
{
	Primitive_Point,
	Primitive_Line,
	Primitive_Plane,
	Primitive_Cube,
	Primitive_Sphere,
	Primitive_Cylinder
};

class Primitive
{
public:

	Primitive();

	virtual void	Render() const;
	virtual void	InnerRender() const;
	void			SetPos(float x, float y, float z);
	void			SetRotation(float angle, const vec3 &u);
	void			Scale(float x, float y, float z);
	PrimitiveTypes	GetType() const;
	vec3			GetPos()const;
public:
	
	Color color;
	mat4x4 transform;
	bool axis,wire;

protected:
	PrimitiveTypes type;
};

// ============================================
class rCube : public Primitive
{
public :
	rCube();
	rCube(float sizeX, float sizeY, float sizeZ);
	void InnerRender() const;
public:
	vec3 size;
};

// ============================================
class rSphere : public Primitive
{
public:
	rSphere();
	rSphere(float radius);
	void InnerRender() const;
public:
	float radius;
};

// ============================================
class rCylinder : public Primitive
{
public:
	rCylinder();
	rCylinder(float radius, float height);
	void InnerRender() const;
public:
	float radius;
	float height;
};

// ============================================
class rLine : public Primitive
{
public:
	rLine();
	rLine(float x, float y, float z);
	void InnerRender() const;
public:
	vec3 origin;
	vec3 destination;
};

// ============================================
class rPlane : public Primitive
{
public:
	rPlane();
	rPlane(float x, float y, float z, float d);
	void InnerRender() const;
public:
	vec3 normal;
	float constant;
};