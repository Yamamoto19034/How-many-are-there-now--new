/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
//無限ループ

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"

//########## マクロ定義 ##########
#define GAME_WIDTH	1000	//画面の横の大きさ
#define GAME_HEIGHT	700		//画面の縦の大きさ
#define GAME_COLOR	32		//画面のカラービット

#define GAME_WINDOW_BAR	0					//タイトルバーはデフォルトにする
#define GAME_WINDOW_NAME	"GAME TITLE"	//ウィンドウのタイトル

#define GAME_FPS	60  //FPSの数値

//パスの長さ
#define PATH_MAX   255
#define NAME_MAX   255

//エラーメッセージ
#define IMAGE_LOAD_ERR_TITLE    TEXT("画像読み込みエラー")

//画像関連
#define IMAGE_START_IMAGE_PATH  TEXT(".\\IMAGE\\スタート画面.png")  //背景(スタート画面)の画像
#define IMAGE_PLAY_IMAGE_PATH   TEXT(".\\IMAGE\\森の中.png")		//背景(プレイ・エンド)の画像
#define IMAGE_MENU_IMAGE_PATH   TEXT(".\\IMAGE\\操作説明.png")		//ボタンの画像
#define IMAGE_MENU_BK_PATH      TEXT(".\\IMAGE\\menu_背景.png")		//背景(操作説明画面)の画像
#define IMAGE_END_CLEAR_PATH	TEXT(".\\IMAGE\\GameClear.png")		//クリアの画像
#define IMAGE_END_FAIL_PATH		TEXT(".\\IMAGE\\sippai.png")		//ゲームオーバーの画像
#define IMAGE_MENU_1_PATH		TEXT(".\\IMAGE\\操作説明-1.png")	//操作説明の1枚目
#define IMAGE_MENU_2_PATH		TEXT(".\\IMAGE\\操作説明-2.png")	//操作説明の2枚目
#define IMAGE_MESSAGE_1_PATH	TEXT(".\\IMAGE\\message-1.png")		//お客様からのメッセージ(成功パターン)
#define IMAGE_MESSAGE_2_PATH	TEXT(".\\IMAGE\\message-2.png")     //お客様からのメッセージ(失敗パターン)

//動物チップ関連
#define GAME_animal1_CHIP_PATH  TEXT(".\\IMAGE\\animal\\mapchip_1.png")  //チップの画像
#define ANIMAL_MAX				4

//画像分割関連
#define CHIP_DIV_WIDTH			565   //画像を分割する幅サイズ
#define CHIP_DIV_HEIGHT			660   //画像を分割する高さサイズ
#define GAME_animal1_DIV_TATE   2     //画像を縦に分割する数
#define GAME_animal1_DIV_YOKO   2     //画像を横に分割する数
#define CHIP_DIV_NUM GAME_animal1_DIV_TATE * GAME_animal1_DIV_YOKO  //画像を分割する総数

//マスク関連
#define EASY_HAVE_MASK				20		//マスクの上限(Easyモード)
#define EASY_GIVE_MASK_RANGE		5		//マスクのランダム数(Easyモード)

//フォントのパスの長さ
#define FONT_PATH_MAX			255

//フォント
#define FONT_TANUKI_PATH		TEXT(".\\FONT\\TanukiMagic.ttf")
#define FONT_TANUKI_NAME		TEXT("たぬき油性マジック")

//フォントのエラーメッセージ
#define FONT_INSTALL_ERR_TITLE	TEXT("フォントインストールエラー")
#define FONT_CREATE_ERR_TITLE	TEXT("フォント作成エラー")

//音楽のパス
#define MUSIC_START_BGM_PATH	TEXT(".\\MUSIC\\game_maoudamashii_7_event43.mp3")  //スタート画面のBGM
#define MUSIC_PLAY_BGM_PATH		TEXT(".\\MUSIC\\game_maoudamashii_7_event34.mp3")  //プレイ画面のBGM
#define MUSIC_END_CLEAR_PATH	TEXT(".\\MUSIC\\game_maoudamashii_7_event42.mp3")  //エンド画面(クリアパターン)の音楽
#define MUSIC_END_FAIL_PATH		TEXT(".\\MUSIC\\game_maoudamashii_8_orgel05.mp3")  //エンド画面(失敗パターン)の音楽

//エラーメッセージ
#define MUSIC_LOAD_ERR_TITLE	TEXT("音楽読み込みエラー")

#define GAME_TIME				5

enum GAME_SCENE {
	GAME_SCENE_START,  //スタート画面
	GAME_SCENE_PLAY,   //プレイ画面
	GAME_SCENE_END,    //エンド画面
	GAME_SCENE_MENU    //操作説明画面
};   //ゲームのシーン

enum GAME_JUDE {
	JUDE_CLEAR,  //成功
	JUDE_OVER    //失敗
};  //クリアか失敗か

typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];	//パス
	int handle;				//ハンドル
	int x;					//X位置
	int y;					//Y位置
	int width;				//幅
	int height;				//高さ
}IMAGE; //画像構造体

