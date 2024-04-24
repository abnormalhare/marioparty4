#include "game/object.h"
#include "game/memory.h"
#include "game/hsfman.h"
#include "game/objsub.h"
#include "game/minigame_seq.h"
#include "game/gamework_data.h"
#include "game/wipe.h"
#include "game/esprite.h"
#include "game/sprite.h"

#include "REL/m401Dll.h"

#include "rel_sqrt_consts.h"

float lbl_2_data_0 = -7.1875f;

s16 lbl_2_data_4[] = {
	0, 1, 2, 3,
	4, 5, 6, 7
};

Vec lbl_2_data_14 = {
	1500, 2500, 1500
};

Vec lbl_2_data_20 = {
	0, -1, 0
};

GXColor lbl_2_data_2C = {
	255, 255, 255, 255
};

Vec lbl_2_data_30 = {
	0, 2500, 0
};

Vec lbl_2_data_3C = {
	0, 1, -1
};

Vec lbl_2_data_48 = {
	0, 0, 0
};

s32 lbl_2_bss_11C;
omObjData **lbl_2_bss_118;
omObjData *lbl_2_bss_114;
omObjData *lbl_2_bss_110;
omObjData *lbl_2_bss_10C;
omObjData *lbl_2_bss_108;
omObjData *lbl_2_bss_100[2];
omObjData *lbl_2_bss_FC;
omObjData *lbl_2_bss_F8;
omObjData *lbl_2_bss_F4;
omObjData *lbl_2_bss_E4[4];
omObjData *lbl_2_bss_E0;
omObjData *lbl_2_bss_DC;
omObjData *lbl_2_bss_D8;
omObjData *lbl_2_bss_D4;
omObjData *lbl_2_bss_D0;
omObjData *lbl_2_bss_CC;
omObjData *lbl_2_bss_C8;
omObjData *lbl_2_bss_C4;
s16 lbl_2_bss_C0;
s16 lbl_2_bss_BE;
s16 lbl_2_bss_BC;
s16 lbl_2_bss_BA;
s16 lbl_2_bss_B2[4];
s16 lbl_2_bss_AA[4];
s16 lbl_2_bss_A8;
s32 lbl_2_bss_A4;
s32 lbl_2_bss_90[5];
s32 lbl_2_bss_8C;
float lbl_2_bss_88;
float lbl_2_bss_84;
Vec lbl_2_bss_78;
Vec lbl_2_bss_6C;
Vec lbl_2_bss_60;
Vec lbl_2_bss_54;
float lbl_2_bss_50;
Vec lbl_2_bss_44;
Vec lbl_2_bss_38;
Vec lbl_2_bss_2C;
Vec lbl_2_bss_20;
Process *lbl_2_bss_1C;
s16 lbl_2_bss_1A;
s16 lbl_2_bss_18;
s32 lbl_2_bss_14;
float lbl_2_bss_10;
s16 lbl_2_bss_E;
s16 lbl_2_bss_C;
omObjData *lbl_2_bss_8;
omObjData *lbl_2_bss_4;
omObjData *lbl_2_bss_0;

void fn_2_70C(omObjData *object);
void fn_2_A10(omObjData *object);
void fn_2_C1C(omObjData *object);
void fn_2_11D0(omObjData *object);

void fn_2_2FA4(omObjData *object);
void fn_2_3B24(omObjData *object);
void fn_2_48A0(omObjData *object);
void fn_2_7CB4(omObjData *object);
void fn_2_8E74(omObjData *object);
void fn_2_95E4(omObjData *object);
void fn_2_9D00(Process *objman);
void fn_2_BD90(omObjData *object);
void fn_2_C130(omObjData *object);
void fn_2_C6DC(omObjData *object);
void fn_2_D088(omObjData *object);

void fn_2_DBCC(s32 arg0);

