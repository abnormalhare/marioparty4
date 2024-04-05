#include "game/object.h"
#include "game/gamework_data.h"
#include "game/minigame_seq.h"
#include "game/wipe.h"
#include "game/audio.h"
#include "game/hsfman.h"

s32 bssPad2;
Process* lbl_1_bss_3980;
omObjData* lbl_1_bss_397C;
s16 lbl_1_bss_3978;

s32 fn_1_4C0(s32 arg0);

void fn_1_4D0C(void);
void fn_1_4D54(void);
void fn_1_4E8C(void);
void fn_1_4FAC(void);
void fn_1_50E8(void);
void fn_1_51E4(void);
void fn_1_52AC(void);
void fn_1_53B8(void);
void fn_1_5574(void);
void fn_1_5630(void);
s16 fn_1_5804(void); 
void fn_1_5A80(void);
void fn_1_5BB0(void);
void fn_1_4B7C(void);
void fn_1_4C6C(omObjData* obj);
void fn_1_4C3C(s32 arg0);
void fn_1_568(s16 arg0, s16 arg1, s16 arg2);
s32 fn_1_508(u8 arg0);
s32 fn_1_53C(u8 arg0);
void fn_1_3C4(u8 arg0);

typedef void (*ObjFuncs)(void);
//data
ObjFuncs lbl_1_data_2A8[] = {
    fn_1_4D0C,
    fn_1_4D54,
    fn_1_4E8C,
    fn_1_4FAC,
    fn_1_50E8,
    fn_1_51E4,
    fn_1_52AC,
    fn_1_53B8,
    fn_1_5574,
    fn_1_5630,
    fn_1_5A80,
    fn_1_5BB0,
    fn_1_4B7C
};

typedef struct unkDominationData5 {
    u32 unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    char unk_0A[6];
    s16 unk_10;
    char unk_12[10];
    s16 unk_1C[4];
    s16 unk_24;
    char unk_26[2];
    Vec unk_28;
    Vec unk_34;
    f32 unk_40;
    s32 unk_44;
} unkDominationData5;

void fn_1_4980(Process* arg0) {
    s32 i;
    unkDominationData5* temp_r31;

    lbl_1_bss_3980 = arg0;
    lbl_1_bss_397C = omAddObjEx(lbl_1_bss_3980, 0x40, 0U, 0U, 0, fn_1_4C6C);
    lbl_1_bss_397C->data = HuMemDirectMallocNum(HEAP_SYSTEM, 0x48, 0x10000000U);
    temp_r31 = lbl_1_bss_397C->data;
    Hu3DShadowCreate(45.0f, 10.0f, 10000.0f);
    Hu3DShadowTPLvlSet(0.6f);
    fn_1_1B1C(lbl_1_bss_3980);
    lbl_1_bss_3978 = GWMGRecordGet(1);
    
    if (lbl_1_bss_3978 == 0) {
        lbl_1_bss_3978 = 0x96;
    }
    
    fn_1_14F0(lbl_1_bss_3980, lbl_1_bss_3978);
    fn_1_F4(lbl_1_bss_3980);
    fn_1_2354(lbl_1_bss_3980);
    fn_1_3AC8(lbl_1_bss_3980);
    fn_1_41CC(lbl_1_bss_3980);
    fn_1_5C5C(lbl_1_bss_3980, lbl_1_bss_3978);
    WipeCreate(1, 0, 0x3C);
    temp_r31->unk_06 = -1;
    temp_r31->unk_08 = -1;
    temp_r31->unk_24 = 0;
    
    for (i = 0; i < 4; i++) {
        temp_r31->unk_1C[i] = -1;
    }
    
    fn_1_5F40(0);
    fn_1_4C3C(0);
}

void fn_1_4B7C(void) {
    unkDominationData5* temp_r31;

    temp_r31 = lbl_1_bss_397C->data;
    if (temp_r31->unk_04 == 0) {
        WipeCreate(2, 0, 0x3C);
        temp_r31->unk_04++;
    }
    if (WipeStatGet() == 0) {
        HuAudFadeOut(100);
        
        if (temp_r31->unk_06 != -1) {
            MGSeqKill(temp_r31->unk_06);
        }
        
        if (temp_r31->unk_08 != -1) {
            MGSeqKill(temp_r31->unk_08);
        }
        
        fn_1_194();
        fn_1_1CA8();
        fn_1_15D8();
        fn_1_3B68();
        fn_1_44F4();
        fn_1_5ECC();
        omOvlReturnEx(1, 1);
    }
}

