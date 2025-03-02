#ifndef KPN_H
#define KPN_H

#include <systemc.h>

SC_MODULE(kpn)
{
private:
    // ADD THINGS HERE

    sc_fifo<unsigned int> a, b, c, d;
    unsigned int depth = 10;

public:
    sc_out<unsigned int> e;
    SC_CTOR(kpn) : a(depth), b(depth), c(depth), d(depth)
    {
        // ADD THINGS HERE
        b.write(1);
        c.write(0);

        SC_THREAD(add);
        SC_THREAD(split);
        SC_THREAD(delay);
    }

    void add();
    void split();
    void delay();
};

#endif // KPN_H
