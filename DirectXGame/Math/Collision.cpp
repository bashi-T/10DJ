#include "Collision.h"

using namespace KamataEngine;

bool isCollision(const KamataEngine::Vector2& square1, const KamataEngine::Vector2& square1Length, const KamataEngine::Vector2& square2, const KamataEngine::Vector2& square2Length)
{
	if (sqrt((square2.x - square1.x) * (square2.x - square1.x)) <= square1Length.x / 2 + square2Length.x / 2 &&
	    sqrt((square2.y - square1.y) * (square2.y - square1.y)) <= square1Length.y / 2 + square2Length.y / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isCollision(const AABB& aabb1, const AABB& aabb2)
{
	if ((aabb1.min.x <= aabb2.max.x) && (aabb1.max.x >= aabb2.min.x) &&
		(aabb1.min.y <= aabb2.max.y) && (aabb1.max.y >= aabb2.min.y) &&
		(aabb1.min.z <= aabb2.max.z) && (aabb1.max.z >= aabb2.min.z))
	{
		return true;
	}
	else
	{
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
	else
	{
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

bool isCollision(const KamataEngine::Vector2& square, const KamataEngine::Vector2& squareLength, const KamataEngine::Vector2& ChipPosition)
{
	Vector2 MapChipOrigin = {ChipPosition.x * chipSize + chipSize / 2, ChipPosition.y * chipSize + chipSize / 2};
	if (sqrt((MapChipOrigin.x - square.x) * (MapChipOrigin.x - square.x)) <= squareLength.x / 2 + chipSize / 2 &&
	    sqrt((MapChipOrigin.y - square.y) * (MapChipOrigin.y - square.y)) <= squareLength.y / 2 + chipSize / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isCollisionToMouse(const KamataEngine::Vector2& mouseSquareLength, const KamataEngine::Vector2& spriteSquare, const KamataEngine::Vector2& spriteSquareLength)
{
	POINT pos;
	HWND hwnd = WinApp::GetInstance()->GetHwnd();
	GetCursorPos(&pos);
	ScreenToClient(hwnd, &pos);
	Vector2 mousePos = {(float)pos.x, (float)pos.y};

	if (sqrt((mousePos.x - spriteSquare.x) * (mousePos.x - spriteSquare.x)) <= mouseSquareLength.x / 2 + spriteSquareLength.x / 2 &&
	    sqrt((mousePos.y - spriteSquare.y) * (mousePos.y - spriteSquare.y)) <= mouseSquareLength.y / 2 + spriteSquareLength.y / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
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

void PushBack(KamataEngine::Vector2& garbagePos, KamataEngine::Vector2& garbageVector, KamataEngine::Vector2& garbageSize, KamataEngine::Vector2& wallPos, KamataEngine::Vector2& wallSize)
{
	if (garbagePos.x - wallPos.x < (garbageSize.x + wallSize.x) / 2 && wallPos.x + wallSize.x / 2 < garbagePos.x && wallPos.x - wallSize.x / 2 > garbagePos.x)
	{//ごみと壁が接触判定中かつごみの中心のxが壁の外側にあるとき(上下から接触されていないとき)
		garbageVector.x *= -1;
	}
	else if (wallPos.x - garbagePos.x < (garbageSize.x + wallSize.x) / 2 && wallPos.x + wallSize.x / 2 < garbagePos.x && wallPos.x - wallSize.x / 2 > garbagePos.x)
	{
		garbageVector.x *= -1;
	}

	if (garbagePos.y - wallPos.y < (garbageSize.y + wallSize.y) / 2 && wallPos.y + wallSize.y / 2 < garbagePos.y && wallPos.y - wallSize.y / 2 > garbagePos.y)
	{//ごみと壁が接触判定中かつごみの中心のyが壁の外側にあるとき(上下から接触されていないとき)
		garbageVector.y *= -1;
	}
	else if (wallPos.y - garbagePos.y < (garbageSize.y + wallSize.y) / 2 && wallPos.y + wallSize.y / 2 < garbagePos.y && wallPos.y - wallSize.y / 2 > garbagePos.y)
	{
		garbageVector.y *= -1;
	}
}
