#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
// custom interfaces, ports and channels
// SC_MODULE(toplevel)
// {

//     place p1, p2;
//     transition t1, t2;

//     void process()
//     {
//         while (true)
//         {
//             wait(10, SC_NS);
//             t1.fire();
//             wait(10, SC_NS);
//             t1.fire();
//             wait(10, SC_NS);
//             t2.fire();
//             sc_stop();
//         }
//     }

//     SC_CTOR(toplevel) : p1(1), p2(0), t1("t1"), t2("t2")
//     {
//         t1.in.bind(p1);
//         t1.out.bind(p2);
//         t2.in.bind(p2);
//         t2.out.bind(p1);
//         SC_THREAD(process);
//     }
// };

//-----------------------------------------------------------------------------------------------------------------------------//
// multiple ports

// SC_MODULE(toplevel)
// {

//     place p1, p2, p3, p4;
//     transition<1, 2> t1;
//     transition<2, 1> t2;
//     transition<1, 1> t3;

//     void process()
//     {
//         while (true)
//         {
//             wait(10, SC_NS);
//             t1.fire();
//             wait(10, SC_NS);
//             t2.fire();
//             wait(10, SC_NS);
//             t3.fire();
//             wait(10, SC_NS);
//             t2.fire();
//             sc_stop();
//         }
//     }

//     SC_CTOR(toplevel) : p1(1), p2(0), p3(0), p4(0), t1("t1"), t2("t2"), t3("t3")
//     {
//         t1.in.bind(p1);
//         t1.out.bind(p2);
//         t1.out.bind(p3);
//         t2.in.bind(p2);
//         t2.in.bind(p4);
//         t2.out.bind(p1);
//         t3.in.bind(p3);
//         t3.out.bind(p4);
//         SC_THREAD(process);
//     }
// };

// templated channels

// SC_MODULE(toplevel)
// {

//     place<1, 1> p1, p2, p3, p4;
//     transition<1, 2> t1;
//     transition<2, 1> t2;
//     transition<1, 1> t3;

//     void process()
//     {
//         while (true)
//         {
//             wait(10, SC_NS);
//             t1.fire();
//             wait(10, SC_NS);
//             t2.fire();
//             wait(10, SC_NS);
//             t3.fire();
//             wait(10, SC_NS);
//             t2.fire();
//             sc_stop();
//         }
//     }

//     SC_CTOR(toplevel) : p1(1), p2(0), p3(0), p4(0), t1("t1"), t2("t2"), t3("t3")
//     {
//         t1.in.bind(p1);
//         t1.out.bind(p2);
//         t1.out.bind(p3);
//         t2.in.bind(p2);
//         t2.in.bind(p4);
//         t2.out.bind(p1);
//         t3.in.bind(p3);
//         t3.out.bind(p4);
//         SC_THREAD(process);
//     }
// };

// int sc_main(int, char **)
// {
//     // TODO
//     toplevel t("t");

//     sc_start();
//     return 0;
// }

//-----------------------------------------------------------------------------------------------------------------------------//
// Single memory bank
// SC_MODULE(toplevel)
// {

//     place<1, 1> IDLE;
//     place<3, 3> ACTIVE;
//     transition<1, 1> ACT;
//     transition<1, 1> RD;
//     transition<1, 1> WR;
//     transition<1, 1> PRE;

//     void process()
//     {
//         while (true)
//         {
//             wait(10, SC_NS);
//             ACT.fire();
//             wait(10, SC_NS);
//             ACT.fire();
//             wait(10, SC_NS);
//             RD.fire();
//             wait(10, SC_NS);
//             WR.fire();
//             wait(10, SC_NS);
//             PRE.fire();
//             wait(10, SC_NS);
//             ACT.fire();
//             sc_stop();
//         }
//     }

//     SC_CTOR(toplevel) : IDLE(1), ACTIVE(0), ACT("ACT"), RD("RD"), WR("WR"), PRE("PRE")
//     {
//         ACT.in.bind(IDLE);
//         ACT.out.bind(ACTIVE);
//         RD.in.bind(ACTIVE);
//         RD.out.bind(ACTIVE);
//         WR.in.bind(ACTIVE);
//         WR.out.bind(ACTIVE);
//         PRE.in.bind(ACTIVE);
//         PRE.out.bind(IDLE);
//         SC_THREAD(process);
//     }
// };

SC_MODULE(toplevel)
{

    subnet s1;
    subnet s2;
    place<1, 1> IDLE;

    void process()
    {
        while (true)
        {
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.RD.fire();
            wait(10, SC_NS);
            s1.WR.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s2.PRE.fire();
            wait(10, SC_NS);
            sc_stop();
        }
    }

    SC_CTOR(toplevel) : s1("s1"), s2("s2"), IDLE(2)
    {
        s1.IN.bind(IDLE);
        s1.OUT.bind(IDLE);
        s2.IN.bind(IDLE);
        s2.OUT.bind(IDLE);
        SC_THREAD(process);
    }
};

int sc_main(int, char **)
{
    // TODO
    toplevel t("t");

    sc_start();
    return 0;
}
