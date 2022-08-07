#ifndef _MASTER_H_
#define _MASTER_H_

#include "type.h"
#include "thread.h"
#include "device.h"

/*マスタ:識別子を得る為オブジェクトクラスを継承*/
class MASTER_CLASS : protected DEVICE_CLASS
{
public:
    MASTER_CLASS();                     /*コンストラクタ*/
public:

};

#endif
