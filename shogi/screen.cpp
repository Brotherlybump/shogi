#include "raylib.h"
#include <string>
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 900;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Color cplayer = {0, 228, 48, 100};
    
    //Vector2 playerpos = {0, 800};
   // Vector2 playersize = {100, 100};
    Rectangle player;
        player.height = 100;
        player.width = 100;
        player.x = 0;
        player.y = 800;
     
    Rectangle lancaL;
        lancaL.height = 60, lancaL.width = 50, lancaL.x = 20, lancaL.y = 840;
    SetTargetFPS(20);              

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        
        Vector2 mouse = GetMousePosition();
        
       

        if(IsKeyPressed(KEY_RIGHT)) player.x += 100;
        if(IsKeyPressed(KEY_LEFT)) player.x -= 100;
        if(IsKeyPressed(KEY_UP)) player.y -= 100;
        if(IsKeyPressed(KEY_DOWN)) player.y += 100;
        
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

           for(int i=0; i<901; i=i+100){
            DrawLine(i, 0, i, 900, BLACK);
            DrawLine(0, i, 900, i, BLACK);
            }

            

            //piony
            
            DrawRectangleRec(player,cplayer);
            DrawRectangleLinesEx(lancaL,1,BLACK);
            //DrawRectangle(player.x, player.y, player.width, player.height, cplayer);
            //DrawRectangle(lancaL.x, lancaL.y, lancaL.width, lancaL.height, BLACK);
            DrawText(("x= " + std::to_string((int)mouse.x) + ", y= " + std::to_string((int)mouse.y)).c_str(), 10, GetScreenHeight() - 20, 20, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}