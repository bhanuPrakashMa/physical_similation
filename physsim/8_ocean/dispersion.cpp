#include "dispersion.hpp"

#include <cmath>

namespace physsim
{
    Dispersion::Dispersion()
        : gravity(9.8065)
        , depth(100)
        , density(1000)         // water
        , surfaceTension(0.074) // water-air interface
    {
    }

    double Dispersion::phaseSpeed(double waveNumber) const
    {
        // TODO: compute the phase speed c_p for the given wave number!
        double g_term = gravity / waveNumber  + (surfaceTension / density) * waveNumber;
        double tan_h = std::tanh(waveNumber * depth);


        return std::sqrt(g_term * tan_h);
    }
}
