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

//���s�ړ��̊֐�
void affineMove(Vector3 vec_[], float moveX, float moveY, float moveZ);


//�g��k���̊֐� �����������x�N�g���Ax�����̊g�嗦�Ay�����̊g�嗦�Az�����̊g�嗦
void affineScale(Vector3 vec[], float scaleX, float scaleY, float scaleZ);

//��]X�@��]���������x�N�g���A�p�x(���W�A��)
void affineRollX(Vector3 vec[], float roll_);

//��]Y�@��]���������x�N�g���A�p�x(���W�A��)
void affineRollY(Vector3 vec[], float roll_);

//��]Z�@��]���������x�N�g���A�p�x(���W�A��)
void affineRollZ(Vector3 vec[], float roll_);