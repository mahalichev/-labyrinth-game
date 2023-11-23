# labyrinth-game
CLI labyrinth game, which was created in the process of studying object-oriented programming. The game code includes the main patterns of this programming paradigm, such as:
* __Singleton__ - creation and provision of the playing field;
* __Iterator__ - pass the playing field;
* __Factory method__ - creation of interactive game elements;
* __Strategy__ - dynamically changing the player's interaction with elements;
* __Observer__ - tracking of game elements;
* __Bridge__ - separation of interface and logging class;
* __Command__ - user interaction with the game;
* __Facade__ - simplifying complex class interactions and providing a unified interface;
* __State__ - transfer of turns between the player and enemies;
* __Memento__ - getting program state.

## ❓ How to play
To compile and run use this commands:
```
cd ./Makefiles
make
./a.out
```

The player starts from cell _s_. To complete the labyrinth, he needs to unlock exit _e_ using the key _*_ and stand on the exit cell (unlocking occurs automatically).

However, the game may end before the player reaches the exit:
1) The player’s HP will run out (from attacks from opponents _V_ or from debuff _-_). To replenish your health, use the buff _+_;
2) You will run out of points. Each turn the player spends 1 point to move, and being near an enemy also takes away some points.

Your opponents can get random buffs, and you can use elements of the playing field to make it easier to navigate through the labyrinth.

# Good luck!
