#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "DebugText.h"
#include "DebugCamera.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <DirectXMath.h>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

	//テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// 3Dモデル
	Model* model_ = nullptr;

	//変数
	int32_t value_ = 0;

	//ワールドトランスフォーム
	WorldTransform worldTransform_;
	//ビュープロジェクション
	ViewProjection viewProjection_;

	//デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;

	//ベクトル
	Vector3 vec[8] =
	{
		{0.0f	,0.0f	,0.0f},	//0
		{0.0f	,10.0f	,0.0f},	//1
		{0.0f	,0.0f	,10.0f},//2
		{0.0f	,10.0f	,10.0f},//3
		{10.0f	,0.0f	,0.0f},	//4
		{10.0f	,10.0f	,0.0f},	//5
		{10.0f	,0.0f	,10.0f},//6
		{10.0f	,10.0f	,10.0f},//7
	};

	Vector3 vec2[8] =
	{
		{0.0f	,0.0f	,0.0f},	//0
		{0.0f	,10.0f	,0.0f},	//1
		{0.0f	,0.0f	,10.0f},//2
		{0.0f	,10.0f	,10.0f},//3
		{10.0f	,0.0f	,0.0f},	//4
		{10.0f	,10.0f	,0.0f},	//5
		{10.0f	,0.0f	,10.0f},//6
		{10.0f	,10.0f	,10.0f},//7
	};
	Vector3 vec3[8] =
	{
		{0.0f	,0.0f	,0.0f},	//0
		{0.0f	,10.0f	,0.0f},	//1
		{0.0f	,0.0f	,10.0f},//2
		{0.0f	,10.0f	,10.0f},//3
		{10.0f	,0.0f	,0.0f},	//4
		{10.0f	,10.0f	,0.0f},	//5
		{10.0f	,0.0f	,10.0f},//6
		{10.0f	,10.0f	,10.0f},//7
	};
	Vector3 vec4[8] =
	{
		{0.0f	,0.0f	,0.0f},	//0
		{0.0f	,10.0f	,0.0f},	//1
		{0.0f	,0.0f	,10.0f},//2
		{0.0f	,10.0f	,10.0f},//3
		{10.0f	,0.0f	,0.0f},	//4
		{10.0f	,10.0f	,0.0f},	//5
		{10.0f	,0.0f	,10.0f},//6
		{10.0f	,10.0f	,10.0f},//7
	};
	Vector3 vec5[8] =
	{
		{0.0f	,0.0f	,0.0f},	//0
		{0.0f	,10.0f	,0.0f},	//1
		{0.0f	,0.0f	,10.0f},//2
		{0.0f	,10.0f	,10.0f},//3
		{10.0f	,0.0f	,0.0f},	//4
		{10.0f	,10.0f	,0.0f},	//5
		{10.0f	,0.0f	,10.0f},//6
		{10.0f	,10.0f	,10.0f},//7
	};
	Vector3 vec6[8] =
	{
		{0.0f	,0.0f	,0.0f},	//0
		{0.0f	,10.0f	,0.0f},	//1
		{0.0f	,0.0f	,10.0f},//2
		{0.0f	,10.0f	,10.0f},//3
		{10.0f	,0.0f	,0.0f},	//4
		{10.0f	,10.0f	,0.0f},	//5
		{10.0f	,0.0f	,10.0f},//6
		{10.0f	,10.0f	,10.0f},//7
	};

	//つながってる点
	int vecConnection[8][3]
	{
		{1,2,4},
		{0,3,5},
		{0,3,6},
		{1,2,7},
		{0,5,6},
		{1,4,7},
		{2,4,7},
		{3,5,6}
	};

	Vector4 color = { 255,255,255,255 };

  public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

  private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	DebugText* debugText_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
