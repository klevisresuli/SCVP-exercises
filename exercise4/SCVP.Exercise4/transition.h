#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
// TODO

// Custom Interfaces, Ports and Channels

// SC_MODULE(transition)
//{
//     sc_port<placeInterface> in;
//     sc_port<placeInterface> out;
//
//     SC_CTOR(transition)
//     {
//     }
//
//     void fire()
//     {
//         if (in->testTockens() > 0)
//         {
//             std::cout << this->name() << ": Fired" << std::endl;
//             in->removeTockens(1);
//             out->addTockens(1);
//         }
//         else
//         {
//             std::cout << this->name() << ": Not fired" << std::endl;
//         }
//     }
// };

// Multiple Ports
// template <unsigned int N = 1, unsigned int M = 1>
// SC_MODULE(transition)
//

// {
//     sc_port<placeInterface, N, SC_ALL_BOUND> in;
//     sc_port<placeInterface, M, SC_ALL_BOUND> out;

//     SC_CTOR(transition)
//     {
//     }

//     void fire()
//     {
//         bool fired = true;
//         for (int i = 0; i < N; i++)
//         {
//             if (in[i]->testTockens() == 0)
//             {
//                 fired = false;
//                 break;
//             }
//         }
//         if (fired)
//         {
//             std::cout << this->name() << ": Fired" << std::endl;
//             for (int i = 0; i < N; i++)
//             {
//                 in[i]->removeTockens(1);
//             }
//             for (int i = 0; i < M; i++)
//             {
//                 out[i]->addTockens(1);
//             }
//         }
//         else
//         {
//             std::cout << this->name() << ": Not fired" << std::endl;
//         }
//     }
// };

// templated channels

// template <unsigned int N = 1, unsigned int M = 1>
// SC_MODULE(transition)
// {
//     sc_port<placeInterface, N, SC_ALL_BOUND> in;
//     sc_port<placeInterface, M, SC_ALL_BOUND> out;

//     SC_CTOR(transition)
//     {
//     }

//     void fire()
//     {
//         bool fired = true;
//         for (int i = 0; i < N; i++)
//         {
//             if (in[i]->testTockens() == 0)
//             {
//                 fired = false;
//                 break;
//             }
//         }
//         if (fired)
//         {
//             std::cout << this->name() << ": Fired" << std::endl;
//             for (int i = 0; i < N; i++)
//             {
//                 in[i]->removeTockens();
//             }
//             for (int i = 0; i < M; i++)
//             {
//                 out[i]->addTockens();
//             }
//         }
//         else
//         {
//             std::cout << this->name() << ": Not fired" << std::endl;
//         }
//     }
// };

// Inhibitors Arcs
template <unsigned int N = 1, unsigned int M = 1, unsigned int L = 0>
SC_MODULE(transition)
{
    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;

    SC_CTOR(transition)
    {
    }

    void fire()
    {
        bool fired = true;
        for (int i = 0; i < N; i++)
        {
            if (in[i]->testTockens() == 0)
            {
                fired = false;
                break;
            }
        }
        if (fired)
        {
            for (int i = 0; i < L; i++)
            {
                if (inhibitors[i]->testTockens() > 0)
                {
                    fired = false;
                    break;
                }
            }
        }
        if (fired)
        {
            std::cout << this->name() << ": Fired" << std::endl;
            for (int i = 0; i < N; i++)
            {
                in[i]->removeTockens();
            }
            for (int i = 0; i < M; i++)
            {
                out[i]->addTockens();
            }
        }
        else
        {
            std::cout << this->name() << ": Not fired" << std::endl;
        }
    }
};

#endif // TRANSITION_H
