#include "../../Headers/Commands/LoadCommand.h"

LoadCommand::LoadCommand(int &width, int &height, PlayerCaretaker *player_caretaker, EnemiesCaretaker *enemies_caretaker, PlayerLogic *player_logic, EnemyLogic *enemy_logic, bool &error): width_(width), height_(height), player_caretaker_(player_caretaker), enemies_caretaker_(enemies_caretaker), player_logic_(player_logic), enemy_logic_(enemy_logic), error_(error){
    load_.open("LastGame.save", std::fstream::in);
};

void LoadCommand::Execute(){
    try {
        PlayerMemento *player_memento = new PlayerMemento(&(player_logic_->player));
        EnemiesMemento *enemies_memento = new EnemiesMemento(enemy_logic_->enemy);
        std::string field_conditions = "";
        std::string size = "";
        std::string number = "";
        int x, y;
        FileExceptions::ReadFromFile(load_, field_conditions);
        FileExceptions::ReadFromFile(load_, size);
        std::istringstream sizestream(size);
        sizestream >> number;
        width_ = stoi(number);
        sizestream >> number;
        height_ = stoi(number);
        FileExceptions::CheckCoordinate(width_, 210, height_, 50);
        Iterator field_iterator = Field::GetInstance(width_, height_)->First();
        int i = 0;
        int enemy_count = 0;
        for (; field_iterator != Field::GetInstance()->Last(); field_iterator++){
            (*field_iterator).NewCell(i / width_, i % width_, (int)(field_conditions[i] - '0'));
            (*field_iterator).SetCreator((int)(field_conditions[i] - '0'));
            i++;
        }
        std::string player_coords = "";
        std::string player_data = "";
        FileExceptions::ReadFromFile(load_, player_coords);
        FileExceptions::ReadFromFile(load_, player_data);
        std::istringstream playercoordsstream(player_coords);
        playercoordsstream >> number;
        y = stoi(number);
        playercoordsstream >> number;
        x = stoi(number);
        FileExceptions::CheckCoordinate(x, width_, y, height_);
        Field::GetInstance()->SetPlayer(Field::GetInstance()->CellInfo(y, x));
        std::istringstream playerdatastream(player_data);
        playerdatastream >> number;
        player_memento->hp_ = stoi(number);
        playerdatastream >> number;
        player_memento->score_ = stoi(number);
        playerdatastream >> number;
        player_memento->target_reached_ = stoi(number);
        player_caretaker_->SetMemento(player_memento);
        std::string enemy_coords = "";
        std::string enemy_data = "";
        FileExceptions::ReadFromFile(load_, enemy_coords);
        std::istringstream enemycoordsstream1(enemy_coords);
        enemycoordsstream1 >> number;
        y = stoi(number);
        enemycoordsstream1 >> number;
        x = stoi(number);
        FileExceptions::CheckCoordinate(x, width_, y, height_);
        Field::GetInstance()->SetEnemy(1, Field::GetInstance()->CellInfo(y, x));
        FileExceptions::ReadFromFile(load_, enemy_data);
        std::istringstream enemydatastream1(enemy_data);
        enemydatastream1 >> number;
        enemies_memento->hp_[0] = stoi(number);
        enemydatastream1 >> number;
        enemies_memento->buff_[0] = stoi(number);
        enemydatastream1 >> number;
        enemies_memento->damage_[0] = stoi(number);
        enemydatastream1 >> number;
        enemies_memento->steal_amount_[0] = stoi(number);
        enemy_coords = "";
        enemy_data = "";
        FileExceptions::ReadFromFile(load_, enemy_coords);
        std::istringstream enemycoordsstream2(enemy_coords);
        enemycoordsstream2 >> number;
        y = stoi(number);
        enemycoordsstream2 >> number;
        x = stoi(number);
        FileExceptions::CheckCoordinate(x, width_, y, height_);
        Field::GetInstance()->SetEnemy(2, Field::GetInstance()->CellInfo(y, x));
        FileExceptions::ReadFromFile(load_, enemy_data);
        std::istringstream enemydatastream2(enemy_data);
        enemydatastream2 >> number;
        enemies_memento->hp_[1] = stoi(number);
        enemydatastream2 >> number;
        enemies_memento->buff_[1] = stoi(number);
        enemydatastream2 >> number;
        enemies_memento->damage_[1] = stoi(number);
        enemydatastream2 >> number;
        enemies_memento->steal_amount_[1] = stoi(number);
        enemy_coords = "";
        enemy_data = "";
        FileExceptions::ReadFromFile(load_, enemy_coords);
        std::istringstream enemycoordsstream3(enemy_coords);
        enemycoordsstream3 >> number;
        y = stoi(number);
        enemycoordsstream3 >> number;
        x = stoi(number);
        FileExceptions::CheckCoordinate(x, width_, y, height_);
        Field::GetInstance()->SetEnemy(3, Field::GetInstance()->CellInfo(y, x));
        FileExceptions::ReadFromFile(load_, enemy_data);
        std::istringstream enemydatastream3(enemy_data);
        enemydatastream3 >> number;
        enemies_memento->hp_[2] = stoi(number);
        enemydatastream3 >> number;
        enemies_memento->buff_[2] = stoi(number);
        enemydatastream3 >> number;
        enemies_memento->damage_[2] = stoi(number);
        enemydatastream3 >> number;
        enemies_memento->steal_amount_[2] = stoi(number);
        enemies_caretaker_->SetMemento(enemies_memento);
        player_caretaker_->Undo();
        enemies_caretaker_->Undo();
        for (int n = 0; n < 3; n++){
            if (enemies_memento->hp_[n] == -15){
                Field::GetInstance()->GetEnemy(n+1)->SetEnemy(false);
            }
        }
    }
    catch (FileExceptions &exception){
        std::cerr << "Error: " << exception.GetType() <<  " Game progress won't be loaded.\n";
        error_ = true;
        return;
    }
}

LoadCommand::~LoadCommand(){
    if (load_.is_open()){
        load_.close();
    }
}
