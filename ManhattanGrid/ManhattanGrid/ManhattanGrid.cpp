#include<GL\freeglut.h>

int main(int argc, char** argv)
{
     //function declarations
     void resize(int, int);
     void display();
     void keyboard(unsigned char, int, int);
     void initialize();

     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowPosition(800, 600);
     glutInitWindowPosition(0, 0);
     glutCreateWindow("NatStorey_Triangle_Square");

     initialize();

     glutDisplayFunc(display);
     glutKeyboardFunc(keyboard);
     glutReshapeFunc(resize);

     glutMainLoop();

}

void initialize()
{
     glClearColor(0.0, 0.0, 0.0, 1.0);
}

void resize(int width, int height)
{
     if (height == 0)
          height = 1;
     if (width == 0)
          width = 1;

     glViewport(0, 0, (GLsizei)width, (GLsizei)height);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     gluPerspective(45.0, (float)width / (float)height, 0.1, 100.0);
}

void display()
{
     glClear(GL_COLOR_BUFFER_BIT);

     glMatrixMode(GL_MODELVIEW);
     //42nd &...
     //42nd &7th
     glLoadIdentity();
     glTranslatef(1.1, 1.085, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.7, 1.095, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 42nd &7th to 42nd &8th
     glLoadIdentity();
     glTranslatef(0.5, 1.1, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.9, 1.075, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 42nd &8th to 42nd &7th
     glLoadIdentity();
     glTranslatef(0.5, 1.12, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //42nd &8th
     glLoadIdentity();
     glTranslatef(0.5, 1.085, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.25, 1.095, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 42nd &8th to 42nd &9th
     glLoadIdentity();
     glTranslatef(0.1, 1.1, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.4, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.4, 1.075, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 42nd &9th to 42nd &8th
     glLoadIdentity();
     glTranslatef(0.1, 1.12, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.4, 0.0, 0.0);
     glEnd();

     //42nd &9th
     glLoadIdentity();
     glTranslatef(0.1, 1.085, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.3, 1.095, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 42nd &9th to 42nd &10th
     glLoadIdentity();
     glTranslatef(-0.5, 1.1, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.1, 1.075, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 42nd &10th to 42nd &9th
     glLoadIdentity();
     glTranslatef(-0.5, 1.12, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //42nd &10th
     glLoadIdentity();
     glTranslatef(-0.5, 1.085, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.9, 1.095, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 42nd &10th to 42nd &11th
     glLoadIdentity();
     glTranslatef(-1.1, 1.1, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.7, 1.075, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 42nd &11th to 42nd &10th
     glLoadIdentity();
     glTranslatef(-1.1, 1.12, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //42nd &11th
     glLoadIdentity();
     glTranslatef(-1.1, 1.085, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();
     /***********************************************************************************************************************
     Vertical Segments, Avenues between 42nd street and 41st street
     ************************************************************************************************************************/
     //7th ave between 42nd and 41st
     glLoadIdentity();
     glTranslatef(1.1, 0.97, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(1.1, 1.065, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //8th ave between 42nd and 41st
     glLoadIdentity();
     glTranslatef(0.5, 0.97, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(0.5, 1.04, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //9th ave between 42nd and 41st
     glLoadIdentity();
     glTranslatef(0.1, 0.97, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(0.1, 1.065, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //10th ave between 42nd and 41st
     glLoadIdentity();
     glTranslatef(-0.5, 0.97, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-0.5, 1.04, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 41st to 42nd
     glLoadIdentity();
     glTranslatef(-1.075, 0.97, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-1.075, 1.04, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 42nd to 41st
     glLoadIdentity();
     glTranslatef(-1.125, 0.97, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     /******************************************************************************************************************************/


     //41st &...
     //41st &7th
     glLoadIdentity();
     glTranslatef(1.1, 0.97, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.7, 0.97, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 41nd &7th to 41nd &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.995, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //41st &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.97, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.3, 0.97, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 41st &8th to 41st &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.995, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //41st &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.97, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.3, 0.97, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 41st &9th to 41st &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.995, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //41st &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.97, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.9, 0.97, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 41st &9th to 41st &10th
     glLoadIdentity();
     glTranslatef(-1.1, 0.995, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //41st &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.97, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();
     /***********************************************************************************************************************
     Vertical Segments, Avenues between 41st street and 40th street
     ************************************************************************************************************************/
     //7th ave between 41st and 40th
     glLoadIdentity();
     glTranslatef(1.1, 0.855, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //8th ave between 41st and 4oth
     glLoadIdentity();
     glTranslatef(0.5, 0.855, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //9th ave between 41st and 40th
     glLoadIdentity();
     glTranslatef(0.1, 0.855, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //10th ave between 41st and 40th
     glLoadIdentity();
     glTranslatef(-0.5, 0.855, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 40th to 41st
     glLoadIdentity();
     glTranslatef(-1.075, 0.855, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 41st to 40th
     glLoadIdentity();
     glTranslatef(-1.125, 0.855, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(-1.125, 0.95, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //40th &...
     //40th &7th
     glLoadIdentity();
     glTranslatef(1.1, 0.855, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.9, 0.855, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 40th &7th to 40th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.88, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //40th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.855, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.4, 0.855, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 40th &8th to 40th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.88, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //40th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.855, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.1, 0.855, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 40th &9th to 40th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.88, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //40th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.855, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.7, 0.855, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 40th &10th to 40th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.88, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //40th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.855, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
     Vertical Segments, Avenues between 40th street and 39th street
     ************************************************************************************************************************/
     //7th ave between 40th and 39th
     glLoadIdentity();
     glTranslatef(1.1, 0.74, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(1.1, 0.835, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //8th ave between 40th and 39th
     glLoadIdentity();
     glTranslatef(0.5, 0.74, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(0.5, 0.81, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //9th ave between 40th and 39th
     glLoadIdentity();
     glTranslatef(0.1, 0.74, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(0.1, 0.835, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //10th ave between 40th and 39th
     glLoadIdentity();
     glTranslatef(-0.5, 0.74, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-0.5, 0.81, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 39th to 40th
     glLoadIdentity();
     glTranslatef(-1.075, 0.74, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-1.075, 0.81, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 40th to 39th
     glLoadIdentity();
     glTranslatef(-1.125, 0.74, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //39th &...
     //39th &7th
     glLoadIdentity();
     glTranslatef(1.1, 0.74, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.7, 0.74, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 39th &7th to 39th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.765, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //39th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.74, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.3, 0.74, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 39th &8th to 39th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.765, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //39th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.74, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.3, 0.74, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 39th &9th to 39th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.765, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //39th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.74, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.9, 0.74, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 39th &10th to 39th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.765, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //39th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.74, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
    Vertical Segments, Avenues between 39th street and 38th street
    ************************************************************************************************************************/
    //7th ave between 39th and 38th
     glLoadIdentity();
     glTranslatef(1.1, 0.625, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //8th ave between 39th and 38th
     glLoadIdentity();
     glTranslatef(0.5, 0.625, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //9th ave between 39th and 38th
     glLoadIdentity();
     glTranslatef(0.1, 0.625, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //10th ave between 39th and 38th
     glLoadIdentity();
     glTranslatef(-0.5, 0.625, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 38th to 39th
     glLoadIdentity();
     glTranslatef(-1.075, 0.625, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 39th to 38th
     glLoadIdentity();
     glTranslatef(-1.125, 0.625, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(-1.125, 0.72, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //38th &...
     //38th &7th
     glLoadIdentity();
     glTranslatef(1.1, 0.625, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.9, 0.625, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 38th &7th to 38th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.65, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //38th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.625, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.4, 0.625, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 38th &8th to 38th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.65, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //38th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.625, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.1, 0.625, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 38th &9th to 38th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.65, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //38th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.625, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.7, 0.625, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 38th &10th to 38th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.65, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //38th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.625, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();
     /***********************************************************************************************************************
    Vertical Segments, Avenues between 38th street and 37th street
    ************************************************************************************************************************/
    //7th ave between 38th and 37th
     glLoadIdentity();
     glTranslatef(1.1, 0.51, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(1.1, 0.605, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //8th ave between 38th and 37th
     glLoadIdentity();
     glTranslatef(0.5, 0.51, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(0.5, 0.58, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //9th ave between 38th and 37th
     glLoadIdentity();
     glTranslatef(0.1, 0.51, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(0.1, 0.605, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //10th ave between 38th and 37th
     glLoadIdentity();
     glTranslatef(-0.5, 0.51, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-0.5, 0.58, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 37th to 38th
     glLoadIdentity();
     glTranslatef(-1.075, 0.51, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 38th to 37th
     glLoadIdentity();
     glTranslatef(-1.125, 0.51, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(-1.125, 0.605, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //37th &...
     //37th &7th
     glLoadIdentity();
     glTranslatef(1.1, 0.51, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.7, 0.51, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 37th &7th to 37th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.535, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //37th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.51, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.3, 0.51, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 37th &8th to 37th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.535, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //37th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.51, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.3, 0.51, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 37th &9th to 37th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.535, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //37th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.51, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.9, 0.51, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 37th &10th to 37th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.535, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //37th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.51, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
    Vertical Segments, Avenues between 37th street and 36th street
    ************************************************************************************************************************/
    //7th ave between 37th and 36th
     glLoadIdentity();
     glTranslatef(1.1, 0.395, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //8th ave between 37th and 36th
     glLoadIdentity();
     glTranslatef(0.5, 0.395, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //9th ave between 37th and 36th
     glLoadIdentity();
     glTranslatef(0.1, 0.395, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //10th ave between 37th and 36th
     glLoadIdentity();
     glTranslatef(-0.5, 0.395, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 36th to 37th
     glLoadIdentity();
     glTranslatef(-1.075, 0.395, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 37th to 36th
     glLoadIdentity();
     glTranslatef(-1.125, 0.395, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(-1.125, 0.49, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     /******************************************************************************************************************************/
     //36th &...
     //36th &7th
     glLoadIdentity();
     glTranslatef(1.1, 0.395, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.9, 0.395, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 36th &10th to 36th &11th
     glLoadIdentity();
     glTranslatef(0.5, 0.42, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //36th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.395, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.4, 0.395, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 36th &10th to 36th &11th
     glLoadIdentity();
     glTranslatef(0.1, 0.42, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //36th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.395, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.1, 0.395, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 36th &9th to 36th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.42, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //36th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.395, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.7, 0.395, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 36th &10th to 36th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.42, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //36th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.395, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
    Vertical Segments, Avenues between 36th street and 35th street
    ************************************************************************************************************************/
    //7th ave between 36th and 35th
     glLoadIdentity();
     glTranslatef(1.1, 0.28, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(1.1, 0.375, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //8th ave between 36th and 35th
     glLoadIdentity();
     glTranslatef(0.5, 0.28, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(0.5, 0.35, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //9th ave between 36th and 35th
     glLoadIdentity();
     glTranslatef(0.1, 0.28, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(0.1, 0.375, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //10th ave between 36th and 35th
     glLoadIdentity();
     glTranslatef(-0.5, 0.28, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-0.5, 0.35, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 35th to 36th
     glLoadIdentity();
     glTranslatef(-1.075, 0.28, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-1.075, 0.35, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 36th to 35th
     glLoadIdentity();
     glTranslatef(-1.125, 0.28, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //35th &...
     //35th &7th
     glLoadIdentity();
     glTranslatef(1.1, 0.28, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.7, 0.28, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 35th &7th to 35th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.305, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //35th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.28, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.3, 0.28, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 35th &8th to 35th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.305, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //35th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.28, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.3, 0.28, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 35th &7th to 35th &8th
     glLoadIdentity();
     glTranslatef(-0.5, 0.305, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //35th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.28, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.9, 0.28, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 35th &10th to 35th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.305, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //35th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.28, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
   Vertical Segments, Avenues between 35th street and 34th street
   ************************************************************************************************************************/
   //7th ave between 35th and 34th
     glLoadIdentity();
     glTranslatef(1.1, 0.165, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //8th ave between 35th and 34th
     glLoadIdentity();
     glTranslatef(0.5, 0.165, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //9th ave between 35th and 34th
     glLoadIdentity();
     glTranslatef(0.1, 0.165, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //10th ave between 35th and 34th
     glLoadIdentity();
     glTranslatef(-0.5, 0.165, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 34th to 35th
     glLoadIdentity();
     glTranslatef(-1.075, 0.165, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 35th to 34th
     glLoadIdentity();
     glTranslatef(-1.125, 0.165, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(-1.125, 0.26, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //34th &...
     //34th &7th
     glLoadIdentity();
     glTranslatef(1.1, 0.165, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.7, 0.175, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 34th &7th to 34th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.2, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.9, 0.15, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 34th &8th to 34th &7th
     glLoadIdentity();
     glTranslatef(0.5, 0.175, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //34th &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.165, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.25, 0.175, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 34th &8th to 34th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.2, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.4, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.4, 0.15, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 34th &9th to 34th &8th
     glLoadIdentity();
     glTranslatef(0.1, 0.175, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.4, 0.0, 0.0);
     glEnd();

     //34th &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.165, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.3, 0.175, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 34th &9th to 34th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.2, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.1, 0.15, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 34th &10th to 34th &9th
     glLoadIdentity();
     glTranslatef(-0.5, 0.175, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //34th &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.165, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.9, 0.175, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 34th &10th to 34th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.2, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.7, 0.15, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 34th &11th to 34th &10th
     glLoadIdentity();
     glTranslatef(-1.1, 0.175, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //34th &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.165, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
   Vertical Segments, Avenues between 34th street and 33rd street
   ************************************************************************************************************************/
   //7th ave between 34th and 33rd
     glLoadIdentity();
     glTranslatef(1.1, 0.05, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(1.1, 0.145, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //8th ave between 34th and 33rd
     glLoadIdentity();
     glTranslatef(0.5, 0.05, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(0.5, 0.12, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //9th ave between 34th and 33rd
     glLoadIdentity();
     glTranslatef(0.1, 0.05, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(0.1, 0.145, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //10th ave between 34th and 33rd
     glLoadIdentity();
     glTranslatef(-0.5, 0.05, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-0.5, 0.12, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 33rd to 34th
     glLoadIdentity();
     glTranslatef(-1.075, 0.05, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-1.075, 0.12, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 34th to 33rd
     glLoadIdentity();
     glTranslatef(-1.125, 0.05, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //33rd &...
     //33rd &7th
     glLoadIdentity();
     glTranslatef(1.1, 0.05, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();
     //No street between 33rd&7th and 33rd&8th
     //33rd &8th
     glLoadIdentity();
     glTranslatef(0.5, 0.05, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.3, 0.05, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 33rd &8th to 33rd &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.075, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //33rd &9th
     glLoadIdentity();
     glTranslatef(0.1, 0.05, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.3, 0.05, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 33rd &9th to 33rd &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.075, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //33rd &10th
     glLoadIdentity();
     glTranslatef(-0.5, 0.05, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.9, 0.05, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 33rd &10th to 33rd &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.075, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //33rd &11th
     glLoadIdentity();
     glTranslatef(-1.1, 0.05, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
   Vertical Segments, Avenues between 33rd street and 32nd street
   ************************************************************************************************************************/
   //7th ave between 33rd and 32nd
     glLoadIdentity();
     glTranslatef(1.1, -0.065, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //8th ave between 33rd and 32nd
     glLoadIdentity();
     glTranslatef(0.5, -0.065, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //9th ave between 33rd and 32nd
     glLoadIdentity();
     glTranslatef(0.1, -0.065, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //10th ave between 33rd and 32nd
     glLoadIdentity();
     glTranslatef(-0.5, -0.065, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 32nd to 33rd
     glLoadIdentity();
     glTranslatef(-1.075, -0.065, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 33rd to 32nd
     glLoadIdentity();
     glTranslatef(-1.125, -0.065, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(-1.125, 0.03, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //32nd &...
     //32nd &7th
     glLoadIdentity();
     glTranslatef(1.1, -0.065, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();
     //32nd &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.065, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();
     //32nd &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.065, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();
     //32nd &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.065, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();
     //32nd &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.065, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
   Vertical Segments, Avenues between 32nd street and 31st street
   ************************************************************************************************************************/
   //7th ave between 32nd and 31st
     glLoadIdentity();
     glTranslatef(1.1, -0.18, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(1.1, -0.085, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //8th ave between 32nd and 31st
     glLoadIdentity();
     glTranslatef(0.5, -0.18, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(0.5, -0.11, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //9th ave between 32nd and 31st
     glLoadIdentity();
     glTranslatef(0.1, -0.18, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(0.1, -0.085, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //10th ave between 32nd and 31st
     glLoadIdentity();
     glTranslatef(-0.5, -0.18, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-0.5, -0.11, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 31st to 32nd
     glLoadIdentity();
     glTranslatef(-1.075, -0.18, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-1.075, -0.11, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 32nd to 31st
     glLoadIdentity();
     glTranslatef(-1.125, -0.18, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //31st &...
     //31st &7th
     glLoadIdentity();
     glTranslatef(1.1, -0.18, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.7, -0.18, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 31st &7th to 31st &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.155, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //31st &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.18, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.3, -0.18, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 31st &8th to 31st &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.155, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //31st &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.18, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.3, -0.18, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 31st &9th to 31st &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.155, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //31st &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.18, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();
     //No street between 31st &10th  and 31st &11th
     //31st &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.18, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
   Vertical Segments, Avenues between 31st street and 30th street
   ************************************************************************************************************************/
   //7th ave between 31st and 30th
     glLoadIdentity();
     glTranslatef(1.1, -0.295, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //8th ave between 31st and 30th
     glLoadIdentity();
     glTranslatef(0.5, -0.295, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //9th ave between 31st and 30th
     glLoadIdentity();
     glTranslatef(0.1, -0.295, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //10th ave between 31st and 30th
     glLoadIdentity();
     glTranslatef(-0.5, -0.295, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 30th to 31st
     glLoadIdentity();
     glTranslatef(-1.075, -0.295, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 31st to 30th
     glLoadIdentity();
     glTranslatef(-1.125, -0.295, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(-1.125, -0.2, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //30th &...
     //30th &7th
     glLoadIdentity();
     glTranslatef(1.1, -0.295, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.9, -0.295, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 30th &7th to 30th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.27, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //30th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.295, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.4, -0.295, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 30th &8th to 30th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.27, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //30th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.295, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.1, -0.295, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 30th &9th to 30th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.27, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //30th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.295, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.7, -0.295, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 30th &10th to 30th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.27, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //30th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.295, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
  Vertical Segments, Avenues between 30th street and 29th street
  ************************************************************************************************************************/
  //7th ave between 30th and 29th
     glLoadIdentity();
     glTranslatef(1.1, -0.41, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(1.1, -0.315, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //8th ave between 30th and 29th
     glLoadIdentity();
     glTranslatef(0.5, -0.41, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(0.5, -0.34, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //9th ave between 30th and 29th
     glLoadIdentity();
     glTranslatef(0.1, -0.41, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(0.1, -0.315, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //10th ave between 30th and 29th
     glLoadIdentity();
     glTranslatef(-0.5, -0.41, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-0.5, -0.34, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 29th to 30th
     glLoadIdentity();
     glTranslatef(-1.075, -0.41, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-1.075, -0.34, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 30th to 29th
     glLoadIdentity();
     glTranslatef(-1.125, -0.41, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //29th &...
     //29th &7th
     glLoadIdentity();
     glTranslatef(1.1, -0.41, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.7, -0.41, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 29th &7th to 29th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.385, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //29th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.41, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.3, -0.41, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 29th &8th to 29th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.385, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //29th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.41, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.3, -0.41, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 29th &9th to 29th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.385, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //29th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.41, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.9, -0.41, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 29th &10th to 29th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.385, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //29th & 11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.41, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
  Vertical Segments, Avenues between 29th street and 28th street
  ************************************************************************************************************************/
  //7th ave between 29th and 28th
     glLoadIdentity();
     glTranslatef(1.1, -0.525, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //8th ave between 29th and 28th
     glLoadIdentity();
     glTranslatef(0.5, -0.525, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //9th ave between 29th and 28th
     glLoadIdentity();
     glTranslatef(0.1, -0.525, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //10th ave between 29th and 28th
     glLoadIdentity();
     glTranslatef(-0.5, -0.525, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 28th to 29th
     glLoadIdentity();
     glTranslatef(-1.075, -0.525, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 29th to 28th
     glLoadIdentity();
     glTranslatef(-1.125, -0.525, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(-1.125, -0.43, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //28th &...
     //28th &7th
     glLoadIdentity();
     glTranslatef(1.1, -0.525, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.9, -0.525, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 28th &7th to 28th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.5, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //28th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.525, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.4, -0.525, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 28th &8th to 28th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.5, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //28th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.525, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.1, -0.525, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 28th &9th to 28th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.5, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //28th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.525, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.7, -0.525, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 28th &10th to 28th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.5, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //28th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.525, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
  Vertical Segments, Avenues between 28th street and 27th street
  ************************************************************************************************************************/
  //7th ave between 28th and 27th
     glLoadIdentity();
     glTranslatef(1.1, -0.64, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(1.1, -0.545, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //8th ave between 28th and 27th
     glLoadIdentity();
     glTranslatef(0.5, -0.64, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(0.5, -0.57, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //9th ave between 28th and 27th
     glLoadIdentity();
     glTranslatef(0.1, -0.64, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(0.1, -0.545, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //10th ave between 28th and 27th
     glLoadIdentity();
     glTranslatef(-0.5, -0.64, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-0.5, -0.57, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 27th to 28th
     glLoadIdentity();
     glTranslatef(-1.075, -0.64, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-1.075, -0.57, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 28th to 27th
     glLoadIdentity();
     glTranslatef(-1.125, -0.64, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //27th &...
     //27th &7th
     glLoadIdentity();
     glTranslatef(1.1, -0.64, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.7, -0.64, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 27th &7th to 27th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.615, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //27th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.64, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();
     //27th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.64, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();
     //27th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.64, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.9, -0.64, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 27th &10th to 27th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.615, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //27th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.64, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
  Vertical Segments, Avenues between 27th street and 26th street
  ************************************************************************************************************************/
  //7th ave between 27th and 26th
     glLoadIdentity();
     glTranslatef(1.1, -0.755, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //8th ave between 27th and 26th
     glLoadIdentity();
     glTranslatef(0.5, -0.755, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //9th ave between 27th and 26th
     glLoadIdentity();
     glTranslatef(0.1, -0.755, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //10th ave between 27th and 26th
     glLoadIdentity();
     glTranslatef(-0.5, -0.755, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 26th to 27th
     glLoadIdentity();
     glTranslatef(-1.075, -0.755, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 27th to 26th
     glLoadIdentity();
     glTranslatef(-1.125, -0.755, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(-1.125, -0.66, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //26th &...
     //26th &7th
     glLoadIdentity();
     glTranslatef(1.1, -0.755, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.9, -0.755, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 26th &7th to 26th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.73, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //26th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.755, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.4, -0.755, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 26th &8th to 26th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.73, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //26th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.755, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.1, -0.755, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 26th &9th to 26th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.73, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //26th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.755, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.7, -0.755, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 26th &10th to 26th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.73, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //26th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.755, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
  Vertical Segments, Avenues between 26th street and 25th street
  ************************************************************************************************************************/
  //7th ave between 26th and 25th
     glLoadIdentity();
     glTranslatef(1.1, -0.87, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(1.1, -0.775, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //8th ave between 26th and 25th
     glLoadIdentity();
     glTranslatef(0.5, -0.87, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(0.5, -0.8, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //9th ave between 26th and 25th
     glLoadIdentity();
     glTranslatef(0.1, -0.87, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(0.1, -0.775, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //10th ave between 26th and 25th
     glLoadIdentity();
     glTranslatef(-0.5, -0.87, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-0.5, -0.8, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 25th to 26th
     glLoadIdentity();
     glTranslatef(-1.075, -0.87, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-1.075, -0.8, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 26th to 25th
     glLoadIdentity();
     glTranslatef(-1.125, -0.87, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //25th &...
     //25th &7th
     glLoadIdentity();
     glTranslatef(1.1, -0.87, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.7, -0.87, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 25th &7th to 25th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.845, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //25th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.87, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.3, -0.87, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 25th &8th to 25th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.845, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //25th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.87, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.3, -0.87, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 25th &9th to 25th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.845, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //25th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.87, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.9, -0.87, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 25th &10th to 25th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.845, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //25th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.87, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
  Vertical Segments, Avenues between 25th street and 24th street
  ************************************************************************************************************************/
  //7th ave between 25th and 24th
     glLoadIdentity();
     glTranslatef(1.1, -0.985, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //8th ave between 25th and 24th
     glLoadIdentity();
     glTranslatef(0.5, -0.985, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //9th ave between 25th and 24th
     glLoadIdentity();
     glTranslatef(0.1, -0.985, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //10th ave between 25th and 24th
     glLoadIdentity();
     glTranslatef(-0.5, -0.985, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 24th to 25th
     glLoadIdentity();
     glTranslatef(-1.075, -0.985, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //11th ave from 25th to 24th
     glLoadIdentity();
     glTranslatef(-1.125, -0.985, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(-1.125, -0.89, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //24th &...
     //24th &7th
     glLoadIdentity();
     glTranslatef(1.1, -0.985, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.9, -0.985, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 24th &7th to 24th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.96, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //24th &8th
     glLoadIdentity();
     glTranslatef(0.5, -0.985, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.4, -0.985, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 24th &8th to 24th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.96, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.45, 0.0, 0.0);
     glEnd();

     //24th &9th
     glLoadIdentity();
     glTranslatef(0.1, -0.985, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.1, -0.985, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 24th &9th to 24th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.96, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //24th &10th
     glLoadIdentity();
     glTranslatef(-0.5, -0.985, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.7, -0.985, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 24th &10th to 24th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.96, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //24th &11th
     glLoadIdentity();
     glTranslatef(-1.1, -0.985, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     /***********************************************************************************************************************
  Vertical Segments, Avenues between 24th street and 23rd street
  ************************************************************************************************************************/
  //7th ave between 24th and 23rd
     glLoadIdentity();
     glTranslatef(1.1, -1.1, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(1.1, -1.005, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //8th ave between 24th and 23rd
     glLoadIdentity();
     glTranslatef(0.5, -1.1, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(0.5, -1.03, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //9th ave between 24th and 23rd
     glLoadIdentity();
     glTranslatef(0.1, -1.1, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle South
     glLoadIdentity();
     glTranslatef(0.1, -1.005, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, -0.05, 0.0);
     glEnd();
     //10th ave between 24th and 23rd
     glLoadIdentity();
     glTranslatef(-0.5, -1.1, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-0.5, -1.03, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 23rd to 24th
     glLoadIdentity();
     glTranslatef(-1.075, -1.1, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     //directional triangle North
     glLoadIdentity();
     glTranslatef(-1.075, -1.03, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.025, 0.05, 0.0);
     glEnd();
     //11th ave from 24th to 23rd
     glLoadIdentity();
     glTranslatef(-1.125, -1.1, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.025, 0.0, 0.0);
     glVertex3f(0.025, 0.115, 0.0);
     glEnd();
     /******************************************************************************************************************************/

     //23rd &...
     //23rd &7th
     glLoadIdentity();
     glTranslatef(1.1, -1.1, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.7, -1.09, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 23rd &7th to 23rd &8th
     glLoadIdentity();
     glTranslatef(0.5, -1.065, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.9, -1.115, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 23rd &8th to 23rd &7th
     glLoadIdentity();
     glTranslatef(0.5, -1.09, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //23rd &8th
     glLoadIdentity();
     glTranslatef(0.5, -1.1, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(0.25, -1.09, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 23rd &8th to 23rd &9th
     glLoadIdentity();
     glTranslatef(0.1, -1.065, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.4, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(0.4, -1.115, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 23rd &9th to 23rd &8th
     glLoadIdentity();
     glTranslatef(0.1, -1.09, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.4, 0.0, 0.0);
     glEnd();

     //23rd &9th
     glLoadIdentity();
     glTranslatef(0.1, -1.1, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.3, -1.09, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 23rd &9th to 23rd &10th
     glLoadIdentity();
     glTranslatef(-0.5, -1.065, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.1, -1.115, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 23rd &10th to 23rd &9th
     glLoadIdentity();
     glTranslatef(-0.5, -1.09, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //23rd &10th
     glLoadIdentity();
     glTranslatef(-0.5, -1.1, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     //directional triangle West
     glLoadIdentity();
     glTranslatef(-0.9, -1.09, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(-0.05, 0.025, 0.0);
     glEnd();
     //from 23rd &10th to 23rd &11th
     glLoadIdentity();
     glTranslatef(-1.1, -1.065, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();
     //directional triangle East
     glLoadIdentity();
     glTranslatef(-0.7, -1.115, -3.0);
     glBegin(GL_TRIANGLES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.05, 0.025, 0.0);
     glEnd();
     //from 23rd &11th to 23rd &10th
     glLoadIdentity();
     glTranslatef(-1.1, -1.09, -3.0);
     glBegin(GL_LINES);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.65, 0.0, 0.0);
     glEnd();

     //23rd &11th
     glLoadIdentity();
     glTranslatef(-1.1, -1.1, -3.0);
     glBegin(GL_QUADS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(0.0, 0.05, 0.0);
     glVertex3f(0.0, 0.0, 0.0);
     glVertex3f(0.05, 0.0, 0.0);
     glVertex3f(0.05, 0.05, 0.0);
     glEnd();

     glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
     switch (key)
     {
     case 27: glutLeaveMainLoop();
          break;
     default:
          break;
     }
}
//look up glrepaint for updating colors
