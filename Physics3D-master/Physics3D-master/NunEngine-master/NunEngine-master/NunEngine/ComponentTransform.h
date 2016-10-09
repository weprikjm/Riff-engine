#ifndef __COMPONENTTRANSFORM_H__
#define __COMPONENTTRANSFORM_H__

#include "Component.h"

class ComponentTransform : public Component 
{

public:

	typeComponent type = COMPONENTTRANSFORM;
	float x;
	float y;
	float z;
};





#endif