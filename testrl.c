#include <stdint.h>
#include <string.h>
#include <math.h>

#include "raylib.h"

#include "dices.h"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

Image ImageFromMonoBitmap( int w, int h, const uint8_t*bitmap_data, Color col )
{
    Image img = GenImageColor(w, h, BLANK);
    
    for (int y=0; y<h; y++)    
      for (int x=0; x<w/8; x++)
      {     
        uint8_t bytevalue = bitmap_data[ y*w/8 + x];        
        for(int bitp = 0; bitp < 8; bitp++)
            ImageDrawPixel(&img, x*8+bitp, y, (bytevalue & (0b10000000 >> bitp) ? col :  BLANK ) );
       }
   
   return img;
}

Texture2D TextureFromMonoBitmap( int w, int h, const uint8_t*bitmap_data, Color col )
{   
   return LoadTextureFromImage(ImageFromMonoBitmap(w,h,bitmap_data,col));
}

void plotInDice(uint8_t *coords)
{
   uint8_t xdesp = (coords[0] % 8);
   uint8_t *pos = diceImage + (coords[0] / 8) + coords[1] * 3;

   if( xdesp != 7)
        *pos |= (0b11000000 >> xdesp);
    else
    {
        *pos |= (0b00000001);
        *(pos+1) |= 0b10000000;      
    }
}


void createDiceBitmap( int diceValue, int diceNextValue, int frame)
{
   // frame = 3-frame;
   if (frame > 0)
    frame = 4 - frame;
    memcpy(diceImage, dicePreImages[frame], 21*3);

    if (frame == 0)
        diceNextValue = diceValue;

    for(int p = 0; p < 7; p++)
    {
        if( (dotsNumbers[diceNextValue-1] & (1 << p)) != 0 )
            plotInDice( dotsPos[frame][0][p] );
        
        if( (dotsNumbers[diceValue-1] & (1 << p)) != 0 )
            plotInDice( dotsPos[frame][1][p] );
    }
}

int main(void)
{
    int frameCount = 0;
    const int screenWidth =1920; //= 800;
    const int screenHeight = 1080; //l450;
    const int gameScreenWidth = 800;
    const int gameScreenHeight = 450;
    int diceCurrentAnim = 0;
    const int diceAnimEveryXFrame = 8;
    int diceAnimCount = 0;
    int diceValue = 3;
    int diceNextValue = 6;
    int dy = 0;


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    //ToggleFullscreen();
    
    float scale = MIN((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);

    RenderTexture2D target = LoadRenderTexture(gameScreenWidth, gameScreenHeight);
    SetTextureFilter(target.texture, FILTER_BILINEAR);  // Texture scale filter to use

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second


    createDiceBitmap( diceValue, diceNextValue, diceCurrentAnim);
    Texture tdice = TextureFromMonoBitmap( 24, 21, diceImage, BLACK );
    Texture tmaskdice = TextureFromMonoBitmap( 24, 21, diceMask[0], WHITE );
    
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginTextureMode(target);
            ClearBackground(LIGHTGRAY);

            if( diceAnimCount++ == diceAnimEveryXFrame)
            {
                diceCurrentAnim = (diceCurrentAnim + 1) % 4 ;
                
                if( diceCurrentAnim == 0)
                {
                    diceValue = diceNextValue;
                    diceNextValue++;
                    if( diceNextValue == 7)
                        diceNextValue = 1;

                }
                createDiceBitmap( diceValue, diceNextValue, diceCurrentAnim);
                tdice = TextureFromMonoBitmap( 24, 21, diceImage, BLACK );
                tmaskdice = TextureFromMonoBitmap( 24, 21, diceMask[diceCurrentAnim == 0 ? 0 : 4-diceCurrentAnim], WHITE );
                diceAnimCount = 0;

            }

            if( frameCount % 1 == 0)
            {
                    dy ++;
                    dy %= 32;
            }

            for(int y = 0; y < screenHeight; y+=128)
            {
                int v = (diceValue + y/32) % 6 + 1;
                int v2 = v+1;
                if( v2 == 7) 
                    v2=1;
                //createDiceBitmap( v, v2, diceCurrentAnim);
                //createDiceBitmap( diceValue, diceNextValue, diceCurrentAnim);
                //tdice = TextureFromMonoBitmap( 24, 21, diceImage, BLACK );
                //tmaskdice = TextureFromMonoBitmap( 24, 21, diceMask[diceCurrentAnim], WHITE );

                double dy = sin(((float)(frameCount))/16.0) * 64.0 - 32 ;

                for(int x = 0; x < screenWidth; x+= 128)
                {
                    double dx = sin(((float)(frameCount))/8.0) * 64.0 - 32 ;
//                    DrawTexture(tmaskdice, x+((int)dx),y-dy, WHITE);
//                    DrawTexture(tdice, x+((int)dx),y-dy, WHITE);

                    double dx2 = sin(((float)(frameCount*200+x))/8.0) * 32.0 - 32 ;
                    double dy2 = cos(((float)(frameCount*200+y))/8.0) * 16.0 - 16 ;
                    

                    DrawTexturePro( tmaskdice, 
                                    (Rectangle){ 0.0f, 0.0f, (float)tmaskdice.width, (float)-tmaskdice.height },
                                    (Rectangle){ x+((int)dx)+dy2,y+dy+dx2, (float)tmaskdice.width*6, (float)tmaskdice.height*6 },                          
                                    (Vector2){ 0,0 }, 0.0f, WHITE);
                    DrawTexturePro( tdice, 
                                    (Rectangle){ 0.0f, 0.0f, (float)tdice.width, (float)-tdice.height },
                                    (Rectangle){ x+((int)dx)+dy2,y+dy+dx2, (float)tdice.width*6, (float)tdice.height*6 },                          
                                    (Vector2){ 0,0 }, 0.0f, WHITE);


                }

                //UnloadTexture( tdice );
                //UnloadTexture( tmaskdice );
                
            }
            
            DrawText("Hello world!", 100, 200, 100, RED);
        EndTextureMode();

        BeginDrawing();
            ClearBackground(BLACK);     // Clear screen background

            // Draw render texture to screen, properly scaled
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
                           (Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5f, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5f,
                           (float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
        frameCount++;
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}