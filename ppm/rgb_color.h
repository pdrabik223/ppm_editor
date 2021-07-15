//
// Created by studio25 on 14.07.2021.
//

#ifndef PPM_EDITOR_PPM_RGB_COLOR_H_
#define PPM_EDITOR_PPM_RGB_COLOR_H_

struct RGBColor {

  RGBColor(char r, char g, char b) : r(r), g(g), b(b) {}
  char GetR() const { return r; }
  char GetG() const { return g; }
  char GetB() const { return b; }
  RGBColor(): r(0), g(0), b(0) {}

  bool operator==(const RGBColor &rhs) const {
    return r == rhs.r && g == rhs.g && b == rhs.b;
  }
  bool operator!=(const RGBColor &rhs) const { return !(rhs == *this); }
  char r;
  char g;
  char b;
};

#endif // PPM_EDITOR_PPM_RGB_COLOR_H_
