#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet\include\btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	rCylinder wheel;

	wheel.color = color;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	rCube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	chassis.color = color;
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());

	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();

	chassis.Render();

	rCube nose(info.nose_size.x, info.nose_size.y, info.nose_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&nose.transform);
	nose.color = color;
	btQuaternion q_n = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset_n(info.nose_offset.x, info.nose_offset.y, info.nose_offset.z);
	offset_n = offset_n.rotate(q_n.getAxis(), q_n.getAngle());

	nose.transform.M[12] += offset_n.getX();
	nose.transform.M[13] += offset_n.getY();
	nose.transform.M[14] += offset_n.getZ();

	nose.Render();
	
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}

// ----------------------------------------------------------------------------
vec3 PhysVehicle3D::GetPos()const
{
	vec3 ret;
	ret.x = vehicle->getChassisWorldTransform().getOrigin().getX();
	ret.y = vehicle->getChassisWorldTransform().getOrigin().getY();
	ret.z = vehicle->getChassisWorldTransform().getOrigin().getZ();
	return ret;
}