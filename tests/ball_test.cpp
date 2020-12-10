#include <core/ball.h>
#include <cmath>
#include <catch2/catch.hpp>

using namespace brickbreaker;

TEST_CASE("Check Ball Bounces After Ball-Container Collision") {
    // Set container boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position1(50.0, 10.0);
    glm::vec2 velocity1(1.0, -1.0);

    glm::vec2 position2(50.0, 90.0);
    glm::vec2 velocity2(1.0, 1.0);

    glm::vec2 position3(10.0, 50.0);
    glm::vec2 velocity3(-1.0, 1.0);

    glm::vec2 position4(90.0, 50.0);
    glm::vec2 velocity4(1.0, 1.0);

    glm::vec2 position5(10.0, 10.0);
    glm::vec2 velocity5(-1.0, -1.0);

    glm::vec2 position6(90.0, 10.0);
    glm::vec2 velocity6(1.0, -1.0);

    glm::vec2 position7(10.0, 90.0);
    glm::vec2 velocity7(-1.0, 1.0);

    glm::vec2 position8(90.0, 90.0);
    glm::vec2 velocity8(1.0, 1.0);

    glm::vec2 position9(95.0, 95.0);
    glm::vec2 velocity9(1.0, 1.0);

    // Ball created to bounce off upper boundary
    Ball upper(10.0f, position1, velocity1, top_left, bottom_right, 0.0f);

    // Ball created to bounce off lower boundary
    Ball lower(10.0f, position2, velocity2, top_left, bottom_right, 0.0f);

    // Ball created to bounce off left boundary
    Ball left(10.0f, position3, velocity3, top_left, bottom_right, 0.0f);

    // Ball created to bounce off right boundary
    Ball right(10.0f, position4, velocity4, top_left, bottom_right, 0.0f);

    // Ball created to bounce off upper left corner (+x and +y velocities)
    Ball top_left_ball(10.0f, position5, velocity5, top_left, bottom_right, 0.0f);

    // Ball created to bounce off upper right corner (+x velocity and -y velocity)
    Ball top_right(10.0f, position6, velocity6, top_left, bottom_right, 0.0f);

    SECTION("Test ball bouncing off upper boundary") {
        REQUIRE(upper.HasCollidedWithWall().at(1));
    }

    SECTION("Test ball bouncing off lower boundary") {
        REQUIRE(lower.HasCollidedWithFloor());
    }

    SECTION("Test ball bouncing off left boundary") {
        REQUIRE(left.HasCollidedWithWall().at(0));
    }

    SECTION("Test ball bounces off right boundary") {
        REQUIRE(right.HasCollidedWithWall().at(0));
    }

    SECTION("Test ball bouncing off upper left corner") {
        REQUIRE(top_left_ball.HasCollidedWithWall().at(0));
        REQUIRE(top_left_ball.HasCollidedWithWall().at(1));
    }

    SECTION("Test ball bouncing off upper right corner") {
        REQUIRE(top_right.HasCollidedWithWall().at(0));
        REQUIRE(top_right.HasCollidedWithWall().at(1));
    }
}

