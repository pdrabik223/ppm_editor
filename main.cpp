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

//  Canvas plane =
//      LoadFromPpm("C:\\Users\\studio25\\Pictures\\chess\\bishop_black.ppm");
//  std::cout << plane.GetInfo();
//
// SaveToPpm(plane, "C:\\Users\\studio25\\Pictures\\chess\\bishop_black2.ppm");

RGBColor test = {234,241,102};
std::cout<<test<<std::endl;
std::cout<<test.Hash()<<std::endl;
RGBColor test_2(test.Hash());
std::cout<<test_2<<std::endl;



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