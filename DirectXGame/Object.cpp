#include "Object.h"

Object::Object(float x, float y, float w, float h) {
    rect = { x, y, w, h };
}

bool Object::HitTest(int mx, int my) {
    return (mx > rect.x && mx < rect.x + rect.w &&
        my > rect.y && my < rect.y + rect.h);
}

bool Object::CheckCollision(const Object& other) {
    return (rect.x < other.rect.x + other.rect.w &&
        rect.x + rect.w > other.rect.x &&
        rect.y < other.rect.y + other.rect.h &&
        rect.y + rect.h > other.rect.y);
}