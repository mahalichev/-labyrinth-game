#include "../../Headers/Logs/PlayerObserver.h"

PlayerObserver::PlayerObserver(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::string filename(80, '\0');
    std::strftime(&filename[0], filename.size(), "PlayerLogs_%F_%H-%M-%S.txt", ltm);
    player_logs_.open(filename, std::fstream::out | std::fstream::app);
}

void PlayerObserver::Update(ISubject *element){
    player_logs_ << (Player*)element;
}

PlayerObserver::~PlayerObserver(){
    if (player_logs_.is_open()){
        player_logs_.close();
    }
}
