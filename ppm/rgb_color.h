//
// Created by studio25 on 14.07.2021.
//

#ifndef PPM_EDITOR_PPM_RGB_COLOR_H_
#define PPM_EDITOR_PPM_RGB_COLOR_H_

struct RGBColor {

  RGBColor(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}
  unsigned char GetR() const { return r; }
  unsigned char GetG() const { return g; }
  unsigned char GetB() const { return b; }
  RGBColor(): r(0), g(0), b(0) {}

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
