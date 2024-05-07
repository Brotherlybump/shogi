#include "raylib.h"
#include <string>

/*class player{
public:
    Color cplayer = {0, 228, 48, 100};
    void DrawPlayer(){
        DrawRectangle(0,900,100,100,cplayer);
    }
};*/
class Pion{
public: 
    Rectangle baza;
    Vector2 wierz[3];

    Pion(float x, float y, float szer, float wys) {
        baza.x = x;
        baza.y = y;
        baza.width = szer;
        baza.height = wys;


        wierz[0] = {(x + szer / 2), (y - 30)}; //top
        wierz[1] = {x, y};                     //left
        wierz[2] = {(x + szer), y};            //right
        
    }

    void Rys_pion_start() {
            DrawRectangleLines(baza.x, baza.y, baza.width, baza.height, BLACK);
            DrawTriangleLines(wierz[0], wierz[1], wierz[2], BLACK);
            DrawLine((baza.x + 1), baza.y, (baza.x + baza.width - 1), baza.y, WHITE);
    }
    void Up_pion() {
            baza.y-=100;
            for (int i = 0; i < 3; ++i) {
            wierz[i].y -= 100;
            }
            DrawRectangleLines(baza.x, baza.y, baza.width, baza.height, BLACK);
            DrawTriangleLines(wierz[0], wierz[1], wierz[2], BLACK);
            DrawLine((baza.x + 1), baza.y, (baza.x + baza.width - 1), baza.y, WHITE);
    }
    void Down_pion(){
        
    }
    };

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 900;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Color cplayer = {0, 228, 48, 100};
    bool player_selected = 0;
    //Vector2 playerpos = {0, 800};
   // Vector2 playersize = {100, 100};
    Rectangle player;
    player.height = 99,
    player.width = 99;
    player.x = 0;
    player.y = 801;
    Pion lancaL(20, 840, 60, 50);
    Pion skoczekL(120, 840, 60, 50); 
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
        if((player_selected) == 0 && (IsKeyPressed(KEY_SPACE))){
            cplayer.a = 150;
            player_selected = 1;
        }
            else if (IsKeyPressed(KEY_SPACE)){
                cplayer.a = 100;
                player_selected = 0;
            }
           
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

           for(int i=0; i<901; i=i+100){
            DrawLine(i, 0, i, 900, BLACK);
            DrawLine(0, i, 900, i, BLACK);
            }

            

            //piony
            lancaL.Rys_pion_start();
            skoczekL.Rys_pion_start();
            if(IsKeyPressed(KEY_W)){
                lancaL.Up_pion();
            }
            DrawRectangleRec(player, cplayer);

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