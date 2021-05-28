#ifndef _SPI_H_
#define _SPI_H_
#include "type.h"

/* KIND */
typedef enum Kind_T{
	MASTER,
	SLAVE1,
	SLAVE2,
	SLAVE3,
	CLOCK_TIMER
}Kind;

typedef enum DataIo_T{
	SIMO,
	MISO
}DataIo;

/* DATA STRUCT */
typedef struct Data_T{
	U1	SCK:1;			
	U1	SS1:1;			
	U1	SS2:1;
	U1	SS3:1;
	U1	CPOL:1;
	U1	CPHA:1;
	U1	SIMO:1;
	U1	MISO:1;
}Data;

/* MODE SETTING TYPE */
typedef struct Mode_T{
	U1	CPOL;		/*Hiにするとクロック信号がHアクティブ*/
	U1	CPHA;		/*Hiにすると半周期遅れてサンプリング*/
}Mode;

/* DATA SETTING TYPE */
typedef struct Data_Attr_T{
	Mode Mode;
	U2	Speed; 	/*`eropdic speed LSB:1/1000 Unit:second*/
}Data_Attr;

/* CPHA/CPOL MODE */
#define Mode0	{ 0 , 0}
#define Mode1	{ 0 , 1}
#define Mode2	{ 1 , 0}
#define Mpde3	{ 1 , 1}

/* MODE KIND */
typedef enum{
	MODE0,		
	MODE1,		
	MODE2,		
	MODE3,	
}MODE;

/* 送信データ数 */
#define DATA_LENGTH ((S4)8)

/* クロック周期 */
#define CLOCK_SPEED ((S4)100)

#endif 