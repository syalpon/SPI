#include <stdio.h>
class A_Class
{
public:
    A_Class()
    {
        printf("A constructor\n");
    }
    
    A_Class(int i)
    {
        printf("A(int) constructor\n");
    }
    ~A_Class()
    {
        printf("A destoructor\n");
    }
    int a;
    int b;
};

class B_Class
{
public:
    B_Class():a(1)
    {
        printf("B constructor\n");
    }
    ~B_Class()
    {
        printf("B destoructor\n");
    }
    A_Class a;
    A_Class b;
};


int main()
{
    B_Class b;

}