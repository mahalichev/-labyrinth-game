#include "../../Headers/Enemies/EnemyHandle.h"

EnemyHandle::EnemyHandle(Player &player, Enemy<int> &enemy): player_(player), enemy_(enemy){};

void EnemyHandle::Handle(){
    if (enemy_.GetHP() > 0){
        BuffsHandle *buffs_state = new BuffsHandle(player_, enemy_);
        context.TransitionTo(buffs_state);
        context.Request();
        MoveHandle *move_state = new MoveHandle(enemy_);
        context.TransitionTo(move_state);
        context.Request();
        StealPointsHandle *steal_state = new StealPointsHandle(player_, enemy_);
        context.TransitionTo(steal_state);
        context.Request();
        DamageHandle *damage_state = new DamageHandle(player_, enemy_);
        context.TransitionTo(damage_state);
        context.Request();
    } else {
        if (enemy_.GetHP() != -15){
            enemy_.SetHP(-15);
            Field::GetInstance()->RemoveEnemy(enemy_.GetNumber());
        }
    }
};
