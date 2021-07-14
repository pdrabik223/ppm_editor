//
// Created by studio25 on 07.07.2021.
//


#include "file_exception.h"
#include "canvas.h"
#include <fstream>
#include <string>

#ifndef CONSOLE_CHESS_GUI_PPM_LOADER_H_
#define CONSOLE_CHESS_GUI_PPM_LOADER_H_

Canvas &LoadFromPpm(std::string path);

bool IsComment(const char &letter);

void IgnoreComment(std::fstream &plik);

void HandleChar(std::fstream &plik);

int ReadNumber(std::fstream &plik);

unsigned char CheckColor(int color);

void ReadHeader(std::fstream &plik);


#endif // CONSOLE_CHESS_GUI_PPM_LOADER_H_
