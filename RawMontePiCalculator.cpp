#include "PiCalculator.h"
#include <cstdlib>

float RawMontePiCalculator::calculate_pi_approx(int tries) {
    int in = 0;
    constexpr uint64_t limit = static_cast<uint64_t>(RAND_MAX)*RAND_MAX;

    for (int i = 0; i<tries; i++) {
        uint64_t x = rand();
        uint64_t y = rand();
        if ((x*x + y*y) <= limit)
            in++;
    }
    return 4.0f*(static_cast<float>(in)/static_cast<float>(tries));
}
