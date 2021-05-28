#include "spi.h"
#include "timer.h"
#include "define.h"
#include "type.h"
#include <stdio.h>


/*global変数*/
extern Data data;

void *clock_timer(void *p_data){
	while(1){
		if( (data.SS1 & data.SS2 & data.SS3 ) == Lo ){
			Sleep_HalfPeriod;
			data.SCK++;
			//printf("time:%hhd\n",data.sclk);
		}else{
			data.SCK = data.CPOL;
		}
		Sleep_HalfPeriod;
	}
	
	return NULL;
}
