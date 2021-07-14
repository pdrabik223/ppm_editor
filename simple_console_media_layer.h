//
// Created by studio25 on 14.07.2021.
//

#ifndef PPM_EDITOR__SIMPLE_CONSOLE_MEDIA_LAYER_H_
#define PPM_EDITOR__SIMPLE_CONSOLE_MEDIA_LAYER_H_

namespace scml {
enum class Event {
  ENTER_PRESS,
  ARROW_UP_PRESS,
  ARROW_DOWN_PRESS,
  ARROW_LEFT_PRESS,
  ARROW_RIGHT_PRESS,
  ARROW_UP_RELEASE,
  ARROW_DOWN_RELEASE,
  ARROW_LEFT_RELEASE,
  ARROW_RIGHT_RELEASE

};

}

#ifdef WIN32
#include "canvas.h"
#include <string>
#include <vector>

class Scml {

  Scml();

  unsigned GetScreenWidth();

  unsigned GetScreenHeight();

  void DisplayText(Coord position, std::string text);

  void DisplayButton(Coord position, Button text);

  bool AwaitEvent();

  void UpdateScreen();



private:
  std::vector<std::string> display_bufor_;

  Coord cursor_position_;
};

#endif

#endif // PPM_EDITOR__SIMPLE_CONSOLE_MEDIA_LAYER_H_
