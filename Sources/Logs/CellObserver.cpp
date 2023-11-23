#include "../../Headers/Logs/CellObserver.h"

CellObserver::CellObserver(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::string filename(80, '\0');
    std::strftime(&filename[0], filename.size(), "CellLogs_%F_%H-%M-%S.txt", ltm);
    cell_logs_.open(filename, std::fstream::out | std::fstream::app);
}

void CellObserver::Update(ISubject *element){
    cell_logs_ << (Cell*)element;
}

CellObserver::~CellObserver(){
    if (cell_logs_.is_open()){
        cell_logs_.close();
    }
}
