/*
#include <core/particle_physics.h>

namespace idealgas {

    ParticlePhysics::ParticlePhysics(glm::vec2 top_left_corner, glm::vec2 bottom_right_corner) {
        container_top_left_corner_ = top_left_corner;
        container_bottom_right_corner_ = bottom_right_corner;
    }

    void ParticlePhysics::CalculatePositionAfterCollision(Particle &particle) {
        particle.SetPosition(particle.GetPosition() + particle.GetVelocity());
    }

    void ParticlePhysics::CalculateVelocityAfterWallCollision(Particle &particle, char direction) {
        direction = tolower(direction);
        size_t collision_axis = -1;

        // Determine appropriate axis based on parameter
        for (size_t axis = 0; axis < kDimensions.size(); ++axis) {
            if (kDimensions.at(axis) == direction) {
                collision_axis = axis;
            }
        }

        float x_velocity = particle.GetVelocity().x;
        float y_velocity = particle.GetVelocity().y;

        // Reflect particle velocity in the x-direction
        if (collision_axis == 0) {
            x_velocity *= -1;
        }

        // Reflect particle velocity in the y-direction
        if (collision_axis == 1) {
            y_velocity *= -1;
        }

        // Update particle velocity
        particle.SetVelocity(glm::vec2{x_velocity, y_velocity});
    }

    bool ParticlePhysics::HasParticleCollidedWithWall(Particle particle, char direction) {
        direction = tolower(direction);
        size_t collision_axis = -1;

        // Determine appropriate axis based on parameter
        for (size_t axis = 0; axis < kDimensions.size(); ++axis) {
            if (kDimensions.at(axis) == direction) {
                collision_axis = axis;
            }
        }

        // Verify an appropriate axis was entered
        if (collision_axis == -1) {
            return false;
        }

        // Obtain the particle's x and y velocities
        float x_velocity = particle.GetVelocity().x;
        float y_velocity = particle.GetVelocity().y;

        // Determine if the particle collided with the top/bottom wall of the container
        if (collision_axis == 1) {
            if ((particle.GetPosition().y - particle.GetRadius() <= container_top_left_corner_.y) && (y_velocity < 0)) {
                return true;
            } else if ((particle.GetPosition().y + particle.GetRadius() >= container_bottom_right_corner_.y) &&
                       (y_velocity > 0)) {
                return true;
            } else {
                return false;
            }
        }

        // Determine if the particle collided with the left/right wall of the container
        if (collision_axis == 0) {
            if ((particle.GetPosition().x - particle.GetRadius() <= container_top_left_corner_.x) && (x_velocity < 0)) {
                return true;
            } else if ((particle.GetPosition().x + particle.GetRadius() >= container_bottom_right_corner_.x) &&
                       (x_velocity > 0)) {
                return true;
            } else {
                return false;
            }
        }

        return false;
    }

    bool ParticlePhysics::HasParticleCollidedWithParticle(Particle particle1, Particle particle2) {
        if ((glm::distance(particle1.GetPosition(), particle2.GetPosition()) <=
             particle1.GetRadius() + particle2.GetRadius()) &&
            (glm::dot((particle1.GetVelocity() - particle2.GetVelocity()),
                      (particle1.GetPosition() - particle2.GetPosition())) < 0)) {
            return true;
        } else {
            return false;
        }
    }

    void ParticlePhysics::CalculateVelocityAfterParticleCollision(Particle &particle1, Particle &particle2) {
        // Store particle1 initial velocity
        glm::vec2 particle1_initial_velocity = particle1.GetVelocity();

        // Calculate new velocity for particle1
        particle1.SetVelocity(particle1.GetVelocity() -
                              (float) ((2 * particle2.GetMass()) / (particle1.GetMass() + particle2.GetMass())) *
                              (glm::dot(particle1.GetVelocity() - particle2.GetVelocity(),
                                        particle1.GetPosition() - particle2.GetPosition()) /
                               (pow(glm::length(particle1.GetPosition() - particle2.GetPosition()), 2))) *
                              (particle1.GetPosition() - particle2.GetPosition()));

        // Calculate new velocity for particle2
        particle2.SetVelocity(particle2.GetVelocity() -
                              (float) ((2 * particle1.GetMass()) / (particle1.GetMass() + particle2.GetMass())) *
                              (glm::dot(particle2.GetVelocity() - particle1_initial_velocity,
                                        particle2.GetPosition() - particle1.GetPosition()) /
                               (pow(glm::length(
                                       particle2.GetPosition() - particle1.GetPosition()),
                                    2))) *
                              (particle2.GetPosition() - particle1.GetPosition()));
    }

}  // namespace idealgas
*/