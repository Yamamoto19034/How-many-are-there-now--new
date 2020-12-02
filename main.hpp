#pragma once

#include "DxLib.h"

//########## �}�N����` ##########
#define GAME_WIDTH						1000	//��ʂ̉��̑傫��
#define GAME_HEIGHT						700		//��ʂ̏c�̑傫��
#define GAME_COLOR						32		//��ʂ̃J���[�r�b�g

#define GAME_WINDOW_BAR					0					//�^�C�g���o�[�̓f�t�H���g�ɂ���
#define GAME_WINDOW_NAME				"����A�����H"	//�E�B���h�E�̃^�C�g��

#define GAME_FPS						60  //FPS�̐��l

//�p�X�̒���
#define PATH_MAX						255
#define NAME_MAX						255

//�G���[���b�Z�[�W
#define IMAGE_LOAD_ERR_TITLE			TEXT("�摜�ǂݍ��݃G���[")

//�摜�֘A	
#define IMAGE_START_BG_PATH				TEXT(".\\IMAGE\\�X�^�[�g���.png")		//�w�i(�X�^�[�g���)�̉摜
#define IMAGE_TITLE_PATH				TEXT(".\\IMAGE\\title.png")				//�^�C�g���摜
#define IMAGE_PLAY_BG_PATH				TEXT(".\\IMAGE\\�X�̒�.png")			//�w�i(�v���C�E�G���h)�̉摜
#define IMAGE_MENU_BUTTON_PATH			TEXT(".\\IMAGE\\�������.png")			//�{�^���̉摜(���[�������s��)
#define IMAGE_MENU_BG_PATH				TEXT(".\\IMAGE\\menu_�w�i.png")			//�w�i(���������ʁE���[���������)�̉摜
#define IMAGE_END_CLEAR_PATH			TEXT(".\\IMAGE\\GameClear.png")			//�N���A�̉摜
#define IMAGE_END_FAIL_PATH				TEXT(".\\IMAGE\\sippai.png")			//�Q�[���I�[�o�[�̉摜
#define IMAGE_MENU_1_PATH				TEXT(".\\IMAGE\\�������-1.png")		//���������1����
#define IMAGE_MENU_2_PATH				TEXT(".\\IMAGE\\�������-2.png")		//���������2����
#define IMAGE_MESSAGE_1_PATH			TEXT(".\\IMAGE\\message-1.png")			//���q�l����̃��b�Z�[�W(�����p�^�[��)
#define IMAGE_MESSAGE_2_PATH			TEXT(".\\IMAGE\\message-2.png")			//���q�l����̃��b�Z�[�W(���s�p�^�[��)
#define IMAGE_BACK_BACKSPACE_KEY_PATH	TEXT(".\\IMAGE\\Back_BackSpaceKey.png")	//�X�^�[�g��ʂɖ߂�悤�ɑ������߂̉摜
#define IMAGE_EASYMODE_PATH				TEXT(".\\IMAGE\\Easy.png")				//Easy���[�h�֑������߂̃{�^��
#define IMAGE_NORMALMODE_PATH			TEXT(".\\IMAGE\\Normal.png")			//Normal���[�h�֑������߂̃{�^��
#define IMAGE_HARDMODE_PATH				TEXT(".\\IMAGE\\Hard.png")				//Hard���[�h�֑������߂̃{�^��
#define IMAGE_LEVEL_BUTTON_PATH			TEXT(".\\IMAGE\\level����.png")			//�{�^���̉摜(level�����s��)
#define IMAGE_LEVEL_EXP_PATH			TEXT(".\\IMAGE\\level�����摜.png")		//level����

//�����`�b�v�֘A
#define GAME_animal1_CHIP_PATH			TEXT(".\\IMAGE\\animal\\mapchip_1.png")  //�`�b�v�̉摜
#define ANIMAL_MAX						4

