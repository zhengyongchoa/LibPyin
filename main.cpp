#include <iostream>
#include <cmath>
#include <vector>

// This code demonstrates using the C++ interface to LibPyin from C++

#include "libpitch/libpyincpp.h"

#define M_PI acos(-1.0)

int main() {
        int SAMPLE_RATE = 16000;
        int SAMPLE_COUNT = 32000;
        int BLOCK_SIZE = 1024;
        int STEP_SIZE = 512;

        // Prepare objects
        PyinCpp my_pyin(SAMPLE_RATE, BLOCK_SIZE, STEP_SIZE);
        std::vector<float> samples(SAMPLE_COUNT);


        // Generate a 440 herz sine wave
        float freq = 440;
        float angle_speed = 2 * M_PI * (freq / SAMPLE_RATE);
        for (int i = 0; i < SAMPLE_COUNT; i++) {
            samples[i] = sin(angle_speed * i);
        }

        // Mine pitches
        std::vector<float> pitches = my_pyin.feed(samples);

        // Go through and print the pitches
        int numf0= 0;
        for (const float pitch : pitches)
        {
            std::cout << pitch << " ";
            numf0++;
        }
        std::cout<< std::endl <<"number is "<< numf0 << std::endl;
}
