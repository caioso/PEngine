// Engine Include
#include "../../engine/engine.hpp"

// Custom User Scripts
#include "board_task.hpp"

int main(int argc, char **argv)
{
    // Do not change this line.
    Engine::Init();

    // Declare and Subscribe your scripts here.
    BoardTask * __board_p1 = new BoardTask("P1 Board",
                                        Dim2D(7,12),
                                        Point2D(32,48 + 32 + 16 + 3),
                                        Point2D(3,5),
                                        PPL_PLAYER_1);
    BoardTask * __board_p2 = new BoardTask("P2 Board",
                                        Dim2D(7,12),
                                        Point2D(320,48 + 32 + 16 + 3),
                                        Point2D(3,5),
                                        PPL_PLAYER_2);

    ScriptManager::Subscribe(__board_p1);
    ScriptManager::Subscribe(__board_p2);

    // Do not change this line.
    Engine::Loop();

    // Do not change this line.
    Engine::Finalize();
}
