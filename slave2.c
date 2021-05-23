#include "spi.h"
#include "timer.h"
#include "define.h"
#include <stdio.h>

/*global変数*/
extern Data data;

extern char data_input(unsigned char *,Kind );
extern void data_output(char ,Kind );

void *slave2(void *p_data){
    unsigned char buff;
    while(1){
        if(data.ss2 == Lo ){
            /*山タイミングで取得する為に半周期遅延させる*/
            //sleep_halfperiod;
            printf("slave2 Receiving\n");
            data_input(&buff,SIMO);
            printf("slave2 Received : %x\n",buff);
            data.ss2 = Hi;
        }
        sleep_halfperiod;
    }
	return NULL;
}