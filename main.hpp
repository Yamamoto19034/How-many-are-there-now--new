#pragma once

#include "DxLib.h"

//########## マクロ定義 ##########
#define GAME_WIDTH						1000	//画面の横の大きさ
#define GAME_HEIGHT						700		//画面の縦の大きさ
#define GAME_COLOR						32		//画面のカラービット

#define GAME_WINDOW_BAR					0					//タイトルバーはデフォルトにする
#define GAME_WINDOW_NAME				"あれ、今何個？"	//ウィンドウのタイトル

#define GAME_FPS						60  //FPSの数値

//パスの長さ
#define PATH_MAX						255
#define NAME_MAX						255

//エラーメッセージ
#define IMAGE_LOAD_ERR_TITLE			TEXT("画像読み込みエラー")

//画像関連	
#define IMAGE_START_BG_PATH				TEXT(".\\IMAGE\\スタート画面.png")		//背景(スタート画面)の画像
#define IMAGE_TITLE_PATH				TEXT(".\\IMAGE\\title.png")				//タイトル画像
#define IMAGE_PLAY_BG_PATH				TEXT(".\\IMAGE\\森の中.png")			//背景(プレイ・エンド)の画像
#define IMAGE_MENU_BUTTON_PATH			TEXT(".\\IMAGE\\操作説明.png")			//ボタンの画像(ルール説明行き)
#define IMAGE_MENU_BG_PATH				TEXT(".\\IMAGE\\menu_背景.png")			//背景(操作説明画面・ルール説明画面)の画像
#define IMAGE_END_CLEAR_PATH			TEXT(".\\IMAGE\\GameClear.png")			//クリアの画像
#define IMAGE_END_FAIL_PATH				TEXT(".\\IMAGE\\sippai.png")			//ゲームオーバーの画像
#define IMAGE_MENU_1_PATH				TEXT(".\\IMAGE\\操作説明-1.png")		//操作説明の1枚目
#define IMAGE_MENU_2_PATH				TEXT(".\\IMAGE\\操作説明-2.png")		//操作説明の2枚目
#define IMAGE_MESSAGE_1_PATH			TEXT(".\\IMAGE\\message-1.png")			//お客様からのメッセージ(成功パターン)
#define IMAGE_MESSAGE_2_PATH			TEXT(".\\IMAGE\\message-2.png")			//お客様からのメッセージ(失敗パターン)
#define IMAGE_BACK_BACKSPACE_KEY_PATH	TEXT(".\\IMAGE\\Back_BackSpaceKey.png")	//スタート画面に戻るように促すための画像
#define IMAGE_EASYMODE_PATH				TEXT(".\\IMAGE\\Easy.png")				//Easyモードへ促すためのボタン
#define IMAGE_NORMALMODE_PATH			TEXT(".\\IMAGE\\Normal.png")			//Normalモードへ促すためのボタン
#define IMAGE_HARDMODE_PATH				TEXT(".\\IMAGE\\Hard.png")				//Hardモードへ促すためのボタン
#define IMAGE_LEVEL_BUTTON_PATH			TEXT(".\\IMAGE\\level説明.png")			//ボタンの画像(level説明行き)
#define IMAGE_LEVEL_EXP_PATH			TEXT(".\\IMAGE\\level説明画像.png")		//level説明

//動物チップ関連
#define GAME_animal1_CHIP_PATH			TEXT(".\\IMAGE\\animal\\mapchip_1.png")  //チップの画像
#define ANIMAL_MAX						4

//画像分割関連
#define CHIP_DIV_WIDTH					565   //画像を分割する幅サイズ
#define CHIP_DIV_HEIGHT					660   //画像を分割する高さサイズ
#define GAME_animal1_DIV_TATE			2     //画像を縦に分割する数
#define GAME_animal1_DIV_YOKO			2     //画像を横に分割する数
#define CHIP_DIV_NUM GAME_animal1_DIV_TATE * GAME_animal1_DIV_YOKO  //画像を分割する総数

