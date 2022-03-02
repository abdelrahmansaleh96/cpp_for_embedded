#ifndef CLSREGISTER_HPP
#define CLSREGISTER_HPP
#include "STD_Types.h"
#include "BIT_UTL.h"
#include "clsRegister_confg.hpp"



template <class Reg_AddressType>
class clsRegister
{
    private:
        Reg_AddressType *  m_Reg_Address;
        u8 m_Reg_u8_Permession;
    public:
        clsRegister(Reg_AddressType  * Reg_Address,u8 Reg_u8_Permession);
        ~clsRegister()
        {

        }
        u8 setRegisterValue(Reg_AddressType Reg_value); //⇒ Sets the whole register bits with the value sent by the user
        u8 getRegisterValue(Reg_AddressType & Reg_value); //⇒ Reads the whole register value
        u8 setBit(u8 bit); //⇒ set only a specific bit in the register by 1
        u8 clearBit(u8 bit); //⇒ set only a specific bit in the register by 0
        u8 getBit(u8 &value,u8 bit);//⇒ get only the value of a specific bit in the register
        void setPermission(u8 permesstion); //⇒ change the register permission of certain bit of the register or the whole register (this API can be used any time during the application running)

};
template <class Reg_AddressType>
clsRegister<Reg_AddressType> :: clsRegister(Reg_AddressType  *Reg_Address,u8 Reg_u8_Permession)
{
    m_Reg_Address = Reg_Address;
    m_Reg_u8_Permession = Reg_u8_Permession;
}

template <class Reg_AddressType>
u8 clsRegister<Reg_AddressType> :: setRegisterValue(Reg_AddressType Reg_value)
{
    if(m_Reg_u8_Permession == WRITE_ONLY || m_Reg_u8_Permession == READ_AND_WRITE)
    {
        *m_Reg_Address=Reg_value;
        return PERMISSION_ACCEPTED;
    }
    else
    {
        return PERMISSION_ERROR;
    }
}

template <class Reg_AddressType>
u8 clsRegister<Reg_AddressType> :: getRegisterValue(Reg_AddressType & Reg_value)
{
    if(m_Reg_u8_Permession == READ_ONLY || m_Reg_u8_Permession == READ_AND_WRITE)
    {
        Reg_value=*m_Reg_Address;
        return PERMISSION_ACCEPTED;
    }
    else 
    {
        return PERMISSION_ERROR;
    }
}

template <class Reg_AddressType>
u8 clsRegister<Reg_AddressType> :: setBit(u8 bit)
{
    if(m_Reg_u8_Permession == WRITE_ONLY || m_Reg_u8_Permession == READ_AND_WRITE)
    {
        SET_BIT(*m_Reg_Address,bit);
        return PERMISSION_ACCEPTED;
    }
    else 
    {
        return PERMISSION_ERROR;
    }   
}


template <class Reg_AddressType>
u8 clsRegister<Reg_AddressType> :: clearBit(u8 bit)
{
    if(m_Reg_u8_Permession == WRITE_ONLY || m_Reg_u8_Permession == READ_AND_WRITE)
    {
        CLR_BIT(*m_Reg_Address,bit);
        return PERMISSION_ACCEPTED;
    }
    else 
    {
        return PERMISSION_ERROR;
    }   
}



template <class Reg_AddressType>
u8 clsRegister<Reg_AddressType> :: getBit(u8 &value,u8 bit)
{
    if(m_Reg_u8_Permession == READ_ONLY || m_Reg_u8_Permession == READ_AND_WRITE)
    {
        value=GET_BIT(*m_Reg_Address,bit);
        return PERMISSION_ACCEPTED;
    }
    else 
    {
        return PERMISSION_ERROR;
    }   
}

template <class Reg_AddressType>
void clsRegister<Reg_AddressType> :: setPermission(u8 permesstion)
{
    m_Reg_u8_Permession = permesstion;
}

#endif