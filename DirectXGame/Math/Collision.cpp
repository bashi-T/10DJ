#include "Collision.h"

using namespace KamataEngine;

bool isCollision(const KamataEngine::Vector2& square1, const KamataEngine::Vector2& square1Length, const KamataEngine::Vector2& square2, const KamataEngine::Vector2& square2Length)
{
	Vector2 origin1 = {square1.x + square1Length.x / 2, square1.y + square1Length.y / 2};
	Vector2 origin2 = {square2.x + square2Length.x / 2, square2.y + square2Length.y / 2};

	if (sqrt((origin2.x - origin1.x) * (origin2.x - origin1.x)) <= square1Length.x / 2 + square2Length.x / 2 &&
	    sqrt((origin2.y - origin1.y) * (origin2.y - origin1.y)) <= square1Length.y / 2 + square2Length.y / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isCollision(const AABB& aabb1, const AABB& aabb2) {
	if ((aabb1.min.x <= aabb2.max.x) && (aabb1.max.x >= aabb2.min.x) &&
		(aabb1.min.y <= aabb2.max.y) && (aabb1.max.y >= aabb2.min.y) &&
		(aabb1.min.z <= aabb2.max.z) && (aabb1.max.z >= aabb2.min.z)) {
		return true;
	}
	else {
		return false;
	}
}

bool isCollision(const AABB& aabb, const Sphere& sphere)
{
	Vector3 closestPoint
	{
		std::clamp(sphere.center.x,aabb.min.x,aabb.max.x),
		std::clamp(sphere.center.y,aabb.min.y,aabb.max.y),
		std::clamp(sphere.center.z,aabb.min.z,aabb.max.z)
	};
	float distance = Length(Subtract(closestPoint, sphere.center));
	if (distance <= sphere.radius)
	{
		return true;
	}
	else {
		return false;
	}
}

bool isCollision(const OBB& obb, const Sphere& sphere)
{
	Matrix4x4 OBBWorldMatrix
	{
		obb.orientations[0].x,
		obb.orientations[0].y,
		obb.orientations[0].z,
		0.0f,

		obb.orientations[1].x,
		obb.orientations[1].y,
		obb.orientations[1].z,
		0.0f,

		obb.orientations[2].x,
		obb.orientations[2].y,
		obb.orientations[2].z,
		0.0f,

		obb.center.x,
		obb.center.y,
		obb.center.z,
		1.0f
	};

	Matrix4x4 OBBWorldMatrixInverce = Inverse(OBBWorldMatrix);
	Vector3 centerInOBBLocalSpace = Transform(sphere.center, OBBWorldMatrixInverce);
	AABB aabbOBBLocal{ {-obb.size.x,-obb.size.y,-obb.size.z},obb.size };
	Sphere sphereOBBLocal{ centerInOBBLocalSpace ,sphere.radius };

	return isCollision(aabbOBBLocal, sphereOBBLocal);
}

bool isCollision(const Sphere& sphere1, const Sphere& sphere2)
{
	float distance = Length(Subtract(sphere2.center, sphere1.center));
	if (distance <= sphere1.radius + sphere2.radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}
