#ifndef INCLUDE_EXP_HH
#define INCLUDE_EXP_HH

#include "breakpoints.hh"

namespace music {

class Exp {
    public:
        static Breakpoints<double, double> curve(double duration, int steps, double startv, double endv);
};

}

#endif