typedef struct STRCT_MENU_IMAGE
{
	IMAGE image;  //画像構造体
	BOOL IsDraw;  //描画できるか否か
}IMAGE_MENU;  //操作説明画面用

typedef struct STRUCT_ANIMAL
{
	char path[PATH_MAX];		//パス
	int handle[CHIP_DIV_NUM];   //分割した動物の画像ハンドルを取得
	int x;						//X位置
	int y;						//Y位置
	int width;					//幅
	int height;					//高さ
	BOOL IsDraw;				//動物を表示できるか
}MAPCHIP;  //マップチップ構造体

typedef struct STRUCT_FONT
{
	char path[FONT_PATH_MAX];   //パス
	char name[FONT_PATH_MAX];   //フォント名
	int handle;                 //ハンドル
	int size;					//大きさ
	int bold;					//太さ
	int type;					//タイプ
}FONT;   //フォント構造体

typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル
}MUSIC;  //音楽構造体

//グローバル変数
int StartTimeFps;				//測定開始時刻
int CountFps;					//カウンタ
float CalcFps;					//計算結果
int SampleNumFps = GAME_FPS;	//平均をとるサンプル数

//キーボードの入力を取得
char AllKeyState[256] = { 0 };
char OldAllKeyState[256] = { 0 };

//ゲームシーン
int GameScene;

//マップチップ関連
MAPCHIP animal[ANIMAL_MAX];
int GHandle[ANIMAL_MAX];
int order = 0;  //表示する順番を管理

//マスク関連
int Mask_num = 0;   //あげるマスクの個数
int Mask_sum = 0;   //マスクの合計値
int HaveMask = 0;   //各モードの上限マスク個数
int GiveMask = 0;   //あげるマスクのランダム数

//時間関連
double StartTime = 0;		//計測開始時間
double ElaTime = 0;		//残り時間
double TimeLimit = 0;
BOOL First_flg = TRUE;

//画像関連
IMAGE ImageSTARTBK;		//ゲームの背景(スタート画面)
IMAGE ImagePLAYENDBK;	//ゲームの背景(プレイ・エンド画面)
IMAGE ImageMENUBtn;		//ボタンの画像
IMAGE ImageMENUBK;		//ゲームの背景(説明画面)
IMAGE ImageEndClear;	//クリアの画像
IMAGE ImageEndFail;		//失敗の画像
IMAGE_MENU ImageMENU1;	//操作説明の1枚目
IMAGE_MENU ImageMENU2;  //操作説明の2枚目
IMAGE ImageMessage1;	//お客様からのメッセージ(成功パターン)
IMAGE ImageMessage2;    //お客様からのメッセージ(失敗パターン)

//フォント
FONT TANUKI;

//クリアか失敗か
int Jude;

//音楽関連
MUSIC START_BGM;		//スタート画面のBGM
MUSIC PLAY_BGM;			//プレイ画面のBGM
MUSIC END_CLEAR_BGM;	//エンド画面(クリアパターン)のBGM
MUSIC END_FAIL_BGM;		//エンド画面(失敗パターン)のBGM

//プロトタイプ宣言
VOID MY_FPS_UPDATE(VOID);		//FPS値を計測、更新する関数
VOID MY_FPS_DRAW(VOID);			//FPS値を描画する関数
VOID MY_FPS_WAIT(VOID);			//FPS値を計測し。待つ関数

VOID MY_ALL_KEYDOWN_UPDATE(VOID);  //キーの入力状態を更新する
BOOL MY_KEY_DOWN(int);			   //キーを押しているか、キーコードで判断する
BOOL MY_KEY_UP(int);			   //キーを押し上げたか、キーコードで判断する
BOOL MY_KEYDOWN_KEEP(int, int);    //キーを押し続けているか、キーコードで判断する
BOOL MY_KEYDOWN_1SECOND(int);      //キーを1秒間押し続けたか

VOID MY_START(VOID);		//スタート画面
VOID MY_START_PROC(VOID);   //スタート画面の処理
VOID MY_START_DRAW(VOID);   //スタート画面の描画

VOID MY_PLAY(VOID);		   //プレイ画面
VOID MY_PLAY_PROC(VOID);   //プレイ画面の処理
VOID MY_PLAY_DRAW(VOID);   //プレイ画面の描画

VOID MY_END(VOID);		  //エンド画面
VOID MY_END_PROC(VOID);   //エンド画面の処理
VOID MY_END_DRAW(VOID);   //エンド画面の描画

VOID MY_MENU(VOID);       //操作説明画面
VOID MY_MENU_PROC(VOID);  //操作説明画面の処理
VOID MY_MENU_DRAW(VOID);  //操作説明画面の描画

BOOL MY_LOAD_IMAGE(VOID);    //画像をまとめて読み込む関数
VOID MY_DELETE_IMAGE(VOID);  //画像をまとめて削除する関数
VOID MY_PICTURE_INIT(VOID);  //画像の消去・初期化する関数

BOOL MY_FONT_INSTALL_ONCE(VOID);    //フォントを一時的にインストール
VOID MY_FONT_UNINSTALL_ONCE(VOID);  //フォントを一時的にアンインストール
BOOL MY_FONT_CREATE(VOID);			//フォントを作成する
VOID MY_FONT_DELETE(VOID);			//フォントを削除する

