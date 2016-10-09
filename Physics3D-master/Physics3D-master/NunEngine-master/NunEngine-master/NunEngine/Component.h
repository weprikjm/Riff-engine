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
	
	Component(typeComponent type):IsEnabled(true), type(type) {}
	typeComponent GetType();

public:

	bool IsEnabled;
	typeComponent type = COMPONENTEMPTY;
};

#endif
