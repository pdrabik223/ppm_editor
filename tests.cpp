
//
// Created by studio25 on 17.07.2021.
//
#include "canvas.h"
#include "ppm/ppm_loader.h"
#include <assert.h>
#include <iostream>
#include <vector>
int main() {
  std::cout << " Pow2 function ";
  assert(Pow2(0) == 1);
  assert(Pow2(1) == 2);
  assert(Pow2(5) == 32);
  assert(Pow2(6) == 64);
  assert(Pow2(7) == 128);
  assert(Pow2(8) == 256);
  std::cout << "[ ok ]\n";

  std::cout << " hash() and constructor from integer";
  {
    RGBColor test(123, 231, 32);
    assert(test == RGBColor(test.Hash()));
  }
  std::cout << "[ ok ]\n";


  return 0;
}