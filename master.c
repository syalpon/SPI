#include "spi.h"
#include "timer.h"
#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*global変数*/
extern Data data;

extern char data_input(Kind );
extern void data_output(char ,Kind );

// マスタ
void *master(void *p_data){
    const size_t BUFF_SIZE = 64;
    char buff[BUFF_SIZE];
    int select = 0;
	do{
        //文字列取得
        printf(">");
        fgets(buff,BUFF_SIZE,stdin);

        //オーバーフロー時
        if(buff[strlen(buff)-1] != '\n'){
            while('\n' != getchar() );
        }

        //q が押された場合終了
		if( strcmp(buff,"q\n") == 0 ){
			break;
		}

        //文字列->数値変換
        select = atoi(buff);

        
        switch(select){
            case 1 : 
                data.ss1 = Lo;
                break;
            case 2 : 
                data.ss2 = Lo;
                break;
            case 3 :
                data.ss3 = Lo;
                break;
            default :
                continue;
        }
        /* 0111 1001のデータを送信 */
        data_output((char)0x79,SIMO);
        sleep_period;
	}while(1);

	return NULL;
}