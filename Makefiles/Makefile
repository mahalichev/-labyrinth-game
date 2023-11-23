OBJ = main.o Cell.o Field.o Player.o PlayerLogic.o EnemyLogic.o Iterator.o PlayerIterator.o Facade.o Maze.o
ENM = Enemy.o EnemiesContext.o State.o EnemyHandle.o PlayerHandle.o PlayerAttackHandle.o BuffsHandle.o DamageHandle.o StealPointsHandle.o MoveHandle.o
STG = Strategy.o StrategyContext.o AddScoreStrategy.o DamageStrategy.o HPStrategy.o MoveStrategy.o TargetStrategy.o
FTR = Element.o AddScoreElement.o DamageElement.o HPElement.o MoveElement.o TargetElement.o Creator.o AddScoreElementCreator.o DamageElementCreator.o HPElementCreator.o MoveElementCreator.o TargetElementCreator.o
LOGS = Abstraction.o CellObserver.o IObserver.o ISubject.o PlayerObserver.o
CMDS = Command.o DisplayFieldCommand.o DisplayInfoCommand.o ExitCommand.o GameLogicCommand.o MoveCommand.o RunCommand.o StartCommand.o SaveCommand.o LoadCommand.o FileExceptions.o
MMNT = Memento.o PlayerMemento.o EnemiesMemento.o Caretaker.o PlayerCaretaker.o EnemiesCaretaker.o
NAME = a.out
H = ../Headers
S = ../Sources

all: a.out

a.out: MakeStrategy MakeFactory MakeLogs MakeCommands MakeEnemies MakeMemento $(OBJ)
	g++ $(OBJ) $(ENM) $(STG) $(FTR) $(LOGS) $(CMDS) $(MMNT) -o $(NAME)
main.o: $(S)/main.cpp $(H)/Facade.h
	g++ -c $(S)/main.cpp
Cell.o: $(S)/Cell.cpp $(H)/Cell.h
	g++ -c $(S)/Cell.cpp
Maze.o: $(S)/Maze.cpp $(H)/Maze.h
	g++ -c $(S)/Maze.cpp
Field.o: $(S)/Field.cpp $(H)/Field.h $(H)/Cell.h
	g++ -c $(S)/Field.cpp
Player.o: $(S)/Player.cpp $(H)/Player.h
	g++ -c $(S)/Player.cpp
PlayerLogic.o: $(S)/PlayerLogic.cpp $(H)/PlayerLogic.h
	g++ -c $(S)/PlayerLogic.cpp
EnemyLogic.o: $(S)/EnemyLogic.cpp $(H)/EnemyLogic.h
	g++ -c $(S)/EnemyLogic.cpp
Iterator.o: $(S)/Iterator.cpp $(H)/Iterator.h $(H)/Field.h
	g++ -c $(S)/Iterator.cpp
PlayerIterator.o: $(S)/PlayerIterator.cpp $(H)/PlayerIterator.h $(H)/Field.h
	g++ -c $(S)/PlayerIterator.cpp
Facade.o: $(S)/Facade.cpp $(H)/Facade.h $(H)/Facade.h $(H)/Field.h $(H)/Iterator.h
	g++ -c $(S)/Facade.cpp
MakeStrategy: $(S)/Strategy $(H)/Strategy
	make -f StrategyPattern
MakeFactory: $(S)/Factory $(H)/Factory
	make -f FactoryPattern
MakeLogs: $(S)/Logs $(H)/Logs
	make -f LogsPattern
MakeCommands: $(S)/Commands $(H)/Commands
	make -f CommandsPattern
MakeEnemies: $(S)/Enemies $(H)/Enemies
	make -f Enemies
MakeMemento: $(S)/Memento $(H)/Memento
	make -f MementoPattern
run: a.out
	./$(NAME)
clearlogs:
	rm -rf CellLogs*.txt PlayerLogs*.txt
clearobj:
	rm -rf *.o
leaks: a.out
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=leaks-out.txt ./$(NAME)
clear:
	rm -rf *.o $(NAME) *.txt *.save
