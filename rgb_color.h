//
// Created by studio25 on 14.07.2021.
//

#ifndef PPM_EDITOR__RGB_COLOR_H_
#define PPM_EDITOR__RGB_COLOR_H_

struct RGBColor {

  RGBColor(char r, char g, char b) : r_(r), g_(g), b_(b) {}
  char GetR() const { return r_; }
  char GetG() const { return g_; }
  char GetB() const { return b_; }
  RGBColor(): r_(0), g_(0), b_(0) {}

  bool operator==(const RGBColor &rhs) const {
    return r_ == rhs.r_ && g_ == rhs.g_ && b_ == rhs.b_;
  }
  bool operator!=(const RGBColor &rhs) const { return !(rhs == *this); }
  char r_;
  char g_;
  char b_;
};

#endif // PPM_EDITOR__RGB_COLOR_H_
