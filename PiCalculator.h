#ifndef MONTE_CARLO_PICALCULATOR_H
#define MONTE_CARLO_PICALCULATOR_H

class PiCalculator {
public:
    virtual float calculate_pi_approx(int tries) = 0;
    virtual ~PiCalculator() = default;
};

class MonteCarloPiCalculator : public PiCalculator {
public:
    float calculate_pi_approx(int tries) override;
};

class RawMontePiCalculator : public PiCalculator {
public:
    float calculate_pi_approx(int tries) override;
};

class FastRandomMontePiCalculator : public PiCalculator {
public:
    float calculate_pi_approx(int tries) override;
};

#endif