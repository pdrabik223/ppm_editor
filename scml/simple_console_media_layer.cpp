//
// Created by studio25 on 14.07.2021.
//

#include "simple_console_media_layer.h"

scml::Event Scml::GetLastEvent() const { return last_event_; }

bool Scml::AwaitEvent() {
  // for now it will be getch()
  // because I dont have energy to fight with windows
  char c;
  while (1 < 2) {
    c = getchar();
    switch (c) {
    case 13:
      last_event_ = scml::Event::ENTER_PRESS;
      return true;
    case '0':
      last_event_ = scml::Event::BUTTON_0_PRESS;
      return true;
    case '1':
      last_event_ = scml::Event::BUTTON_1_PRESS;
      return true;
    case '2':
      last_event_ = scml::Event::BUTTON_2_PRESS;
      return true;
    case '3':
      last_event_ = scml::Event::BUTTON_3_PRESS;
      return true;
    case '4':
      last_event_ = scml::Event::BUTTON_4_PRESS;
      return true;
    case '5':
      last_event_ = scml::Event::BUTTON_5_PRESS;
      return true;
    case '6':
      last_event_ = scml::Event::BUTTON_6_PRESS;
      return true;
    case '7':
      last_event_ = scml::Event::BUTTON_7_PRESS;
      return true;
    case '8':
      last_event_ = scml::Event::BUTTON_8_PRESS;
      return true;
    case '9':
      last_event_ = scml::Event::BUTTON_9_PRESS;
      return true;
    default:
      break;
    }
  }
}
