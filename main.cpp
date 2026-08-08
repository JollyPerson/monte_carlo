#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

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


int get_user_int_input() {
    int user_input;
    while (true) {
        std::cout << "Enter an integer number of tries: ";
        std::cin >> user_input;

        if (std::cin.fail()) {
            std::cerr << "Invalid input." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return user_input;
        }
    }
}

int main() {
    const auto pi_approx = calculate_pi(get_user_int_input());
    std::cout << pi_approx << std::endl;
    return 0;
}


