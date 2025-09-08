#pragma once
#include<algorithm>
#include "CGvector.h"
#include "StageMapChip.h"
#include <windows.h>
#include <iostream>

//bool IsCollision(const Segment&segment,const Plane&plane)
//{
//	float dot = Dot(plane.normal, line.diff);
//	if (dot == 0.0f)
//	{
//		return false;
//	}
//
//	float t = (plane.distance - Dot(line.origin, plane.normal)) / dot;
//
//}

//spriteどうしの当たり判定 アンカーポイントを0.5に
bool isCollision(const KamataEngine::Vector2& square1, const KamataEngine::Vector2& square1Length, const KamataEngine::Vector2& square2, const KamataEngine::Vector2& square2Length);

bool isCollision(const AABB& aabb1, const AABB& aabb2);

bool isCollision(const AABB& aabb, const Sphere& sphere);

bool isCollision(const OBB& obb, const Sphere& sphere);

bool isCollision(const KamataEngine::Vector2& square, const KamataEngine::Vector2& squareLength, const KamataEngine::Vector2& ChipPosition);

bool isCollisionToMouse(const KamataEngine::Vector2& mouseSquareLength, const KamataEngine::Vector2& spriteSquare, const KamataEngine::Vector2& spriteSquareLength);

//bool isCollision(const OBB& obb1, const OBB& obb2)
//{
//	float sumSpan;
//}

bool isCollision(const Sphere& sphere1, const Sphere& sphere2);