void ModuleProlog(void)
{
	s32 i;
	omObjData *object;
	CameraData *camera;
	LightData *light;
	OSReport("**** M401ObjectSetup ****\n");
	HuMemHeapDump(HuMemHeapPtrGet(HEAP_SYSTEM), -1);
	HuMemHeapDump(HuMemHeapPtrGet(HEAP_DATA), -1);
	HuMemHeapDump(HuMemHeapPtrGet(HEAP_DVD), -1);
	lbl_2_bss_1C = omInitObjMan(60, 8192);
	omGameSysInit(lbl_2_bss_1C);
	lbl_2_bss_A8 = Hu3DGLightCreateV(&lbl_2_data_14, &lbl_2_data_20, &lbl_2_data_2C);
	Hu3DGLightInfinitytSet(lbl_2_bss_A8);
	light = &Hu3DGlobalLight[lbl_2_bss_A8];
	light->unk_00 |= 0x8000;
	Hu3DCameraCreate(1);
	camera = &Hu3DCamera[0];
	Hu3DCameraViewportSet(1, 0, 0, 640, 480, 0, 1);
	lbl_2_bss_114 = omAddObjEx(lbl_2_bss_1C, 1000, 3, 0, -1, fn_2_BD90);
	lbl_2_bss_114->work[0] = 0;
	lbl_2_bss_110 = omAddObjEx(lbl_2_bss_1C, 10, 0, 0, -1, fn_2_70C);
	omMakeGroupEx(lbl_2_bss_1C, 0, 4);
	lbl_2_bss_118 = omGetGroupMemberListEx(lbl_2_bss_1C, 0);
	omMakeGroupEx(lbl_2_bss_1C, 1, 28);
	for(i=0; i<4; i++) {
		object = omAddObjEx(lbl_2_bss_1C, 1200, 4, 10, 0, fn_2_3B24);
		object->work[0] = i;
	}
	lbl_2_bss_12C = 60;
	lbl_2_bss_128 = 50;
	lbl_2_bss_124 = 25000;
	Hu3DShadowCreate(30, 20, 5000);
	Hu3DShadowTPLvlSet(0.35f);
	lbl_2_data_30.y = lbl_2_bss_60.y + 1500.0f;
	lbl_2_data_30.z = lbl_2_bss_60.z + 500.0f;
	lbl_2_data_48.y = lbl_2_bss_60.y;
	lbl_2_data_48.z = lbl_2_bss_60.z + 500.0f;
	Hu3DShadowPosSet(&lbl_2_data_30, &lbl_2_data_3C, &lbl_2_data_48);
	lbl_2_bss_10C = omAddObjEx(lbl_2_bss_1C, 500, 12, 3, -1, fn_2_2FA4);
	lbl_2_bss_108 = omAddObjEx(lbl_2_bss_1C, 1100, 1, 1, -1, fn_2_7CB4);
	lbl_2_bss_100[0] = omAddObjEx(lbl_2_bss_1C, 1110, 1, 1, -1, fn_2_8E74);
	lbl_2_bss_100[1] = omAddObjEx(lbl_2_bss_1C, 1110, 1, 1, -1, fn_2_8E74);
	lbl_2_bss_FC = omAddObjEx(lbl_2_bss_1C, 1120, 1, 2, -1, fn_2_95E4);
	lbl_2_bss_C8 = omAddObjEx(lbl_2_bss_1C, 100, 0, 0, -1, fn_2_D088);
	lbl_2_bss_E0 = omAddObjEx(lbl_2_bss_1C, 1500, 0, 0, -1, fn_2_C1C);
	fn_2_DBCC(90);
	lbl_2_bss_F8 = omAddObjEx(lbl_2_bss_1C, 500, 9, 0, -1, fn_2_C6DC);
	fn_2_9D00(lbl_2_bss_1C);
	fn_2_1041C();
	fn_2_1079C();
	lbl_2_bss_F4 = fn_2_14640(lbl_2_bss_1C);
	lbl_2_bss_50 = 0;
	lbl_2_bss_54 = camera->pos;
	Hu3DReflectNoSet(0);
	lbl_2_bss_120 = 0;
	lbl_2_bss_BE = 0;
	lbl_2_bss_BA = 0;
	Hu3DFogSet(3000, 10000, 10, 60, 160);
	Hu3DBGColorSet(10, 60, 160);
	lbl_2_bss_88 = 3000;
	lbl_2_bss_84 = 142000;
	lbl_2_bss_11C = HuAudFXPlay(1290);
}

