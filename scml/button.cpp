//
// Created by studio25 on 14.07.2021.
//

#include "button.h"
scml::Button::Button(const std::string &text, const Coord &position,
                     unsigned int w, unsigned int h)
    : text_(text), position_(position), w_(w), h_(h) {

  highlight_mode_ = button::HighlightMode::BOTH_SIDES;

  highlight_characters_ = {'>', '<'};
}

bool scml::Button::CheckBoundaries(Coord position) {

  position.w -= position_.w;

  position.h -= position_.h;

  if (position.w < w_ and position.h < h_)
    return true;
  return false;
}

std::string scml::Button::Display(Coord position) {
  position.w -= position_.w;

  position.h -= position_.h;

  if (position.w >= w_ or position.h >= h_)
    return text_;
  switch (highlight_mode_) {

  case button::HighlightMode::CHARACTER_LEFT:
    return highlight_characters_.first + text_;

  case button::HighlightMode::CHARACTER_RIGHT:
    return text_ + highlight_characters_.second;

  case button::HighlightMode::BOTH_SIDES:
    return highlight_characters_.first + text_ + highlight_characters_.second;

  case button::HighlightMode::UPPERCASE:
    std::string upper_case;

    for (char c : text_)
      upper_case.push_back((int)c < 97 ? c - 32 : c);

    return upper_case;
  }
}

const Coord &scml::Button::GetPosition() const { return position_; }