void fn_1_4C3C(s32 arg0) {
    unkDominationData5* temp_r31;

    temp_r31 = lbl_1_bss_397C->data;
    temp_r31->unk_00 = arg0;
    temp_r31->unk_04 = 0;
}

void fn_1_4C6C(omObjData* obj) {
    unkDominationData5* temp_r30;
    unkDominationData5* temp_r31;
    
    temp_r30 = lbl_1_bss_397C->data;
    lbl_1_data_2A8[temp_r30->unk_00]();

    if (omSysExitReq != 0) {
        temp_r31 = lbl_1_bss_397C->data;
        temp_r31->unk_00 = 0xC;
        temp_r31->unk_04 = 0;
        omSysExitReq = 0;
    }
}

void fn_1_4D0C(void) {
    unkDominationData5* sp8;
    unkDominationData5* temp_r31;

    sp8 = lbl_1_bss_397C->data;
    temp_r31 = lbl_1_bss_397C->data;
    temp_r31->unk_00 = 1;
    temp_r31->unk_04 = 0;
}

f32 lbl_1_data_2DC[4] = {850.0f, 900.0f, 1300.0f, 1500.0f};
Vec lbl_1_data_2EC = {540.0f, 0.0f, 10000.0f};
Vec lbl_1_data_2F8 = {-50.0f, -360.0f, 0.0f};
f32 lbl_1_data_304 = 2670.0f;
Vec lbl_1_data_308 = {437.0f, 0.0f, 5000.0f};
Vec lbl_1_data_314 = {-50.0f, -360.0f, 0.0f};
f32 lbl_1_data_320 = 2290.0f;
Vec lbl_1_data_324 = {0.0f, 0.0f, 100.0f};
Vec lbl_1_data_330 = {-45.0f, -540.0f, 0.0f};
f32 lbl_1_data_33C = 1910.0f;
Vec lbl_1_data_340 = {0.0f, 0.0f, 100.0f};
Vec lbl_1_data_34C = {-53.0f, -680.0f, 0.0f};
f32 lbl_1_data_358 = 1900.0f;

void fn_1_4D54(void) {
    s16 temp_r0;
    unkDominationData5* temp_r30;
    unkDominationData5* temp_r31;

    temp_r31 = lbl_1_bss_397C->data;
    switch (temp_r31->unk_04) {
    case 0:
        HuAudFXPlay(0x545);
        fn_1_1DB0(&lbl_1_data_2EC, &lbl_1_data_2F8, &lbl_1_data_304, 0, 0);
        temp_r31->unk_04 = 1;
        break;
    case 1:
        fn_1_1DB0(&lbl_1_data_308, &lbl_1_data_314, &lbl_1_data_320, 0x64, 1);
        temp_r31->unk_04 = 2;
        break;
    case 2:
        if (fn_1_1D88() == 0) {
            fn_1_1DB0(&lbl_1_data_324, &lbl_1_data_330, &lbl_1_data_33C, 0x6E, 2);
            temp_r31->unk_04 = 3;
        case 3:
            if (fn_1_1D88() == 0) {
                temp_r30 = lbl_1_bss_397C->data;
                temp_r30->unk_00 = 2;
                temp_r30->unk_04 = 0;
                return;
            }
        }
    }
}

void fn_1_4E8C(void) {
    s32 i;
    unkDominationData5* temp_r29;
    unkDominationData5* temp_r31;

    temp_r31 = lbl_1_bss_397C->data;
    if (temp_r31->unk_06 == -1) {
        temp_r31->unk_06 = MGSeqCreate(3, 0);
        temp_r31->unk_44 = HuAudSeqPlay(0x46);
        fn_1_2564();
        for (i = 0; i < 4; i++) {
            fn_1_568(i, 1, 0x3C);
        }
    }
    if (MGSeqStatGet(temp_r31->unk_06) == 0) {
        MGSeqKill(temp_r31->unk_06);
        temp_r31->unk_06 = -1;
        temp_r31->unk_10 = 0x258;
        temp_r31->unk_08 = MGSeqCreate(1, temp_r31->unk_10 / 60, -1, -1);
        fn_1_1E4();
        temp_r29 = lbl_1_bss_397C->data;
        temp_r29->unk_00 = 3;
        temp_r29->unk_04 = 0;
    }
}