typedef struct m401_work_player {
	s16 unk0;
	u8 unk2[0x66];
	s16 unk68;
	u8 unk6A[8];
	s16 unk72;
	s16 unk74;
} M401WorkPlayer;

void fn_2_70C(omObjData *object)
{
	s32 temp_r31;
	M401WorkPlayer *temp_r30;
	s16 temp_r29;
	switch(lbl_2_bss_120) {
		case 0:
			break;
			
		case 1:
			if(lbl_2_bss_BE == 1) {
				lbl_2_bss_120 = 2;
				lbl_2_bss_C0 = MGSeqFinishCreate();
				HuAudSeqFadeOut(lbl_2_bss_A4, 100);
			}
			break;
			
		case 2:
			if(lbl_2_bss_114 == NULL) {
				lbl_2_bss_114 = omAddObjEx(HuPrcCurrentGet(), 1000, 0, 0, -1, fn_2_C130);
				lbl_2_bss_114->work[0] = 0;
				temp_r29 = 0;
				lbl_2_bss_BA = 0;
				for(temp_r31=0; temp_r31<4; temp_r31++) {
					temp_r30 = lbl_2_bss_118[temp_r31]->data;
					lbl_2_bss_118[temp_r31]->func = fn_2_48A0;
					temp_r30->unk0 = 5;
					temp_r30->unk68 = 0;
					if(temp_r30->unk72 > temp_r29) {
						temp_r29 = temp_r30->unk72;
					}
					lbl_2_bss_B2[temp_r31] = -1;
					lbl_2_bss_AA[temp_r31] = -1;
				}
				if(temp_r29 > 0) {
					for(temp_r31=0; temp_r31<4; temp_r31++) {
						temp_r30 = lbl_2_bss_118[temp_r31]->data;
						if(temp_r30->unk72 == temp_r29) {
							lbl_2_bss_AA[lbl_2_bss_BA] = GWPlayerCfg[temp_r31].character;
							lbl_2_bss_B2[lbl_2_bss_BA++] = temp_r31;
							temp_r30->unk68 = 1;
						}
					}
				}
				OSReport("winnercnt:%d\n", lbl_2_bss_BA);
			}
			break;
	}
	if(omSysExitReq) {
		WipeCreate(WIPE_MODE_OUT, WIPE_TYPE_NORMAL, 60);
		HuAudSeqFadeOut(lbl_2_bss_A4, 100);
		HuAudFXStop(lbl_2_bss_11C);
		object->func = fn_2_A10;
	}
}

void fn_2_A10(omObjData *object)
{
	s32 i;
	if(!WipeStatGet()) {
		fn_2_10710();
		for(i=0; i<4; i++) {
			CharModelKill(lbl_2_data_4[GWPlayerCfg[i].character]);
		}
		HuAudFXListnerKill();
		omOvlReturnEx(1, 1);
	}
}

void fn_2_A98(void)
{
	Hu3DFogSet(3000, 10000, 10, 60, 160);
	Hu3DBGColorSet(10, 60, 160);
}

typedef struct m401_work_2d {
	s16 unk0[4];
	s16 unk8[4][3];
	u8 unk20[0x30];
	s16 unk50[4][3];
	s16 unk68[4][3];
	s16 unk80[4];
	s16 unk88[4];
	float unk90[4];
	float unkA0[4];
	float unkB0[4];
	float unkC0[4];
	float unkD0[4];
	float unkE0[4];
	float unkF0[4];
	float unk100[4];
	float unk110[4];
	float unk120[4];
	s16 unk130[4];
	s16 unk138[4];
	s16 unk140[4];
} M401Work2D;

void fn_2_AEC(s16 arg0)
{
	M401Work2D *temp_r31;
	s32 i;
	s32 j;
	temp_r31 = lbl_2_bss_E0->data;
	if(arg0) {
		for(i=0; i<4; i++) {
			espDispOn(temp_r31->unk0[i]);
			espDispOn(temp_r31->unk80[i]);
			espDispOn(temp_r31->unk88[i]);
			for(j=0; j<2; j++) {
				espDispOn(temp_r31->unk8[i][j]);
			}
		}
	} else {
		for(i=0; i<4; i++) {
			espDispOff(temp_r31->unk0[i]);
			espDispOff(temp_r31->unk80[i]);
			espDispOff(temp_r31->unk88[i]);
			for(j=0; j<2; j++) {
				espDispOff(temp_r31->unk8[i][j]);
			}
		}
	}
}

