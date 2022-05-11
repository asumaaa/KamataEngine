#include "affine.h"
#include "math.h"

//原点からの距離
float SuqareWidht = 0.0f;
float SuqareHeight = 0.0f;
float SuqareDepth = 0.0f;

//平行移動の関数
void affineMove(Vector3 vec_[], float moveX, float moveY, float moveZ)
{
	float move_[4][4]
	{
		{1.0f,0.0f,0.0f,moveX},
		{0.0f,1.0f,0.0f,moveY},
		{0.0f,0.0f,1.0f,moveZ},
		{0.0f,0.0f,0.0f,1.0f},
	};

	//平行移動
	for (int i = 0; i < 8; i++) {
		vec_[i].x = move_[0][0] * vec_[i].x + move_[0][1] * vec_[i].x + move_[0][2] * vec_[i].x + move_[0][3] * 1.0f;
		vec_[i].y = move_[1][0] * vec_[i].y + move_[1][1] * vec_[i].y + move_[1][2] * vec_[i].y + move_[1][3] * 1.0f;
		vec_[i].z = move_[2][0] * vec_[i].z + move_[2][1] * vec_[i].z + move_[2][2] * vec_[i].z + move_[2][3] * 1.0f;
	}
}

//拡大縮小の関数 動かしたいベクトル、x方向の拡大率、y方向の拡大率、z方向の拡大率
void affineScale(Vector3 vec[], float scaleX, float scaleY, float scaleZ)
{
	//拡大縮小の行列
	float scale[4][4] = {
		{scaleX	,0.0f	,0.0f	,0.0f},
		{0.0f	,scaleY	,0.0f	,0.0f},
		{0.0f	,0.0f	,scaleZ	,0.0f},
		{0.0f	,0.0f	,0.0f	,1.0f},
	};

	//保存用の変数
	float squareScaleX = 0.0f;
	float squareScaleY = 0.0f;
	float squareScaleZ = 0.0f;

	//拡大縮小	左上原点
	for (int i = 0; i < 8; i++) {
		squareScaleX = vec[i].x - SuqareWidht;
		squareScaleY = vec[i].y - SuqareWidht;
		squareScaleZ = vec[i].z - SuqareDepth;

		vec[i].x =
			scale[0][0] * squareScaleX + scale[0][1] * squareScaleX + scale[0][2] * squareScaleX;
		vec[i].y =
			scale[1][0] * squareScaleY + scale[1][1] * squareScaleY + scale[1][2] * squareScaleY;
		vec[i].z =
			scale[2][0] * squareScaleZ + scale[2][1] * squareScaleZ + scale[2][2] * squareScaleZ;

		vec[i].x += SuqareWidht;
		vec[i].y += SuqareHeight;
		vec[i].z += SuqareDepth;
	}
}

//回転X　回転させたいベクトル、角度(ラジアン)
void affineRollX(Vector3 vec[], float roll_)
{
	//回転の行列
	float roll[4][4] = {
		{1.0f	,0.0f		,0.0f			,0.0f},
		{0.0f	,cos(roll_)	,-sin(roll_)	,0.0f},
		{0.0f	,sin(roll_)	,cos(roll_)		,0.0f},
		{0.0f	,0.0f		,0.0f			,1.0f},
	};

	float squareRollX = 0.0f;
	float squareRollY = 0.0f;
	float squareRollZ = 0.0f;
	//回転	左上原点
	for (int i = 0; i < 8; i++) {
		squareRollX = vec[i].x - SuqareWidht;
		squareRollY = vec[i].y - SuqareHeight;
		squareRollZ = vec[i].z - SuqareDepth;

		vec[i].x =
			roll[0][0] * squareRollX + roll[0][1] * squareRollY + roll[0][2] * squareRollZ;
		vec[i].y =
			roll[1][0] * squareRollX + roll[1][1] * squareRollY + roll[1][2] * squareRollZ;
		vec[i].z =
			roll[2][0] * squareRollX + roll[2][1] * squareRollY + roll[2][2] * squareRollZ;

		vec[i].x += SuqareWidht;
		vec[i].y += SuqareHeight;
		vec[i].z += SuqareDepth;
	}
}

//回転Y　回転させたいベクトル、角度(ラジアン)
void affineRollY(Vector3 vec[], float roll_)
{
	//回転の行列
	float roll[4][4] = {
		{cos(roll_)		,0.0f	,sin(roll_)		,0.0f},
		{0.0f			,1.0f	,0.0f			,0.0f},
		{-sin(roll_)	,0.0f	,cos(roll_)		,0.0f},
		{0.0f			,0.0f	,0.0f			,1.0f},
	};

	float squareRollX = 0.0f;
	float squareRollY = 0.0f;
	float squareRollZ = 0.0f;
	//回転	左上原点
	for (int i = 0; i < 8; i++) {
		squareRollX = vec[i].x - SuqareWidht;
		squareRollY = vec[i].y - SuqareHeight;
		squareRollZ = vec[i].z - SuqareDepth;

		vec[i].x =
			roll[0][0] * squareRollX + roll[0][1] * squareRollY + roll[0][2] * squareRollZ;
		vec[i].y =
			roll[1][0] * squareRollX + roll[1][1] * squareRollY + roll[1][2] * squareRollZ;
		vec[i].z =
			roll[2][0] * squareRollX + roll[2][1] * squareRollY + roll[2][2] * squareRollZ;

		vec[i].x += SuqareWidht;
		vec[i].y += SuqareHeight;
		vec[i].z += SuqareDepth;
	}
}

//回転Z　回転させたいベクトル、角度(ラジアン)
void affineRollZ(Vector3 vec[], float roll_)
{
	//回転の行列
	float roll[4][4] = {
		{cos(roll_)		,-sin(roll_)	,0.0f		,0.0f},
		{sin(roll_)		,cos(roll_)		,0.0f		,0.0f},
		{0.0f			,0.0f			,1.0f		,0.0f},
		{0.0f			,0.0f			,0.0f		,1.0f},
	};

	float squareRollX = 0.0f;
	float squareRollY = 0.0f;
	float squareRollZ = 0.0f;
	//回転	左上原点
	for (int i = 0; i < 8; i++) {
		squareRollX = vec[i].x - SuqareWidht;
		squareRollY = vec[i].y - SuqareHeight;
		squareRollZ = vec[i].z - SuqareDepth;

		vec[i].x =
			roll[0][0] * squareRollX + roll[0][1] * squareRollY + roll[0][2] * squareRollZ;
		vec[i].y =
			roll[1][0] * squareRollX + roll[1][1] * squareRollY + roll[1][2] * squareRollZ;
		vec[i].z =
			roll[2][0] * squareRollX + roll[2][1] * squareRollY + roll[2][2] * squareRollZ;

		vec[i].x += SuqareWidht;
		vec[i].y += SuqareHeight;
		vec[i].z += SuqareDepth;
	}
}