BOOL MY_LOAD_MUSIC(VOID);			//音楽をまとめて読み込む関数
VOID MY_DELETE_MUSIC(VOID);			//音楽をまとめて削除する関数

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);						//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//指定の数値でウィンドウを表示する
	SetWindowStyleMode(GAME_WINDOW_BAR);		//タイトルバーはデフォルトにする
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));	//ウィンドウのタイトルの文字
	SetAlwaysRunFlag(TRUE);						//非アクティブでも実行する

	if (DxLib_Init() == -1) { return -1; }	//ＤＸライブラリ初期化処理

	//フォントを一時的にインストール
	if (MY_FONT_INSTALL_ONCE() == FALSE) { return -1; }

	//フォントハンドルを作成
	if (MY_FONT_CREATE() == FALSE) { return -1; }

	//画像を読み込む
	if (MY_LOAD_IMAGE() == FALSE) { return -1; }

	//音楽を読み込む
	if (MY_LOAD_MUSIC() == FALSE) { return -1; }

	GameScene = GAME_SCENE_START;   //ゲームシーンはスタート画面から

	SetDrawScreen(DX_SCREEN_BACK);	//Draw系関数は裏画面に描画

	//StartTime = GetNowCount();

	//無限ループ
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了

		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		MY_ALL_KEYDOWN_UPDATE();       //押しているキー状態を取得する

		MY_FPS_UPDATE();   //FPSの処理(更新)

		//シーンごとに処理を行う
		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();   //スタート画面
			break;
		case GAME_SCENE_PLAY:
			MY_PLAY();    //プレイ画面
			break;
		case GAME_SCENE_END:
			MY_END();     //エンド画面
			break;
		case GAME_SCENE_MENU:
			MY_MENU();    //操作説明画面
			break;
		}

		MY_FPS_DRAW();	   //FPSの処理(描画)

		ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画

		MY_FPS_WAIT();     //FPSの処理(待つ)
	}

	//画像ハンドルを破棄
	MY_DELETE_IMAGE();

	//フォントハンドルを破棄
	MY_FONT_DELETE();

	//一時的にインストールしたフォントをアンインストール
	MY_FONT_UNINSTALL_ONCE();

	//音楽ハンドルを破棄
	MY_DELETE_MUSIC();

	DxLib_End();	//ＤＸライブラリ使用の終了処理

	return 0;
}

//FPS値を計測、待つ関数
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0)  //1フレーム目なら時刻を記憶
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps)   //60フレーム目なら平均を計算
	{
		int now = GetNowCount();
		//現在の時間から、0フレームの時間を引き、FPSの数値で割る = 1FPS辺りの平均時間が計算される
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//FPS値を描画する関数
VOID MY_FPS_DRAW(VOID)
{
	//文字列を描画
	DrawFormatString(0, GAME_HEIGHT - 20, GetColor(255, 255, 255), "FPS:%.1f", CalcFps);
	return;
}

//FPS値を計測し、待つ関数
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;			//かかった時間
	int waitTime = CountFps * 1000 / GAME_FPS - resultTime; //待つべき時間

	if (waitTime > 0)
	{
		WaitTimer(waitTime);    //待つ
	}

	return;
}

//キーの入力状態を更新する関数
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];  //一時的に、現在のキーの入力状態を格納する

	//直前のキー入力を取っておく
	for (int i = 0; i < 256; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}

//キーを押しているか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
BOOL MY_KEY_DOWN(int KEY_INPUT_)
{
	//キーコードのキーを押している時
	if (AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;	//キーを押している
	}
	else
	{
		return FALSE;	//キーを押していない
	}
}


//キーを押し上げたか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
BOOL MY_KEY_UP(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] >= 1	//直前は押していて
		&& AllKeyState[KEY_INPUT_] == 0)	//今は押していないとき
	{
		return TRUE;	//キーを押し上げている
	}
	else
	{
		return FALSE;	//キーを押し上げていない
	}
}

//キーを押し続けているか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
//引　数：int：キーを押し続ける時間
BOOL MY_KEYDOWN_KEEP(int KEY_INPUT_, int DownTime)
{
	//押し続ける時間=秒数×FPS値
	//例）60FPSのゲームで、1秒間押し続けるなら、1秒×60FPS
	int UpdateTime = DownTime * GAME_FPS;

	if (AllKeyState[KEY_INPUT_] > UpdateTime)
	{
		return TRUE;	//押し続けている
	}
	else
	{
		return FALSE;	//押し続けていない
	}
}

//動物の画像変更用・操作説明画面用
BOOL MY_KEYDOWN_1SECOND(int KEY_INPUT_)
{
	//キーコードのキーを押している時
	if (AllKeyState[KEY_INPUT_] == 1)
	{
		return TRUE;	//キーを押している
	}
	else
	{
		return FALSE;	//キーを押していない
	}
}