void fn_1_4FAC(void) {
    s16 temp_r0;
    unkDominationData5* temp_r31;
    unkDominationData5* temp_r30;
    unkDominationData5* temp_r29;
    
    temp_r31 = lbl_1_bss_397C->data;
    if (temp_r31->unk_10 > 0) {
        if ((--temp_r31->unk_10 % 60) == 0) {
            MGSeqParamSet(temp_r31->unk_08, 1, (temp_r31->unk_10 / 60));
        }
        return;
    }
    
    MGSeqParamSet(temp_r31->unk_08, 2, -1);
    temp_r31->unk_08 = -1;
    HuAudSeqFadeOut(temp_r31->unk_44, 0x64);
    fn_1_238();
    fn_1_5804();
    
    if (temp_r31->unk_24 > 0) {
        temp_r30 = lbl_1_bss_397C->data;
        temp_r30->unk_00 = 4;
        temp_r30->unk_04 = 0;
        return;
    }
    
    temp_r29 = lbl_1_bss_397C->data;
    temp_r29->unk_00 = 6;
    temp_r29->unk_04 = 0;
}

void fn_1_50E8(void) {
    unkDominationData5* temp_r31;
    unkDominationData5* temp_r30;

    temp_r31 = lbl_1_bss_397C->data;
    switch (temp_r31->unk_04++) {                              /* irregular */
    case 0xA:
        fn_1_1DB0(&lbl_1_data_340, &lbl_1_data_34C, &lbl_1_data_358, 0xB4, 4);
        return;
    case 0x32:
        fn_1_28C();
        return;
    case 0x78:
        fn_1_2E0();
        return;
    case 0x9A:
        fn_1_334();
        return;
    case 0xBE:
        temp_r31->unk_44 = HuAudSeqPlay(0x3A);
        fn_1_25C0();
        temp_r30 = lbl_1_bss_397C->data;
        temp_r30->unk_00 = 5;
        temp_r30->unk_04 = 0;
        return;
    }
}

void fn_1_51E4(void) {
    Vec sp8;
    unkDominationData5* temp_r30;
    unkDominationData5* temp_r31;

    temp_r30 = lbl_1_bss_397C->data;
    if ((temp_r30->unk_04++ >= 0xF) || (fn_1_2880() != 0)) {
        if (fn_1_2880() == 0) {
            fn_1_1CD4(&sp8.z, &sp8.y, &sp8.x);
            sp8.x += 33.5f;
            fn_1_1CAC(sp8.z, sp8.y, sp8.x);
            return;
        }
        temp_r31 = lbl_1_bss_397C->data;
        temp_r31->unk_00 = 6;
        temp_r31->unk_04 = 0;
    }
}

void fn_1_52AC(void) {
    unkDominationData5* temp_r31;
    unkDominationData5* temp_r30;
    unkDominationData5* temp_r29;

    temp_r31 = lbl_1_bss_397C->data;
    if (temp_r31->unk_04 == 0) {
        temp_r31->unk_06 = MGSeqCreate(3, 1);
        temp_r31->unk_04++;
        HuAudSeqFadeOut(temp_r31->unk_44, 0x64);
    }
    if (MGSeqStatGet(temp_r31->unk_06) == 0) {
        MGSeqKill(temp_r31->unk_06);
        temp_r31->unk_06 = -1;
        if (temp_r31->unk_08 != 0) {
            MGSeqKill(temp_r31->unk_08);
            temp_r31->unk_08 = -1;
        }
        if (temp_r31->unk_24 > 0) {
            temp_r30 = lbl_1_bss_397C->data;
            temp_r30->unk_00 = 7;
            temp_r30->unk_04 = 0;
            return;
        }
        temp_r29 = lbl_1_bss_397C->data;
        temp_r29->unk_00 = 0xA;
        temp_r29->unk_04 = 0;
    }
}

