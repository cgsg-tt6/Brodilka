/* FILE NAME   : main.cpp
 * PROGRAMMER  : TT6
 * LAST UPDATE : 06.01.2022
 * PURPOSE     : Simple game sample.
 */

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

#include "glut.h"

#define FRAME_W 8  //1277
#define FRAME_H 8  //655

typedef unsigned char byte;

byte Frame[FRAME_H][FRAME_W][3];

/* Condition of the pixel.
 * 0 - default field,
 * 1 - The Hero (only one pixel, in snake it could be multiple),
 * 2 - apple for snake or something to shot in.
 */
byte Cond[FRAME_H][FRAME_W];

double Zoom = 50;
int PosX = 0, PosY = 0;

// References.
void Display( void );

/* Put pixel to Frame function. (Not drawing)
 * ARGUMENTS:
 *   - coordinates of the pixel:
 *       int X, int Y;
 *   - color of the pixel [0..255]:
         int R, int G, int B;
 * RETURNS: None.
 */
void PutPixel( int X, int Y, int R, int G, int B )
{
  if (X < 0 || X >= FRAME_W || Y < 0 || Y > FRAME_H)
    return;
  Frame[Y][X][0] = B;
  Frame[Y][X][1] = G;
  Frame[Y][X][2] = R;
} /* End of 'PutPixel' function */

/* Drawing to screen function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
void Display( void )
{
  glClearColor(0.30, 0.47, 0.8, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glRasterPos2d(-1, 1);
  glPixelZoom(Zoom, -Zoom);

  Cond[PosX][PosY] = 1;

  for (int i = 0; i < FRAME_W; i++)
    for (int j = 0; j < FRAME_H; j++)
    {
      switch (Cond[i][j])
      {
      case 1:
        PutPixel(i, j, 100, 100, 100);
        break;
      default:
        PutPixel(i, j, 0, 0, 0);
        break;
      }
    }

  glDrawPixels(FRAME_W, FRAME_H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
} /* End of 'Display' function */

/* Keyboard function.
 * ARGUMENTS:
 *   - key that is tapped:
 *       unsigned char Key;
 *   - needed parameters for template in main:
 *       int X, int Y;
 * RETURNS: None.
 */
void Keyboard( unsigned char Key, int X, int Y )
{
  switch (Key)
  {
  case 27:
    exit(0);
    break;

  case 's':
    if (PosY < 7)
    {
      Cond[PosX][PosY] = 0;
      PosY++;
    }
    printf("%i,%i\n", PosX, PosY);
    break;
  case 'w':
    if (PosY > 0)
    {
      Cond[PosX][PosY] = 0;
      PosY--;
    }
    printf("%i,%i\n", PosX, PosY);
    break;
  case 'a':
    if (PosX > 0)
    {
      Cond[PosX][PosY] = 0;
      PosX--;
    }
    printf("%i,%i\n", PosX, PosY);
    break;
  case 'd':
    if (PosX < 7)
    {
      Cond[PosX][PosY] = 0;
      PosX++;
    }
    printf("%i,%i\n", PosX, PosY);
    break;
  }
} /* End of 'Keyboard' function */

/* Main function of the project.
 * ARGUMENTS:
 *   - parameters:
 *       int argc, char* argv[];
 * RETURNS:
 *   (int) - 30 if correct.
 */
int main( int argc, char* argv[] )
{
  /* Initialization */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  /* Create window */
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(FRAME_W * Zoom, FRAME_H * Zoom);
  glutCreateWindow("2D Game-2022");

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glutMainLoop();

  return 30;
} /* End of 'main' function */

/* END OF 'main.cpp' FILE */
