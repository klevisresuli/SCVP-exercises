#include <iostream>
#include <systemc.h>

#include "kpn.h"

/*  What is this KPN doing?
    It is performing a Fibonacci Sequence
*/

int sc_main(int, char **)
{
    sc_signal<unsigned int> output_signal;
    kpn kahn("kpn");

    kahn.e.bind(output_signal);
    sc_start();
    return 0;
}
