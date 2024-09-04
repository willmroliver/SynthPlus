#ifndef INCLUDE_SIN_H
#define INCLUDE_SIN_H

#include "breakpoints.hh"

namespace music {

class Sin {
    public:
        static Breakpoints<double, double> curve(double duration, int steps, double startv, double endv);
        static Breakpoints<double, double> tone(double hz, int steps);
};

}

#endif