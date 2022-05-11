#include <Novice.h>
#include <math.h>
#define PI 3.141592653589

const float SuqareWidht = 128.0;	//立方体の横幅
const float SuqareHeight = 128.0;	//立方体の立幅

//平行移動の関数　動かしたいベクトル、x座標、y座標
void affineParalellMove(float(*box)[3], float moveX, float moveY)
{
	float move[3][3] = {
	  {1.0f, 0.0f, moveX},
	  {0.0f,1.0f, moveY},
	  {0.0f, 0.0f, 1.0f}
	};

	//平行移動
	for (int i = 0; i < 4; i++) {
		box[i][0] = move[0][0] * box[i][0] + move[0][1] * box[i][1] + move[0][2] * box[i][2];
		box[i][1] = move[1][0] * box[i][0] + move[1][1] * box[i][1] + move[1][2] * box[i][2];
		box[i][2] = move[2][0] * box[i][0] + move[2][1] * box[i][1] + move[2][2] * box[i][2];
	}
}

//拡大縮小の関数 動かしたいベクトル、x方向の拡大率、y方向の拡大率
void affineScale(float(*box)[3], float scaleX, float scaleY)
{
	//拡大縮小の行列
	float scale[3][3] = {
	  {scaleX, 0.0f, 0},
	  {0.0f, scaleY, 0},
	  {0.0f, 0.0f, 1},
	};

	//保存用の変数
	float squareScaleX = 0.0f;
	float squareScaleY = 0.0f;

	//拡大縮小	左上原点
	for (int i = 0; i < 4; i++) {
		squareScaleX = box[i][0] - SuqareWidht;
		squareScaleY = box[i][1] - SuqareWidht;

		box[i][0] =
			scale[0][0] * squareScaleX + scale[0][1] * squareScaleY + scale[0][2] * box[i][2];
		box[i][1] =
			scale[1][0] * squareScaleX + scale[1][1] * squareScaleY + scale[1][2] * box[i][2];
		box[i][2] =
			scale[2][0] * squareScaleX + scale[2][1] * squareScaleY + scale[2][2] * box[i][2];

		box[i][0] += SuqareWidht;
		box[i][1] += SuqareHeight;
	}
}

//回転の関数　回転させたいベクトル、角度(ラジアン)
void affineRoll(float(*box)[3], float roll_)
{
	//回転の行列
	float roll[3][3] = {
	  {cos(roll_), -sin(roll_), 0},
	  {sin(roll_), cos(roll_), 0},
	  {0.0f,0.0f, 1},
	};

	float squareRollX = 0.0f;
	float squareRollY = 0.0f;
	//回転	左上原点
	for (int i = 0; i < 4; i++) {
		squareRollX = box[i][0] - SuqareWidht;
		squareRollY = box[i][1] - SuqareHeight;

		box[i][0] = squareRollX * roll[0][0] + squareRollY * roll[0][1];
		box[i][1] = squareRollX * roll[1][0] + squareRollY * roll[1][1];

		box[i][0] += SuqareWidht;
		box[i][1] += SuqareHeight;
	}
}

const char kWindowTitle[] = "LE2B_02_アスマ_ショウタ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//反時計回りの座標
	float box[4][3] = {
	  {128.0f, 128.0f, 1.0f},
	  {128.0f, 256.0f, 1.0f},
	  {256.0f, 256.0f, 1.0f},
	  {256.0f,  128.0f, 1.0f},
	};
	float box2[4][3] = {
	  {128.0f, 128.0f, 1.0f},
	  {128.0f, 256.0f, 1.0f},
	  {256.0f, 256.0f, 1.0f},
	  {256.0f, 128.0f, 1.0f},
	};
	float box3[4][3] = {
	  {128.0f, 128.0f, 1.0f},
	  {128.0f, 256.0f, 1.0f},
	  {256.0f, 256.0f, 1.0f},
	  {256.0f, 128.0f, 1.0f},
	};
	float box4[4][3] = {
	  {128.0f, 128.0f, 1.0f},
	  {128.0f, 256.0f, 1.0f},
	  {256.0f, 256.0f, 1.0f},
	  {256.0f, 128.0f, 1.0f},
	};

	//拡大縮小の行列
	float scale[3][3] = {
	  {2.0f, 0.0f, 0},
	  {0.0f, 2.0f, 0},
	  {0.0f, 0.0f, 1},
	};

	//平行移動
	affineParalellMove(box, 100.0f, 100.0f);

	//拡大縮小
	affineScale(box2, 2.0f, 2.0f);

	//回転
	affineRoll(box3, PI / 3);


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		//平行移動の行列

		///
		/// ↓描画処理ここから
		///

		//平行移動
		for (int i = 0; i < 4; i++) {
			Novice::DrawLine(
				box[i][0], box[i][1], box[(i + 1) % 4][0], box[(i + 1) % 4][1], 0x86BD3EFF);
			Novice::DrawLine(
				box2[i][0], box2[i][1], box2[(i + 1) % 4][0], box2[(i + 1) % 4][1], 0x86BD3EFF);
			Novice::DrawLine(
				box3[i][0], box3[i][1], box3[(i + 1) % 4][0], box3[(i + 1) % 4][1], 0x86BD3EFF);
			Novice::DrawLine(
				box4[i][0], box4[i][1], box4[(i + 1) % 4][0], box4[(i + 1) % 4][1], 0x86BD3EFF);
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}