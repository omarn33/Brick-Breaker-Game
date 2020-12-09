#include <core/paddle.h>

namespace brickbreaker {

    Paddle::Paddle(const glm::vec2 paddle_top_left_corner, const glm::vec2 &paddle_bottom_right_corner,
                   float paddle_sensitivity, const glm::vec2 &container_top_left_corner,
                   const glm::vec2 &container_bottom_right_corner, float container_stroke_width) {
        paddle_top_left_corner_ = paddle_top_left_corner;
        paddle_bottom_right_corner_ = paddle_bottom_right_corner;
        paddle_sensitivity_ = paddle_sensitivity;
        container_top_left_corner_ = container_top_left_corner;
        container_bottom_right_corner_ = container_bottom_right_corner;
        container_stroke_width_ = container_stroke_width;
    }

    const glm::vec2 &Paddle::GetPaddlePosition() {
        return paddle_top_left_corner_;
    }

    void Paddle::SetPaddlePosition(const glm::vec2 &position) {
        paddle_top_left_corner_ = position;
    }

    void Paddle::MovePaddleRight() {
        if(paddle_bottom_right_corner_.x + (container_stroke_width_ / 2) + paddle_sensitivity_ <= container_bottom_right_corner_.x) {
            paddle_top_left_corner_.x += paddle_sensitivity_;
            paddle_bottom_right_corner_.x += paddle_sensitivity_;
        }
    }

    void Paddle::MovePaddleLeft() {
        if(paddle_top_left_corner_.x - (container_stroke_width_ / 2) - paddle_sensitivity_ >= container_top_left_corner_.x) {
            paddle_top_left_corner_.x -= paddle_sensitivity_;
            paddle_bottom_right_corner_.x -= paddle_sensitivity_;
        }
    }

    void Paddle::Draw() {

        ci::gl::color(ci::Color8u(255, 255, 255));
        ci::gl::Texture2dRef paddle = ci::gl::Texture::create(ci::loadImage(
                "C:\\Users\\Omar\\Desktop\\Paddle.png"));
        ci::gl::draw(paddle, ci::Rectf(paddle_top_left_corner_, paddle_bottom_right_corner_));
    }

} // namespace brickbreaker


