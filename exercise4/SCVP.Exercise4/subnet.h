#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
// TODO

SC_MODULE(subnet)
{
    sc_port<placeInterface> IN;
    sc_port<placeInterface> OUT;
    place<3, 3> ACTIVE;
    transition<1, 1, 1> ACT;
    transition<1, 1> RD;
    transition<1, 1> WR;
    transition<1, 1> PRE;

    void process()
    {
    }

    SC_CTOR(subnet) : ACTIVE(0), ACT("ACT"), RD("RD"), WR("WR"), PRE("PRE"), IN("IN"), OUT("OUT")
    {
        ACT.in.bind(IN);
        ACT.out.bind(ACTIVE);
        ACT.inhibitors.bind(ACTIVE);
        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);
        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);
        PRE.in.bind(ACTIVE);
        PRE.out.bind(OUT);
        SC_THREAD(process);
    }
};

#endif // SUBNET_H
