#pragma once

#include <core/brick.h>
#include "../../../../include/glm/glm.hpp"
#include "cinder/gl/gl.h"
#include <cinder/Color.h>
#include <iostream>
#include <string>

#include <vector>

namespace brickbreaker {

class Ball {
private:
    /** Ball Attributes */
    float radius_;
    ci::Color8u color_;
    glm::vec2 position_;
    glm::vec2 velocity_;
    std::vector<bool> wall_collision_directions_;
    std::vector<bool> brick_collision_directions_;

    /** Ball Container Attributes */
    glm::vec2 container_top_left_corner_;
    glm::vec2 container_bottom_right_corner_;

public:
    /**
     * Constructor that initializes ball and container attributes
     * @param radius float representing the ball radius
     * @param mass double representing the ball mass
     * @param color string representing the ball color
     * @param position vec2 representing the ball's position
     * @param velocity vec2 representing the ball's velocity
     * @param top_left_corner vec2 representing the coordinate of the top left corner of the container
     * @param bottom_right_corner vec2 representing the coordinate of the bottom right corner of the container
     */
    Ball(float radius, const ci::Color8u &color, const glm::vec2 &position, const glm::vec2 &velocity,
         const glm::vec2 &top_left_corner, const glm::vec2 &bottom_right_corner);

    /** Getter Methods */
    const float GetRadius();

    const ci::Color &GetColor();

    const glm::vec2 &GetPosition();

    const glm::vec2 &GetVelocity();

    /** Setter Methods */
    void SetRadius(float radius);

    void SetColor(const cinder::Color &color);

    void SetPosition(const glm::vec2 &position);

    void SetVelocity(const glm::vec2 &velocity);

    /**
     * Determines if the ball collided with the container in any direction (x or y)
     * @return vector<bool> storing bool in the indices representing the direction in which the collision occurred
     * true if the collision occurred in a given direction, false otherwise
     * Note: <true, false> signifies a collision in the x-direction
     *       <false, true> signifies a collision in the y-direction
     *       <true, true> signifies a collision in both the x and y-direction
     *       <false, false> signifies no collision
     */
     const std::vector<bool> &HasCollidedWithWall();

    /**
     * Determines if the ball collided with a brick in any direction (x or y)
     * @return vector<bool> storing bool in the indices representing the direction in which the collision occurred
     * true if the collision occurred in a given direction, false otherwise
     */
    const std::vector<bool> &HasCollidedWithBrick(const Brick &brick);

    /**
     * Determines if the ball collided with the paddle in any direction (x or y)
     * @return vector<bool> storing bool in the indices representing the direction in which the collision occurred
     * true if the collision occurred in a given direction, false otherwise
     */
    const std::vector<bool> &HasCollidedWithPaddle();

    /**
     * Calculates the velocity of the ball after a wall collision
     */
    void CalculateVelocityAfterWallCollision(std::vector<bool> collision_directions);

    /**
     * Calculates the velocity of the ball after a brick collision
     */
    void CalculateVelocityAfterBrickCollision(std::vector<bool> collision_directions);

    /**
     * Calculates the velocity of the ball after a paddle collision
     */
    void CalculateVelocityAfterPaddleCollision(std::vector<bool> collision_directions);

    /**
     * Calculates the position of the ball after any collision (with paddle, brick, or wall)
     */
    void CalculatePositionAfterCollision();

    void Draw();
};

} // namespace brickbreaker