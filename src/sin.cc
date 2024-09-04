#include "sin.hh"

#include <iostream>
#include <cmath>
#include <numbers>

using namespace music;

constexpr double pi = 3.14159265358979311599796346854;
constexpr double tau = 2*pi;

Breakpoints<double, double> Sin::curve(double duration, int steps, double startv, double endv) {
    Breakpoints<double, double> bp;

    double min = startv, max = endv, vrange = startv - endv;
    
    if (vrange == 0) {
        std::cerr << "invalid range: start equals end" << std::endl;
        return bp;
    }

    if (min < max) {
        vrange = -vrange;
    } else {
        min = endv;
        max = startv;
    }

    double offset = -(vrange/2.0) - min;
    double stepsize = duration/steps;

    for (int i = 0; i <= steps; ++i) {
        bp[stepsize*i] = (std::sin((tau*i)/steps) * (vrange/2.0)) - offset;
    }

    return bp;
}

Breakpoints<double, double> Sin::tone(double hz, int steps) {
    Breakpoints<double, double> bp, add = Sin::curve(1, steps, -1, 1);

    int whole = static_cast<int>(hz);
    // int frac = hz - whole;

    for (int i = 0; i < whole; ++i) {
        bp = bp + add;
        add += 1;
    }

    return bp;
} 