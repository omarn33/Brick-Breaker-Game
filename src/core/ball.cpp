#include <core/ball.h>

#include <iostream>

namespace brickbreaker {

Ball::Ball(float radius, const ci::Color &color, const glm::vec2 &position, const glm::vec2 &velocity,
           glm::vec2 top_left_corner, glm::vec2 bottom_right_corner) {
    radius_ = radius;
    color_ = color;
    position_ = position;
    velocity_ = velocity;
    container_top_left_corner_ = top_left_corner;
    container_bottom_right_corner_ = bottom_right_corner;
}

/** Getter Methods */
const float Ball::GetRadius() {
    return radius_;
}

const ci::Color &Ball::GetColor() {
    return color_;
}

const glm::vec2 &Ball::GetPosition() {
    return position_;
}

const glm::vec2 &Ball::GetVelocity() {
    return velocity_;
}

/** Setter Methods */
void Ball::SetRadius(float radius) {
    radius_ = radius;
}

void Ball::SetColor(const ci::Color &color) {
    color_ = color;
}

void Ball::SetPosition(const glm::vec2 &position) {
    position_ = position;
}

void Ball::SetVelocity(const glm::vec2 &velocity) {
    velocity_ = velocity;
}

const std::vector<bool> &Ball::HasCollidedWithWall() {
    // Initialize a 2d vector to store bools in the directions in which a collision occurred
    std::vector<bool> collision_directions = {false, false};

    // Determine if the ball collided with the top wall of the container
    if ((position_.y - radius_ <= container_top_left_corner_.y) && (velocity_.y < 0)) {
        collision_directions.at(1) = true;
    }

    // Determine if the particle collided with the left/right walls of the container
    if ((position_.x - radius_ <= container_top_left_corner_.x) && (velocity_.x < 0)) {
        collision_directions.at(0) = true;
    } else if ((position_.x + radius_ >= container_bottom_right_corner_.x) &&
               (velocity_.x > 0)) {
        collision_directions.at(0) = true;
    }

    return collision_directions;
}

const std::vector<bool> &Ball::HasCollidedWithBrick() {

}

}  // namespace brickbreaker
