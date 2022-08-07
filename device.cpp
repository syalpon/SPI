

#include "type.h"
#include "device.h"


/*コンストラクタ*/
DEVICE_CLASS::DEVICE_CLASS()
{
    DEVICE_CLASS(1);
}

DEVICE_CLASS::DEVICE_CLASS(U4 u4_SS_num)
{
    /*動的配列のメモリ確保*/
    U1 *u1p_M_SS = new U1[u1_SS_num];
}

/*デストラクタ*/
DEVICE_CLASS::~DEVICE_CLASS()
{
    /*動的メモリの解放*/
    delete[] u1p_M_SS;
}