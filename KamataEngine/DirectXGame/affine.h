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

//平行移動の関数
void affineMove(Vector3 vec_[], float moveX, float moveY, float moveZ);


//拡大縮小の関数 動かしたいベクトル、x方向の拡大率、y方向の拡大率、z方向の拡大率
void affineScale(Vector3 vec[], float scaleX, float scaleY, float scaleZ);

//回転X　回転させたいベクトル、角度(ラジアン)
void affineRollX(Vector3 vec[], float roll_);

//回転Y　回転させたいベクトル、角度(ラジアン)
void affineRollY(Vector3 vec[], float roll_);

//回転Z　回転させたいベクトル、角度(ラジアン)
void affineRollZ(Vector3 vec[], float roll_);