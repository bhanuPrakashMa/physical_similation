#include "wave.hpp"

namespace physsim
{
    double Wave::waveNumber() const { return 2 * (float)EIGEN_PI / waveLength; }

    Eigen::Vector2d Wave::direction() const { return Eigen::Vector2d(std::cos(angle), std::sin(angle)); }

    Eigen::Vector2d Wave::waveVector() const { return direction() * waveNumber(); }

    double Wave::angularFrequency() const
    {
        double k = waveNumber();
        return k * dispersion.phaseSpeed(k);
    }

    Eigen::Vector3d Wave::offset(const Eigen::Vector2d& position, const double& t) const
    {
        // TODO: compute the offset for the displaced wave from the given position.
        double phase = waveVector().dot(position) - waveNumber() *dispersion.phaseSpeed(waveNumber()) *t + 0.0f;

        double eta = amplitude * std::cos(phase);

        Eigen::Vector2d horiz_disp = -0.5f * (waveVector()/waveNumber() ) * amplitude * std::sin(phase);

        return Eigen::Vector3d(horiz_disp.x(), horiz_disp.y(), eta);
        // return Eigen::Vector3d(0, 0, eta);
    }
}