//�摜�����֘A
#define CHIP_DIV_WIDTH					565   //�摜�𕪊����镝�T�C�Y
#define CHIP_DIV_HEIGHT					660   //�摜�𕪊����鍂���T�C�Y
#define GAME_animal1_DIV_TATE			2     //�摜���c�ɕ������鐔
#define GAME_animal1_DIV_YOKO			2     //�摜�����ɕ������鐔
#define CHIP_DIV_NUM GAME_animal1_DIV_TATE * GAME_animal1_DIV_YOKO  //�摜�𕪊����鑍��

//�}�X�N�֘A
#define EASY_HAVE_MASK					20		//�}�X�N�̏��(Easy���[�h�A20��)
#define NORMAL_HAVE_MASK				50		//�}�X�N�̏��(Normal���[�h�A50��)
#define HARD_HAVE_MASK					100		//�}�X�N�̏��(Hard���[�h�A100��)
#define EASY_GIVE_MASK_RANGE			4		//�}�X�N�̃����_����(Easy���[�h�A0�`4)
#define NORMAL_GIVE_MASK_RANGE			10		//�}�X�N�̃����_����(Normal���[�h�A0�`9)
#define HARD_GIVE_MASK_RANGE			20		//�}�X�N�̃����_����(Hard���[�h�A0�`19)

//�t�H���g�̃p�X�̒���
#define FONT_PATH_MAX					255

//�t�H���g
#define FONT_TANUKI_PATH				TEXT(".\\FONT\\TanukiMagic.ttf")
#define FONT_TANUKI_NAME				TEXT("���ʂ������}�W�b�N")

//�t�H���g�̃G���[���b�Z�[�W
#define FONT_INSTALL_ERR_TITLE			TEXT("�t�H���g�C���X�g�[���G���[")
#define FONT_CREATE_ERR_TITLE			TEXT("�t�H���g�쐬�G���[")

//���y�̃p�X
#define MUSIC_START_BGM_PATH			TEXT(".\\MUSIC\\game_maoudamashii_7_event43.mp3")  //�X�^�[�g��ʂ�BGM
#define MUSIC_PLAY_BGM_PATH				TEXT(".\\MUSIC\\game_maoudamashii_7_event34.mp3")  //�v���C��ʂ�BGM
#define MUSIC_END_CLEAR_PATH			TEXT(".\\MUSIC\\game_maoudamashii_7_event42.mp3")  //�G���h���(�N���A�p�^�[��)�̉��y
#define MUSIC_END_FAIL_PATH				TEXT(".\\MUSIC\\game_maoudamashii_8_orgel05.mp3")  //�G���h���(���s�p�^�[��)�̉��y
#define SOUND_EFFECT_TIME_PATH			TEXT(".\\MUSIC\\decision31.mp3")				   //���Ԃ������Ă������̌��ʉ�
#define SOUND_EFFECT_BUTTON_PATH		TEXT(".\\MUSIC\\decision15.mp3")				   //�{�^�����������ۂ̌��ʉ�

//�G���[���b�Z�[�W
#define MUSIC_LOAD_ERR_TITLE			TEXT("���y�ǂݍ��݃G���[")

//�e���[�h�̐�������  1000�~�����P�b
#define EASY_TIMELIMIT					5 * 1000	//��������(Easy���[�h�A5�b��)
#define NORMAL_TIMELIMIT				10 * 1000	//��������(Normal���[�h�A10�b��)
#define HARD_TIMELIMIT					15 * 1000	//��������(Hard���[�h�A15�b��)

//########## �񋓌^ ##########
enum GAME_SCENE {
	GAME_SCENE_START,  //�X�^�[�g���
	GAME_SCENE_PLAY,   //�v���C���
	GAME_SCENE_END,    //�G���h���
	GAME_SCENE_MENU,   //����������
	GAME_SCENE_LEVEL,  //level�������
};   //�Q�[���̃V�[��

enum GAME_JUDE {
	JUDE_CLEAR,  //����
	JUDE_OVER    //���s
};  //�N���A�����s��

//########## �\���� ##########
typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];	//�p�X
	int handle;				//�n���h��
	int x;					//X�ʒu
	int y;					//Y�ʒu
	int width;				//��
	int height;				//����
}IMAGE; //�摜�\����

typedef struct STRCT_MENU_IMAGE
{
	IMAGE image;  //�摜�\����
	BOOL IsDraw;  //�`��ł��邩�ۂ�
}IMAGE_MENU;  //���������ʗp

typedef struct STRUCT_ANIMAL
{
	char path[PATH_MAX];		//�p�X
	int handle[CHIP_DIV_NUM];   //�������������̉摜�n���h�����擾
	int x;						//X�ʒu
	int y;						//Y�ʒu
	int width;					//��
	int height;					//����
	BOOL IsDraw;				//������\���ł��邩
}MAPCHIP;  //�}�b�v�`�b�v�\����

typedef struct STRUCT_FONT
{
	char path[FONT_PATH_MAX];   //�p�X
	char name[FONT_PATH_MAX];   //�t�H���g��
	int handle;                 //�n���h��
	int size;					//�傫��
	int bold;					//����
	int type;					//�^�C�v
}FONT;   //�t�H���g�\����

typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];		//�p�X
	int handle;					//�n���h��
}MUSIC;  //���y�\����

//########## �O���[�o���ϐ� ##########
int StartTimeFps;				//����J�n����
int CountFps;					//�J�E���^
float CalcFps;					//�v�Z����
int SampleNumFps = GAME_FPS;	//���ς��Ƃ�T���v����

//�L�[�{�[�h�̓��͂��擾
char AllKeyState[256] = { 0 };
char OldAllKeyState[256] = { 0 };

//�Q�[���V�[��
int GameScene;

//�}�b�v�`�b�v�֘A
MAPCHIP animal[ANIMAL_MAX];
int GHandle[ANIMAL_MAX];		//�n���h����ۑ�����p�̔z��
int order = 0;					//�\�����鏇�Ԃ��Ǘ�

//�}�X�N�֘A
int Mask_num = 0;   //������}�X�N�̌�
int Mask_sum = 0;   //�}�X�N�̍��v�l
int HaveMask = 0;   //�e���[�h�̏���}�X�N��
int GiveMask = 0;   //������}�X�N�̃����_����

//���Ԋ֘A
int StartTime = 0;		//�v���J�n����
int ElaTime = 0;		//�c�莞��
int CDTimeLimit = 0;	//�J�E���g�_�E���p�̐�������(CD = CountDown)
int TimeLimit = 0;		//��������
BOOL First_flg = TRUE;  //�Q�[���ɓ���ۂ̃J�E���g�_�E��������
BOOL CountDown = TRUE;  //�J�E���g�_�E��������ۂ̊���Ԃ��m�ۂ���

//�摜�֘A
IMAGE ImageSTARTBG;		//�Q�[���̔w�i(�X�^�[�g���)
IMAGE ImageTITLE;		//�^�C�g���摜
IMAGE ImagePLAYENDBG;	//�Q�[���̔w�i(�v���C�E�G���h���)
IMAGE ImageMENUBtn;		//�{�^���̉摜(���[�������s��)
IMAGE ImageMENUBG;		//�Q�[���̔w�i(�������)
IMAGE ImageEndClear;	//�N���A�̉摜
IMAGE ImageEndFail;		//���s�̉摜
IMAGE_MENU ImageMENU1;	//���������1����
IMAGE_MENU ImageMENU2;  //���������2����
IMAGE ImageMessage1;	//���q�l����̃��b�Z�[�W(�����p�^�[��)
IMAGE ImageMessage2;    //���q�l����̃��b�Z�[�W(���s�p�^�[��)
IMAGE ImageBack_BSK;    //�X�^�[�g��ʂɖ߂�悤�ɑ������߂̉摜 BSK = Back Space Key
IMAGE ImageEasyMode;	//Easy���[�h�֑������߂̃{�^��
IMAGE ImageNormalMode;	//Normal���[�h�֑������߂̃{�^��
IMAGE ImageHardMode;	//Hard���[�h�֑������߂̃{�^��
IMAGE ImageLEVELBtn;	//�{�^���̉摜(level�����s��)
IMAGE ImageLEVELExp;	//level����

//�t�H���g
FONT TANUKI;
FONT CD_TANUKI;  //�J�E���g�_�E���p�̃t�H���g

//�N���A�����s��
int Jude;

//�ŏ��̖���\�����邽�߂̊֐�
BOOL First_Qus = TRUE;

//���y�֘A
MUSIC START_BGM;		//�X�^�[�g��ʂ�BGM
MUSIC PLAY_BGM;			//�v���C��ʂ�BGM
MUSIC END_CLEAR_BGM;	//�G���h���(�N���A�p�^�[��)��BGM
MUSIC END_FAIL_BGM;		//�G���h���(���s�p�^�[��)��BGM
MUSIC SF_TIME;			//���Ԃ������Ă������̌��ʉ�  (SF = SoundEffect)
MUSIC SF_BUTTON;		//�{�^�����������ۂ̌��ʉ�

//########## �v���g�^�C�v�錾 ##########
VOID MY_FPS_UPDATE(VOID);			//FPS�l���v���A�X�V����֐�
VOID MY_FPS_DRAW(VOID);				//FPS�l��`�悷��֐�
VOID MY_FPS_WAIT(VOID);				//FPS�l���v�����B�҂֐�

VOID MY_ALL_KEYDOWN_UPDATE(VOID);   //�L�[�̓��͏�Ԃ��X�V����
BOOL MY_KEY_DOWN(int);			    //�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEY_UP(int);				//�L�[�������グ�����A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEYDOWN_KEEP(int, int);		//�L�[�����������Ă��邩�A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEYDOWN_1SECOND(int);		//�L�[��1�b�ԉ�����������

VOID MY_START(VOID);				//�X�^�[�g���
VOID MY_START_PROC(VOID);			//�X�^�[�g��ʂ̏���
VOID MY_START_DRAW(VOID);			//�X�^�[�g��ʂ̕`��

VOID MY_MENU(VOID);					//����������
VOID MY_MENU_PROC(VOID);			//���������ʂ̏���
VOID MY_MENU_DRAW(VOID);			//���������ʂ̕`��

VOID MY_LEVEL(VOID);				//level�������
VOID MY_LEVEL_PROC(VOID);			//level������ʂ̏���
VOID MY_LEVEL_DRAW(VOID);			//level������ʂ̕`��

VOID MY_PLAY(VOID);					//�v���C���
VOID MY_PLAY_PROC(VOID);			//�v���C��ʂ̏���
VOID MY_PLAY_DRAW(VOID);			//�v���C��ʂ̕`��

VOID MY_END(VOID);					//�G���h���
VOID MY_END_PROC(VOID);				//�G���h��ʂ̏���
VOID MY_END_DRAW(VOID);				//�G���h��ʂ̕`��

BOOL MY_LOAD_IMAGE(VOID);			//�摜���܂Ƃ߂ēǂݍ��ފ֐�
VOID MY_DELETE_IMAGE(VOID);			//�摜���܂Ƃ߂č폜����֐�
VOID MY_PICTURE_INIT(VOID);			//�摜�̏����E����������֐�

BOOL MY_FONT_INSTALL_ONCE(VOID);    //�t�H���g���ꎞ�I�ɃC���X�g�[��
VOID MY_FONT_UNINSTALL_ONCE(VOID);  //�t�H���g���ꎞ�I�ɃA���C���X�g�[��
BOOL MY_FONT_CREATE(VOID);			//�t�H���g���쐬����
VOID MY_FONT_DELETE(VOID);			//�t�H���g���폜����

BOOL MY_LOAD_MUSIC(VOID);			//���y���܂Ƃ߂ēǂݍ��ފ֐�
VOID MY_DELETE_MUSIC(VOID);			//���y���܂Ƃ߂č폜����֐