//スタート画面
VOID MY_START(VOID)
{
	MY_START_PROC();    //スタート画面の処理
	MY_START_DRAW();    //スタート画面の描画

	return;
}

//スタート画面の処理
VOID MY_START_PROC(VOID)
{
	//BGMが流れていないなら
	if (CheckSoundMem(START_BGM.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * 50 / 100, START_BGM.handle);  //50%の音量にする
		PlaySoundMem(START_BGM.handle, DX_PLAYTYPE_LOOP);
	}

	//エンターキーを押したら、プレイシーンへ移動する
	if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
	{
		//プレイ画面に向けて準備
		HaveMask = EASY_HAVE_MASK;			//マスクの上限個数の設定
		GiveMask = EASY_GIVE_MASK_RANGE;	//上げるマスクのランダム数の設定
		GameScene = GAME_SCENE_PLAY;

		//BGMが流れているなら
		if (CheckSoundMem(START_BGM.handle) != 0)
		{
			StopSoundMem(START_BGM.handle);   //BGMを止める
		}
	}

	//シフトキー(左シフトキー or 右シフトキー)を押したら、操作説明画面に移動する
	if (MY_KEY_DOWN(KEY_INPUT_LSHIFT) || MY_KEY_DOWN(KEY_INPUT_RSHIFT) == TRUE)
	{
		GameScene = GAME_SCENE_MENU;
	}

	return;
}

//スタート画面の描画
VOID MY_START_DRAW(VOID)
{
	//背景を描画する
	DrawGraph(ImageSTARTBK.x, ImageSTARTBK.y, ImageSTARTBK.handle, TRUE);

	//操作説明画面へ促すボタン
	DrawGraph(ImageMENUBtn.x, ImageMENUBtn.y, ImageMENUBtn.handle, TRUE);

	return;
}

//操作説明画面
VOID MY_MENU(VOID)
{
	MY_MENU_PROC();     //操作説明画面の処理
	MY_MENU_DRAW();     //操作説明画面の描画

	return;
}

//操作説明画面の処理
VOID MY_MENU_PROC(VOID)
{
	if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
	{
		//スタート画面に戻る
		GameScene = GAME_SCENE_START;
	}

	//2つの説明画像を交互に切り替え
	if (MY_KEYDOWN_1SECOND(KEY_INPUT_RETURN) == TRUE)
	{
		if (ImageMENU1.IsDraw == TRUE) {
			ImageMENU1.IsDraw = FALSE;	//消去
			ImageMENU2.IsDraw = TRUE;	//表示
		}
		else {
			ImageMENU1.IsDraw = TRUE;	//表示
			ImageMENU2.IsDraw = FALSE;	//消去
		}
	}

	return;
}

//操作説明画面の描画
VOID MY_MENU_DRAW(VOID)
{
	//背景を描画する
	DrawGraph(ImageMENUBK.x, ImageMENUBK.y, ImageMENUBK.handle, TRUE);

	if(ImageMENU1.IsDraw == TRUE)  //説明画像の1枚目
		DrawGraph(ImageMENU1.image.x, ImageMENU1.image.y, ImageMENU1.image.handle, TRUE);
	if(ImageMENU2.IsDraw == TRUE)  //説明画像の2枚目
		DrawGraph(ImageMENU2.image.x, ImageMENU2.image.y, ImageMENU2.image.handle, TRUE);
	return;
}

//プレイ画面
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();    //プレイ画面の処理
	MY_PLAY_DRAW();    //プレイ画面の描画

	return;
}