TEST_CASE("Check Conditions Where Balls DO NOT Bounce within Container") {
    // Set container boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position0(50.0, 50.0);
    glm::vec2 velocity0(1.0, 1.0);

    glm::vec2 position1(50.0, 10.0);
    glm::vec2 velocity1(-1.0, 1.0);

    glm::vec2 position2(50.0, 90.0);
    glm::vec2 velocity2(-1.0, -1.0);

    glm::vec2 position3(10.0, 50.0);
    glm::vec2 velocity3(1.0, -1.0);

    glm::vec2 position4(90.0, 50.0);
    glm::vec2 velocity4(-1.0, -1.0);

    glm::vec2 position5(10.0, 10.0);
    glm::vec2 velocity5(1.0, 1.0);

    glm::vec2 position6(90.0, 10.0);
    glm::vec2 velocity6(-1.0, 1.0);

    glm::vec2 position7(10.0, 90.0);
    glm::vec2 velocity7(1.0, -1.0);

    glm::vec2 position8(90.0, 90.0);
    glm::vec2 velocity8(-1.0, -1.0);

    glm::vec2 position9(90.0, 90.0);
    glm::vec2 velocity9(0.0, 0.0);

    // Ball created to NOT bounce in the middle of the container
    Ball middle_ball(10.0f, position0, velocity0, top_left, bottom_right, 0.0f);

    // Ball created to NOT bounce off upper boundary
    Ball upper_ball(10.0f, position1, velocity1, top_left, bottom_right, 0.0f);

    // Ball created to NOT bounce off lower boundary
    Ball lower_ball(10.0f, position2, velocity2, top_left, bottom_right, 0.0f);

    // Ball created to NOT bounce off left boundary
    Ball left_ball(10.0f, position3, velocity3, top_left, bottom_right, 0.0f);

    // Ball created to NOT bounce off right boundary
    Ball right_ball(10.0f, position4, velocity4, top_left, bottom_right, 0.0f);

    // Ball created to NOT bounce off upper left corner (-x and -y velocities)
    Ball top_left_ball(10.0f, position5, velocity5, top_left, bottom_right, 0.0f);

    // Ball created to NOT bounce off upper right corner (-x velocity and +y velocity)
    Ball top_right_ball(10.0f, position6, velocity6, top_left, bottom_right, 0.0f);

    // Ball created to NOT bounce off container with zero velocity
    Ball stationary_ball(10.0f, position9, velocity9, top_left, bottom_right, 0.0f);

    SECTION("Test Ball does NOT bounce in the middle of the container") {
        REQUIRE_FALSE(middle_ball.HasCollidedWithWall().at(0));
        REQUIRE_FALSE(middle_ball.HasCollidedWithWall().at(1));
    }

    SECTION("Test Ball does NOT bounce off upper boundary with reversed velocity") {
        REQUIRE_FALSE(upper_ball.HasCollidedWithWall().at(1));
    }

    SECTION("Test Ball does NOT bounce off lower boundary with reversed velocity") {
        REQUIRE_FALSE(lower_ball.HasCollidedWithWall().at(1));
    }

    SECTION("Test Ball does NOT bounce off left boundary with reversed velocity") {
        REQUIRE_FALSE(left_ball.HasCollidedWithWall().at(0));
    }

    SECTION("Test Ball does NOT bounce off right boundary with reversed velocity") {
        REQUIRE_FALSE(right_ball.HasCollidedWithWall().at(0));
    }

    SECTION("Test Ball does NOT bounce off upper left corner with reversed velocity") {
        REQUIRE_FALSE(top_left_ball.HasCollidedWithWall().at(0));
        REQUIRE_FALSE(top_left_ball.HasCollidedWithWall().at(1));
    }

    SECTION("Test Ball does NOT bounce off upper right corner with reversed velocity") {
        REQUIRE_FALSE(top_right_ball.HasCollidedWithWall().at(0));
        REQUIRE_FALSE(top_right_ball.HasCollidedWithWall().at(1));
    }

    SECTION("Test Ball does NOT bounce off container when stationary") {
        REQUIRE_FALSE(stationary_ball.HasCollidedWithWall().at(0));
        REQUIRE_FALSE(stationary_ball.HasCollidedWithWall().at(1));
    }
}

