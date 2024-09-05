#include "test.hh"
#include "exp.hh"

using namespace test;
using namespace music;

static auto _ = AddTest("exp | test Exp::curve", [] () -> bool {
    Breakpoints<double, double> curve = Exp::curve(1, 1, 1, 2);

    if (curve.size() != 2) {
        return false;
    }

    double e = 1e-8;
    
    if (curve[0] - 1.0 > e || curve[1] - 2.0 > e) {
        return false;
    }

    return true;
});