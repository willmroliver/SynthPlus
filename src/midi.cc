#include "midi.hh"

#include <cmath>

const double SEMITONE_RATIO = std::pow(2, 1 / 12.0);
const double C5_FREQ = 220 * std::pow(SEMITONE_RATIO, 3);
const double C0_FREQ = C5_FREQ * std::pow(0.5, 5);

using namespace music;

double Midi::freq(short midinote) noexcept {
    return C0_FREQ * std::pow(SEMITONE_RATIO, midinote);
}