#include <iostream>
#include <cstdlib>
#include <string>

auto square = [](auto x) { return x * x; };

//Calculate pi via monte carlo method. Generate pair of random values between 0 and 1
float calculate_pi(const int tries) {



    int in = 0;
    int out = 0;

    for (int i = 0; i < tries; i++) {
        float x = rand() / static_cast<float>(RAND_MAX);
        float y = rand() / static_cast<float>(RAND_MAX);
        if ((square(x) + square(y)) <= 1) {
            in += 1;
        }else {
            out += 1;
        }

    }

    return 4.00f*(static_cast<float>(in)/(out+in));
}


int main() {
    int tries;
    std::cout << "Enter number of tries: ";
    std::cin >> tries;

    const auto pi_approx = calculate_pi(tries);
    std::cout << pi_approx << std::endl;
    return 0;
}

