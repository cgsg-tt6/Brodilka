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
double Zoom = 50;
int PosX = 0, PosY = 0;

void Display( void );

void PutPixel( int X, int Y, int R, int G, int B )
{
  if (X < 0 || X >= FRAME_W || Y < 0 || Y > FRAME_H)
    return;
  Frame[Y][X][0] = B;
  Frame[Y][X][1] = G;
  Frame[Y][X][2] = R;
}

void Display( void )
{
  glClearColor(0.30, 0.47, 0.8, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glRasterPos2d(-1, 1);
  glPixelZoom(Zoom, -Zoom);

  PutPixel(PosX, PosY, 100, 100, 100);

  glDrawPixels(FRAME_W, FRAME_H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}

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
      PutPixel(PosX, PosY, 0, 0, 0);
      PosY++;
    }
    printf("%i,%i\n", PosX, PosY);
    break;
  case 'w':
    if (PosY > 0)
    {
      PutPixel(PosX, PosY, 0, 0, 0);
      PosY--;
    }
    printf("%i,%i\n", PosX, PosY);
    break;
  case 'a':
    if (PosX > 0)
    {
      PutPixel(PosX, PosY, 0, 0, 0);
      PosX--;
    }
    printf("%i,%i\n", PosX, PosY);
    break;
  case 'd':
    if (PosX < 7)
    {
      PutPixel(PosX, PosY, 0, 0, 0);
      PosX++;
    }
    printf("%i,%i\n", PosX, PosY);
    break;
  }
}

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
  glutCreateWindow("Vitsan forever!!!");

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glutMainLoop();

  return 30;
} /* End of 'main' function */

/* END OF 'main.cpp' FILE */
