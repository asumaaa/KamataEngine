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

//�A�t�B���ϊ��̕��s�ړ� �x�N�g���Ax�ړ��ʁAy�ړ��ʁAz�ړ���
void affineMove(Vector3 vec_[], float moveX, float moveY, float moveZ);

void affineScale(Vector3 vec[], float scaleX, float scaleY, float scaleZ);

void affineRollX(Vector3 vec[], float roll_)