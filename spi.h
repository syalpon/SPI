#ifndef _SPI_H_
#define _SPI_H_

/* kind */
typedef enum{
	SCLK,      // シグナルクロック(同期矩形波信号)
	SIMO,      // スレーブIN , マスタOut
	SOMI,      // スレーブOut, マスタIn
	SS         // スレーブセレクト(スレーブ指定信号:Low時通信開始)
}Kind;

/* Data型 */
typedef struct Data_T{
	unsigned char sclk: 1;
	unsigned char simo: 1;
	unsigned char somi: 1;
   	unsigned char ss0 : 1;
	unsigned char ss1 : 1;
	unsigned char ss2 : 1;
	unsigned char ss3 : 1;
	unsigned char ss4 : 1;
}Data;

#endif 