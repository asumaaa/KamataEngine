#include "TextureManager.h"
#include <cassert>
#include "PrimitiveDrawer.h"
#include "GameScene.h"

class Player
{
private:
	//ワールド変換データ
	WorldTransform worldTransform_;
	//モデル
	Model* model_ = nullptr;
	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;
public:
	void Initialize(Model * model,uint32_t textureHandle);
	void Update();
	void Draw();
};