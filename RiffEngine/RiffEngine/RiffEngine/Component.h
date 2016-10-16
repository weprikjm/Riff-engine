#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "Globals.h"

enum typeComponent
{
	COMPONENTEMPTY,
	COMPONENTTRANSFORM,
	COMPONENTRIGIDBODY,
	COMPONENTMESH
};


class Component
{
public:
	
	Component(typeComponent type):IsEnabled(true), type(type) {}
	typeComponent GetType()
	{
		return type;
	}

	virtual void Enable() 
	{
		if (!IsEnabled)
		{
			IsEnabled = true;
		}
	}

	
	virtual update_status Update() 
	{
		return UPDATE_CONTINUE;
	}

	virtual void Disable()
	{
		if (IsEnabled)
		{
			IsEnabled = false;
		}
	}

public:

	bool IsEnabled;
	typeComponent type = COMPONENTEMPTY;
};

#endif
