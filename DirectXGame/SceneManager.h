#pragma once

enum SceneType {
    TITLE,
    STAGESELECT
};

class SceneManager {
public:
    static SceneType current;
    static void ChangeScene(SceneType next);
};