void fn_1_53B8(void) {
    s32 i;
    unkDominationData5* temp_r31;
    unkDominationData5* temp_r29;
    unkDominationData5* temp_r28;
    
    temp_r31 = lbl_1_bss_397C->data;
    if (temp_r31->unk_04 == 0) {
        fn_1_1DB0(&temp_r31->unk_28, &temp_r31->unk_34, &temp_r31->unk_40, 0x3C, 4);
        temp_r31->unk_04++;
        for (i = 0; i < 4; i++) {
            if ((fn_1_508(i) == 0) && (fn_1_28B8(i) >= 0x64)) {
                GWGameStat.present[0x38] = 1;
            }
        }
    }
    if (temp_r31->unk_04 == 0x28) {
        fn_1_404();
        for (i = 0; i < temp_r31->unk_24; i++) {
            fn_1_2770(temp_r31->unk_1C[i]);
            fn_1_568(temp_r31->unk_1C[i], 2, 60);
        }
    }
    if (temp_r31->unk_04 == 0x46) {
       for (i = 0; i < temp_r31->unk_24; i++) {
            if (!(fn_1_508(temp_r31->unk_1C[i])) && (lbl_1_bss_3978 < fn_1_28D4())) {
                temp_r29 = lbl_1_bss_397C->data;
                temp_r29->unk_00 = 8;
                temp_r29->unk_04 = 0;
                return;
            }
        }
        temp_r28 = lbl_1_bss_397C->data;
        temp_r28->unk_00 = 9;
        temp_r28->unk_04 = 0;
    } else {
        temp_r31->unk_04++;
    }

}

void fn_1_5574(void) {
    unkDominationData5* temp_r31;
    unkDominationData5* temp_r30;
    
    temp_r31 = lbl_1_bss_397C->data;
    if (temp_r31->unk_04 == 0) {
        GWMGRecordSet(1, fn_1_28D4());
        temp_r31->unk_06 = MGSeqCreate(0xE, fn_1_28D4());
        fn_1_5F40(1);
        temp_r31->unk_04++;
        return;
    }
    if (MGSeqStatGet(temp_r31->unk_06) == 0) {
        temp_r30 = lbl_1_bss_397C->data;
        temp_r30->unk_00 = 9;
        temp_r30->unk_04 = 0;
    }
}

void fn_1_5630(void) {
    unkDominationData5* temp_r31;
    unkDominationData5* temp_r29;
    s32 temp_r28;
    s16 temp_r27;
    s32 temp_r26;
    s32 coins;
    s32 coins2;
    s32 temp_r23;
    s32 temp_r22;
    s32 temp_r21;
    s32 i;

    temp_r31 = lbl_1_bss_397C->data;
    if (temp_r31->unk_04 == 0) {
        for (i = 0; i < 4; i++) {
            if (fn_1_53C(i) == 0) {
                return;
            }
        }
        if (temp_r31->unk_24 == 0) {
            temp_r31->unk_06 = MGSeqCreate(3, 2);
            HuAudSStreamPlay(4);
        } else {
            temp_r21 = fn_1_4C0(temp_r31->unk_1C[3]);
            temp_r22 = fn_1_4C0(temp_r31->unk_1C[2]);
            temp_r23 = fn_1_4C0(temp_r31->unk_1C[1]);
            temp_r31->unk_06 = MGSeqCreate(5, 3, fn_1_4C0(temp_r31->unk_1C[0]), temp_r23, temp_r22, temp_r21);
            for (i = 0; i < 4; i++) {
                if (temp_r31->unk_1C[i] != -1) {

                    fn_1_3C4(temp_r31->unk_1C[i]);
                    temp_r26 = temp_r31->unk_1C[i];
                    coins = GWPlayer[temp_r26].coin_win;
                    coins2 = coins;
                    temp_r27 = coins2 + 0xA;
                    temp_r28 = temp_r31->unk_1C[i];
                    if (_CheckFlag(0x1000CU) == 0) {
                        GWPlayer[temp_r28].coin_win = temp_r27;
                    }
                }                    
            }
            HuAudSStreamPlay(1);
        }
        
    }
    if (temp_r31->unk_04++ >= 0xD2) {
        MGSeqKill(temp_r31->unk_06);
        temp_r31->unk_06 = -1;
        temp_r29 = lbl_1_bss_397C->data;
        temp_r29->unk_00 = 0xC;
        temp_r29->unk_04 = 0;
    }
}

