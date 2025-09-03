#pragma once
#include <cmath>
#include <iostream>

class Vector2 {
public:
    float x;
    float y;

    // コンストラクタ
    Vector2();
    Vector2(float x, float y);

    // 演算子オーバーロード
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(float scalar) const;
    Vector2 operator/(float scalar) const;

    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    Vector2& operator*=(float scalar);

    // ユーティリティ関数
    float Length() const;
    Vector2 Normalized() const;
    float Dot(const Vector2& other) const;

    void Print() const;
};