#pragma once
#include<algorithm>
#include <KamataEngine.h>

class PlayerCursor {
	PlayerCursor();
	~PlayerCursor();

public:
	bool MouthCollsion(const KamataEngine::Vector2& SquarePos, const KamataEngine::Vector2& SquareScale);

private:

};
