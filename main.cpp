//
// Created by studio25 on 14.07.2021.
//
#include "canvas.h"
#include "ppm/ppm_loader.h"
#include <iostream>
#include <vector>

int RaundUpTobpm(Canvas &target);
int SwapColors(Canvas &target, const std::vector<RGBColor> &unwanted_colors,
               RGBColor swap_color);
int main() {

  Canvas plane =
      LoadFromPpm("C:\\Users\\studio25\\Pictures\\chess\\test1.ppm");
  std::cout << plane.GetInfo();
  auto color_list_copy = plane.CountUniqueColors();
  std::cout << "number of unique colors: " << color_list_copy.size()
            << std::endl;


  for (auto color : color_list_copy)
    std::cout << color << std::endl;

  return 0;
}

int RaundUpTobpm(Canvas &target) {
  int change_counter = 0;

  for (size_t x = 0; x < target.GetWidth(); x++)
    for (size_t y = 0; y < target.GetHeight(); y++) {

      if (target.Pixel({x, y}) == RGBColor(195, 195, 195) ||
          target.Pixel({x, y}) == RGBColor(0, 0, 0)) {

        continue;
      } else {
        target.Pixel({x, y}) = {195, 195, 195};
        change_counter++;
      }
    }
  return change_counter;
}

int SwapColors(Canvas &target, const std::vector<RGBColor> &unwanted_colors,
               RGBColor swap_color) {
  int change_counter = 0;

  for (size_t x = 0; x < target.GetWidth(); x++)
    for (size_t y = 0; y < target.GetHeight(); y++) {
      for (RGBColor color : unwanted_colors)
        if (color == target.Pixel({x, y})) {
          target.Pixel({x, y}) = swap_color;
          change_counter++;
        }
    }
  return change_counter;
}