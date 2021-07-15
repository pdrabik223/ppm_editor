//
// Created by studio25 on 14.07.2021.
//

#ifndef PPM_EDITOR__CONSOLE_UI_H_
#define PPM_EDITOR__CONSOLE_UI_H_

#include "ppm/rgb_color.h"
#include "scml/button.h"

#include <string>
class ConsoleUi {

protected:

std::string path_;
unsigned image_height_;
unsigned image_width_;
unsigned image_no_pixels_;
unsigned image_no_unique_pixels_;

scml::Button pixel_display_mode_;
RGBColor* unique_pixels_;





};

#endif // PPM_EDITOR__CONSOLE_UI_H_