TEST_CASE("Check Ball Velocity After Ball-Container Collision") {
    // Set container boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position1(50.0, 10.0);
    glm::vec2 velocity1(1.0, -1.0);

    glm::vec2 position2(50.0, 90.0);
    glm::vec2 velocity2(1.0, 1.0);

    glm::vec2 position3(10.0, 50.0);
    glm::vec2 velocity3(-1.0, 1.0);

    glm::vec2 position4(90.0, 50.0);
    glm::vec2 velocity4(1.0, 1.0);

    glm::vec2 position5(10.0, 10.0);
    glm::vec2 velocity5(-1.0, -1.0);

    glm::vec2 position6(90.0, 10.0);
    glm::vec2 velocity6(1.0, -1.0);

    glm::vec2 position7(10.0, 90.0);
    glm::vec2 velocity7(-1.0, 1.0);

    glm::vec2 position8(90.0, 90.0);
    glm::vec2 velocity8(1.0, 1.0);

    // Ball created to bounce off upper boundary
    Ball upper(10.0f, position1, velocity1, top_left, bottom_right, 0.0f);

    // Ball created to bounce off lower boundary
    Ball lower(10.0f, position2, velocity2, top_left, bottom_right, 0.0f);

    // Ball created to bounce off left boundary
    Ball left(10.0f, position3, velocity3, top_left, bottom_right, 0.0f);

    // Ball created to bounce off right boundary
    Ball right(10.0f, position4, velocity4, top_left, bottom_right, 0.0f);

    // Ball created to bounce off upper left corner (+x and +y velocities)
    Ball top_left_ball(10.0f, position5, velocity5, top_left, bottom_right, 0.0f);

    // Ball created to bounce off upper right corner (+x velocity and -y velocity)
    Ball top_right(10.0f, position6, velocity6, top_left, bottom_right, 0.0f);

    SECTION("Test Ball bouncing off upper boundary") {
        REQUIRE(upper.HasCollidedWithWall().at(1));
        upper.CalculateVelocityAfterWallCollision({false, true});
        REQUIRE(upper.GetVelocity().x == 1.0f);
        REQUIRE(upper.GetVelocity().y == 1.0f);
    }

    SECTION("Test Ball colliding with floor") {
        REQUIRE(lower.HasCollidedWithFloor());
    }

    SECTION("Test Ball bouncing off left boundary") {
        REQUIRE(left.HasCollidedWithWall().at(0));
        left.CalculateVelocityAfterWallCollision({true, false});
        REQUIRE(left.GetVelocity().x == 1.0f);
        REQUIRE(left.GetVelocity().y == 1.0f);
    }

    SECTION("Test Ball bounces off right boundary") {
        REQUIRE(right.HasCollidedWithWall().at(0));
        right.CalculateVelocityAfterWallCollision({true, false});
        REQUIRE(right.GetVelocity().x == -1.0f);
        REQUIRE(right.GetVelocity().y == 1.0f);
    }

    SECTION("Test Ball bouncing off upper left corner") {
        REQUIRE(top_left_ball.HasCollidedWithWall().at(0));
        REQUIRE(top_left_ball.HasCollidedWithWall().at(1));
        top_left_ball.CalculateVelocityAfterWallCollision({true, true});
        REQUIRE(top_left_ball.GetVelocity().x == 1.0f);
        REQUIRE(top_left_ball.GetVelocity().y == 1.0f);
    }

    SECTION("Test Ball bouncing off upper right corner") {
        REQUIRE(top_right.HasCollidedWithWall().at(0));
        REQUIRE(top_right.HasCollidedWithWall().at(1));
        top_right.CalculateVelocityAfterWallCollision({true, true});
        REQUIRE(top_right.GetVelocity().x == -1.0f);
        REQUIRE(top_right.GetVelocity().y == 1.0f);
    }

}

TEST_CASE("Check Ball Position After Collision") {
    // Set container boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position1(50.0, 10.0);
    glm::vec2 velocity1(1.0, -1.0);

    glm::vec2 position2(20.0, 20.0);
    glm::vec2 velocity2(0.1, 0.0);

    glm::vec2 position3(21.4, 21.4);
    glm::vec2 velocity3(-0.1, 0.0);

    // Ball created to bounce off upper boundary
    Ball wall_ball(10.0f, position1, velocity1, top_left, bottom_right, 0.0f);

    SECTION("Test Ball Position After Container Collision") {
        REQUIRE(wall_ball.HasCollidedWithWall().at(1));
        wall_ball.CalculateVelocityAfterWallCollision({false, true});
        REQUIRE(wall_ball.GetVelocity().x == 1.0f);
        REQUIRE(wall_ball.GetVelocity().y == 1.0f);
        wall_ball.CalculatePositionAfterCollision();
        REQUIRE(wall_ball.GetPosition().x == 51.0f);
        REQUIRE(wall_ball.GetPosition().y == 11.0f);
    }
}