//マスク関連
#define EASY_HAVE_MASK					20		//マスクの上限(Easyモード、20個)
#define NORMAL_HAVE_MASK				50		//マスクの上限(Normalモード、50個)
#define HARD_HAVE_MASK					100		//マスクの上限(Hardモード、100個)
#define EASY_GIVE_MASK_RANGE			4		//マスクのランダム数(Easyモード、0～4)
#define NORMAL_GIVE_MASK_RANGE			10		//マスクのランダム数(Normalモード、0～9)
#define HARD_GIVE_MASK_RANGE			20		//マスクのランダム数(Hardモード、0～19)

//フォントのパスの長さ
#define FONT_PATH_MAX					255

//フォント
#define FONT_TANUKI_PATH				TEXT(".\\FONT\\TanukiMagic.ttf")
#define FONT_TANUKI_NAME				TEXT("たぬき油性マジック")

//フォントのエラーメッセージ
#define FONT_INSTALL_ERR_TITLE			TEXT("フォントインストールエラー")
#define FONT_CREATE_ERR_TITLE			TEXT("フォント作成エラー")

//音楽のパス
#define MUSIC_START_BGM_PATH			TEXT(".\\MUSIC\\game_maoudamashii_7_event43.mp3")  //スタート画面のBGM
#define MUSIC_PLAY_BGM_PATH				TEXT(".\\MUSIC\\game_maoudamashii_7_event34.mp3")  //プレイ画面のBGM
#define MUSIC_END_CLEAR_PATH			TEXT(".\\MUSIC\\game_maoudamashii_7_event42.mp3")  //エンド画面(クリアパターン)の音楽
#define MUSIC_END_FAIL_PATH				TEXT(".\\MUSIC\\game_maoudamashii_8_orgel05.mp3")  //エンド画面(失敗パターン)の音楽
#define SOUND_EFFECT_TIME_PATH			TEXT(".\\MUSIC\\decision31.mp3")				   //時間が減っていく毎の効果音
#define SOUND_EFFECT_BUTTON_PATH		TEXT(".\\MUSIC\\decision15.mp3")				   //ボタンを押した際の効果音

//エラーメッセージ
#define MUSIC_LOAD_ERR_TITLE			TEXT("音楽読み込みエラー")

//各モードの制限時間  1000ミリ＝１秒
#define EASY_TIMELIMIT					5 * 1000	//制限時間(Easyモード、5秒間)
#define NORMAL_TIMELIMIT				10 * 1000	//制限時間(Normalモード、10秒間)
#define HARD_TIMELIMIT					15 * 1000	//制限時間(Hardモード、15秒間)

//########## 列挙型 ##########
enum GAME_SCENE {
	GAME_SCENE_START,  //スタート画面
	GAME_SCENE_PLAY,   //プレイ画面
	GAME_SCENE_END,    //エンド画面
	GAME_SCENE_MENU,   //操作説明画面
	GAME_SCENE_LEVEL,  //level説明画面
};   //ゲームのシーン

enum GAME_JUDE {
	JUDE_CLEAR,  //成功
	JUDE_OVER    //失敗
};  //クリアか失敗か

//########## 構造体 ##########
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

//########## グローバル変数 ##########
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
int GHandle[ANIMAL_MAX];		//ハンドルを保存する用の配列
int order = 0;					//表示する順番を管理

//マスク関連
int Mask_num = 0;   //あげるマスクの個数
int Mask_sum = 0;   //マスクの合計値
int HaveMask = 0;   //各モードの上限マスク個数
int GiveMask = 0;   //あげるマスクのランダム数

//時間関連
int StartTime = 0;		//計測開始時間
int ElaTime = 0;		//残り時間
int CDTimeLimit = 0;	//カウントダウン用の制限時間(CD = CountDown)
int TimeLimit = 0;		//制限時間
BOOL First_flg = TRUE;  //ゲームに入る際のカウントダウンをする
BOOL CountDown = TRUE;  //カウントダウンをする際の基準時間を確保する

