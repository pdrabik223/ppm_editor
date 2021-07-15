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

Scml::Scml() : last_event_(scml::Event::NONE) {
  hc_ = GetStdHandle(STD_OUTPUT_HANDLE);
}

unsigned Scml::GetScreenWidth() {
  _CONSOLE_SCREEN_BUFFER_INFO info;
  GetConsoleScreenBufferInfo(hc_, &info);
  return info.dwSize.X;
}

unsigned Scml::GetScreenHeight() {
  _CONSOLE_SCREEN_BUFFER_INFO info;
  GetConsoleScreenBufferInfo(hc_, &info);
  return info.dwSize.Y;
}

void Scml::ClearScreen() {
  SetConsoleCursorPosition(hc_, {0, 0});
  for (std::string &line : display_bufor_)
    for (char &c : line)
      printf(" ");
}

void Scml::DisplayText(Coord position, const std::string &text) {

  display_bufor_.resize(position.h);
  display_bufor_[position.h].resize(position.w + text.size());

  for (int i = 0; i < text.size(); i++)
    display_bufor_[position.h][i + position.w] = text[i];
}

void Scml::DisplayButton(const scml::Button &text, Coord cursor_position) {
  DisplayText(text.GetPosition(), text.Display(cursor_position));
}
void Scml::DisplayTextField(const scml::TextField &text_field) {
  DisplayText(text_field.GetPosition(), text_field.Display());
}
void Scml::UpdateScreen() {
  for (std::string &line : display_bufor_)
    for (char &c : line)
      printf("%c", c);
}