/*
TEST_CASE("Check Ball Bounces After Ball-Brick Collision") {
    // Set container boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position0(50.0, 50.0);
    glm::vec2 velocity0(0.0, 0.0);

    glm::vec2 position1(50.0, 30.0);
    glm::vec2 velocity1(0.0, 1.0);

    glm::vec2 position2(30.0, 50.0);
    glm::vec2 velocity2(1.0, 0.0);

    glm::vec2 position3(70.0, 50.0);
    glm::vec2 velocity3(-1.0, 0.0);

    glm::vec2 position4(50.0, 70.0);
    glm::vec2 velocity4(0.0, -1.0);

    glm::vec2 position5(50.0 + 10.0 * pow(2, 0.5), 50.0 + 10.0 * pow(2, 0.5));
    glm::vec2 velocity5(-1.0, -1.0);

    glm::vec2 position6(50.0, 55.0);
    glm::vec2 velocity6(0.0, -1.0);

    glm::vec2 position7(40.0, 40.0);
    glm::vec2 velocity7(1.0, -1.0);

    glm::vec2 position8(60.0, 40.0);
    glm::vec2 velocity8(-1.0, -1.0);

    glm::vec2 position9(50.0, 23.0);
    glm::vec2 velocity9(0.0, -1.0);

    // Middle Particle
    Ball middle_particle(10.0f, 10.0, "white", position0, velocity0);

    // Particle created to collide with the middle particle from the top
    Particle upper_particle(10.0f, 10.0, "white", position1, velocity1);

    // Particle created to collide with the middle particle from the bottom
    Particle lower_particle(10.0f, 10.0, "white", position2, velocity2);

    // Particle created to collide with the middle particle from the left
    Particle left_particle(10.0f, 10.0, "white", position3, velocity3);

    // Particle created to collide with the middle particle from the right
    Particle right_particle(10.0f, 10.0, "white", position4, velocity4);

    // Particle created to collide with the middle particle from a diagonal
    Particle diagonal_particle(10.0f, 10.0, "white", position5, velocity5);

    // Particle created to collide while emerged in the middle particle
    Particle emerged_particle(10.0f, 10.0, "white", position6, velocity6);

    // Particle created to collide with multiple particles
    Particle multi_collision_particle1(10.0f, 10.0, "white", position7, velocity7);

    // Particle created to collide with multiple particles
    Particle multi_collision_particle2(10.0f, 10.0, "white", position8, velocity8);

    // Particle created to collide with multiple particles
    Particle multi_collision_particle3(10.0f, 10.0, "white", position9, velocity9);

    ParticlePhysics physics(top_left, bottom_right);

    SECTION("Test particle bouncing from a particle-collision from the top") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, upper_particle));
    }

    SECTION("Test particle bouncing from a particle-collision from the bottom") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, lower_particle));
    }

    SECTION("Test particle bouncing from a particle-collision from the left") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, left_particle));
    }

    SECTION("Test particle bouncing from a particle-collision from the right") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, right_particle));
    }

    SECTION("Test particle bouncing from a particle-collision from a diagonal") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, diagonal_particle));
    }

    SECTION("Test particle bouncing from a particle-collision while being emerged in another particle") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, emerged_particle));
    }

    SECTION("Test particle bouncing after a multi-particle collision") {
        REQUIRE(physics.HasParticleCollidedWithParticle(multi_collision_particle1, multi_collision_particle2));
        REQUIRE(physics.HasParticleCollidedWithParticle(multi_collision_particle2, multi_collision_particle3));
        REQUIRE(physics.HasParticleCollidedWithParticle(multi_collision_particle1, multi_collision_particle3));
    }
}
*/

