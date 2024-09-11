#include "test.hh"
#include "sin.hh"

using namespace test;
using namespace music;

static auto _ = AddTest("sin | test Sin::curve", []() -> bool {
    Breakpoints<double, double> curve = Sin::curve(1, 4, -1, 1);

    if (curve.size() != 5) {
        return false;
    }

    double e = 1e-8;
    
    if (
        curve[0] - 0.0 > e || 
        curve[.25] - 1.0 > e ||
        curve[.5] - 0.0 > e ||
        curve[.75] + 1.0 > e ||
        curve[1] - 0.0 > e
    ) {
        return false;
    }

    return true;
});