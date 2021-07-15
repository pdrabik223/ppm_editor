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
  ARROW_RIGHT_RELEASE,
  BUTTON_0_PRESS,
  BUTTON_1_PRESS,
  BUTTON_2_PRESS,
  BUTTON_3_PRESS,
  BUTTON_4_PRESS,
  BUTTON_5_PRESS,
  BUTTON_6_PRESS,
  BUTTON_7_PRESS,
  BUTTON_8_PRESS,
  BUTTON_9_PRESS



};

}

#ifdef WIN32
#include "canvas.h"
#include <string>
#include <vector>
#include "button.h"
#include "text_field.h"

class Scml {
public:
  Scml();

  unsigned GetScreenWidth();

  unsigned GetScreenHeight();

  void DisplayText(Coord position, std::string text);

  void DisplayButton(Coord position, scml::Button text);

  void DisplayTextField(Coord position, scml::TextField text);

  void DisplayTextField();

  bool AwaitEvent();

  void UpdateScreen();

  scml::Event GetLastEvent() const;

private:
  std::vector<std::string> display_bufor_;

  Coord cursor_position_;

  scml::Event last_event_;

};

#endif

#endif // PPM_EDITOR__SIMPLE_CONSOLE_MEDIA_LAYER_H_
