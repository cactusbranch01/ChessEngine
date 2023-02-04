//
// Created by user on 2023-02-03.
//

#ifndef MATRIXCHESSENGINECODE_INPUT_H
#define MATRIXCHESSENGINECODE_INPUT_H
#include <string>
using namespace std;


class Input {
public:
    int size;

public:
    explicit Input(string file_name);

    int convert(string target);

};


#endif //MATRIXCHESSENGINECODE_INPUT_H
