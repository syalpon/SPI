#include "spi.h"
#include "timer.h"
#include "define.h"
#include <stdio.h>

/*global変数*/
extern Data data;

extern char data_input(unsigned char *,Kind );
extern void data_output(char ,Kind );

void *slave3(void *p_data){
    unsigned char buff;
    while(1){
        if(data.ss3 == Lo){
            /*山タイミングで取得する為に半周期遅延させる*/
            //sleep_halfperiod;
            printf("slave3 Receiving\n");
            data_input(&buff,SIMO);
            printf("slave3 Received : %x\n",buff);
            data.ss3 = Hi;
        }
        sleep_halfperiod;
    }
	return NULL;
}