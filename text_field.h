//
// Created by studio25 on 15.07.2021.
//

#ifndef PPM_EDITOR__TEXT_FIELD_H_
#define PPM_EDITOR__TEXT_FIELD_H_

#include "canvas.h"
#include "simple_console_media_layer.h"
#include <string>
namespace scml {

class TextField {
public:
  TextField(const Coord &position, unsigned int w, unsigned int h);

  void CatchKeyBoard();

private:
  std::string bufor_;

  /// placement on the screen
  Coord position_;
  /// width of the text field
  unsigned w_;
  /// height of the text field
  unsigned h_;

  Scml console_handle_;
};
} // namespace scml

#endif // PPM_EDITOR__TEXT_FIELD_H_
