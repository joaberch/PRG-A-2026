//
// Created by cyco on 16.10.2026.
//

#include "saisir.h"

#include <iostream>
#include <ostream>
#include <string>

int saisir(const std::string& message, const int min, const int max) {
    int input;
    do {
        std::cout << message << std::endl;
        std::cin >> input;
    } while (input < min || input > max);
    return input;
}