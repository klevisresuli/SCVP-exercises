#include <systemc.h>

#include "stim.h"
#include "exor.h"
#include "mon.h"

int sc_main(int, char **)
{
    sc_signal<bool> sigA, sigB, sigZ;
    sc_clock clk("clk", 10, SC_NS);

    stim Stim1("Stimulus");
    Stim1.A(sigA);
    Stim1.B(sigB);
    Stim1.clk.bind(clk);

    exor DUT("exor");
    DUT.A(sigA);
    DUT.B(sigB);
    DUT.Z(sigZ);

    Monitor mon("Monitor");
    mon.A(sigA);
    mon.B(sigB);
    mon.Z(sigZ);
    mon.clk.bind(clk);

    // Setup Waveform Tracing:
    sc_trace_file *wf = sc_create_vcd_trace_file("trace");
    sc_trace(wf, clk, "clk");
    sc_trace(wf, sigA, "sigA");
    sc_trace(wf, sigB, "sigB");
    sc_trace(wf, sigZ, "sigZ");

    sc_start(); // run forever

    sc_close_vcd_trace_file(wf);

    return 0;
}
