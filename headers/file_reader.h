//
// Created by gosha on 10/26/2022.
//

#ifndef MATRIX_FILE_READER_H
#define MATRIX_FILE_READER_H


#include <fstream>
#include <cstddef>
#include <string>
#include "rational.h"

//read info from file
class File_Reader {
public:
    File_Reader(const char*);
    ~File_Reader();

    bool float_reading(float&);
    bool sizet_reading(std::size_t&);
    bool char_reading(char&);
    bool string_reading(std::string&);

private:
    const char* file_name;
    std::ifstream fin;
};


#endif //MATRIX_FILE_READER_H
