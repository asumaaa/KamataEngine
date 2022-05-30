#include "TextureManager.h"
#include <cassert>
#include "PrimitiveDrawer.h"
#include "GameScene.h"

class Player
{
private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//���f��
	Model* model_ = nullptr;
	//�e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;
public:
	void Initialize(Model * model,uint32_t textureHandle);
	void Update();
	void Draw();
};