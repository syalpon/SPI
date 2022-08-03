#ifndef _MASTER_H_
#define _MASTER_H_

#include "type.h"
#include "thread.h"
#include "object.h"
#include "spi.h"

/*マスタ:識別子を得る為オブジェクトクラスを継承*/
class MASTER_CLASS : protected OBJECT_CLASS
{
public:
    MASTER_CLASS();                     /*コンストラクタ*/
public:
    /*SPI用*/
    U1 *u1_M_CLK;           /*クロックバスは共通の為ポインタで共通メモリを参照*/
    U1 *u1_M_DO;            /*データバスは共通の為ポインタで共通メモリを参照*/
    U1 *u1_M_DI;            /*データバスは共通の為ポインタで共通メモリを参照*/
    U1 *u1_M_SS[SLAVE_NUM]; /*スレーブセレクトはスレーブの数だけ必要*/
};

#endif
