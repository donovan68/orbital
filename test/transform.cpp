//
// Created by jim on 29.01.18.
//

#include "catch/catch.hpp"
#include <orbital/math/Transform.h>

TEST_CASE("Matrix", "[math]") // NOLINT
{
    Transform<Decimal> transform;

    SECTION("default construction is identity matrix")
    {

        CHECK(transform.transformation()[0][0] == Approx(1));
        CHECK(transform.transformation()[0][1] == Approx(0));
        CHECK(transform.transformation()[0][2] == Approx(0));

        CHECK(transform.transformation()[1][0] == Approx(0));
        CHECK(transform.transformation()[1][1] == Approx(1));
        CHECK(transform.transformation()[1][2] == Approx(0));

        CHECK(transform.transformation()[2][0] == Approx(0));
        CHECK(transform.transformation()[2][1] == Approx(0));
        CHECK(transform.transformation()[2][2] == Approx(1));
    }

    SECTION("reset to identity matrix")
    {
        transform.translate({1, 2});
        transform.scale(4);
        transform.rotate(-1_pi);
        transform.reset();

        CHECK(transform.transformation()[0][0] == Approx(1));
        CHECK(transform.transformation()[0][1] == Approx(0));
        CHECK(transform.transformation()[0][2] == Approx(0));

        CHECK(transform.transformation()[1][0] == Approx(0));
        CHECK(transform.transformation()[1][1] == Approx(1));
        CHECK(transform.transformation()[1][2] == Approx(0));

        CHECK(transform.transformation()[2][0] == Approx(0));
        CHECK(transform.transformation()[2][1] == Approx(0));
        CHECK(transform.transformation()[2][2] == Approx(1));
    }

    SECTION("translation matrix")
    {
        transform.translate({3, 4});

        CHECK(transform.transformation()[0][0] == Approx(1));
        CHECK(transform.transformation()[0][1] == Approx(0));
        CHECK(transform.transformation()[0][2] == Approx(0));

        CHECK(transform.transformation()[1][0] == Approx(0));
        CHECK(transform.transformation()[1][1] == Approx(1));
        CHECK(transform.transformation()[1][2] == Approx(0));

        CHECK(transform.transformation()[2][0] == Approx(3));
        CHECK(transform.transformation()[2][1] == Approx(4));
        CHECK(transform.transformation()[2][2] == Approx(1));
    }

    SECTION("scale matrix")
    {
        transform.scale(2);

        CHECK(transform.transformation()[0][0] == Approx(2));
        CHECK(transform.transformation()[0][1] == Approx(0));
        CHECK(transform.transformation()[0][2] == Approx(0));

        CHECK(transform.transformation()[1][0] == Approx(0));
        CHECK(transform.transformation()[1][1] == Approx(2));
        CHECK(transform.transformation()[1][2] == Approx(0));

        CHECK(transform.transformation()[2][0] == Approx(0));
        CHECK(transform.transformation()[2][1] == Approx(0));
        CHECK(transform.transformation()[2][2] == Approx(1));
    }

    SECTION("rotation matrix")
    {
        auto alpha = 0.25_pi;
        transform.rotate(alpha);

        CHECK(transform.transformation()[0][0] == Approx(alpha.cos()));
        CHECK(transform.transformation()[0][1] == Approx(alpha.sin()));
        CHECK(transform.transformation()[0][2] == Approx(0));

        CHECK(transform.transformation()[1][0] == Approx(-alpha.sin()));
        CHECK(transform.transformation()[1][1] == Approx(alpha.cos()));
        CHECK(transform.transformation()[1][2] == Approx(0));

        CHECK(transform.transformation()[2][0] == Approx(0));
        CHECK(transform.transformation()[2][1] == Approx(0));
        CHECK(transform.transformation()[2][2] == Approx(1));
    }

    SECTION("rotation matrix with negative angle")
    {
        auto alpha = -0.25_pi;
        transform.rotate(alpha);

        CHECK(transform.transformation()[0][0] == Approx(alpha.cos()));
        CHECK(transform.transformation()[0][1] == Approx(alpha.sin()));
        CHECK(transform.transformation()[0][2] == Approx(0));

        CHECK(transform.transformation()[1][0] == Approx(-alpha.sin()));
        CHECK(transform.transformation()[1][1] == Approx(alpha.cos()));
        CHECK(transform.transformation()[1][2] == Approx(0));

        CHECK(transform.transformation()[2][0] == Approx(0));
        CHECK(transform.transformation()[2][1] == Approx(0));
        CHECK(transform.transformation()[2][2] == Approx(1));
    }
}
