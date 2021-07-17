//
// Created by studio25 on 14.07.2021.
//

#ifndef PPM_EDITOR_CMAKE_BUILD_DEBUG_CANVAS_H_
#define PPM_EDITOR_CMAKE_BUILD_DEBUG_CANVAS_H_
#include "ppm/rgb_color.h"
#include <cstddef>
#include <string>
#include <vector>

struct Coord{
  Coord();

  Coord(const size_t &w, const size_t &h);

  size_t Convert21D(const size_t &w);


  /// position in 2d space on x axis
  size_t w;
  /// position in 2d space on y axis
  size_t h;

};


class Canvas {

public:
  /// Canvas always has to have size
  Canvas() = delete;

  /// basic copy constructor
  Canvas(const Canvas &other);

  Canvas(size_t width, size_t height);

  /// overrides the pixels with black color
  void Clear();

  /// \brief
  /// changes all of the pixels to chosen color
  /// \param fill_color whole canvas will be overwritten with this color
  void Fill(RGBColor fill_color);


  void SetPixel(Coord position, RGBColor color);

  /// \brief dangerous way to access a pixel in canvas
  /// \param position 2d Coord
  /// \return the reference to chosen pixel
  RGBColor &Pixel(Coord position);

  /// \brief dangerous way to access a pixel in canvas <br>
  /// direct access to data in memory
  /// \param position 1d position in pixel array
  /// \return the reference to chosen pixel
  RGBColor &operator[](size_t position);

  RGBColor GetPixel(Coord position) const ;

  std::string GetInfo();

  std::vector<RGBColor> GetUniqueColors();

  size_t CountColor(RGBColor color);

  ///
  /// \param old_color every instance of this color will be replaced with new_color
  /// \param new_color the replacement
  void SwapColors(RGBColor old_color,RGBColor new_color);

  size_t GetWidth() const;
  size_t GetHeight() const;

protected:

  /// actual pixel array
  RGBColor *pixels_;
  /// width of a Canvas a.k.a. x axis
  size_t w_;
  /// height of a Canvas a.k.a. y_ axis
  size_t h_;

};

#endif // PPM_EDITOR_CMAKE_BUILD_DEBUG_CANVAS_H_
