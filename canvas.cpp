//
// Created by studio25 on 14.07.2021.
//

#include "canvas.h"

Coord::Coord(const size_t &w, const size_t &h) : w(w), h(h) {}

size_t Coord::Convert21D(const size_t &w) { return h * w + this->w; }

Coord::Coord() : w(0), h(0) {}

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

RGBColor &Canvas::Pixel(Coord position) {
  return pixels_[position.Convert21D(w_)];
}

RGBColor Canvas::GetPixel(Coord position) const {
  return pixels_[position.Convert21D(w_)];
}

void Canvas::SwapColors(RGBColor old_color, RGBColor new_color) {
  for (int i = 0; i < w_ * h_; ++i)
    if (pixels_[i] == old_color)
      pixels_[i] = new_color;
}
size_t Canvas::GetWidth() const { return w_; }
size_t Canvas::GetHeight() const { return h_; }
std::string Canvas::GetInfo() {
  return "Width: " + std::to_string(GetWidth()) +
         " Height: " + std::to_string(GetHeight()) + "\n";
}
size_t Canvas::CountColor(RGBColor color) {
  size_t counter = 0;
  for (int i = 0; i < w_ * h_; ++i)
    if (pixels_[i] == color)
      counter++;

  return counter;
}
std::vector<RGBColor> Canvas::GetUniqueColors() {

  std::vector<RGBColor> solution;

  char* hash_array = new char[2097152];

  memset(hash_array, 0, 2097152);

  for (size_t i = 0; i < w_ * h_; i++) {

    int local_hash = operator[](i).Hash();

    hash_array[local_hash / 8] |= (char)(pow(2, local_hash % 8));
  }


  unsigned counted_colors = 0;

  for (int i = 0; i < 2097152; i++) {
    for (int j = 0; j <= 8; j++) {
      if (hash_array[i] & (char)pow(2, j)) { solution.push_back(i * pow(2, j)); }
    }
  }

  delete[] hash_array;


  return solution;
}
