//
// Created by studio25 on 14.07.2021.
//

#include "canvas.h"
Coord::Coord(const size_t &w, const size_t &h) : w(w), h(h) {}

size_t Coord::Convert21D(const size_t &w) { return h * w + w; }


Coord::Coord(): w(0), h(0) {}

RGBColor &Canvas::operator[](size_t position) { return pixels_[position]; }

Canvas::Canvas(size_t width, size_t height) {
  w_ = width;
  h_ = height;
  pixels_ = new RGBColor[w_ * h_];
}

Canvas::Canvas(const Canvas &other) {
  pixels_ = new RGBColor[other.w_ * other.h_];

  w_ = other.w_;
  h_ = other.h_;
  for (int i = 0; i < w_ * h_; ++i)
    pixels_[i] = other.pixels_[i];
}

void Canvas::Clear() {
  for (int i = 0; i < w_ * h_; ++i)
    pixels_[i] = {0, 0, 0};
}

void Canvas::Fill(RGBColor fill_color) {
  for (int i = 0; i < w_ * h_; ++i)
    pixels_[i] = fill_color;
}

void Canvas::SetPixel(Coord position, RGBColor color) {
  pixels_[position.Convert21D(w_)] = color;
}

RGBColor &Canvas::GetPixel(Coord position) {
  return pixels_[position.Convert21D(w_)];
}

void Canvas::SwapColors(RGBColor old_color, RGBColor new_color) {
  for (int i = 0; i < w_ * h_; ++i)
    if (pixels_[i] == old_color)
      pixels_[i] = new_color;
}
