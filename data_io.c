#include "spi.h"
#include "timer.h"
#include "define.h"
#include <stdio.h>

extern Data data;

void data_output(char send_data,Kind kind){
    /*クロックのHi時に送信*/
    int sent_count = 0;
    unsigned char Bit_Mask = 0x80;  // 1000 0000
    unsigned char data_bit = 0;
    unsigned char send_flag = false;

    /*8bit送信時終了*/
    while( sent_count <= 7 ){
        /*クロック信号がHi時データをセットする*/
        /*谷タイミングで8bitデータを1bitずつセットする*/
        if(data.sclk == Hi && send_flag == true){
            /*データの送信するデータをMSBから順にセット*/
            data_bit = send_data & (Bit_Mask>>sent_count);
            if(kind == SCLK){
                /*Do nothing*/
            }else if(kind == SIMO){
                data.simo = data_bit >> (7-sent_count) ;
                printf("master send : %hhd\n",data.simo);
            }else if(kind == SOMI){
                data.somi = data_bit >> (7-sent_count);
            }else if(kind == SS){
                /*Do nothing*/
            }
            
            sent_count++;
            send_flag = false;
        }else if(data.sclk == Lo){
            send_flag = true;
        }
    }


}

char data_input(unsigned char *receive_data,Kind kind){
    char receive_flag = false;
    int receive_count = 7;
    unsigned char Bit_Mask = 0x80;  // 1000 0000
    unsigned char receive = 0;
    unsigned char send_flag = false;


    /*8bit受信時終了*/
    while( receive_count >= 0 ){
        /*クロック信号がHi時データをセットする*/
        /*山タイミングで8bitデータを1bitずつ読み込む*/
        if(data.sclk == Lo && send_flag == true){
            
            if(kind == SCLK){
                /*Do nothing*/
            }else if(kind == SIMO){
                receive |= (data.simo << receive_count);
                printf("slave  read : %hhd\n",data.simo);
            }else if(kind == SOMI){
                receive |= (data.somi << receive_count);
            }else if(kind == SS){
                /*Do nothing*/
            }
            
            receive_count--;
            send_flag = false;
        }else if(data.sclk == Hi){
            send_flag = true;
        }
        
        if(receive_count < 0){
            *receive_data = receive;
            receive_flag = true;
            break;
        }
    }    
    return receive_flag;
}