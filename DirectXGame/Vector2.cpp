#include "Vector2.h"
#include <cmath>
#include <iostream>

class Vector2 {
public:
	struct Vector2D
    {
		float x;
        float y;
    }; 
    
    float x, y;

    // コンストラクタ
    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}

    // 加算
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    // 減算
    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    // スカラー倍
    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    // スカラー除算
    Vector2 operator/(float scalar) const {
        return Vector2(x / scalar, y / scalar);
    }

    // 加算代入
    Vector2& operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // 減算代入
    Vector2& operator-=(const Vector2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    // スカラー代入（乗算）
    Vector2& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    // 長さ（magnitude）
    float Length() const {
        return std::sqrt(x * x + y * y);
    }

    // 正規化
    Vector2 Normalized() const {
        float len = Length();
        if (len == 0) return Vector2(0, 0);
        return Vector2(x / len, y / len);
    }

    // 内積
    float Dot(const Vector2& other) const {
        return x * other.x + y * other.y;
    }

    // 出力用
    void Print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};