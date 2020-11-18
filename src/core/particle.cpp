#include <core/particle.h>

#include <iostream>

namespace idealgas {

    Particle::Particle(float radius, double mass, ci::Color color, glm::vec2 position, glm::vec2 velocity) {
        radius_ = radius;
        mass_ = mass;
        color_ = color;
        position_ = position;
        velocity_ = velocity;
    }

    /** Getter Methods */
    float Particle::GetRadius() {
        return radius_;
    }

    double Particle::GetMass() {
        return mass_;
    }

    ci::Color Particle::GetColor() {
        return color_;
    }

    glm::vec2 Particle::GetPosition() {
        return position_;
    }

    glm::vec2 Particle::GetVelocity() {
        return velocity_;
    }

    double Particle::GetSpeed() {
        return glm::length(velocity_);
    }

    /** Setter Methods */
    void Particle::SetRadius(float radius) {
        radius_ = radius;
    }

    void Particle::SetMass(double mass) {
        mass_ = mass;
    }

    void Particle::SetColor(ci::Color color) {
        color_ = color;
    }

    void Particle::SetPosition(glm::vec2 position) {
        position_ = position;
    }

    void Particle::SetVelocity(glm::vec2 velocity) {
        velocity_ = velocity;
    }

}  // namespace idealgas
