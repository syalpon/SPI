#include "object.h"
#include "type.h"

static U4 u4g_object_num = 0;

OBJECT_CLASS::OBJECT_CLASS()
{
    u4_object_number = u4g_object_num++;
}