//画像関連
IMAGE ImageSTARTBG;		//ゲームの背景(スタート画面)
IMAGE ImageTITLE;		//タイトル画像
IMAGE ImagePLAYENDBG;	//ゲームの背景(プレイ・エンド画面)
IMAGE ImageMENUBtn;		//ボタンの画像(ルール説明行き)
IMAGE ImageMENUBG;		//ゲームの背景(説明画面)
IMAGE ImageEndClear;	//クリアの画像
IMAGE ImageEndFail;		//失敗の画像
IMAGE_MENU ImageMENU1;	//操作説明の1枚目
IMAGE_MENU ImageMENU2;  //操作説明の2枚目
IMAGE ImageMessage1;	//お客様からのメッセージ(成功パターン)
IMAGE ImageMessage2;    //お客様からのメッセージ(失敗パターン)
IMAGE ImageBack_BSK;    //スタート画面に戻るように促すための画像 BSK = Back Space Key
IMAGE ImageEasyMode;	//Easyモードへ促すためのボタン
IMAGE ImageNormalMode;	//Normalモードへ促すためのボタン
IMAGE ImageHardMode;	//Hardモードへ促すためのボタン
IMAGE ImageLEVELBtn;	//ボタンの画像(level説明行き)
IMAGE ImageLEVELExp;	//level説明

//フォント
FONT TANUKI;
FONT CD_TANUKI;  //カウントダウン用のフォント

//クリアか失敗か
int Jude;

//最初の問題を表示するための関数
BOOL First_Qus = TRUE;

//音楽関連
MUSIC START_BGM;		//スタート画面のBGM
MUSIC PLAY_BGM;			//プレイ画面のBGM
MUSIC END_CLEAR_BGM;	//エンド画面(クリアパターン)のBGM
MUSIC END_FAIL_BGM;		//エンド画面(失敗パターン)のBGM
MUSIC SF_TIME;			//時間が減っていく毎の効果音  (SF = SoundEffect)
MUSIC SF_BUTTON;		//ボタンを押した際の効果音

//########## プロトタイプ宣言 ##########
VOID MY_FPS_UPDATE(VOID);			//FPS値を計測、更新する関数
VOID MY_FPS_DRAW(VOID);				//FPS値を描画する関数
VOID MY_FPS_WAIT(VOID);				//FPS値を計測し。待つ関数

VOID MY_ALL_KEYDOWN_UPDATE(VOID);   //キーの入力状態を更新する
BOOL MY_KEY_DOWN(int);			    //キーを押しているか、キーコードで判断する
BOOL MY_KEY_UP(int);				//キーを押し上げたか、キーコードで判断する
BOOL MY_KEYDOWN_KEEP(int, int);		//キーを押し続けているか、キーコードで判断する
BOOL MY_KEYDOWN_1SECOND(int);		//キーを1秒間押し続けたか

VOID MY_START(VOID);				//スタート画面
VOID MY_START_PROC(VOID);			//スタート画面の処理
VOID MY_START_DRAW(VOID);			//スタート画面の描画

VOID MY_MENU(VOID);					//操作説明画面
VOID MY_MENU_PROC(VOID);			//操作説明画面の処理
VOID MY_MENU_DRAW(VOID);			//操作説明画面の描画

VOID MY_LEVEL(VOID);				//level説明画面
VOID MY_LEVEL_PROC(VOID);			//level説明画面の処理
VOID MY_LEVEL_DRAW(VOID);			//level説明画面の描画

VOID MY_PLAY(VOID);					//プレイ画面
VOID MY_PLAY_PROC(VOID);			//プレイ画面の処理
VOID MY_PLAY_DRAW(VOID);			//プレイ画面の描画

VOID MY_END(VOID);					//エンド画面
VOID MY_END_PROC(VOID);				//エンド画面の処理
VOID MY_END_DRAW(VOID);				//エンド画面の描画

BOOL MY_LOAD_IMAGE(VOID);			//画像をまとめて読み込む関数
VOID MY_DELETE_IMAGE(VOID);			//画像をまとめて削除する関数
VOID MY_PICTURE_INIT(VOID);			//画像の消去・初期化する関数

BOOL MY_FONT_INSTALL_ONCE(VOID);    //フォントを一時的にインストール
VOID MY_FONT_UNINSTALL_ONCE(VOID);  //フォントを一時的にアンインストール
BOOL MY_FONT_CREATE(VOID);			//フォントを作成する
VOID MY_FONT_DELETE(VOID);			//フォントを削除する

BOOL MY_LOAD_MUSIC(VOID);			//音楽をまとめて読み込む関数
VOID MY_DELETE_MUSIC(VOID);			//音楽をまとめて削除する関数