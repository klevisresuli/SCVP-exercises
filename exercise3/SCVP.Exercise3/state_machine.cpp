#include <iostream>

#include "state_machine.h"

void stateMachine::process()
{
    position++;
    states nextState;
    switch (currentState)
    {
    case START:
        if (input.read() == 'G')
        {
            nextState = G;
        }
        else
        {
            nextState = START;
        }
        break;
    case G:
        if (input.read() == 'A')
        {
            nextState = GA;
        }
        else if (input.read() == 'G')
        {
            nextState = G;
        }
        else
        {
            nextState = START;
        }
        break;
    case GA:
        if (input.read() == 'A')
        {
            nextState = GAA;
        }
        else if (input.read() == 'G')
        {
            nextState = G;
        }
        else
        {
            nextState = START;
        }
        break;
    case GAA:
        if (input.read() == 'G')
        {
            nextState = GAAG;
            counter++;
            std::cout << "Genome number" << counter << "found! starting at position: " << position - 4 << " till " << position << std::endl;
        }
        else
        {
            nextState = START;
        }
        break;
    case GAAG:
        if (input.read() == 'G')
        {
            nextState = G;
        }
        else
        {
            nextState = START;
        }
        break;
    }
    // std::cout << "Current state: " << stateNamestocken[currentState.read()] << std::endl;
    // std::cout << "Input: " << input.read() << std::endl;
    currentState = nextState;
    // std::cout << "Next state: " << stateNamestocken[nextState] << std::endl;
    // std::cout << "----------------" << std::endl;
}