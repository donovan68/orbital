//
// Created by jim on 23.01.18.
//

#pragma once

#include <glm/glm.hpp>
#include <complex>

using vec = glm::dvec2;

using complex = std::complex<double>;

/**
 * Gravitational constant: [m^3 kg / s^2]
 */
extern const double G;

/**
 * Factor to convert astronomic units to meters.
 */
extern const double AU;

/**
 * Pi
 */
extern const double PI;

/**
 * Smallest value, to use for 0 in cases 0 is forbidden
 */
extern const double ZERO;

extern const double S_PER_MIN;
extern const double S_PER_HOUR;
extern const double S_PER_DAY;
extern const double S_PER_MONTH;
extern const double S_PER_YEAR;

/**
 * Serialize a complex number: [real]+[imag]i
 */
std::ostream &
operator<<(
        std::ostream &os,
        const complex &c
);

std::ostream &
operator<<(
        std::ostream &os,
        const vec &v
);

double length(
        const vec &v
);