//プレイ画面の処理
VOID MY_PLAY_PROC(VOID)
{
	if (First_flg == TRUE)
	{
		StartTime = GetNowCount();
		TimeLimit = GAME_TIME;
		First_flg = FALSE;
	}

	else
	{
		//エンターキーを押す際の行動パターン(マスクを「あげる」)
		if (MY_KEYDOWN_1SECOND(KEY_INPUT_RETURN) == TRUE)
		{
			//ElaTime = GetNowCount();

			//ElaTime = (TimeLimit - (GetNowCount() - (StartTime = GetNowCount())) / 1000);

			/*if (ElaTime <= 0)
			{
				GameScene = GAME_SCENE_MENU;
			}*/

			//▼▼▼▼▼考える時間が一定時間過ぎるとゲームオーバー(修正箇所多々残留)▼▼▼▼▼
			//ElaTime = (TimeLimit - (GetNowCount() - StartTime) / 1000);

			//if (ElaTime <= 0)
			//{
			//	Jude = JUDE_OVER;

			//	GameScene = GAME_SCENE_END;

			//	//画像の消去・初期化
			//	MY_PICTURE_INIT();

			//	return;
			//}
			//▲▲▲▲▲

			//BGMが流れていないなら
			if (CheckSoundMem(PLAY_BGM.handle) == 0)
			{
				//BGMの音量を下げる
				ChangeVolumeSoundMem(255 * 50 / 100, PLAY_BGM.handle);  //50%の音量にする
				PlaySoundMem(PLAY_BGM.handle, DX_PLAYTYPE_LOOP);
			}

			//加算していく
			Mask_sum += Mask_num;

			//乱数を取得
			Mask_num = GetRand(GiveMask);

			//一定量を超えたら終了
			if (Mask_sum > HaveMask)
			{
				Jude = JUDE_OVER;  //判定は「失敗」

				GameScene = GAME_SCENE_END;  //エンド画面に移動

				//画像の消去・初期化
				MY_PICTURE_INIT();

				//BGMが流れているなら
				if (CheckSoundMem(PLAY_BGM.handle) != 0)
				{
					StopSoundMem(PLAY_BGM.handle);   //BGMを止める
				}

				return;
			}

			//単体で表示する
			if (order == 0)
			{
				//描画する
				animal[ANIMAL_MAX - 1].IsDraw = FALSE;  //一個前の絵を消す
				animal[order].IsDraw = TRUE;			//表示
				order++;
			}
			else if (order == 3)
			{
				//描画
				animal[order - 1].IsDraw = FALSE;		//一個前の絵を消す
				animal[order].IsDraw = TRUE;			//表示
				order = 0;								//最初から
			}
			else
			{
				//描画
				animal[order - 1].IsDraw = FALSE;		//一個前の絵を消す
				animal[order].IsDraw = TRUE;			//表示
				order++;
			}
		}

		//デリートーキーを押す際の行動パターン(マスクを「あげない」)
		if (MY_KEYDOWN_1SECOND(KEY_INPUT_DELETE) == TRUE)
		{
			//成功パターン
			if ((Mask_sum + Mask_num) >= HaveMask)
			{
				Jude = JUDE_CLEAR;  //判定は「失敗」

				GameScene = GAME_SCENE_END;  //エンド画面に移動

				//画像の消去・初期化
				MY_PICTURE_INIT();

				//BGMが流れているなら
				if (CheckSoundMem(PLAY_BGM.handle) != 0)
				{
					StopSoundMem(PLAY_BGM.handle);   //BGMを止める
				}

				return;
			}
			//失敗パターン
			else if ((Mask_sum + Mask_num) < HaveMask)
			{
				Jude = JUDE_OVER;  //判定は「失敗」

				GameScene = GAME_SCENE_END;  //エンド画面に移動

				//画像の消去・初期化
				MY_PICTURE_INIT();

				//BGMが流れているなら
				if (CheckSoundMem(PLAY_BGM.handle) != 0)
				{
					StopSoundMem(PLAY_BGM.handle);   //BGMを止める
				}

				return;
			}
		}
	}

	return;
}

