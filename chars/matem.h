#pragma once


class debora
{
public:
    int xxx = 0;

    debora(int d)
    {
        xxx = d;
    }
    debora() : debora(10) {}

    void say();    
    virtual void borea(){cout << "xxx";};
};