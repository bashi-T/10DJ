#pragma once
#include "KamataEngine.h"
#include <numbers>

typedef struct Matrix2x2 {
	float m[2][2];
} Matrix2x2;

typedef struct Matrix3x3 {
	float m[3][3];
} Matrix3x3;

struct Line//直線
{
	KamataEngine::Vector3 origin; // 始点
	KamataEngine::Vector3 diff;   // 終点
};

struct Ray//半直線
{
	KamataEngine::Vector3 origin;
	KamataEngine::Vector3 diff;
};

struct Segment//線分
{
	KamataEngine::Vector3 origin;
	KamataEngine::Vector3 diff;
};

struct Plane {//平面
	KamataEngine::Vector3 normal;//法線
	float distance;//距離
};

struct Triangle
{
	KamataEngine::Vector3 vertices[3];
};

struct Sphere {
	KamataEngine::Vector3 center;
	float radius;
};

struct Quaternion
{
	float x;
	float y;
	float z;
	float w;
};

struct AABB {
	KamataEngine::Vector3 min;
	KamataEngine::Vector3 max;
};

struct OBB {
	KamataEngine::Vector3 center;//中心点
	KamataEngine::Vector3 orientations[3];//座標軸　正規化・直交必須 0=x 1=y 2=z
	KamataEngine::Vector3 size;//中心から面までの距離　座標軸方向の長さの半分
};

struct EulerTransform
{
	KamataEngine::Vector3 scale;
	KamataEngine::Vector3 rotate;
	KamataEngine::Vector3 translate;
};

struct QuaternionTransform
{
	KamataEngine::Vector3 scale;
	Quaternion rotate;
	KamataEngine::Vector3 translate;
};

const float radianPerFrequency = 0.0174533f;
const float theta_ = 3.14159265359f;

constexpr double epsilon = std::numeric_limits<double>::epsilon();

Matrix2x2 Add(Matrix2x2 a, Matrix2x2 b);
Matrix2x2 Subtract(Matrix2x2 a, Matrix2x2 b);
Matrix2x2 Multiply(Matrix2x2 a, Matrix2x2 b);

KamataEngine::Vector2 Multiply(KamataEngine::Vector2 v, Matrix2x2 b);

Matrix3x3 Multiply(Matrix3x3 a, Matrix3x3 b);


Matrix2x2 MakeRotateMatrix(float theta);

Matrix3x3 MakeRotateMatrix3x3(float theta);

Matrix3x3 MakeTranslateMatrix(KamataEngine::Vector2 translate);

KamataEngine::Vector2 Transform(KamataEngine::Vector2 vector, Matrix3x3 matrix);

Matrix2x2 Inverse(Matrix2x2 a);

Matrix3x3 Inverse(Matrix3x3 a);

Matrix2x2 Transpose(Matrix2x2 a);

Matrix3x3 Transpose(Matrix3x3 a);

Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom);

Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height);

Matrix3x3 Inverse3x3(Matrix3x3 a);

KamataEngine::Vector2 Lerp(const KamataEngine::Vector2& a, const KamataEngine::Vector2& b, float t);

KamataEngine::Vector2 Bezier(const KamataEngine::Vector2& p0, const KamataEngine::Vector2& p1, const KamataEngine::Vector2& p2, float t);

KamataEngine::Vector3 Lerp(const KamataEngine::Vector3& a, const KamataEngine::Vector3& b, float t);

KamataEngine::Vector3 Add(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);

KamataEngine::Vector3 Subtract(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);

KamataEngine::Vector3 Multiply(float scalar, const KamataEngine::Vector3& v);
//内積
float Dot(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);
//ベクトルの長さ
float Length(const KamataEngine::Vector3& v);
//正規化
KamataEngine::Vector3 Normalize(const KamataEngine::Vector3& v);

KamataEngine::Matrix4x4 Add(KamataEngine::Matrix4x4 a, KamataEngine::Matrix4x4 b);

KamataEngine::Matrix4x4 Subtract(KamataEngine::Matrix4x4 a, KamataEngine::Matrix4x4 b);

KamataEngine::Matrix4x4 Multiply(KamataEngine::Matrix4x4 a, KamataEngine::Matrix4x4 b);

KamataEngine::Matrix4x4 Inverse(KamataEngine::Matrix4x4 a);

KamataEngine::Matrix4x4 Transpose(KamataEngine::Matrix4x4 a);

KamataEngine::Matrix4x4 MakeIdentity4x4();

KamataEngine::Matrix4x4 MakeTranslateMatrix(const KamataEngine::Vector3& translate);

KamataEngine::Matrix4x4 MakeScaleMatrix(const KamataEngine::Vector3& scale);

KamataEngine::Vector3 Transform(const KamataEngine::Vector3& vector, const KamataEngine::Matrix4x4& matrix);

KamataEngine::Matrix4x4 MakeRotateXMatrix(float radian);

KamataEngine::Matrix4x4 MakeRotateYMatrix(float radian);

KamataEngine::Matrix4x4 MakeRotateZMatrix(float radian);

KamataEngine::Matrix4x4 MakeRotateMatrix(KamataEngine::Vector3 rotate);

KamataEngine::Matrix4x4 MakeAffineMatrix(KamataEngine::Vector3 scale, KamataEngine::Vector3 rotate, KamataEngine::Vector3 translate);
//透視投影行列
KamataEngine::Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
//正射影
KamataEngine::Matrix4x4 MakeOrthographicMatrix(
    float left, float top, float right, float bottom, float nearClip, float farClip);
//ビューポート
KamataEngine::Matrix4x4 MakeViewportMatrix(
    float left, float top, float width, float height, float minDepth, float maxDepth);

KamataEngine::Vector3 Cross(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);

KamataEngine::Vector3 TransformNormal(const KamataEngine::Vector3& v, const KamataEngine::Matrix4x4& m);

// 行ベクトル
KamataEngine::Matrix4x4 MakeRotateAxisAngle(const KamataEngine::Vector3& axis, float angle);

KamataEngine::Matrix4x4 DirectionTodirection(const KamataEngine::Vector3& from, const KamataEngine::Vector3& to);

Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);

Quaternion identityQuaternion();

Quaternion Conjugate(const Quaternion& quaternion);

float Norm(const Quaternion& quaternion);

Quaternion Normalize(const Quaternion& quaternion);//正規化・単位Quaternion

Quaternion Inverse(const Quaternion& quaternion);

Quaternion MakerotateAxisQuaternion(const KamataEngine::Vector3& axis, float angle);

KamataEngine::Vector3 RotateVector(const KamataEngine::Vector3& vector, const Quaternion& quaternion);

KamataEngine::Matrix4x4 MakeRotateMatrix(const Quaternion& quaternion);

Quaternion Slerp(const Quaternion& q0, const Quaternion& q1, float t);

KamataEngine::Matrix4x4 MakeAffineMatrix(KamataEngine::Vector3 scale, Quaternion rotate, KamataEngine::Vector3 translate);

float Lerp(const float& a, const float& b, float t);

float LerpShortAngle(float a, float b, float t);
//公転
KamataEngine::Vector3 Revolution(KamataEngine::Vector3 distance, KamataEngine::Vector3 tergetTranslate,KamataEngine::Vector3 rotate);