#include <iostream>
#include <stdio.h>
#include "clsRegister.hpp"
using std::stringstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    u32 x=0x0;
    u32 y;
    u8 c;
    clsRegister<u32,u32> x_reg(&x , READ_AND_WRITE);

    x_reg.setRegisterValue(0xff);
    printf("%x\n",x);
    x_reg.getRegisterValue(y);
    printf("%x\n",y);
    x_reg.setRegisterValue(0x01);
    x_reg.setBit(1);
    x_reg.getRegisterValue(y);
    printf("%x\n",x);
    x_reg.getBit(c,2);
    printf("%x\n",c);
    x_reg.clearBit(0);
    printf("%x\n",x);
    return 0;
}