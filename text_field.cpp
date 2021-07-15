//
// Created by studio25 on 15.07.2021.
//

#include "text_field.h"
scml::TextField::TextField(const Coord &position, unsigned int w,
                           unsigned int h)
    : position_(position), w_(w), h_(h) {
  bufor_ = " ";
}
void scml::TextField::CatchKeyBoard() {

  while (1 < 2) {
    console_handle_.AwaitEvent();
    switch (console_handle_.GetLastEvent()) {

    case Event::ENTER_PRESS:
      return;
    case Event::ARROW_UP_PRESS:
      break;
    case Event::ARROW_DOWN_PRESS:
      break;
    case Event::ARROW_LEFT_PRESS:
      break;
    case Event::ARROW_RIGHT_PRESS:
      break;
    case Event::ARROW_UP_RELEASE:
      break;
    case Event::ARROW_DOWN_RELEASE:
      break;
    case Event::ARROW_LEFT_RELEASE:
      break;
    case Event::ARROW_RIGHT_RELEASE:
      break;
    case Event::BUTTON_0_PRESS:
      bufor_ += '0';
      break;
    case Event::BUTTON_1_PRESS:
      bufor_ += '1';
      break;
    case Event::BUTTON_2_PRESS:
      bufor_ += '2';
      break;
    case Event::BUTTON_3_PRESS:
      bufor_ += '3';
      break;
    case Event::BUTTON_4_PRESS:
      bufor_ += '4';
      break;
    case Event::BUTTON_5_PRESS:
      bufor_ += '5';
      break;
    case Event::BUTTON_6_PRESS:
      bufor_ += '6';
      break;
    case Event::BUTTON_7_PRESS:
      bufor_ += '7';
      break;
    case Event::BUTTON_8_PRESS:
      bufor_ += '8';
      break;
    case Event::BUTTON_9_PRESS:
      bufor_ += '9';
      break;
    }
  }
}
