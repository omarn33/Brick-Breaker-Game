/*
#pragma once

#include <core/particle_physics.h>
//#include <cinder/gl/gl.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cinder/Color.h>

namespace idealgas {

    namespace visualizer {

        class IdealGasSimulator {

        private:
            /** Coordinates for container */
            //glm::vec2 container_top_left_corner_;
            //glm::vec2 container_bottom_right_corner_;

            /** Container attributes */
            //const std::string container_color_ = "white";
            //const float container_stroke_ = 20.0f;

            /** Red Particle */
            //const float kRedParticleRadius = 20.0f;
            //const double kRedParticleMass = 20.0;
            //const double kRedParticleMaxInitialSpeed = 20.0;

            /** Blue Particle */
            //const float kBlueParticleRadius = 40.0f;
            //const double kBlueParticleMass = 40.0;
            //const double kBlueParticleMaxInitialSpeed = 10.0;

            /** Green Particle */
            //const float kGreenParticleRadius = 80.0f;
            //const double kGreenParticleMass = 80.0;
            //const double kGreenParticleMaxInitialSpeed = 5.0;

            /** Particle Physics */
            //std::vector<Particle> particles_;
            //ParticlePhysics physics_;


        //public:
            /**
             * Constructor that takes in boundaries of container
             * @param top_left_corner vec2 coordinate of the top left corner of the container
             * @param bottom_right_corner vec2 coordinate of the bottom right corner of the container
             */
            //IdealGasSimulator(glm::vec2 top_left_corner, glm::vec2 bottom_right_corner);

            /**
             * Displays the current state of the ideal gas simulator in the cinder application
             */
//void Draw();

            /**
             * Updates the state of the particles within the ideal gas simulator
             */
//void Update();

            /**
             * Adds a particle of a given color to the simulator
             * @param color The color of the particle
             */
//void AddParticle(ci::Color color);

            /**
             * Generates a random integer between an upper and lower bound inclusive
             * @param lower int representing the lower bound
             * @param upper int representing the upper bound
             * @return int representing the random number
             */
//int GenerateRandomNumber(int lower, int upper);

            /**
             * Clears all particles within the container
             */
//void ClearParticles();

            /**
             * Returns the a vector of Particles with a given color
             * @param color The color of the particles
             * @return vector<Particle> representing the colored particles
             */
//std::vector<Particle> GetColoredParticles(ci::Color color);
//};

//  } // namespace visualizer

//} // namespace idealgas
