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

//アフィン変換の平行移動 ベクトル、x移動量、y移動量、z移動量
void affineMove(Vector3 vec_[], float moveX, float moveY, float moveZ);

void affineScale(Vector3 vec[], float scaleX, float scaleY, float scaleZ);

void affineRollX(Vector3 vec[], float roll_)