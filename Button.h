//
// Created by studio25 on 14.07.2021.
//

#ifndef PPM_EDITOR__BUTTON_H_
#define PPM_EDITOR__BUTTON_H_
#include "canvas.h"
#include <string>
namespace scml {
namespace button {

enum class Highlight_mode {
  CHARACTER_LEFT,
  CHARACTER_RIGHT,
  BOTH_SIDES,
  UPPERCASE
};

}// namespace button

class Button {
public:


protected:

  /// button text
  std::string text_;

  /// placement on the screen
  Coord position_;
  /// width of the button
  unsigned w_;
  /// height of the button
  unsigned h_;
  /// highlight mode
  button::Highlight_mode highlight_mode_;

  char highlight_character_;

};




} // namespace scml
#endif // PPM_EDITOR__BUTTON_H_
