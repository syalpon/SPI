#ifndef _DEVICE_H_
#define _DEVICE_H_

#include "type.h"
#include "object.h"
#include "bus.h"

/*�f�o�C�X�N���X�FID�𓾂�ׂɃI�u�W�F�N�g�N���X���p��*/
class DEVICE_CLASS:public OBJECT_CLASS
{
public:         
    DEVICE_CLASS();         /*�R���X�g���N�^*/
    DEVICE_CLASS(U4);       /*�R���X�g���N�^*/
    ~DEVICE_CLASS();        /*�f�X�g���N�^*/

protected:
    BUS_CLASS bus_M_CLK;    /*�N���b�N�o�X�͋��ʂ̈׃|�C���^�ŋ��ʃ��������Q��*/
    BUS_CLASS bus_M_DO;     /*�f�[�^�o�X�͋��ʂ̈׃|�C���^�ŋ��ʃ��������Q��*/
    BUS_CLASS bus_M_DI;     /*�f�[�^�o�X�͋��ʂ̈׃|�C���^�ŋ��ʃ��������Q��*/
    BUS_CLASS bus_M_SS;     /*�X���[�u�Z���N�g�̓X���[�u�̐������K�v�Ȉד��I�Ɋm��*/

private:
    
};

#endif
