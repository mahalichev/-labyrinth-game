#include "../../Headers/Enemies/MoveHandle.h"

MoveHandle::MoveHandle(Enemy<int> &enemy): enemy_(enemy){}

void MoveHandle::Handle(){
    int directions[2] = {0, 1};
    int range[2] = {-1, 1};

    int N = 1;
    if (enemy_.GetBuffId() == 2){
        N = 2;
    }
    for (int i = 0; i < N; i++){
        bool working = true;
        do {
            int dir = directions[rand() % 2];
            int step = range[rand() % 2];
            if (dir){
                if ((Field::GetInstance()->CellInfo(Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetY(), Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetX() + step)->GetCondition() != 1) &&
                    (Field::GetInstance()->CellInfo(Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetY(), Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetX() + step)->IsEnemy() == false)){
                    Field::GetInstance()->SetEnemy(enemy_.GetNumber(), Field::GetInstance()->CellInfo(Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetY(), Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetX()+step));
                    working = false;
                }
            } else {
                if ((Field::GetInstance()->CellInfo(Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetY() + step, Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetX())->GetCondition() != 1) &&
                    (Field::GetInstance()->CellInfo(Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetY() + step, Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetX())->IsEnemy() == false)){
                    Field::GetInstance()->SetEnemy(enemy_.GetNumber(), Field::GetInstance()->CellInfo(Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetY() + step, Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetX()));
                    working = false;
                }
            }
        } while (working);
        enemy_.SetX(Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetX());
        enemy_.SetY(Field::GetInstance()->GetEnemy(enemy_.GetNumber())->GetY());
    }
}
