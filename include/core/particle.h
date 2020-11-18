#pragma once

#include "../../../../include/glm/glm.hpp"
#include <iostream>
#include <string>
#include <cinder/Color.h>

namespace idealgas {

    class Particle {
    private:
        float radius_;
        double mass_;
        ci::Color color_;
        glm::vec2 position_;
        glm::vec2 velocity_;

    public:
        /**
         * Constructor that initializes particle attributes
         * @param radius float representing the particle radius
         * @param mass double representing the particle mass
         * @param color string representing the particle color
         * @param position vec2 representing the particle's position
         * @param velocity vec2 representing the particle's velocity
         */
        Particle(float radius, double mass, ci::Color color, glm::vec2 position, glm::vec2 velocity);

        /** Getter Methods */
        float GetRadius();

        double GetMass();

        ci::Color GetColor();

        glm::vec2 GetPosition();

        glm::vec2 GetVelocity();

        double GetSpeed();

        /** Setter Methods */
        void SetRadius(float radius);

        void SetMass(double mass);

        void SetColor(ci::Color color);

        void SetPosition(glm::vec2 position);

        void SetVelocity(glm::vec2 velocity);

    };
}  // namespace idealgas