/*
TEST_CASE("Check Conditions Where Balls DO NOT Bounce Off Bricks) {
    // Set container boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position0(50.0, 50.0);
    glm::vec2 velocity0(0.0, 0.0);

    glm::vec2 position1(50.0, 30.0);
    glm::vec2 velocity1(0.0, -1.0);

    glm::vec2 position2(30.0, 50.0);
    glm::vec2 velocity2(-1.0, 0.0);

    glm::vec2 position3(70.0, 50.0);
    glm::vec2 velocity3(1.0, 0.0);

    glm::vec2 position4(50.0, 70.0);
    glm::vec2 velocity4(0.0, 1.0);

    glm::vec2 position5(50.0 + 10.0 * pow(2, 0.5), 50.0 + 10.0 * pow(2, 0.5));
    glm::vec2 velocity5(1.0, 1.0);

    glm::vec2 position6(50.0, 55.0);
    glm::vec2 velocity6(0.0, 0.0);

    glm::vec2 position7(80.0, 80.0);
    glm::vec2 velocity7(1.0, 1.0);

    // Middle Particle
    Particle middle_particle(10.0f, 10.0, "white", position0, velocity0);

    // Particle created to NOT collide with the middle particle from the top
    Particle upper_particle(10.0f, 10.0, "white", position1, velocity1);

    // Particle created to NOT collide with the middle particle from the bottom
    Particle lower_particle(10.0f, 10.0, "white", position2, velocity2);

    // Particle created to NOT collide with the middle particle from the left
    Particle left_particle(10.0f, 10.0, "white", position3, velocity3);

    // Particle created to NOT collide with the middle particle from the right
    Particle right_particle(10.0f, 10.0, "white", position4, velocity4);

    // Particle created to NOT collide with the middle particle from a diagonal
    Particle diagonal_particle(10.0f, 10.0, "white", position5, velocity5);

    // Particle created to NOT collide while emerged in the middle particle
    Particle emerged_particle(10.0f, 10.0, "white", position6, velocity6);

    // Particle created to NOT collide with the middle particle by being distant
    Particle distant_particle(10.0f, 10.0, "white", position7, velocity7);

    ParticlePhysics physics(top_left, bottom_right);

    SECTION("Test particle does not bounce from the top with reversed velocity") {
        REQUIRE_FALSE(physics.HasParticleCollidedWithParticle(middle_particle, upper_particle));
    }

    SECTION("Test particle does not bounce from the bottom with reversed velocity") {
        REQUIRE_FALSE(physics.HasParticleCollidedWithParticle(middle_particle, lower_particle));
    }

    SECTION("Test particle does not bounce from the left with reversed velocity") {
        REQUIRE_FALSE(physics.HasParticleCollidedWithParticle(middle_particle, left_particle));
    }

    SECTION("Test particle does not bounce from the right with reversed velocity") {
        REQUIRE_FALSE(physics.HasParticleCollidedWithParticle(middle_particle, right_particle));
    }

    SECTION("Test particle does not bounce from a diagonal with reversed velocity") {
        REQUIRE_FALSE(physics.HasParticleCollidedWithParticle(middle_particle, diagonal_particle));
    }

    SECTION("Test particle does not bounce from an emerged stationary particle") {
        REQUIRE_FALSE(physics.HasParticleCollidedWithParticle(middle_particle, emerged_particle));
    }

    SECTION("Test particle does not bounce from a distant particle that does not touch") {
        REQUIRE_FALSE(physics.HasParticleCollidedWithParticle(middle_particle, distant_particle));
    }
}

TEST_CASE("Check Ball Velocity After Ball-Brick Collision") {
    // Set container boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position0(50.0, 50.0);
    glm::vec2 velocity0(0.0, 0.0);

    glm::vec2 position1(50.0, 30.0);
    glm::vec2 velocity1(0.0, 1.0);

    glm::vec2 position2(30.0, 50.0);
    glm::vec2 velocity2(1.0, 0.0);

    glm::vec2 position3(70.0, 50.0);
    glm::vec2 velocity3(-1.0, 0.0);

    glm::vec2 position4(50.0, 70.0);
    glm::vec2 velocity4(0.0, -1.0);

    glm::vec2 position5(50.0 + 10.0 * pow(2, 0.5), 50.0 + 10.0 * pow(2, 0.5));
    glm::vec2 velocity5(-1.0, -1.0);

    glm::vec2 position6(50.0, 55.0);
    glm::vec2 velocity6(0.0, -1.0);

    glm::vec2 position7(40.0, 40.0);
    glm::vec2 velocity7(1.0, -1.0);

    glm::vec2 position8(60.0, 40.0);
    glm::vec2 velocity8(-1.0, -1.0);

    glm::vec2 position9(50.0, 23.0);
    glm::vec2 velocity9(0.0, -1.0);

    // Middle Particle
    Particle middle_particle(10.0f, 10.0, "white", position0, velocity0);

    // Particle created to collide with the middle particle from the top
    Particle upper_particle(10.0f, 10.0, "white", position1, velocity1);

    // Particle created to collide with the middle particle from the bottom
    Particle lower_particle(10.0f, 10.0, "white", position2, velocity2);

    // Particle created to collide with the middle particle from the left
    Particle left_particle(10.0f, 10.0, "white", position3, velocity3);

    // Particle created to collide with the middle particle from the right
    Particle right_particle(10.0f, 10.0, "white", position4, velocity4);

    // Particle created to collide with the middle particle from a diagonal
    Particle diagonal_particle(10.0f, 10.0, "white", position5, velocity5);

    // Particle created to collide while emerged in the middle particle
    Particle emerged_particle(10.0f, 10.0, "white", position6, velocity6);

    // Particle created to collide with multiple particles
    Particle multi_collision_particle1(10.0f, 10.0, "white", position7, velocity7);

    // Particle created to collide with multiple particles
    Particle multi_collision_particle2(10.0f, 10.0, "white", position8, velocity8);

    // Particle created to collide with multiple particles
    Particle multi_collision_particle3(10.0f, 10.0, "white", position9, velocity9);


    ParticlePhysics physics(top_left, bottom_right);

    SECTION("Test particle velocity from a particle-collision from the top") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, upper_particle));
        physics.CalculateVelocityAfterParticleCollision(middle_particle, upper_particle);

        REQUIRE(middle_particle.GetVelocity().x == 0.0f);
        REQUIRE(middle_particle.GetVelocity().y == 1.0f);

        REQUIRE(upper_particle.GetVelocity().x == 0.0f);
        REQUIRE(upper_particle.GetVelocity().y == 0.0f);
    }

    SECTION("Test particle velocity from a particle-collision from the bottom") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, lower_particle));
        physics.CalculateVelocityAfterParticleCollision(middle_particle, lower_particle);

        REQUIRE(middle_particle.GetVelocity().x == 1.0f);
        REQUIRE(middle_particle.GetVelocity().y == 0.0f);

        REQUIRE(lower_particle.GetVelocity().x == 0.0f);
        REQUIRE(lower_particle.GetVelocity().y == 0.0f);
    }

    SECTION("Test particle velocity from a particle-collision from the left") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, left_particle));
        physics.CalculateVelocityAfterParticleCollision(middle_particle, left_particle);

        REQUIRE(middle_particle.GetVelocity().x == -1.0f);
        REQUIRE(middle_particle.GetVelocity().y == 0.0f);

        REQUIRE(left_particle.GetVelocity().x == 0.0f);
        REQUIRE(left_particle.GetVelocity().y == 0.0f);
    }

    SECTION("Test particle velocity from a particle-collision from the right") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, right_particle));
        physics.CalculateVelocityAfterParticleCollision(middle_particle, right_particle);

        REQUIRE(middle_particle.GetVelocity().x == 0.0f);
        REQUIRE(middle_particle.GetVelocity().y == -1.0f);

        REQUIRE(right_particle.GetVelocity().x == 0.0f);
        REQUIRE(right_particle.GetVelocity().y == 0.0f);
    }

    SECTION("Test particle velocity from a particle-collision from a diagonal") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, diagonal_particle));

        physics.CalculateVelocityAfterParticleCollision(middle_particle, diagonal_particle);

        REQUIRE(middle_particle.GetVelocity().x == -1.0f);
        REQUIRE(middle_particle.GetVelocity().y == -1.0f);

        REQUIRE(right_particle.GetVelocity().x == 0.0f);
        REQUIRE(right_particle.GetVelocity().y == -1.0f);
    }

    SECTION("Test particle velocity from an emerged particle") {
        REQUIRE(physics.HasParticleCollidedWithParticle(middle_particle, emerged_particle));
        physics.CalculateVelocityAfterParticleCollision(middle_particle, emerged_particle);

        REQUIRE(middle_particle.GetVelocity().x == 0.0f);
        REQUIRE(middle_particle.GetVelocity().y == -1.0f);

        REQUIRE(right_particle.GetVelocity().x == 0.0f);
        REQUIRE(right_particle.GetVelocity().y == -1.0f);
    }

    SECTION("Test particle velocity after multi-particle collision") {

        REQUIRE(physics.HasParticleCollidedWithParticle(multi_collision_particle1, multi_collision_particle2));
        REQUIRE(physics.HasParticleCollidedWithParticle(multi_collision_particle2, multi_collision_particle3));
        REQUIRE(physics.HasParticleCollidedWithParticle(multi_collision_particle1, multi_collision_particle3));

        physics.CalculateVelocityAfterParticleCollision(multi_collision_particle1, multi_collision_particle2);
        physics.CalculateVelocityAfterParticleCollision(multi_collision_particle2, multi_collision_particle3);
        physics.CalculateVelocityAfterParticleCollision(multi_collision_particle1, multi_collision_particle3);

        // I had to cast this to a double in order to work
        REQUIRE((double) multi_collision_particle1.GetVelocity().x == Approx(-0.86783f));
        REQUIRE((double) multi_collision_particle1.GetVelocity().y == Approx(-1.22469f));

        REQUIRE((double) multi_collision_particle2.GetVelocity().x == Approx(0.7429305911f));
        REQUIRE((double) multi_collision_particle2.GetVelocity().y == Approx(-1.4370179176f));

        REQUIRE((double) multi_collision_particle3.GetVelocity().x == Approx(0.124900043f));
        REQUIRE((double) multi_collision_particle3.GetVelocity().y == Approx(-0.3382940888f));
    }
}

TEST_CASE("Test Law of Conservation of Energy") {
    // Set container boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position1(50.0, 10.0);
    glm::vec2 velocity1(1.0, -1.0);

    glm::vec2 position2(20.0, 20.0);
    glm::vec2 velocity2(0.1, 0.0);

    glm::vec2 position3(21.4, 21.4);
    glm::vec2 velocity3(-0.1, 0.0);

    // Create a particle
    Particle particle1(30.0f, 10.0, "red", position1, velocity1);

    // Create a particle
    Particle particle2(20.0f, 20.0, "blue", position2, velocity2);

    // Create a particle
    Particle particle3(10.0f, 30.0, "green", position3, velocity3);

    ParticlePhysics physics(top_left, bottom_right);
    std::vector<Particle> particles_;

    particles_.push_back(particle1);
    particles_.push_back(particle2);
    particles_.push_back(particle3);

    SECTION("Test Kinetic Energy Conservation") {

        size_t counter = 0;
        size_t number_of_frames = 500;

        double initial_energy = ((0.5) * (particle1.GetMass()) * (particle1.GetSpeed()) * (particle1.GetSpeed())) +
                ((0.5) * (particle2.GetMass()) * (particle2.GetSpeed()) * (particle2.GetSpeed())) +
                ((0.5) * (particle3.GetMass()) * (particle3.GetSpeed()) * (particle3.GetSpeed()));

        // Run the simulation for 500 rounds
        while(counter < number_of_frames) {


            // Determine if a particle collided with the container
            for (size_t particle = 0; particle < particles_.size(); ++particle) {
                // Determine if a particle collided with the container in a corner
                if (physics.HasParticleCollidedWithWall(particles_.at(particle), 'x') &&
                    physics.HasParticleCollidedWithWall(particles_.at(particle), 'y')) {

                    physics.CalculateVelocityAfterWallCollision(particles_.at(particle), 'x');
                    physics.CalculateVelocityAfterWallCollision(particles_.at(particle), 'y');
                }
                    // Determine if a particle collided with the left/right container boundary
                else if (physics.HasParticleCollidedWithWall(particles_.at(particle), 'x')) {
                    physics.CalculateVelocityAfterWallCollision(particles_.at(particle), 'x');
                }
                    // Determine if a particle collided with the left/right container boundary
                else if (physics.HasParticleCollidedWithWall(particles_.at(particle), 'y')) {
                    physics.CalculateVelocityAfterWallCollision(particles_.at(particle), 'y');
                }

                // Update particle position
                physics.CalculatePositionAfterCollision(particles_.at(particle));
            }

            // Determine if a particle collided with another particle
            for (size_t particle1 = 0; particle1 < particles_.size(); ++particle1) {
                for (size_t particle2 = particle1 + 1; particle2 < particles_.size(); ++particle2) {
                    if (physics.HasParticleCollidedWithParticle(particles_.at(particle1), particles_.at(particle2))) {

                        physics.CalculateVelocityAfterParticleCollision(particles_.at(particle1),
                                                                         particles_.at(particle2));

                        // Update particle positions
                        physics.CalculatePositionAfterCollision(particles_.at(particle1));
                        physics.CalculatePositionAfterCollision(particles_.at(particle2));
                    }
                }
            }

            ++counter;
        }

        double final_energy = ((0.5) * (particle1.GetMass()) * (particle1.GetSpeed()) * (particle1.GetSpeed())) +
                                ((0.5) * (particle2.GetMass()) * (particle2.GetSpeed()) * (particle2.GetSpeed())) +
                                ((0.5) * (particle3.GetMass()) * (particle3.GetSpeed()) * (particle3.GetSpeed()));

        REQUIRE(initial_energy == final_energy);
    }
}
 */