s32 lbl_2_data_80[] = {
	0x610000,
	0x610001,
	0x610002,
	0x610003,
	0x610004,
	0x610005,
	0x610006,
	0x610007
};

#define PLAYER_POS_X(index, left, width) ((((index)&1)*width)+left)
#define PLAYER_POS_Y(index, top, height) ((((index)>1)*height)+top)

void fn_2_C1C(omObjData *object)
{
	M401Work2D *temp_r31;
	s32 i;
	s32 j;
	object->data = HuMemDirectMallocNum(HEAP_SYSTEM, sizeof(M401Work2D), MEMORY_DEFAULT_NUM);
	temp_r31 = object->data;
	for(i=0; i<4; i++) {
		temp_r31->unk0[i] = espEntry(lbl_2_data_80[GWPlayerCfg[i].character], 2, 0);
		espDispOff(temp_r31->unk0[i]);
		espDrawNoSet(temp_r31->unk0[i], 0);
		espPosSet(temp_r31->unk0[i], PLAYER_POS_X(i, 37, 438), PLAYER_POS_Y(i, 59, 358));
		temp_r31->unk80[i] = espEntry(0x20002F, 3, 0);
		espDispOff(temp_r31->unk80[i]);
		espDrawNoSet(temp_r31->unk80[i], 0);
		espPosSet(temp_r31->unk80[i], PLAYER_POS_X(i, 73, 438), PLAYER_POS_Y(i, 61, 358));
		temp_r31->unk88[i] = espEntry(0x200030, 4, 0);
		espDispOff(temp_r31->unk88[i]);
		espDrawNoSet(temp_r31->unk88[i], 0);
		espPosSet(temp_r31->unk88[i], PLAYER_POS_X(i, 73, 438), PLAYER_POS_Y(i, 61, 358));
		espColorSet(temp_r31->unk88[i], 0, 0, 0);
		espTPLvlSet(temp_r31->unk88[i], 0.5f);
		for(j=0; j<2; j++) {
			temp_r31->unk8[i][j] = espEntry(0x20002E, 1, 0);
			espDispOff(temp_r31->unk8[i][j]);
			espDrawNoSet(temp_r31->unk8[i][j], 0);
			espPosSet(temp_r31->unk8[i][j], PLAYER_POS_X(i, 69+(j*20), 438), PLAYER_POS_Y(i, 63, 358));
			espAttrSet(temp_r31->unk8[i][j], HUSPR_ATTR_NOANIM);
		}
		for(j=0; j<3; j++) {
			temp_r31->unk50[i][j] = espEntry(0x20002D, 0, 0);
			espDispOff(temp_r31->unk50[i][j]);
			espDrawNoSet(temp_r31->unk50[i][j], 0);
			espAttrSet(temp_r31->unk50[i][j], HUSPR_ATTR_NOANIM);
			temp_r31->unk68[i][j] = espEntry(0x20002D, 0, 0);
			espDispOff(temp_r31->unk68[i][j]);
			espDrawNoSet(temp_r31->unk68[i][j], 0);
			espAttrSet(temp_r31->unk68[i][j], HUSPR_ATTR_NOANIM);
		}
		espBankSet(temp_r31->unk50[i][0], 10);
		espBankSet(temp_r31->unk68[i][0], 11);
		temp_r31->unk90[i] = 1.0f;
		temp_r31->unkA0[i] = 1.0f;
		temp_r31->unk130[i] = 0;
		temp_r31->unk138[i] = 0;
	}
	object->func = fn_2_11D0;
}

void fn_2_15C4(s16 arg0);

