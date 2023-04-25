//
// Created by gosha on 10/26/2022.
//

#ifndef MATRIX_FILE_WRITER_H
#define MATRIX_FILE_WRITER_H


#include <cstddef>
#include <fstream>
#include <string>
#include "rational.h"
//write information to file
class File_Writer {

public:
    File_Writer(const char *);
    ~File_Writer();

    bool float_writing(const float&);
    bool sizet_writing(const std::size_t&);
    bool char_writing(const char&);
    bool string_writing(const std::string&);
    bool rational_writing(const rational&);
public:
    const char* file_name;
    std::ofstream fout;
};

#endif //MATRIX_FILE_WRITER_H
