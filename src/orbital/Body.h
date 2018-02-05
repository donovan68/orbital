//
// Created by jim on 23.01.18.
//

#pragma once

#include <memory>
#include <glm/glm.hpp>
#include "constants.h"
#include "Ellipse.h"

class Body
{

public:

    Body() = default;

    /**
     * Create a new body.
     * @param name Planet name
     * @param mass Planet mass
     * @param radius Planet radius
     * @param a Major semi axis (a > 0)
     * @param e Elliptic eccentricity (0 <= e < 1)
     */
    Body(
            std::string name,
            Decimal mass,
            Decimal radius,
            Decimal a,
            Decimal e
    );

    const std::string &
    getName() const;

    Decimal
    getMass() const;

    Decimal
    getRadius() const;

    const vec &
    getPosition() const;

    const Ellipse &
    getTrajectory() const;

    void
    step(
            Decimal M,
            Decimal dt
    );

private:

    std::string mName;
    Decimal mMass{};      ///< [kg]   Planet mass (m > 0)
    Decimal mRadius{};    ///< [m]    Planet radius (r > 0)
    vec mPosition;            ///< [m]    Position of body mass center
    Ellipse mTrajectory;
    vec mTrajectoryCenter;

};