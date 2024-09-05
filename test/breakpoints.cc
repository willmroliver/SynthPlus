#include "test.hh"
#include "breakpoints.hh"

using namespace test;
using namespace music;

static auto _ = AddTest("breakpoints | integration test", []() -> bool {
    Breakpoints<double, double> bp;

    bp[1.25] = 1.4;
    bp[0.5] = -0.8;
    bp[3.1] = 20.0;

    auto it = bp.begin();

    if (it->first - 0.5 > 1e-8) {
        return false;
    }

    it = bp.end();
    --it;

    if (it->second - 20.0 > 1e-8) {
        return false;
    }

    bp += 5;

    if (it->first - (3.1 + 5) > 1e-8) {
        return false;
    }

    Breakpoints<double, double> add;
    add[0.5] = 5.0;
    add[8.2] = 1.0;

    bp = bp + add;
    it = bp.begin();

    if (it->first - 0.5 > 1e-8 || it->second - 5.0 > 1e-8) {
        return false;
    }

    it = bp.end();

    if (it->first - 8.2 > 1e-8 || it->second - 1.0 > 1e-8) {
        return false;
    }

    if (bp.size() != 5) {
        return false;
    }

    return true;
});