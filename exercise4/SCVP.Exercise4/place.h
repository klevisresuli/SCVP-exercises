#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:

// custom interface places and channels
//  class placeInterface : public sc_interface
//  {
//  public:
//      virtual void addTockens(unsigned int n) = 0;
//      virtual void removeTockens(unsigned int n) = 0;
//      virtual unsigned int testTockens() = 0;
//  };

// // Place Channel:
// // TODO

// class place : public placeInterface
// {
//     unsigned int tockens;

// public:
//     place(int nTockens)
//     {
//         tockens = nTockens;
//     }

//     void addTockens(unsigned int n)
//     {
//         tockens = tockens + n;
//     }

//     void removeTockens(unsigned int n)
//     {
//         tockens = tockens - n;
//     }

//     unsigned int testTockens()
//     {
//         return this->tockens;
//     }
// };

// templated channels

class placeInterface : public sc_interface
{
public:
    virtual void addTockens() = 0;
    virtual void removeTockens() = 0;
    virtual bool testTockens() = 0;
};

// Place Channel:
// TODO
template <unsigned int Win = 1, unsigned int Wout = 1>
class place : public placeInterface
{
    unsigned int tockens;

public:
    place(int nTockens)
    {
        tockens = nTockens;
    }

    void addTockens()
    {
        tockens = tockens + Win;
    }

    void removeTockens()
    {
        tockens = tockens - Wout;
    }

    bool testTockens()
    {
        return (tockens >= Wout);
    }
};

#endif // PLACE_H
