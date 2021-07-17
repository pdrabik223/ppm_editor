//
// Created by studio25 on 07.07.2021.
//

#include "../canvas.h"
#include "file_exception.h"
#include <fstream>
#include <string>

#ifndef PPM_LOADER_H_
#define PPM_LOADER_H_

void LoadFromPpm(std::string path, Canvas &image);

void SaveToPpm(const Canvas & target,const std::string& path);

bool IsComment(const char &letter);

void IgnoreComment(std::fstream &plik);

void HandleChar(std::fstream &plik);

int ReadNumber(std::fstream &plik);

unsigned char CheckColor(int color);

void ReadHeader(std::fstream &plik);


#endif // PPM_LOADER_H_
