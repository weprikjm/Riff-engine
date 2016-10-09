#ifndef __COMPONENTTRANSFORM_H__
#define __COMPONENTTRANSFORM_H__

#include "Component.h"

class ComponentTransform : public Component 
{

public:

	ComponentTransform(typeComponent type) : Component(type){}


	typeComponent type = COMPONENTTRANSFORM;
	float x;
	float y;
	float z;
};





#endif