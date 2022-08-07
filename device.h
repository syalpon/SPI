#ifndef _DEVICE_H_
#define _DEVICE_H_

#include "type.h"
#include "object.h"
#include "bus.h"

/*デバイスクラス：IDを得る為にオブジェクトクラスを継承*/
class DEVICE_CLASS:public OBJECT_CLASS
{
public:         
    DEVICE_CLASS();         /*コンストラクタ*/
    DEVICE_CLASS(U4);       /*コンストラクタ*/
    ~DEVICE_CLASS();        /*デストラクタ*/

protected:
    BUS_CLASS bus_M_CLK;    /*クロックバスは共通の為ポインタで共通メモリを参照*/
    BUS_CLASS bus_M_DO;     /*データバスは共通の為ポインタで共通メモリを参照*/
    BUS_CLASS bus_M_DI;     /*データバスは共通の為ポインタで共通メモリを参照*/
    BUS_CLASS bus_M_SS;     /*スレーブセレクトはスレーブの数だけ必要な為動的に確保*/

private:
    
};

#endif
