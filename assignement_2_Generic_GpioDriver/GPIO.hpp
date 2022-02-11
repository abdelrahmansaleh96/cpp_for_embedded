
class GPIO
{
    public:
    GPIO()
    {
        
    }
    virtual ~GPIO()
    {
        
    }
    virtual void write(int pin,int value)= 0;
    virtual void tog(int pin,int value)= 0;
    virtual int read(int pin,int value)= 0;
};