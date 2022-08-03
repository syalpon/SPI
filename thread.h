#ifndef _THREAD_H_
#define _THREAD_H_

#include "type.h"
#include "object.h"
/*------マクロ------*/
#define SLAVE_NUM ((U1)4)                           /*スレーブの数*/
#define MASTER_NUM ((U1)1)                          /*マスタの数*/
#define THREAD_NUM ((U1)(SLAVE_NUM + MASTER_NUM))   /*立てるスレッドの数*/

#endif