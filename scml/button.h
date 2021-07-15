//
// Created by studio25 on 14.07.2021.
//

#ifndef PPM_EDITOR_SCML_BUTTON_H_
#define PPM_EDITOR_SCML_BUTTON_H_
#include "../canvas.h"
#include <string>

namespace scml {
namespace button {

enum class HighlightMode {
  CHARACTER_LEFT,
  CHARACTER_RIGHT,
  BOTH_SIDES,
  UPPERCASE
};

} // namespace button
/// classic button if you press it, it's pressed
/// otherwise it's not
class Button {
public:
  Button(const std::string &text, const Coord &position, unsigned int w,
         unsigned int h);

  bool CheckBoundaries(Coord position);

  const std::string Display(Coord position)const ;

  const Coord GetPosition() const;



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
  button::HighlightMode highlight_mode_;

  std::pair<char,char> highlight_characters_;
};

} // namespace scml
#endif // PPM_EDITOR_SCML_BUTTON_H_