void fn_2_11D0(omObjData *object)
{
	M401Work2D *temp_r31;
	s32 i;
	s32 j;
	omObjData *temp_r28;
	Vec sp18;
	Vec spC;
	M401WorkPlayer *sp8;
	temp_r31 = object->data;
	for(i=0; i<4; i++) {
		sp8 = lbl_2_bss_118[i]->data;
		if(temp_r31->unk130[i]) {
			temp_r28 = lbl_2_bss_118[i];
			sp18.x = temp_r28->trans.x;
			sp18.y = temp_r28->trans.y;
			sp18.z = temp_r28->trans.z;
			fn_2_10240(&sp18, &spC);
			for(j=0; j<3; j++) {
				espPosSet(temp_r31->unk50[i][j], (-20.0f+spC.x+temp_r31->unkF0[i])+(j*16), 20.0f+spC.y+temp_r31->unk100[i]);
				espTPLvlSet(temp_r31->unk50[i][j], temp_r31->unk90[i]);
			}
			temp_r31->unkC0[i] -= 0.5f;
			temp_r31->unk100[i] -= 1.0f;
			if(temp_r31->unk130[i] < 15) {
				temp_r31->unk90[i] -= 1.0f/15.0f;
			}
			if(--temp_r31->unk130[i] == 0) {
				espDispOff(temp_r31->unk50[i][0]);
				espDispOff(temp_r31->unk50[i][1]);
			}
		}
		if(temp_r31->unk138[i]) {
			temp_r28 = lbl_2_bss_118[i];
			sp18.x = temp_r28->trans.x;
			sp18.y = temp_r28->trans.y;
			sp18.z = temp_r28->trans.z;
			fn_2_10240(&sp18, &spC);
			for(j=0; j<2; j++) {
				espPosSet(temp_r31->unk68[i][j], (-20.0f+spC.x+temp_r31->unk110[i])+(j*16), -20.0f+spC.y+temp_r31->unk120[i]);
				espTPLvlSet(temp_r31->unk68[i][j], temp_r31->unkA0[i]);
			}
			temp_r31->unkE0[i] += 0.5f;
			temp_r31->unk120[i] += 1.0f;
			if(temp_r31->unk138[i] < 15) {
				temp_r31->unkA0[i] -= 1.0f/15.0f;
			}
			if(--temp_r31->unk138[i] == 0) {
				espDispOff(temp_r31->unk68[i][0]);
				espDispOff(temp_r31->unk68[i][1]);
			}
		}
		fn_2_15C4(i);
	}
}

void fn_2_15C4(s16 arg0)
{
	M401Work2D *temp_r31;
	s32 temp_r30;
	M401WorkPlayer *temp_r29;
	temp_r31 = lbl_2_bss_E0->data;
	temp_r29 = lbl_2_bss_118[arg0]->data;
	temp_r30 = temp_r29->unk72;
	espBankSet(temp_r31->unk8[arg0][0], temp_r30/10);
	espBankSet(temp_r31->unk8[arg0][1], temp_r30%10);
}

void fn_2_169C(s16 arg0)
{
	M401Work2D *temp_r31;
	s32 i;
	M401WorkPlayer *temp_r28;
	temp_r31 = lbl_2_bss_E0->data;
	temp_r28 = lbl_2_bss_118[arg0]->data;
	for(i=0; i<2; i++ ){
		espDispOn(temp_r31->unk50[arg0][i]);
	}
	temp_r31->unk90[arg0] = 1;
	temp_r31->unkC0[arg0] = PLAYER_POS_Y(arg0, 52, 398);
	temp_r31->unkB0[arg0] = PLAYER_POS_X(arg0, 41, 442);
	temp_r31->unk100[arg0] = 0;
	temp_r31->unkF0[arg0] = 0;
	espBankSet(temp_r31->unk50[arg0][1], temp_r28->unk74);
	temp_r31->unk130[arg0] = 45;
}

void fn_2_1858(s16 arg0, s16 arg1)
{
	M401Work2D *temp_r31;
	M401WorkPlayer *temp_r29;
	s32 i;
	temp_r31 = lbl_2_bss_E0->data;
	temp_r29 = lbl_2_bss_118[arg0]->data;
	for(i=0; i<2; i++ ){
		espDispOn(temp_r31->unk68[arg0][i]);
	}
	temp_r31->unkA0[arg0] = 1;
	temp_r31->unkE0[arg0] = PLAYER_POS_Y(arg0, 20, 398);
	temp_r31->unkD0[arg0] = PLAYER_POS_X(arg0, 41, 442);
	temp_r31->unk120[arg0] = 0;
	temp_r31->unk110[arg0] = 0;
	espBankSet(temp_r31->unk68[arg0][1], arg1);
	temp_r31->unk138[arg0] = 45;
	temp_r31->unk140[arg0] = arg1;
	temp_r29->unk72 -= arg1;
	if(temp_r29->unk72 < 0) {
		temp_r29->unk72 = 0;
	}
}

