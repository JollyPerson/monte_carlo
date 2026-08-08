#include "PiCalculator.h"
#include <random>
#include <cstdint>

float FastRandomMontePiCalculator::calculate_pi_approx(int tries) {

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<uint32_t> dist(0, RAND_MAX);

    uint64_t in = 0;
    constexpr uint64_t limit = static_cast<uint64_t>(RAND_MAX) * RAND_MAX;

    for (int i = 0; i<tries; i++) {
        uint64_t x = dist(gen);
        uint64_t y = dist(gen);
        if ((x*x + y*y) <= limit)
            ++in;
    }
    return 4.0f * (static_cast<float>(in) / static_cast<float>(tries));
}
