#include "PiCalculator.h"
#include <cstdlib>

auto square = [](auto x) { return x * x; };

float MonteCarloPiCalculator::calculate_pi_approx(const int tries) {
    int in = 0;
    for (int i = 0; i < tries; ++i) {
        auto x = static_cast<double>(rand()) / RAND_MAX;
        auto y = static_cast<double>(rand()) / RAND_MAX;
        if (square(x) + square(y) <= 1.0) {
            ++in;
        }
    }
    return 4.0f * (static_cast<float>(in) / static_cast<float>(tries));
}
