#pragma once

namespace KamataEngine {

    /// <summary>
    /// 4x4行列
    /// </summary>
    struct Matrix4x4 final {
        float m[4][4];
    };

    /// <summary>
    /// 4x4行列の掛け算
    /// </summary>
    inline Matrix4x4 MultiplyMatrix4x4(const Matrix4x4& a, const Matrix4x4& b) {
        Matrix4x4 result{};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m[i][j] =
                    a.m[i][0] * b.m[0][j] +
                    a.m[i][1] * b.m[1][j] +
                    a.m[i][2] * b.m[2][j] +
                    a.m[i][3] * b.m[3][j];
            }
        }
        return result;
    }

} // namespace KamataEngine
