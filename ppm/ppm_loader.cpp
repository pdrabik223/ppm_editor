//
// Created by studio25 on 07.07.2021.
//

#include "ppm_loader.h"

exception::InvalidFileFormatException invalid_file_format;
exception::InvalidCharacterException invalid_character;

exception::BadDimensionsException bad_dimensions;
exception::InvalidPathException invalid_path;

exception::NotImplementedFileFormatException not_implemented_file_format;

bool IsComment(const char &letter) { return letter == '#'; }

void IgnoreComment(std::fstream &plik) {

  std::string comment;
  std::getline(plik, comment, '\n');
}

void HandleChar(std::fstream &plik) {
  char letter;

  plik.clear(plik.goodbit);

  plik >> letter; // ponownie wczytuje znak

  if (IsComment(letter))
    IgnoreComment(plik);
  else {

    throw invalid_character;
    // napotkano nioczekiwany symbol
  }
}

int ReadNumber(std::fstream &plik) {
  int number;
  do {
    plik >> number;
    if (plik.fail())
      HandleChar(plik);
    else
      return number;

  } while (!plik.eof());
  throw invalid_file_format;
  // plik nie posiada liczb albo ma ich za malo
}

unsigned char CheckColor(int color) {
  if (color < 0 || color > (int)256) {
    throw invalid_file_format;
  } else
    return (unsigned char)color;
}

void ReadHeader(std::fstream &plik) {
  char letter;
  do {

    plik >> letter;
    if (IsComment(letter))
      IgnoreComment(plik); // in case of # we ignore the rest of the line

    else if (letter == 'P') {
      plik >> letter;
      if (letter == '3')
        return;

      else
        throw invalid_character;
    }
  } while (!plik.eof());
  throw invalid_file_format;
}

void LoadFromPpm(std::string path, Canvas &image) {

  std::fstream plik;
  plik.open(path, std::ios::in);
  int image_width, image_height;
  if (plik.good()) {

    ReadHeader(plik);

    image_width = ReadNumber(plik);

    image_height = ReadNumber(plik);

    int max_color = ReadNumber(plik);

    if (max_color < 0 || max_color > 255) {
      throw bad_dimensions;
    }

    size_t array_size = image_height * image_width; // tymczasowa  zmienna

    Canvas target_image(image_height, image_width);

    for (unsigned i = 0; i < array_size; i++) {

      if (plik.eof()) {
        throw bad_dimensions;
      }
      unsigned char R = CheckColor(ReadNumber(plik));

      if (plik.eof()) {
        throw bad_dimensions;
      }
      unsigned char G = CheckColor(ReadNumber(plik));

      if (plik.eof()) {
        throw bad_dimensions;
      }
      unsigned char B = CheckColor(ReadNumber(plik));

      target_image[i] = {R, G, B};
    }


  } else {
    // in case of invalid path
    throw invalid_path;
  }
}

void SaveToPpm(const Canvas &target, const std::string &path) {
  std::ofstream myfile;
  myfile.open(path);

  myfile << "P3\n";
  myfile << target.GetWidth();
  myfile << " ";
  myfile << target.GetHeight();

  myfile << "\n";
  myfile << 255;
  myfile << "\n";

  size_t l = 0;

  for (size_t y = 0; y < target.GetHeight(); y++) {
    for (size_t x = 0; x < target.GetWidth(); x++) {

      myfile << (int)target.GetPixel({x, y}).GetR();
      myfile << " ";
      myfile << (int)target.GetPixel({x, y}).GetG();
      myfile << " ";
      myfile << (int)target.GetPixel({x, y}).GetB();
      myfile << " ";

      l += 12;
      if (l > 70) {
        l = 0;
        myfile << "\n";
      }
    }
  }
  myfile.close();
}