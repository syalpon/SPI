#ifndef _SLAVE_H_
#define _SLAVE_H_

#include "type.h"
#include "device.h"

/*スレーブ:識別子を得る為オブジェクトクラスを継承*/
class SLAVE_CLASS : public DEVICE_CLASS
{
public:
    SLAVE_CLASS();      /*コンストラクタ*/
    SLAVE_CLASS(VP);    /*コンストラクタ*/

public:


public:
    U1 u1_level_previous;       /*エッジ前回値*/
    U1 u1_EdgeDetection(U1);    /*エッジ検出関数*/
    U1 u1_SS_ON();
};

#endif
