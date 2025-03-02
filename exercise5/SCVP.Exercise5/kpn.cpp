#include <unistd.h>
#include <systemc.h>

#include "kpn.h"

// ADD THINGS HERE
unsigned int valuea, valueb, valuec, valued;
void kpn::add()
{
    while (true)
    {
        a.read(valuea);
        c.read(valuec);
        b.write(valuea + valuec);
    }
}
void kpn::split()
{
    unsigned int counter = 0;
    while (true)
    {
        if (counter == 10)
        {
            sc_stop();
        }
        b.read(valueb);
        a.write(valueb);
        d.write(valueb);
        counter++;
        e = valueb;
        std::cout << "Output value: " << e << std::endl;
    }
}
void kpn::delay()
{
    while (true)
    {
        d.read(valued);

        c.write(valued);
    }
}