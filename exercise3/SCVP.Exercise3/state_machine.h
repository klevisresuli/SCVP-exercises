#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>
#include <map>

enum states
{
  START,
  G,
  GA,
  GAA,
  GAAG
};

SC_MODULE(stateMachine)
{
  sc_in<char> input;
  sc_in<bool> clk;

  sc_signal<states> currentState;

  int counter, position;

  std::map<states, std::string> stateNamestocken = {
      {START, "START"},
      {G, "G"},
      {GA, "GA"},
      {GAA, "GAA"},
      {GAAG, "GAAG"}};

  SC_CTOR(stateMachine)
  {
    SC_METHOD(process);
    sensitive << clk.pos();
    currentState.write(START);
    counter = 0;
    position = 0;
    dont_initialize();
  }
  void process();
};

#endif // STATE_MACHINE_H