//プレイ画面の描画
VOID MY_PLAY_DRAW(VOID)
{
	//プレイ画面の背景
	DrawGraph(ImagePLAYENDBK.x, ImagePLAYENDBK.y, ImagePLAYENDBK.handle, TRUE);

	//DrawFormatStringToHandle(0, 200, GetColor(255, 255, 255), TANUKI.handle, "%dミリ秒", ElaTime);
	//DrawFormatStringToHandle(0, 200, GetColor(255, 255, 255), TANUKI.handle, "%dミリ秒", StartTime);

	//トークシーンの背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);  //透明度を25%上げる
	DrawBox(0, GAME_HEIGHT - 180, GAME_WIDTH, GAME_HEIGHT, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  //元に戻す

	//動物の情報を生成
	for (int cnt = 0; cnt < ANIMAL_MAX; cnt++)
	{
		//描画できるなら
		if (animal[cnt].IsDraw == TRUE)
		{
			//画像を1.5倍に縮小表示
			DrawExtendGraph(
				animal[cnt].x, animal[cnt].y,
				animal[cnt].x + animal[cnt].width / 1.5, animal[cnt].y + (int)animal[cnt].height / 1.5,
				GHandle[cnt], TRUE
			);

			//欲しいマスクの表示
			DrawFormatStringToHandle(170, GAME_HEIGHT - 170, GetColor(255, 255, 255), TANUKI.handle, "マスク %d個 ちょうだい！！", Mask_num);
			DrawFormatStringToHandle(0, 0, GetColor(255, 255, 255), TANUKI.handle, "%d個", Mask_sum);

			//「あげる？」「あげない？」の追加
			DrawBox(200, GAME_HEIGHT - 100, 410, GAME_HEIGHT - 50, GetColor(255, 0, 0), TRUE);
			DrawStringToHandle(200, GAME_HEIGHT - 100, "あげる？", GetColor(255, 255, 255), TANUKI.handle);
			DrawBox(500, GAME_HEIGHT - 100, 770, GAME_HEIGHT - 50, GetColor(0, 0, 255), TRUE);
			DrawStringToHandle(500, GAME_HEIGHT - 100, "あげない？", GetColor(255, 255, 255), TANUKI.handle);
		}
	}

	return;
}

//エンド画面
VOID MY_END(VOID)
{
	MY_END_PROC();    //エンド画面の処理
	MY_END_DRAW();    //エンド画面の描画

	return;
}

//エンド画面の処理
VOID MY_END_PROC(VOID)
{
	switch (Jude)
	{
	//クリアパターン
	case JUDE_CLEAR:
		//BGMが流れていないなら
		if (CheckSoundMem(END_CLEAR_BGM.handle) == 0)
		{
			//BGMの音量を下げる
			ChangeVolumeSoundMem(255 * 50 / 100, END_CLEAR_BGM.handle);  //50%の音量にする
			PlaySoundMem(END_CLEAR_BGM.handle, DX_PLAYTYPE_LOOP);
		}
		break;

	//失敗パターン
	case JUDE_OVER:
		//BGMが流れていないなら
		if (CheckSoundMem(END_FAIL_BGM.handle) == 0)
		{
			//BGMの音量を下げる
			ChangeVolumeSoundMem(255 * 50 / 100, END_FAIL_BGM.handle);  //50%の音量にする
			PlaySoundMem(END_FAIL_BGM.handle, DX_PLAYTYPE_LOOP);
		}
		break;
	}

	//バックスペースキーを押したら、スタートシーンへ移動する
	if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
	{
		HaveMask = 0;					//初期化
		GiveMask = 0;					//初期化
		GameScene = GAME_SCENE_START;   //スタート画面に移動

		//BGMが流れているなら(クリアパターン)
		if (CheckSoundMem(END_CLEAR_BGM.handle) != 0)
		{
			StopSoundMem(END_CLEAR_BGM.handle);   //BGMを止める
		}
		//BGMが流れているなら(失敗パターン)
		if (CheckSoundMem(END_FAIL_BGM.handle) != 0)
		{
			StopSoundMem(END_FAIL_BGM.handle);   //BGMを止める
		}
	}

	return;
}

//エンド画面の描画
VOID MY_END_DRAW(VOID)
{
	//背景を描画
	DrawGraph(ImagePLAYENDBK.x, ImagePLAYENDBK.y, ImagePLAYENDBK.handle, TRUE);

	switch (Jude)
	{
	//クリアパターン
	case JUDE_CLEAR:
		DrawGraph(ImageEndClear.x, ImageEndClear.y, ImageEndClear.handle, TRUE);
		DrawGraph(ImageMessage1.x, ImageMessage1.y, ImageMessage1.handle, TRUE);
		break;

	//失敗パターン
	case JUDE_OVER:
		DrawGraph(ImageEndFail.x, ImageEndFail.y, ImageEndFail.handle, TRUE);
		DrawGraph(ImageMessage2.x, ImageMessage2.y, ImageMessage2.handle, TRUE);
		break;
	}

	return;
}

//画像をまとめて読み込む関数
BOOL MY_LOAD_IMAGE(VOID)
{
	//スタート画面の背景画像
	strcpy_s(ImageSTARTBK.path, IMAGE_START_IMAGE_PATH);  //パスの設定
	ImageSTARTBK.handle = LoadGraph(ImageSTARTBK.path);   //読み込み
	if (ImageSTARTBK.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_START_IMAGE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSTARTBK.handle, &ImageSTARTBK.width, &ImageSTARTBK.height);  //幅と高さを取得
	ImageSTARTBK.x = GAME_WIDTH / 2 - ImageSTARTBK.width / 2;		//X位置を決める
	ImageSTARTBK.y = GAME_HEIGHT / 2 - ImageSTARTBK.height / 2;     //Y位置を決める

	//プレイ画面とエンド画面の背景画像
	strcpy_s(ImagePLAYENDBK.path, IMAGE_PLAY_IMAGE_PATH);  //パスの設定
	ImagePLAYENDBK.handle = LoadGraph(ImagePLAYENDBK.path);   //読み込み
	if (ImagePLAYENDBK.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_PLAY_IMAGE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImagePLAYENDBK.handle, &ImagePLAYENDBK.width, &ImagePLAYENDBK.height);  //幅と高さを取得
	ImagePLAYENDBK.x = GAME_WIDTH / 2 - ImagePLAYENDBK.width / 2;	//X位置を決める
	ImagePLAYENDBK.y = GAME_HEIGHT / 2 - ImagePLAYENDBK.height / 2; //Y位置を決める

	//操作説明画面へ促すためのボタン
	strcpy_s(ImageMENUBtn.path, IMAGE_MENU_IMAGE_PATH);  //パスの設定
	ImageMENUBtn.handle = LoadGraph(ImageMENUBtn.path);   //読み込み
	if (ImageMENUBtn.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_IMAGE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageMENUBtn.handle, &ImageMENUBtn.width, &ImageMENUBtn.height);  //幅と高さを取得
	ImageMENUBtn.x = GAME_WIDTH - ImageMENUBtn.width - 20;			//X位置を決める
	ImageMENUBtn.y = GAME_HEIGHT - ImageMENUBtn.height - 20;		//Y位置を決める

	//操作説明画面の背景
	strcpy_s(ImageMENUBK.path, IMAGE_MENU_BK_PATH);  //パスの設定
	ImageMENUBK.handle = LoadGraph(ImageMENUBK.path);   //読み込み
	if (ImageMENUBK.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageMENUBK.handle, &ImageMENUBK.width, &ImageMENUBK.height);  //幅と高さを取得
	ImageMENUBK.x = GAME_WIDTH / 2 - ImageMENUBK.width / 2;			//X位置を決める
	ImageMENUBK.y = GAME_HEIGHT / 2 - ImageMENUBK.height / 2;		//Y位置を決める

	//動物チップ
	int animalRes = LoadDivGraph(
		GAME_animal1_CHIP_PATH,										//動物チップのパス
		CHIP_DIV_NUM, GAME_animal1_DIV_TATE, GAME_animal1_DIV_YOKO, //分割する数
		CHIP_DIV_WIDTH, CHIP_DIV_HEIGHT,							//画像を分割する幅と高さ
		GHandle
	);

	//正しく分割できなかったら
	if (animalRes == -1)
	{
		MessageBox(GetMainWindowHandle(), GAME_animal1_CHIP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//それぞれ幅と高さを取得
	for (int cnt = 0; cnt < ANIMAL_MAX; cnt++)
	{
		GetGraphSize(GHandle[cnt], &animal[cnt].width, &animal[cnt].height);
	}

	//情報を与える
	for (int cnt = 0; cnt < ANIMAL_MAX; cnt++)
	{
		strcpyDx(animal[cnt].path, TEXT(GAME_animal1_CHIP_PATH));						//パス
		animal[cnt].width = animal[0].width;											//幅
		animal[cnt].height = animal[0].height;											//高さ
		animal[cnt].x = (GAME_WIDTH / 2 - animal[0].width / 2) + animal[0].width / 10;	//X座標
		animal[cnt].y = animal[0].height / 10;											//Y座標
		animal[cnt].IsDraw = FALSE;														//描画できるか(初期値は 描画できない)
	}

	//クリアの画像
	strcpy_s(ImageEndClear.path, IMAGE_END_CLEAR_PATH);  //パスの設定
	ImageEndClear.handle = LoadGraph(ImageEndClear.path);   //読み込み
	if (ImageEndClear.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_CLEAR_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndClear.handle, &ImageEndClear.width, &ImageEndClear.height);  //幅と高さを取得
	ImageEndClear.x = GAME_WIDTH / 2 - ImageEndClear.width / 2;			//X位置を決める
	ImageEndClear.y = GAME_HEIGHT / 2 - ImageEndClear.height / 2 - 75;  //Y位置を決める

	//失敗の画像
	strcpy_s(ImageEndFail.path, IMAGE_END_FAIL_PATH);  //パスの設定
	ImageEndFail.handle = LoadGraph(ImageEndFail.path);   //読み込み
	if (ImageEndFail.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_FAIL_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndFail.handle, &ImageEndFail.width, &ImageEndFail.height);  //幅と高さを取得
	ImageEndFail.x = GAME_WIDTH / 2 - ImageEndFail.width / 2;			//X位置を決める
	ImageEndFail.y = GAME_HEIGHT / 2 - ImageEndFail.height / 2 - 75;    //Y位置を決める

	//操作説明の1枚目の背景
	strcpy_s(ImageMENU1.image.path, IMAGE_MENU_1_PATH);  //パスの設定
	ImageMENU1.image.handle = LoadGraph(ImageMENU1.image.path);   //読み込み
	if (ImageMENU1.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_1_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageMENU1.image.handle, &ImageMENU1.image.width, &ImageMENU1.image.height);  //幅と高さを取得
	ImageMENU1.image.x = 0;				//X位置を決める
	ImageMENU1.image.y = 0;				//Y位置を決める
	ImageMENU1.IsDraw = TRUE;			//最初は描画できる

	//操作説明の2枚目の背景
	strcpy_s(ImageMENU2.image.path, IMAGE_MENU_2_PATH);  //パスの設定
	ImageMENU2.image.handle = LoadGraph(ImageMENU2.image.path);   //読み込み
	if (ImageMENU2.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_MENU_2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageMENU2.image.handle, &ImageMENU2.image.width, &ImageMENU2.image.height);  //幅と高さを取得
	ImageMENU2.image.x = 0;				//X位置を決める
	ImageMENU2.image.y = 0;				//Y位置を決める
	ImageMENU2.IsDraw = FALSE;			//最初は描画しない

	//お客様からのメッセージ(成功パターン)
	strcpy_s(ImageMessage1.path, IMAGE_MESSAGE_1_PATH);  //パスの設定
	ImageMessage1.handle = LoadGraph(ImageMessage1.path);   //読み込み
	if (ImageMessage1.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_MESSAGE_1_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageMessage1.handle, &ImageMessage1.width, &ImageMessage1.height);  //幅と高さを取得
	ImageMessage1.x = GAME_WIDTH / 2 - ImageMessage1.width / 2;			//X位置を決める
	ImageMessage1.y = ImageEndClear.y + ImageEndClear.height;			//Y位置を決める

	//お客様からのメッセージ(失敗パターン)
	strcpy_s(ImageMessage2.path, IMAGE_MESSAGE_2_PATH);  //パスの設定
	ImageMessage2.handle = LoadGraph(ImageMessage2.path);   //読み込み
	if (ImageMessage2.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_MESSAGE_2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageMessage2.handle, &ImageMessage2.width, &ImageMessage2.height);  //幅と高さを取得
	ImageMessage2.x = GAME_WIDTH / 2 - ImageMessage2.width / 2;			//X位置を決める
	ImageMessage2.y = ImageEndFail.y + ImageEndFail.height;				//Y位置を決める

	return TRUE;
}

//画像をまとめて削除する関数
VOID MY_DELETE_IMAGE(VOID)
{
	//背景の画像
	DeleteGraph(ImageSTARTBK.handle);
	DeleteGraph(ImagePLAYENDBK.handle);
	DeleteGraph(ImageMENUBtn.handle);
	DeleteGraph(ImageMENUBK.handle);

	//動物チップ
	for (int i_num = 0; i_num < CHIP_DIV_NUM; i_num++)
	{
		DeleteGraph(animal[0].handle[i_num]);
	}

	//成功・失敗の画像
	DeleteGraph(ImageEndClear.handle);
	DeleteGraph(ImageEndFail.handle);

	//操作説明の画像
	DeleteGraph(ImageMENU1.image.handle);
	DeleteGraph(ImageMENU2.image.handle);

	//メッセージの画像
	DeleteGraph(ImageMessage1.handle);
	DeleteGraph(ImageMessage2.handle);

	return;
}

//画像の消去・初期化
VOID MY_PICTURE_INIT(VOID)
{
	//終了する際は全て消す
	for (int cnt = 0; cnt < ANIMAL_MAX; cnt++)
	{
		animal[cnt].IsDraw = FALSE;
	}
	//再開しても最初から
	order = 0;
	//初期化
	Mask_num = 0;
	Mask_sum = 0;
	First_flg = TRUE;

	return;
}

//フォントを一時的にインストール
BOOL MY_FONT_INSTALL_ONCE(VOID)
{
	//フォントを一時的に読み込み
	if (AddFontResourceEx(FONT_TANUKI_PATH, FR_PRIVATE, NULL) == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), FONT_TANUKI_NAME, FONT_INSTALL_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//フォントを一時的にアンインストール
VOID MY_FONT_UNINSTALL_ONCE(VOID)
{
	//フォントを一時的にアンインストール
	RemoveFontResourceEx(FONT_TANUKI_PATH, FR_PRIVATE, NULL);

	return;
}

//フォントを読み込む
BOOL MY_FONT_CREATE(VOID)
{
	//フォントデータを作成
	strcpy_s(TANUKI.path, sizeof(TANUKI.path), FONT_TANUKI_PATH);  //パスをコピー
	strcpy_s(TANUKI.name, sizeof(TANUKI.name), FONT_TANUKI_NAME);  //フォント名をコピー
	TANUKI.handle = -1;							//ハンドルを初期化
	TANUKI.size = 50;								//サイズ: 50
	TANUKI.bold = 4;								//太さ: 4
	TANUKI.type = DX_FONTTYPE_ANTIALIASING_EDGE;   //アンチエイリアシング付き

	//フォントハンドル作成
	TANUKI.handle = CreateFontToHandle(TANUKI.name, TANUKI.size, TANUKI.bold, TANUKI.type);
	//フォントハンドルを作成できないときエラー
	if (TANUKI.handle == -1) { MessageBox(GetMainWindowHandle(), FONT_TANUKI_NAME, FONT_CREATE_ERR_TITLE, MB_OK); return FALSE; }

	return TRUE;
}

//フォントを削除する
VOID MY_FONT_DELETE(VOID)
{
	//フォントデータを削除
	DeleteFontToHandle(TANUKI.handle);

	return;
}

//音楽をまとめて読み込む関数
BOOL MY_LOAD_MUSIC(VOID)
{
	//スタート画面の音楽
	strcpy_s(START_BGM.path, MUSIC_START_BGM_PATH);
	START_BGM.handle = LoadSoundMem(START_BGM.path);
	if (START_BGM.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_START_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//プレイ画面の音楽
	strcpy_s(PLAY_BGM.path, MUSIC_PLAY_BGM_PATH);
	PLAY_BGM.handle = LoadSoundMem(PLAY_BGM.path);
	if (PLAY_BGM.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_PLAY_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//エンド画面(クリアパターン)の音楽
	strcpy_s(END_CLEAR_BGM.path, MUSIC_END_CLEAR_PATH);
	END_CLEAR_BGM.handle = LoadSoundMem(END_CLEAR_BGM.path);
	if (END_CLEAR_BGM.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_END_CLEAR_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//エンド画面(失敗パターン)の音楽
	strcpy_s(END_FAIL_BGM.path, MUSIC_END_FAIL_PATH);
	END_FAIL_BGM.handle = LoadSoundMem(END_FAIL_BGM.path);
	if (END_FAIL_BGM.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_END_FAIL_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//音楽をまとめて削除する関数
VOID MY_DELETE_MUSIC(VOID)
{
	DeleteSoundMem(START_BGM.handle);
	DeleteSoundMem(PLAY_BGM.handle);
	DeleteSoundMem(END_CLEAR_BGM.handle);
	DeleteSoundMem(END_FAIL_BGM.handle);

	return;
}