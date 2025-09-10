#pragma once

enum SceneType {
    TITLE,
    STAGE_SELECT
};

class SceneManager {
public:
    static SceneType current;
    static void ChangeScene(SceneType next);
};
