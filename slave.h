#ifndef _SLAVE_H_
#define _SLAVE_H_

#include "type.h"
#include "thread.h"
#include "object.h"

/*スレーブ:識別子を得る為オブジェクトクラスを継承*/
class SLAVE_CLASS : public OBJECT_CLASS
{
public:
    SLAVE_CLASS(); /*コンストラクタ*/
public:
    /*SPI用*/
    U1 *u1_S_CLK;  /*クロックバスは共通の為ポインタで共通メモリを参照*/
    U1 *u1_S_DO;   /*データバスは共通の為ポインタで共通メモリを参照*/
    U1 *u1_S_DI;   /*データバスは共通の為ポインタで共通メモリを参照*/
    U1 *u1_S_SS;   /*スレーブセレクトのエッジをトリガにデータの受信・ポーリング*/

public:
    U1 u1_level_previous;       /*エッジ前回値*/
    U1 u1_EdgeDetection(U1);    /*エッジ検出関数*/
};

#endif
