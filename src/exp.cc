#include "exp.hh"

#include <iostream>
#include <cmath>

using namespace music;

Breakpoints<double, double> Exp::curve(double duration, int steps, double startv, double endv) {
    Breakpoints<double, double> bp;
    double vrange = endv - startv;

    double start = 1.0;
    double end = 1.0e-4;
    double offset = end;

    if (vrange == 0) {
        std::cerr << "invalid range: start equals end" << std::endl;
        return bp;
    }

    if (vrange < 0) {
        vrange = -vrange;
    } else {
        start = 1.0e-4;
        end = 1.0;
        offset = start;
    }

    double factor = std::pow(end/start, 1.0/steps);
    double stepsize = duration/steps;

    for (int i = 0; i <= steps; ++i) {
        bp[stepsize*i] = offset + start*vrange;
        start *= factor;
    }

    return bp;
}