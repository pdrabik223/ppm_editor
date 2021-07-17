//
// Created by studio25 on 14.07.2021.
//

#ifndef PPM_EDITOR_PPM_RGB_COLOR_H_
#define PPM_EDITOR_PPM_RGB_COLOR_H_

#include <ostream>
struct RGBColor {

  RGBColor(unsigned char r, unsigned char g, unsigned char b)
      : r(r), g(g), b(b) {}
  RGBColor(int hash) : r(hash & 16711680), g(hash & 65280), b(hash & 255) {}
  unsigned char GetR() const { return r; }
  unsigned char GetG() const { return g; }
  unsigned char GetB() const { return b; }
  RGBColor() : r(0), g(0), b(0) {}
  friend std::ostream &operator<<(std::ostream &os, const RGBColor &color) {
    os << "r: " << (int)color.r << " g: " << (int)color.g
       << " b: " << (int)color.b;
    return os;
  }
  bool operator==(const RGBColor &rhs) const {
    return r == rhs.r && g == rhs.g && b == rhs.b;
  }
  bool operator!=(const RGBColor &rhs) const { return !(rhs == *this); }

  int Hash() const {return (r<<16) + (g<<8) + b;}

  unsigned char r;
  unsigned char g;
  unsigned char b;
};

#endif // PPM_EDITOR_PPM_RGB_COLOR_H_
