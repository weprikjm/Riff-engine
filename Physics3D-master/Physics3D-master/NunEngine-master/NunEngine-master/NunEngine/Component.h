#ifndef __COMPONENT_H__
#define __COMPONENT_H__

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
	
	Component():IsEnabled(true) {}


public:

	bool IsEnabled;
	typeComponent type = COMPONENTEMPTY;
};

#endif
