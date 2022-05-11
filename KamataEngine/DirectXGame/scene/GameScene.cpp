#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "PrimitiveDrawer.h"
#include "math.h"
#include "affine.h"

#define PI 3.141592653589

////原点からの距離
//float SuqareWidht = 0.0f;
//float SuqareHeight = 0.0f;
//float SuqareDepth = 0.0f;
//
////平行移動の関数
//void affineMove(Vector3 vec_[], float moveX, float moveY, float moveZ)
//{
//	float move_[4][4]
//	{
//		{1.0f,0.0f,0.0f,moveX},
//		{0.0f,1.0f,0.0f,moveY},
//		{0.0f,0.0f,1.0f,moveZ},
//		{0.0f,0.0f,0.0f,1.0f},
//	};
//
//	//平行移動
//	for (int i = 0; i < 8; i++) {
//		vec_[i].x = move_[0][0] * vec_[i].x + move_[0][1] * vec_[i].x + move_[0][2] * vec_[i].x + move_[0][3] * 1.0f;
//		vec_[i].y = move_[1][0] * vec_[i].y + move_[1][1] * vec_[i].y + move_[1][2] * vec_[i].y + move_[1][3] * 1.0f;
//		vec_[i].z = move_[2][0] * vec_[i].z + move_[2][1] * vec_[i].z + move_[2][2] * vec_[i].z + move_[2][3] * 1.0f;
//	}
//}
//
//
////拡大縮小の関数 動かしたいベクトル、x方向の拡大率、y方向の拡大率、z方向の拡大率
//void affineScale(Vector3 vec[], float scaleX, float scaleY, float scaleZ)
//{
//	//拡大縮小の行列
//	float scale[4][4] = {
//		{scaleX	,0.0f	,0.0f	,0.0f},
//		{0.0f	,scaleY	,0.0f	,0.0f},
//		{0.0f	,0.0f	,scaleZ	,0.0f},
//		{0.0f	,0.0f	,0.0f	,1.0f},
//	};
//
//	//保存用の変数
//	float squareScaleX = 0.0f;
//	float squareScaleY = 0.0f;
//	float squareScaleZ = 0.0f;
//
//	//拡大縮小	左上原点
//	for (int i = 0; i < 8; i++) {
//		squareScaleX = vec[i].x - SuqareWidht;
//		squareScaleY = vec[i].y - SuqareWidht;
//		squareScaleZ = vec[i].z - SuqareDepth;
//
//		vec[i].x =
//			scale[0][0] * squareScaleX + scale[0][1] * squareScaleX + scale[0][2] * squareScaleX;
//		vec[i].y =
//			scale[1][0] * squareScaleY + scale[1][1] * squareScaleY + scale[1][2] * squareScaleY;
//		vec[i].z =
//			scale[2][0] * squareScaleZ + scale[2][1] * squareScaleZ + scale[2][2] * squareScaleZ;
//
//		vec[i].x += SuqareWidht;
//		vec[i].y += SuqareHeight;
//		vec[i].z += SuqareDepth;
//	}
//}
//
////回転X　回転させたいベクトル、角度(ラジアン)
//void affineRollX(Vector3 vec[], float roll_)
//{
//	//回転の行列
//	float roll[4][4] = {
//		{1.0f	,0.0f		,0.0f			,0.0f},
//		{0.0f	,cos(roll_)	,-sin(roll_)	,0.0f},
//		{0.0f	,sin(roll_)	,cos(roll_)		,0.0f},
//		{0.0f	,0.0f		,0.0f			,1.0f},
//	};
//
//	float squareRollX = 0.0f;
//	float squareRollY = 0.0f;
//	float squareRollZ = 0.0f;
//	//回転	左上原点
//	for (int i = 0; i < 8; i++) {
//		squareRollX = vec[i].x - SuqareWidht;
//		squareRollY = vec[i].y - SuqareHeight;
//		squareRollZ = vec[i].z - SuqareDepth;
//
//		vec[i].x =
//			roll[0][0] * squareRollX + roll[0][1] * squareRollY + roll[0][2] * squareRollZ;
//		vec[i].y =
//			roll[1][0] * squareRollX + roll[1][1] * squareRollY + roll[1][2] * squareRollZ;
//		vec[i].z =
//			roll[2][0] * squareRollX + roll[2][1] * squareRollY + roll[2][2] * squareRollZ;
//
//		vec[i].x += SuqareWidht;
//		vec[i].y += SuqareHeight;
//		vec[i].z += SuqareDepth;
//	}
//}
//
////回転Y　回転させたいベクトル、角度(ラジアン)
//void affineRollY(Vector3 vec[], float roll_)
//{
//	//回転の行列
//	float roll[4][4] = {
//		{cos(roll_)		,0.0f	,sin(roll_)		,0.0f},
//		{0.0f			,1.0f	,0.0f			,0.0f},
//		{-sin(roll_)	,0.0f	,cos(roll_)		,0.0f},
//		{0.0f			,0.0f	,0.0f			,1.0f},
//	};
//
//	float squareRollX = 0.0f;
//	float squareRollY = 0.0f;
//	float squareRollZ = 0.0f;
//	//回転	左上原点
//	for (int i = 0; i < 8; i++) {
//		squareRollX = vec[i].x - SuqareWidht;
//		squareRollY = vec[i].y - SuqareHeight;
//		squareRollZ = vec[i].z - SuqareDepth;
//
//		vec[i].x =
//			roll[0][0] * squareRollX + roll[0][1] * squareRollY + roll[0][2] * squareRollZ;
//		vec[i].y =
//			roll[1][0] * squareRollX + roll[1][1] * squareRollY + roll[1][2] * squareRollZ;
//		vec[i].z =
//			roll[2][0] * squareRollX + roll[2][1] * squareRollY + roll[2][2] * squareRollZ;
//
//		vec[i].x += SuqareWidht;
//		vec[i].y += SuqareHeight;
//		vec[i].z += SuqareDepth;
//	}
//}
//
////回転Y　回転させたいベクトル、角度(ラジアン)
//void affineRollZ(Vector3 vec[], float roll_)
//{
//	//回転の行列
//	float roll[4][4] = {
//		{cos(roll_)		,-sin(roll_)	,0.0f		,0.0f},
//		{sin(roll_)		,cos(roll_)		,0.0f		,0.0f},
//		{0.0f			,0.0f			,1.0f		,0.0f},
//		{0.0f			,0.0f			,0.0f		,1.0f},
//	};
//
//	float squareRollX = 0.0f;
//	float squareRollY = 0.0f;
//	float squareRollZ = 0.0f;
//	//回転	左上原点
//	for (int i = 0; i < 8; i++) {
//		squareRollX = vec[i].x - SuqareWidht;
//		squareRollY = vec[i].y - SuqareHeight;
//		squareRollZ = vec[i].z - SuqareDepth;
//
//		vec[i].x =
//			roll[0][0] * squareRollX + roll[0][1] * squareRollY + roll[0][2] * squareRollZ;
//		vec[i].y =
//			roll[1][0] * squareRollX + roll[1][1] * squareRollY + roll[1][2] * squareRollZ;
//		vec[i].z =
//			roll[2][0] * squareRollX + roll[2][1] * squareRollY + roll[2][2] * squareRollZ;
//
//		vec[i].x += SuqareWidht;
//		vec[i].y += SuqareHeight;
//		vec[i].z += SuqareDepth;
//	}
//}


GameScene::GameScene() 
{
	affineMove(vec2, 10, 10, 10);
	affineScale(vec3, 1.5f, 1.5f, 1.5f);
	affineRollX(vec4, PI / 3);
	affineRollY(vec5, PI / 3);
	affineRollZ(vec6, PI / 3);
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
	worldTransform_.translation_ = { 10.0f, 10.f, 10.0f };

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
					Vector4(255, 0, 255, 255)
				);
				PrimitiveDrawer::GetInstance()->DrawLine3d(
					vec3[i],
					vec3[vecConnection[i][k]],
					Vector4(255, 255, 0, 255)
				);
				PrimitiveDrawer::GetInstance()->DrawLine3d(
					vec4[i],
					vec4[vecConnection[i][k]],
					Vector4(0, 255, 255, 255)
				);
				PrimitiveDrawer::GetInstance()->DrawLine3d(
					vec5[i],
					vec5[vecConnection[i][k]],
					Vector4(0, 255, 0, 255)
				);
				PrimitiveDrawer::GetInstance()->DrawLine3d(
					vec6[i],
					vec6[vecConnection[i][k]],
					Vector4(255, 0, 0, 255)
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
