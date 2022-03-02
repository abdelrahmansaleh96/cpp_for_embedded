#ifndef _BIT_UTL_H
#define _BIT_UTL_H

#define SET_BIT(Reg,Bit) Reg|=(1<<Bit)
#define CLR_BIT(Reg,Bit) Reg&=~(1<<Bit)
#define GET_BIT(Reg,Bit) ((Reg>>Bit)&1)
#define RSHIFT_REG(Reg,No) Reg>>=No
#define LSHIFT_REG(Reg,No) Reg<<=No
#define CRSHIFT_REG(Reg,Size,No) Reg=(Reg<<(Size-No))|(Reg>>No)
#define CLSHIFT_REG(Reg,Size,No) Reg=(Reg>>(Size-No))|(Reg<<No)
//#define CRSHIFT_REG(Reg,size,No) Reg=(Reg>>No)+((Reg&(((u8)~0)>>(size-No)))<<(size-No))
//#define CLSHIFT_REG(Reg,size,No) Reg=(Reg<<No)+((Reg&((u8)~0)<<(size-No))>>(size-No))
#define ASSIGN_REG(Reg,Value) Reg=Value
#define SET_REG(Reg) Reg|=(~0)
#define CLR_REG(Reg) Reg&=0
#define TGL_BIT(Reg,Bit) Reg^=(1<<Bit)
#define TGL_REG(Reg) Reg^=(~0)
#define SET_H_NIP(Reg) Reg|=((u8)~0)>>4
#define SET_L_NIP(Reg) Reg|=((u8)~0)<<4
#define CLR_H_NIP(Reg) Reg&=((u8)~0)>>4
#define CLR_L_NIP(Reg) Reg&=((u8)~0)<<4
#define GET_H_NIP(Reg) ((Reg>>4)&((u8)~0)>>4)
#define GET_L_NIP(Reg) ((Reg)&((u8)~0)>>4)
#define ASSIGN_H_NIP(Reg,Value) Reg=CLR_H_NIP(Reg)|Value<<4
#define ASSIGN_L_NIP(Reg,Value) Reg=CLR_L_NIP(Reg)|CLR_H_NIP(Value)


#endif