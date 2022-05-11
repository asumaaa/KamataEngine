#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "PrimitiveDrawer.h"
#include "affine.h"
#include "math.h"

#define PI 3.141592653589

GameScene::GameScene() 
{
	//アフィン変換
	affineMove(vec2, 10.0f, 10.0f, 10.0f);
	affineScale(vec3, 2.0f, 2.0f, 2.0f);
	affineRollX(vec4, 2 / 2);
}


GameScene::~GameScene()
{
	delete model_;
	delete debugCamera_;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();

	////ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("mario.jpg");

	//3Dモデルの生成
	model_ = Model::Create();

	//デバッグカメラの生成
	debugCamera_ = new DebugCamera(1280, 720);

	//ライン描画が参照するビュープロジェクションを指定する（アドレス渡し）
	PrimitiveDrawer::GetInstance()->SetViewProjection(&debugCamera_->GetViewProjection());

	// X,Y,Z方向のスケーリングを設定
	worldTransform_.scale_ = { 5.0f, 5.0f, 5.0f };

	// X, Y, Z軸周りの回転角を設定 XMConvertToRadians()
	worldTransform_.rotation_ = { 0.78f,0.78f , 0.0f };

	// X, Y, Z軸周りの平行移動を設定
	worldTransform_.translation_ = { 10.0f, 15.f, 10.0f };

	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	//ビュープロジェクションの初期化
	viewProjection_.Initialize();
}

void GameScene::Update() 
{
	debugCamera_->Update();
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	
	/*model_->Draw(worldTransform_, viewProjection_, textureHandle_);*/

	/*PrimitiveDrawer::GetInstance()->DrawLine3d(
		Vector3(0.0f, 0.0f, 0.0f),
		Vector3(5.0f, 5.0f, 5.0f),
		color
	);*/

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (vecConnection[i][k] == j)
					PrimitiveDrawer::GetInstance()->DrawLine3d(
						vec[i],
						vec[vecConnection[i][k]],
						Vector4(255, 255, 255, 255)
				);
				PrimitiveDrawer::GetInstance()->DrawLine3d(
					vec2[i],
					vec2[vecConnection[i][k]],
					Vector4(0, 255, 255, 255)
				);
				PrimitiveDrawer::GetInstance()->DrawLine3d(
					vec3[i],
					vec3[vecConnection[i][k]],
					Vector4(255, 0, 255, 255)
				);
				PrimitiveDrawer::GetInstance()->DrawLine3d(
					vec4[i],
					vec4[vecConnection[i][k]],
					Vector4(255, 255, 0, 255)
				);
			}
		}
	}

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
