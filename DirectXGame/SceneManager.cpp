#include "SceneManager.h"

SceneType SceneManager::current = TITLE;

void SceneManager::ChangeScene(SceneType next) {
    current = next;
}