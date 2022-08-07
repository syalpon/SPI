#ifndef _BUS_H_
#define _BUS_H_

#include "type.h"

static VP vp_ICU(VP vp_arg);

class BUS_CLASS
{
public:
    /*コンストラクタ*/
    BUS_CLASS();
    BUS_CLASS(U1 *);    
public:
    U1 *u1_address;
};


#endif