float lbl_2_data_A0[] = {
	-500,
	-8500,
	-17500,
	-26500,
	-99000
};

float lbl_2_data_B4[] = {
	-9100,
	-18100,
	-27100,
	-36100,
	-45100,
	-100000
};

void fn_2_1A38(omObjData *object);
void fn_2_1B80(omObjData *object);
void fn_2_1CF0(omObjData *object);
void fn_2_1DE8(omObjData *object);
void fn_2_1DE8(omObjData *object);
void fn_2_20B0(omObjData *object);
void fn_2_2CBC(omObjData *object);
void fn_2_2D64(omObjData *object);
void fn_2_2DCC(omObjData *object);
void fn_2_2E20(omObjData *object);
void fn_2_2ED0(omObjData *object);

omObjFunc lbl_2_data_CC[] = {
	fn_2_1A38,
	fn_2_2CBC,
	fn_2_1B80,
	fn_2_2D64,
	fn_2_1CF0,
	fn_2_2DCC,
	fn_2_1DE8,
	fn_2_2E20,
	fn_2_20B0,
	fn_2_2ED0
};

char *lbl_2_data_124[] = {
	"kaitei01",
	"kaitei02",
	"kaitei03",
	"kaitei04",
	"kaitei05"
};

s32 lbl_2_data_138[] = {
	0x5C0002,
	0x5C0002,
	0x5C0002,
	0x5C0002,
	0x5C0002,
	0x5C0002,
	0x5C0002,
	0x5C0002,
};

omObjData *fn_2_FC40(s16 arg0, Vec *arg1, Vec *arg2, Vec *arg3);
void fn_2_E6BC(omObjData *object, float arg2, float arg3, float arg4, float arg5, float arg6);

void fn_2_1A38(omObjData *object)
{
	Vec sp20;
	Vec sp14;
	Vec sp8;
	HsfObject *temp_r31 = Hu3DModelObjPtrGet(object->model[0], lbl_2_data_124[0]);
	omObjData *temp_r30;
	temp_r31->type = 2;
	sp20.x = -2500;
	sp20.y = 150;
	sp20.z = -6800;
	sp14.x = 50;
	sp14.y = 50;
	sp14.z = 50;
	sp8.x = 1500;
	sp8.y = 150;
	sp8.z = -4800;
	temp_r30 = fn_2_FC40(18, &sp20, &sp14, &sp8);
	fn_2_E6BC((omObjData *)temp_r30->work[0], 5, 1.5, 0.2, 0.8, 3);
}

void fn_2_1B80(omObjData *object)
{
	Vec sp14;
	Vec sp8;
	omObjData *temp_r31;
	HsfObject *temp_r30 = Hu3DModelObjPtrGet(object->model[0], lbl_2_data_124[1]);
	
	temp_r30->type = 2;
	sp14.x = -1000;
	sp14.y = 0;
	sp14.z = -9100;
	sp8.x = 150;
	sp8.y = 100;
	sp8.z = 100;
	temp_r31 = fn_2_FC40(14, &sp14, &sp8, &sp14);
	omSetRot(temp_r31, 3, 0, 0);
	omSetSca(temp_r31, 0, 0, 50);
	fn_2_E6BC((omObjData *)temp_r31->work[0], 4.5, 2.5, 0.08, 0.9, 1);
}

void fn_2_1CF0(omObjData *object)
{
	Vec sp20;
	Vec sp14;
	Vec sp8;
	HsfObject *temp_r31 = Hu3DModelObjPtrGet(object->model[0], lbl_2_data_124[2]);
	temp_r31->type = 2;
	sp20.x = 500;
	sp20.y = 0;
	sp20.z = -24300;
	sp14.x = 200;
	sp14.y = 100;
	sp14.z = 100;
	sp8.x = 1000;
	sp8.y = 0;
	sp8.z = -16300;
	fn_2_FC40(40, &sp20, &sp14, &sp8);
}