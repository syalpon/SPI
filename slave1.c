#include "spi.h"
#include "timer.h"
#include "define.h"
#include <stdio.h>

/*global変数*/
extern Data data;

extern char data_input(unsigned char *,Kind );
extern void data_output(char ,Kind );

void *slave1(void *p_data){
    unsigned char buff;
    while(1){
        if(data.ss1 == Lo){
            /*山タイミングで取得する為に半周期遅延させる*/
            //sleep_halfperiod;
            printf("slave1 Receiving\n");
            data_input(&buff,SIMO);
            printf("slave1 Received : %x\n",buff);
            data.ss1 = Hi;
        }
        sleep_halfperiod;
    }
	return NULL;
} 