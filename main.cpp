#include <iostream>
#include <chrono>
#include <memory>
#include "PiCalculator.h" // Only include the "Menu"

static auto square = [](auto x) { return x * x; };

int main() {
    std::unique_ptr<PiCalculator> calculator = std::make_unique<FastRandomMontePiCalculator>();

    auto start = std::chrono::high_resolution_clock::now();
    float pi_approx = calculator->calculate_pi_approx(INT32_MAX);

    auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> delta = end - start;

    std::cout << "Pi: " << pi_approx << " (Time: " << delta.count() << "s)" << std::endl;
    return 0;
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

