//
// Created by studio25 on 14.07.2021.
//
#include "canvas.h"
#include "ppm/ppm_loader.h"
#include <iostream>
#include <vector>

int RaundUpTobpm(Canvas &target);
int SwapUnwantedColors(Canvas &target,
                       const std::vector<RGBColor> &unwanted_colors,
                       RGBColor swap_color);
int SwapAllButWantedColors(Canvas &target,
                           const std::vector<RGBColor> &unwanted_colors,
                           RGBColor swap_color);
int main() {
  std::vector<std::string> paths;
  std::string directory = "C:\\Users\\studio25\\Pictures\\chess\\";
  paths.emplace_back(directory + "king_black.ppm");
  paths.emplace_back(directory + "king_white.ppm");
  paths.emplace_back(directory + "queen_black.ppm");
  paths.emplace_back(directory + "queen_white.ppm");
  paths.emplace_back(directory + "pawn_black.ppm");
  paths.emplace_back(directory + "pawn_white.ppm");
  paths.emplace_back(directory + "rook_black.ppm");
  paths.emplace_back(directory + "rook_white.ppm");
  paths.emplace_back(directory + "night_black.ppm");
  paths.emplace_back(directory + "night_white.ppm");

  std::vector<RGBColor> unwanted_colors;
  unwanted_colors.emplace_back(0, 0, 0);
  unwanted_colors.emplace_back(0, 0, 1);

  for (auto path : paths) {

    Canvas plane = LoadFromPpm(path);
    std::cout << path << std::endl;

    std::cout << SwapAllButWantedColors(plane, unwanted_colors, {0, 0, 1})
              << std::endl;
    SaveToPpm(plane, path);
  }
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
          break;
        }
    }
  return change_counter;
}

int SwapAllButWantedColors(Canvas &target,
                           const std::vector<RGBColor> &wanted_colors,
                           RGBColor swap_color) {
  int change_counter = 0;

  for (size_t x = 0; x < target.GetWidth(); x++)
    for (size_t y = 0; y < target.GetHeight(); y++) {

      for (RGBColor color : wanted_colors)
        if (color == target.Pixel({x, y})) {
          goto skip_swap;
        }
      target.Pixel({x, y}) = swap_color;
    skip_swap:;
    }
  return change_counter;
}