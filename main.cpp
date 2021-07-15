//
// Created by studio25 on 14.07.2021.
//
#include "canvas.h"
#include "ppm/ppm_loader.h"
#include <iostream>

int RaundUpTobpm(Canvas &target);

int main() {

  Canvas plane =
      LoadFromPpm("C:\\Users\\studio25\\Pictures\\chess\\bishop_black.ppm");
  std::cout << plane.GetInfo();
  std::cout << RaundUpTobpm(plane) << std::endl;
  std::cout << "no of black: " << plane.CountColor({0, 0, 0});
  SaveToPpm(plane, "C:\\Users\\studio25\\Pictures\\chess\\bishop_black.ppm");

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