#include "spi.h"
#include "timer.h"
#include "define.h"
#include <stdio.h>


/*global変数*/
extern Data data;

void *clock_timer(void *p_data){
	while(1){
		if( (data.ss0 & data.ss1 & data.ss2 & data.ss3 & data.ss4) == Lo ){
			data.sclk++;
			//printf("time:%hhd\n",data.sclk);
		}else{
			data.sclk = Hi;
		}
		sleep_halfperiod;
	}
	
	return NULL;
}
