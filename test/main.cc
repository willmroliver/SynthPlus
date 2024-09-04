#include "midi.hh"
#include "breakpoints.hh"
#include "exp.hh"
#include "sin.hh"

#include <iostream>
#include <string>
#include <filesystem>

int main() {
    music::Breakpoints<double, double> bp("midi.txt");
    bp[0.25] = music::Midi::freq(69);
    bp[0.5] = music::Midi::freq(70);
    bp[0.75] = music::Midi::freq(72);
    bp[1] = music::Midi::freq(73);
    bp.save();

    bp = music::Exp::curve(10, 20, 10, 0);
    bp.name("exp.txt");
    bp.save();

    bp = music::Sin::curve(5, 50, -1, 4);
    bp.name("sin.txt");
    bp.save();

    bp = music::Sin::tone(440, 20);
    bp.name("tone.txt");
    bp.save();

    return 0;
}