#include "../../Headers/Commands/FileExceptions.h"

FileExceptions::FileExceptions(std::string type): type_(type){};

void FileExceptions::ReadFromFile(std::fstream &load_, std::string &to_read){
    if (!load_.is_open()){
        throw FileExceptions("Can't open file.");
    }
    getline(load_, to_read);
    if (to_read == ""){
        throw FileExceptions("Can't read stroke.");
    }
}

void FileExceptions::WriteToFile(std::fstream &save_, std::string &to_write){
    if (!save_.is_open()){
        throw FileExceptions("Can't open file.");
    }
    if(!(save_ << to_write)){
        throw FileExceptions("Can't write to file.");
    }
}

void FileExceptions::CheckCoordinate(int x, int xlim, int y, int ylim){
    if ((x < 0) || (x >= xlim) || (y < 0) || (y >= ylim)){
        throw FileExceptions("Wrong coordinates.");
    }
}

std::string FileExceptions::GetType(){
    return type_;
}