s16 fn_1_5804(void) {
    f32 var_f31;
    f32 var_f30;
    s16 temp_r28;
    s16 temp_r3;
    s16 var_r29;
    s32 i;
    s32 var_r27;
    s32 var_r26;
    
    s32 var_r30;
    unkDominationData5* temp_r31;

    var_r27 = 0;
    var_r26 = 0;
    temp_r31 = lbl_1_bss_397C->data;
    var_r29 = 0;

    for (i = 0; i < 4; i++) {
        temp_r28 = fn_1_28B8(i);
        if (temp_r28 > var_r29) {
            var_r29 = temp_r28;
        }
    }

    for (i = 0; i < 4; i++) {
        temp_r28 = fn_1_28B8(i);
        if (var_r29 == temp_r28) {
            if (var_r29 > 0) {
                temp_r31->unk_1C[temp_r31->unk_24++] = i;
                fn_1_388((u8) i, 1);
            }
            if (var_r27 == 0) {
                var_r27 = 1;
                var_f31 = 400.0f * i;
            } else {
                var_r26 = 1;
                var_f30 = 400.0f * i;
            }
        } else {
            fn_1_388((u8) i, 2);
        }        
    }
    if (var_r26 == 0) {
        var_f30 = var_f31;
    }
    temp_r31->unk_28.x = (600.0f - (0.5f * (var_f30 + var_f31)));
    temp_r31->unk_28.y = 250.0f;
    temp_r31->unk_28.z = (200.0f * ((s16) var_r29 + 2));
    temp_r31->unk_34.x = -42.0f;
    temp_r31->unk_34.y = -720.0f;
    temp_r31->unk_34.z = 0.0f;
    temp_r31->unk_40 = lbl_1_data_2DC[(s32) ((var_f30 - var_f31) / 400.0f)];
    return var_r29;
}

void fn_1_5A80(void) {
    s32 sp20;
    s32 sp1C;
    Vec sp18 = {0.0f, 0.0f, -300.0f};
    Vec spC = {-40.0f, -720.0f, 0.0f};
    f32 sp8;
    s16 temp_r0;
    s16 temp_r3;
    unkDominationData5* temp_r30;
    unkDominationData5* temp_r31;

    sp8 = 1420.0f;
    temp_r31 = lbl_1_bss_397C->data;
    switch (temp_r31->unk_04++) {
    case 0x0:
        MGSeqKill(temp_r31->unk_08);
        temp_r31->unk_08 = -1;
        fn_1_1DB0(&sp18, &spC, &sp8, 0x78, 4);
        return;
    case 0xA:
        fn_1_5F40(0);
        fn_1_28C();
        return;
    case 0x78:
        fn_1_404();
        temp_r30 = lbl_1_bss_397C->data;
        temp_r30->unk_00 = 9;
        temp_r30->unk_04 = 0;
        return;
        /* fallthrough */
    case 0x3C:
        break;
    }
    
}

void fn_1_5BB0(void) {
    unkDominationData5* temp_r30;
    unkDominationData5* temp_r31;

    temp_r31 = lbl_1_bss_397C->data;
    if (temp_r31->unk_04 == 0) {
        temp_r31->unk_06 = MGSeqCreate(3, 2);
        temp_r31->unk_04++;
    }
    if (MGSeqStatGet(temp_r31->unk_06) == 0) {
        MGSeqKill(temp_r31->unk_06);
        temp_r31->unk_06 = -1;
        temp_r30 = lbl_1_bss_397C->data;
        temp_r30->unk_00 = 0xC;
        temp_r30->unk_04 = 0;
    }
}

f32 pad4[1] = {0.0f};
const f32 pad5 = 0.0f;