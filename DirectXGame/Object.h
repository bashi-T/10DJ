#pragma once

struct Rect {
    float x, y, w, h;
};

class Object {
public:
    Rect rect;

    Object(float x, float y, float w, float h);
    bool HitTest(int mx, int my);               // マウス座標との判定
    bool CheckCollision(const Object& other);   // 他オブジェクトとの当たり判定
};
