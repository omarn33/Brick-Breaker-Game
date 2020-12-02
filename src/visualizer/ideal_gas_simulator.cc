/*
#include <visualizer/ideal_gas_simulator.h>
#include <iostream>
#include <cinder/gl/gl.h>

namespace idealgas {

namespace visualizer {
    IdealGasSimulator::IdealGasSimulator(glm::vec2 top_left_corner, glm::vec2 bottom_right_corner) : physics_(
            ParticlePhysics(top_left_corner, bottom_right_corner)) {

        container_top_left_corner_ = top_left_corner;
        container_bottom_right_corner_ = bottom_right_corner;
    }

    void IdealGasSimulator::Draw() {
        // Draw the container
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(container_top_left_corner_,
                                          container_bottom_right_corner_), container_stroke_);

        // Draw particles
        for (size_t particle = 0; particle < particles_.size(); ++particle) {
            ci::gl::color(particles_.at(particle).GetColor());
            ci::gl::drawSolidCircle(particles_.at(particle).GetPosition(),
                                    particles_.at(particle).GetRadius());
        }
    }

    void IdealGasSimulator::Update() {

        // Determine if a particle collided with the container
        for (size_t particle = 0; particle < particles_.size(); ++particle) {
            // Determine if a particle collided with the container in a corner
            if (physics_.HasParticleCollidedWithWall(particles_.at(particle), 'x') &&
                physics_.HasParticleCollidedWithWall(particles_.at(particle), 'y')) {

                physics_.CalculateVelocityAfterWallCollision(particles_.at(particle), 'x');
                physics_.CalculateVelocityAfterWallCollision(particles_.at(particle), 'y');
            }
                // Determine if a particle collided with the left/right container boundary
            else if (physics_.HasParticleCollidedWithWall(particles_.at(particle), 'x')) {
                physics_.CalculateVelocityAfterWallCollision(particles_.at(particle), 'x');
            }
                // Determine if a particle collided with the left/right container boundary
            else if (physics_.HasParticleCollidedWithWall(particles_.at(particle), 'y')) {
                physics_.CalculateVelocityAfterWallCollision(particles_.at(particle), 'y');
            }

            // Update particle position
            physics_.CalculatePositionAfterCollision(particles_.at(particle));
        }

        // Determine if a particle collided with another particle
        for (size_t particle1 = 0; particle1 < particles_.size(); ++particle1) {
            for (size_t particle2 = particle1 + 1; particle2 < particles_.size(); ++particle2) {
                if (physics_.HasParticleCollidedWithParticle(particles_.at(particle1),
                                                             particles_.at(particle2))) {

                    physics_.CalculateVelocityAfterParticleCollision(particles_.at(particle1),
                                                                     particles_.at(particle2));
                    // Update particle positions
                    physics_.CalculatePositionAfterCollision(particles_.at(particle1));
                    physics_.CalculatePositionAfterCollision(particles_.at(particle2));
                }
            }
        }
    }

    void IdealGasSimulator::AddParticle(ci::Color color) {
        // Generate a random position
        double x_coordinate = GenerateRandomNumber(container_top_left_corner_.x + kGreenParticleRadius,
                                                   container_bottom_right_corner_.x - kGreenParticleRadius);
        double y_coordinate = GenerateRandomNumber(container_top_left_corner_.y + kGreenParticleRadius,
                                                   container_bottom_right_corner_.y - kGreenParticleRadius);

        // Declare velocity variables
        double x_velocity;
        double y_velocity;

        if(color == ci::Color("red")) {
            // Generate a random velocity between particle speed restrictions
            x_velocity = GenerateRandomNumber(-1 * kRedParticleMaxInitialSpeed, kRedParticleMaxInitialSpeed);
            y_velocity = GenerateRandomNumber(-1 * kRedParticleMaxInitialSpeed, kRedParticleMaxInitialSpeed);

            Particle particle(kRedParticleRadius, kRedParticleMass, color,
                              glm::vec2 {x_coordinate, y_coordinate}, glm::vec2 {x_velocity, y_velocity});
            particles_.push_back(particle);
        }
        else if(color == ci::Color("blue")) {
            // Generate a random velocity between particle speed restrictions
            x_velocity = GenerateRandomNumber(-1 * kBlueParticleMaxInitialSpeed, kBlueParticleMaxInitialSpeed);
            y_velocity = GenerateRandomNumber(-1 * kBlueParticleMaxInitialSpeed, kBlueParticleMaxInitialSpeed);

            Particle particle(kBlueParticleRadius, kBlueParticleMass, color,
                              glm::vec2 {x_coordinate, y_coordinate}, glm::vec2 {x_velocity, y_velocity});
            particles_.push_back(particle);
        }
        else if(color == ci::Color("green")) {
            // Generate a random velocity between particle speed restrictions
            x_velocity = GenerateRandomNumber(-1 * kGreenParticleMaxInitialSpeed, kGreenParticleMaxInitialSpeed);
            y_velocity = GenerateRandomNumber(-1 * kGreenParticleMaxInitialSpeed, kGreenParticleMaxInitialSpeed);

            Particle particle(kGreenParticleRadius, kGreenParticleMass, color,
                              glm::vec2 {x_coordinate, y_coordinate}, glm::vec2 {x_velocity, y_velocity});
            particles_.push_back(particle);
        }
        else {
            // Generate a random velocity between particle speed restrictions
            x_velocity = GenerateRandomNumber(-1, 1);
            y_velocity = GenerateRandomNumber(-1, 1);

            Particle particle(1, 1, ci::Color("gray"),
                              glm::vec2 {x_coordinate, y_coordinate}, glm::vec2 {x_velocity, y_velocity});
            particles_.push_back(particle);
        }
    }

    int IdealGasSimulator::GenerateRandomNumber(int lower, int upper)
    {
        int random_number_ = ((rand() % (upper - lower + 1)) + lower);
        std::cout << "Random Number: " << random_number_ << std::endl;
        return random_number_;
    }

    void IdealGasSimulator::ClearParticles() {
        particles_.clear();
    }

    std::vector<Particle> IdealGasSimulator::GetColoredParticles(ci::Color color) {
        std::vector<Particle> colored_particles;
        for(size_t particle = 0; particle < particles_.size(); ++particle) {
            if(particles_.at(particle).GetColor() == color) {
                colored_particles.push_back(particles_.at(particle));
            }
        }

        return colored_particles;
    }
} // namespace visualizer

} // namespace idealgas
*/
