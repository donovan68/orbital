//
// Created by jim on 29.01.18.
//

#include <gtest/gtest.h>
#include <orbit/Transform.h>

TEST(Transform, DefaultConstructionIsIdentityMatrix)
{
    Transform transform;

    ASSERT_DOUBLE_EQ(transform.transformation()[0][0], 1);
    ASSERT_DOUBLE_EQ(transform.transformation()[0][1], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[0][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[1][0], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[1][1], 1);
    ASSERT_DOUBLE_EQ(transform.transformation()[1][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[2][0], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[2][1], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[2][2], 1);
}

TEST(Transform, ResetToIdentityMatrix)
{
    Transform transform;
    transform.translate({1, 2});
    transform.scale(4);
    transform.rotate(-1_pi);
    transform.reset();

    ASSERT_DOUBLE_EQ(transform.transformation()[0][0], 1);
    ASSERT_DOUBLE_EQ(transform.transformation()[0][1], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[0][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[1][0], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[1][1], 1);
    ASSERT_DOUBLE_EQ(transform.transformation()[1][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[2][0], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[2][1], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[2][2], 1);
}

TEST(Transform, TranslationMatrix)
{
    Transform transform;
    transform.translate({3, 4});

    ASSERT_DOUBLE_EQ(transform.transformation()[0][0], 1);
    ASSERT_DOUBLE_EQ(transform.transformation()[0][1], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[0][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[1][0], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[1][1], 1);
    ASSERT_DOUBLE_EQ(transform.transformation()[1][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[2][0], 3); // x-translation
    ASSERT_DOUBLE_EQ(transform.transformation()[2][1], 4); // y-translation
    ASSERT_DOUBLE_EQ(transform.transformation()[2][2], 1);
}

TEST(Transform, ScaleMatrix)
{
    Transform transform;
    transform.scale(2);

    ASSERT_DOUBLE_EQ(transform.transformation()[0][0], 2);
    ASSERT_DOUBLE_EQ(transform.transformation()[0][1], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[0][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[1][0], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[1][1], 2);
    ASSERT_DOUBLE_EQ(transform.transformation()[1][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[2][0], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[2][1], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[2][2], 1);
}

TEST(Transform, RotationMatrix)
{
    Transform transform;

    auto alpha = 0.25_pi;
    transform.rotate(alpha);

    ASSERT_DOUBLE_EQ(transform.transformation()[0][0], std::cos(alpha));
    ASSERT_DOUBLE_EQ(transform.transformation()[0][1], std::sin(alpha));
    ASSERT_DOUBLE_EQ(transform.transformation()[0][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[1][0], -std::sin(alpha));
    ASSERT_DOUBLE_EQ(transform.transformation()[1][1], std::cos(alpha));
    ASSERT_DOUBLE_EQ(transform.transformation()[1][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[2][0], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[2][1], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[2][2], 1);
}

TEST(Transform, RotationMatrixNegativeAngle)
{
    Transform transform;

    auto alpha = -0.25_pi;
    transform.rotate(alpha);

    ASSERT_DOUBLE_EQ(transform.transformation()[0][0], std::cos(alpha));
    ASSERT_DOUBLE_EQ(transform.transformation()[0][1], std::sin(alpha));
    ASSERT_DOUBLE_EQ(transform.transformation()[0][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[1][0], -std::sin(alpha));
    ASSERT_DOUBLE_EQ(transform.transformation()[1][1], std::cos(alpha));
    ASSERT_DOUBLE_EQ(transform.transformation()[1][2], 0);

    ASSERT_DOUBLE_EQ(transform.transformation()[2][0], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[2][1], 0);
    ASSERT_DOUBLE_EQ(transform.transformation()[2][2], 1);
}
