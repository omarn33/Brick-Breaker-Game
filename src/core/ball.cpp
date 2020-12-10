#include <core/ball.h>

#include <iostream>

namespace brickbreaker {

Ball::Ball(float radius, const glm::vec2 &position, const glm::vec2 &velocity,
           const glm::vec2 &top_left_corner, const glm::vec2 &bottom_right_corner, float container_stroke_width) {
    radius_ = radius;
    position_ = position;
    velocity_ = velocity;
    container_top_left_corner_ = top_left_corner;
    container_bottom_right_corner_ = bottom_right_corner;
    wall_collision_directions_ = {false, false};
    brick_collision_directions_ = {false, false};
    container_stroke_width_ = container_stroke_width;
}

/** Getter Methods */
const glm::vec2 &Ball::GetPosition() {
    return position_;
}

const glm::vec2 &Ball::GetVelocity() {
    return velocity_;
}

/** Setter Methods */
void Ball::SetPosition(const glm::vec2 &position) {
    position_ = position;
}

void Ball::SetVelocity(const glm::vec2 &velocity) {
    velocity_ = velocity;
}

const std::vector<bool> &Ball::HasCollidedWithWall() {
    // Determine if the ball collided with the top wall of the container
    if ((position_.y - radius_ <= container_top_left_corner_.y + (container_stroke_width_ / 2)) &&
        (velocity_.y < 0)) {
        wall_collision_directions_.at(1) = true;
    }

    // Determine if the particle collided with the left/right walls of the container
    if ((position_.x - radius_ <= container_top_left_corner_.x + (container_stroke_width_ / 2)) &&
        (velocity_.x < 0)) {
        wall_collision_directions_.at(0) = true;
    } else if ((position_.x + radius_ >= container_bottom_right_corner_.x - (container_stroke_width_ / 2)) &&
               (velocity_.x > 0)) {
        wall_collision_directions_.at(0) = true;
    }

    return wall_collision_directions_;
}

bool Ball::HasCollidedWithFloor() {
    // Determine if the ball collided with the floor
    if ((position_.y + radius_ >= container_bottom_right_corner_.y - (container_stroke_width_ / 2)) &&
        (velocity_.y > 0)) {
        velocity_ = {0.0f, 0.0f};
        return true;
    }

    return false;
}

const std::vector<bool> &Ball::HasCollidedWithBrick(const Brick &brick) {
    // Tolerance variable to aid in the collision detection with a brick
    // Without this, the ball may phase through the brick without colliding
    double tolerance = 3.5;

    // Determine if the ball collided with the top/bottom of the brick
    if ((velocity_.y > 0) &&
        (position_.y + radius_ <= brick.brick_top_left_corner_.y) &&
        (position_.y - radius_ >= brick.brick_top_left_corner_.y - tolerance * radius_) &&
        (position_.x + radius_ >= brick.brick_top_left_corner_.x) &&
        (position_.x - radius_ <= brick.brick_bottom_right_corner_.x)) {
        brick_collision_directions_.at(1) = true;
    } else if ((velocity_.y < 0) &&
               (position_.y + radius_ <= brick.brick_bottom_right_corner_.y + tolerance * radius_) &&
               (position_.y - radius_ >= brick.brick_bottom_right_corner_.y) &&
               (position_.x + radius_ >= brick.brick_top_left_corner_.x) &&
               (position_.x - radius_ <= brick.brick_bottom_right_corner_.x)) {
        brick_collision_directions_.at(1) = true;
    }

    // Determine if the ball collided with the left/right of the brick
    if ((velocity_.x > 0) &&
        (position_.x + radius_ <= brick.brick_top_left_corner_.x) &&
        (position_.x - radius_ >= brick.brick_top_left_corner_.x - tolerance * radius_) &&
        (position_.y + radius_ >= brick.brick_top_left_corner_.y) &&
        (position_.y - radius_ <= brick.brick_bottom_right_corner_.y)) {
        brick_collision_directions_.at(0) = true;
    } else if ((velocity_.x < 0) &&
               (position_.x - radius_ >= brick.brick_bottom_right_corner_.x) &&
               (position_.x + radius_ <= brick.brick_bottom_right_corner_.x + tolerance * radius_) &&
               (position_.y + radius_ >= brick.brick_top_left_corner_.y) &&
               (position_.y - radius_ <= brick.brick_bottom_right_corner_.y)) {
        brick_collision_directions_.at(0) = true;
    }

    return brick_collision_directions_;
}

bool Ball::HasCollidedWithPaddle(const Paddle &paddle) {

    if ((velocity_.y > 0) &&
        (position_.x >= paddle.paddle_top_left_corner_.x) &&
        (position_.x <= paddle.paddle_bottom_right_corner_.x) &&
        (position_.y + radius_ >= paddle.paddle_top_left_corner_.y)) {
        return true;
    }

    return false;
}

void Ball::CalculateVelocityAfterWallCollision(std::vector<bool> collision_directions) {
    // Reflect ball velocity in the x-direction
    if (collision_directions.at(0)) {
        velocity_.x *= -1;
    }

    // Reflect ball velocity in the y-direction
    if (collision_directions.at(1)) {
        velocity_.y *= -1;
    }

    // Reset wall collision directions
    wall_collision_directions_ = {false, false};
}

void Ball::CalculateVelocityAfterBrickCollision(std::vector<bool> collision_directions) {
    // Reflect ball velocity in the x-direction
    if (collision_directions.at(0)) {
        velocity_.x *= -1;
    }

    // Reflect ball velocity in the y-direction
    if (collision_directions.at(1)) {
        velocity_.y *= -1;
    }

    // Reset brick collision directions
    brick_collision_directions_ = {false, false};
}

void Ball::CalculateVelocityAfterPaddleCollision() {
    // Reflect ball velocity in the x,y-direction
    velocity_.y *= -kBallPaddleCollisionY;
    velocity_.x *= kBallPaddleCollisionX;
}

void Ball::CalculatePositionAfterCollision() {
    position_ += velocity_;
}

void Ball::Draw() {
    // Draw Ball
    ci::gl::color(ci::Color8u(255, 255, 255));
    ci::gl::Texture2dRef ball = ci::gl::Texture::create(ci::loadImage(
            "C:\\Users\\Omar\\Desktop\\Ball.png"));
    ci::gl::draw(ball, ci::Rectf(glm::vec2{position_.x - radius_, position_.y - radius_},
                                 glm::vec2{position_.x + radius_, position_.y + radius_}));
}
}  // namespace brickbreaker
