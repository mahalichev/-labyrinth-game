#ifndef FILEEXCEPTIONS_H
#define FILEEXCEPTIONS_H

#include <iostream>
#include <fstream>

class FileExceptions{
public:
    FileExceptions(std::string type);
    static void ReadFromFile(std::fstream &load_, std::string &to_read);
    static void WriteToFile(std::fstream &save_, std::string &to_write);
    static void CheckCoordinate(int x, int xlim, int y, int ylim);
    std::string GetType();
private:
    std::string type_;
};

#endif
