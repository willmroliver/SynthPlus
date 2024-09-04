#ifndef INCLUDE_MIDI_HH
#define INCLUDE_MIDI_HH

namespace music {

class Midi {
    public:
        static double freq(short midinote) noexcept;
};

}

#endif