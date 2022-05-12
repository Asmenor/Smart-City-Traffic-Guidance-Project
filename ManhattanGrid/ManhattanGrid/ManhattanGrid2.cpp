#include<GL\freeglut.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<double> congestionVals;
float color1 = 0.0f;
float color2 = 1.0f;
float color3 = 0.0f;

void read() {
     string fname = "manhattan_test.csv";
     vector<vector<string>> content;
     vector<string> row;
     string line, word;
     fstream file(fname, ios::in);
     if (file.is_open())
     {
          while (getline(file, line))
          {
               row.clear();

               stringstream str(line);

               while (getline(str, word, ','))
                    row.push_back(word);
               content.push_back(row);
          }
     }
     else
          cout << "Could not open the file\n";
     for (int i = 1; i < content.size(); i++)
     {
          double currVal = stod(content[i][7]);
          congestionVals.push_back(currVal);
     }
}

void determineColor(double congestion) {
     //red 1
     if (congestion > 0.999) {
          color1 = 1.0f; color2 = 0.0f; color3 = 0.0f;
     }//purple 0.8-0.99
     else if (congestion > 0.7999) {
          color1 = 1.0f; color2 = 0.0f; color3 = 1.0f;
     }//yellow 0.4-0.8
     else if (congestion > 0.3999) {
          color1 = 1.0f; color2 = 1.0f; color3 = 0.0f;
     }//green 0-0.4
     else {
          color1 = 0.0f; color2 = 1.0f; color3 = 0.0f;
     }
}

void intersection(float d, float e, float f) {
     glLoadIdentity();
     glTranslatef(d, e, f);
     glBegin(GL_QUADS);
     glColor3f(0.0f, 1.0f, 0.0f);
     glVertex3f(0.0f, 0.05f, 0.0f);
     glVertex3f(0.0f, 0.0f, 0.0f);
     glVertex3f(0.05f, 0.0f, 0.0f);
     glVertex3f(0.05f, 0.05f, 0.0f);
     glEnd();
}

void street(float g, float h, float i, int x) {
     glLoadIdentity();
     glTranslatef(g, h, i);
     glBegin(GL_LINES);
     determineColor(congestionVals[x]);
     glColor3f(color1, color2, color3);
     glVertex3f(0.05f, 0.0f, 0.0f);
     glVertex3f(0.6f, 0.0f, 0.0f);
     glEnd();
}

void shortStreet(float g, float h, float i, int x) {
     glLoadIdentity();
     glTranslatef(g, h, i);
     glBegin(GL_LINES);
     determineColor(congestionVals[x]);
     glColor3f(color1, color2, color3);
     glVertex3f(0.05f, 0.0f, 0.0f);
     glVertex3f(0.4f, 0.0f, 0.0f);
     glEnd();
}

void avenue(float g, float h, float i, int x) {
     glLoadIdentity();
     glTranslatef(g, h, i);
     glBegin(GL_LINES);
     determineColor(congestionVals[x]);
     glColor3f(color1, color2, color3);
     glVertex3f(0.025f, 0.0f, 0.0f);
     glVertex3f(0.025f, 0.115f, 0.0f);
     glEnd();
}

void directionalEast(float a, float b, float c, int x) {
     glLoadIdentity();
     glTranslatef(a, b, c);
     glBegin(GL_TRIANGLES);
     determineColor(congestionVals[x]);
     glColor3f(color1, color2, color3);
     glVertex3f(0.0f, 0.0f, 0.0f);
     glVertex3f(0.0f, 0.05f, 0.0f);
     glVertex3f(0.05f, 0.025f, 0.0f);
     glEnd();
}

void directionalWest(float a, float b, float c, int x) {
     glLoadIdentity();
     glTranslatef(a, b, c);
     glBegin(GL_TRIANGLES);
     determineColor(congestionVals[x]);
     glColor3f(color1, color2, color3);
     glVertex3f(0.0f, 0.0f, 0.0f);
     glVertex3f(0.0f, 0.05f, 0.0f);
     glVertex3f(-0.05f, 0.025f, 0.0f);
     glEnd();
}

void directionalNorth(float a, float b, float c, int x){
     glLoadIdentity();
     glTranslatef(a, b, c);
     glBegin(GL_TRIANGLES);
     determineColor(congestionVals[x]);
     glColor3f(color1, color2, color3);
     glVertex3f(0.0f, 0.0f, 0.0f);
     glVertex3f(0.05f, 0.0f, 0.0f);
     glVertex3f(0.025f, 0.05f, 0.0f);
     glEnd();
}

void directionalSouth(float a, float b, float c, int x) {
     glLoadIdentity();
     glTranslatef(a, b, c);
     glBegin(GL_TRIANGLES);
     determineColor(congestionVals[x]);
     glColor3f(color1, color2, color3);
     glVertex3f(0.0f, 0.0f, 0.0f);
     glVertex3f(0.05f, 0.0f, 0.0f);
     glVertex3f(0.025f, -0.05f, 0.0f);
     glEnd();
}

int main(int argc, char** argv)
{
     //function declarations
     void resize(int, int);
     void display();
     void keyboard(unsigned char, int, int);
     void initialize();
     void read();
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowPosition(800, 600);
     glutInitWindowPosition(0, 0);
     glutCreateWindow("NatStorey_ManahattanGrid");

     initialize();

     glutDisplayFunc(display);
     glutKeyboardFunc(keyboard);
     glutReshapeFunc(resize);
     read();

     glutMainLoop();
     //glutMainLoopEvent();
     //display();
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
     intersection(1.1f, 1.085f, -3.0f);
          //from 42nd &7th to 42nd &8th
          street(0.5f, 1.1f, -3.0f, 186);
          //directional triangle East
          directionalEast(0.9f, 1.075f, -3.0f, 186);
          //from 42nd &8th to 42nd &7th
          street(0.5f, 1.12f, -3.0f, 156);
     //42nd &8th
     intersection(0.5f, 1.085f, -3.0f);
          //from 42nd &8th to 42nd &9th
          shortStreet(0.1f, 1.1f, -3.0f, 155);
          //from 42nd &9th to 42nd &8th
          shortStreet(0.1f, 1.12f, -3.0f, 116);
     //42nd &9th
     intersection(0.1f, 1.085f, -3.0f);
          //from 42nd &9th to 42nd &10th
          street(-0.5f, 1.1f, -3.0f, 115);
          //from 42nd &10th to 42nd &9th
          street(-0.5f, 1.12f, -3.0f, 76);
     //42nd &10th
     intersection(-0.5f, 1.085f, -3.0f);
          //directional triangle West
          directionalWest(-0.9f, 1.095f, -3.0f, 75);
          //from 42nd &10th to 42nd &11th
          street(-1.1f, 1.1f, -3.0f, 75);
          //from 42nd &11th to 42nd &10th
          street(-1.1f, 1.12f, -3.0f, 36);
     //42nd &11th
     intersection(-1.1f, 1.085f, -3.0f);
     /***********************************************************************************************************************
     Vertical Segments, Avenues between 42nd street and 41st street
     ************************************************************************************************************************/
     //7th ave between 42nd and 41st
     avenue(1.1f, 0.97f, -3.0f, 185);
     //8th ave between 42nd and 41st
     avenue(0.5f, 0.97f, -3.0f, 153);
          //directional triangle North
          directionalNorth(0.5f, 1.04f, -3.0f, 153);
     //9th ave between 42nd and 41st
     avenue(0.1f, 0.97f, -3.0f, 114);
     //10th ave between 42nd and 41st
     avenue(-0.5f, 0.97f, -3.0f, 73);
          //directional triangle North
          directionalNorth(-0.5f, 1.04f, -3.0f, 73);
     //11th ave from 41st to 42nd
     avenue(-1.075f, 0.97f, -3.0f, 34);
          //directional triangle North
          directionalNorth(-1.075f, 1.04f, -3.0f, 34);
     //11th ave from 42nd to 41st
     avenue(-1.125f, 0.97f, -3.0f, 35);
     /******************************************************************************************************************************/
     //41st &...
     //41st &7th
     intersection(1.1f, 0.97f, -3.0f);
          //from 41nd &7th to 41nd &8th
          street(0.5f, 0.995f, -3.0f, 184);
     //41st &8th
     intersection(0.5f, 0.97f, -3.0f);
          //from 41st &8th to 41st &9th
          shortStreet(0.1f, 0.995f, -3.0f, 154);
     //41st &9th
     intersection(0.1f, 0.97f, -3.0f);
          //from 41st &9th to 41st &10th
          street(-0.5f, 0.995f, -3.0f, 113);
     //41st &10th
     intersection(-0.5f, 0.97f, -3.0f);
          //directional triangle West
          directionalWest(-0.9f, 0.97f, -3.0f, 74);
          //from 41st &10th to 41st &11th
          street(-1.1f, 0.995f, -3.0f, 74);
     //41st &11th
     intersection(-1.1f, 0.97f, -3.0f);
     /***********************************************************************************************************************
     Vertical Segments, Avenues between 41st street and 40th street
     ************************************************************************************************************************/
     //7th ave between 41st and 40th
     avenue(1.1f, 0.855f, -3.0f, 183);
     //8th ave between 41st and 40th
     avenue(0.5f, 0.855f, -3.0f, 151);
     //9th ave between 41st and 40th
     avenue(0.1f, 0.855f, -3.0f, 112);
     //10th ave between 41st and 40th
     avenue(-0.5f, 0.855f, -3.0f, 71);
     //11th ave from 40th to 41st
     avenue(-1.075f, 0.855f, -3.0f, 31);
     //11th ave from 41st to 40th
     avenue(-1.125f, 0.855f, -3.0f, 33);
     /******************************************************************************************************************************/
     //40th &...
     //40th &7th
     intersection(1.1f, 0.855f, -3.0f);
          //directional triangle East
          directionalEast(0.9f, 0.855f, -3.0f, 152);
          //from 40th &8th to 40th &7th
          street(0.5f, 0.88f, -3.0f, 152);
     //40th &8th
     intersection(0.5f, 0.855f, -3.0f);
          //from 40th &9th to 40th &8th
          shortStreet(0.1f, 0.88f, -3.0f, 111);
     //40th &9th
     intersection(0.1f, 0.855f, -3.0f);
          //from 40th &10th to 40th &9th
          street(-0.5f, 0.88f, -3.0f, 72);
     //40th &10th
     intersection(-0.5f, 0.855f, -3.0f);
          //from 40th &11th to 40th &10th
          street(-1.1f, 0.88f, -3.0f, 32);
     //40th &11th
     intersection(-1.1f, 0.855f, -3.0f);
     /***********************************************************************************************************************
     Vertical Segments, Avenues between 40th street and 39th street
     ************************************************************************************************************************/
     //7th ave between 40th and 39th
     avenue(1.1f, 0.74f, -3.0f, 182);
     //8th ave between 40th and 39th
     avenue(0.5f, 0.74f, -3.0f, 149);
     //9th ave between 40th and 39th
     avenue(0.1f, 0.74f, -3.0f, 110);
     //10th ave between 40th and 39th
     avenue(-0.5f, 0.74f, -3.0f, 69);
     //11th ave from 39th to 40th
     avenue(-1.075f, 0.74f, -3.0f, 29);
     //11th ave from 40th to 39th
     avenue(-1.125f, 0.74f, -3.0f, 30);
     /******************************************************************************************************************************/
     //39th &...
     //39th &7th
     intersection(1.1f, 0.74f, -3.0f);
          //from 39th &7th to 39th &8th
          street(0.5f, 0.765f, -3.0f, 181);
     //39th &8th
     intersection(0.5f, 0.74f, -3.0f);
          //from 39th &8th to 39th &9th
          shortStreet(0.1f, 0.765f, -3.0f, 150);
     //39th &9th
     intersection(0.1f, 0.74f, -3.0f);
          //from 39th &9th to 39th &10th
          street(-0.5f, 0.765f, -3.0f, 109);
     //39th &10th
     intersection(-0.5f, 0.74f, -3.0f);
          //directional triangle West
          directionalWest(-0.9f, 0.74f, -3.0f, 70);
          //from 39th &10th to 39th &11th
          street(-1.1f, 0.765f, -3.0f, 70);
     //39th &11th
     intersection(-1.1f, 0.74f, -3.0f);
     /***********************************************************************************************************************
    Vertical Segments, Avenues between 39th street and 38th street
    ************************************************************************************************************************/
    //7th ave between 39th and 38th
     avenue(1.1f, 0.625f, -3.0f, 180);
     //8th ave between 39th and 38th
     avenue(0.5f, 0.625f, -3.0f, 147);
     //9th ave between 39th and 38th
     avenue(0.1f, 0.625f, -3.0f, 108);
     //10th ave between 39th and 38th
     avenue(-0.5f, 0.625f, -3.0f, 67);
     //11th ave from 38th to 39th
     avenue(-1.075f, 0.625f, -3.0f, 26);
     //11th ave from 39th to 38th
     avenue(-1.125f, 0.625f, -3.0f, 28);
     /******************************************************************************************************************************/
     //38th &...
     //38th &7th
     intersection(1.1f, 0.625f, -3.0f);
          //directional triangle East
          directionalEast(0.9f, 0.625f, -3.0f, 148);
          //from 38th &8th to 38th &7th
          street(0.5f, 0.65f, -3.0f, 148);
     //38th &8th
     intersection(0.5f, 0.625f, -3.0f);
          //from 38th &9th to 38th &8th
          shortStreet(0.1f, 0.65f, -3.0f, 107);
     //38th &9th
     intersection(0.1f, 0.625f, -3.0f);
          //from 38th &10th to 38th &9th
          street(-0.5f, 0.65f, -3.0f, 68);
     //38th &10th
     intersection(-0.5f, 0.625f, -3.0f);
          //from 38th &11th to 38th &10th
          street(-1.1f, 0.65f, -3.0f, 27);
     //38th &11th
     intersection(-1.1f, 0.625f, -3.0f);
     /***********************************************************************************************************************
    Vertical Segments, Avenues between 38th street and 37th street
    ************************************************************************************************************************/
    //7th ave between 38th and 37th
     avenue(1.1f, 0.51f, -3.0f, 179);
     //8th ave between 38th and 37th
     avenue(0.5f, 0.51f, -3.0f, 145);
     //9th ave between 38th and 37th
     avenue(0.1f, 0.51f, -3.0f, 106);
     //10th ave between 38th and 37th
     avenue(-0.5f, 0.51f, -3.0f, 65);
     //11th ave from 37th to 38th
     avenue(-1.075f, 0.51f, -3.0f, 24);
     //11th ave from 38th to 37th
     avenue(-1.125f, 0.51f, -3.0f, 25);
     /******************************************************************************************************************************/
     //37th &...
     //37th &7th
     intersection(1.1f, 0.51f, -3.0f);
          //from 37th &7th to 37th &8th
          street(0.5f, 0.535f, -3.0f, 178);
     //37th &8th
     intersection(0.5f, 0.51f, -3.0f);
          //from 37th &8th to 37th &9th
          shortStreet(0.1f, 0.535f, -3.0f, 146);
     //37th &9th
     intersection(0.1f, 0.51f, -3.0f);
          //from 37th &9th to 37th &10th
          street(-0.5f, 0.535f, -3.0f, 105);
     //37th &10th
     intersection(-0.5f, 0.51f, -3.0f);
          //directional triangle West
          directionalWest(-0.9f, 0.51f, -3.0f, 66);
          //from 37th &10th to 37th &11th
          street(-1.1f, 0.535f, -3.0f, 66);
     //37th &11th
     intersection(-1.1f, 0.51f, -3.0f);
     /***********************************************************************************************************************
    Vertical Segments, Avenues between 37th street and 36th street
    ************************************************************************************************************************/
    //7th ave between 37th and 36th
     avenue(1.1f, 0.395f, -3.0f, 177);
     //8th ave between 37th and 36th
     avenue(0.5f, 0.395f, -3.0f, 143);
     //9th ave between 37th and 36th
     avenue(0.1f, 0.395f, -3.0f, 104);
     //10th ave between 37th and 36th
     avenue(-0.5f, 0.395f, -3.0f, 63);
     //11th ave from 36th to 37th
     avenue(-1.075f, 0.395f, -3.0f, 21);
     //11th ave from 37th to 36th
     avenue(-1.125f, 0.395f, -3.0f, 23);
     /******************************************************************************************************************************/
     //36th &...
     //36th &7th
     intersection(1.1f, 0.395f, -3.0f);
          //directional triangle East
          directionalEast(0.9f, 0.395f, -3.0f, 144);
          //from 36th &8th to 36th &7th
          street(0.5f, 0.42f, -3.0f, 144);
     //36th &8th
     intersection(0.5f, 0.395f, -3.0f);
          //from 36th &9th to 36th &8th
          shortStreet(0.1f, 0.42f, -3.0f, 103);
     //36th &9th
     intersection(0.1f, 0.395f, -3.0f);
          //from 36th &10th to 36th &9th
          street(-0.5f, 0.42f, -3.0f, 64);
     //36th &10th
     intersection(-0.5f, 0.395f, -3.0f);
          //from 36th &11th to 36th &10th
          street(-1.1f, 0.42f, -3.0f, 22);
     //36th &11th
     intersection(-1.1f, 0.395f, -3.0f);
     /***********************************************************************************************************************
    Vertical Segments, Avenues between 36th street and 35th street
    ************************************************************************************************************************/
    //7th ave between 36th and 35th
     avenue(1.1f, 0.28f, -3.0f, 176);
     //8th ave between 36th and 35th
     avenue(0.5f, 0.28f, -3.0f, 141);
     //9th ave between 36th and 35th
     avenue(0.1f, 0.28f, -3.0f, 102);
     //10th ave between 36th and 35th
     avenue(-0.5f, 0.28f, -3.0f, 61);
     //11th ave from 35th to 36th
     avenue(-1.075f, 0.28f, -3.0f, 19);
     //11th ave from 36th to 35th
     avenue(-1.125f, 0.28f, -3.0f, 20);
     /******************************************************************************************************************************/
     //35th &...
     //35th &7th
     intersection(1.1f, 0.28f, -3.0f);
          //from 35th &7th to 35th &8th
          street(0.5f, 0.305f, -3.0f, 175);
     //35th &8th
     intersection(0.5f, 0.28f, -3.0f);
          //from 35th &8th to 35th &9th
          shortStreet(0.1f, 0.305f, -3.0f, 142);
     //35th &9th
     intersection(0.1f, 0.28f, -3.0f);
          //from 35th &7th to 35th &8th
          street(-0.5f, 0.305f, -3.0f, 101);
     //35th &10th
     intersection(-0.5f, 0.28f, -3.0f);
          //directional triangle West
          directionalWest(-0.9f, 0.28f, -3.0f, 62);
          //from 35th &10th to 35th &11th
          street(-1.1f, 0.305f, -3.0f, 62);
     //35th &11th
     intersection(-1.1f, 0.28f, -3.0f);
     /***********************************************************************************************************************
   Vertical Segments, Avenues between 35th street and 34th street
   ************************************************************************************************************************/
   //7th ave between 35th and 34th
     avenue(1.1f, 0.165f, -3.0f, 174);
     //8th ave between 35th and 34th
     avenue(0.5f, 0.165f, -3.0f, 138);
     //9th ave between 35th and 34th
     avenue(0.1f, 0.165f, -3.0f, 100);
     //10th ave between 35th and 34th
     avenue(-0.5f, 0.165f, -3.0f, 58);
     //11th ave from 34th to 35th
     avenue(-1.075f, 0.165f, -3.0f, 16);
     //11th ave from 35th to 34th
     avenue(-1.125f, 0.165f, -3.0f, 18);
     /******************************************************************************************************************************/
     //34th &...
     //34th &7th
     intersection(1.1f, 0.165f, -3.0f);
          //from 34th &7th to 34th &8th
          street(0.5f, 0.2f, -3.0f, 173);
          //directional triangle East
          directionalEast(0.9f, 0.15f, -3.0f, 140);
          //from 34th &8th to 34th &7th
          street(0.5f, 0.175f, -3.0f, 140);
     //34th &8th
     intersection(0.5f, 0.165f, -3.0f);
          //from 34th &8th to 34th &9th
          shortStreet(0.1f, 0.2f, -3.0f, 139);
          //from 34th &9th to 34th &8th
          shortStreet(0.1f, 0.175f, -3.0f, 99);
     //34th &9th
     intersection(0.1f, 0.165f, -3.0f);
          //from 34th &9th to 34th &10th
          street(-0.5f, 0.2f, -3.0f, 98);
          //from 34th &10th to 34th &9th
          street(-0.5f, 0.175f, -3.0f, 60);
     //34th &10th
     intersection(-0.5f, 0.165f, -3.0f);
          //directional triangle West
          directionalWest(-0.9f, 0.175f, -3.0f, 59);
          //from 34th &10th to 34th &11th
          street(-1.1f, 0.2f, -3.0f, 59);
          //from 34th &11th to 34th &10th
          street(-1.1f, 0.175f, -3.0f, 17);
     //34th &11th
     intersection(-1.1f, 0.165f, -3.0f);
     /***********************************************************************************************************************
   Vertical Segments, Avenues between 34th street and 33rd street
   ************************************************************************************************************************/
   //7th ave between 34th and 33rd
     avenue(1.1f, 0.05f, -3.0f, 172);
     //8th ave between 34th and 33rd
     avenue(0.5f, 0.05f, -3.0f, 136);
     //9th ave between 34th and 33rd
     avenue(0.1f, 0.05f, -3.0f, 97);
     //10th ave between 34th and 33rd
     avenue(-0.5f, 0.05f, -3.0f, 56);
     //11th ave from 33rd to 34th
     //avenue(-1.075f, 0.05f, -3.0f, x); segment omitted from csv data
     //11th ave from 34th to 33rd
     avenue(-1.125f, 0.05f, -3.0f, 15);
     /******************************************************************************************************************************/
     //33rd &...
     //33rd &7th
     intersection(1.1f, 0.05f, -3.0f);
     //No street between 33rd&7th and 33rd&8th
     //33rd &8th
     intersection(0.5f, 0.05f, -3.0f);
          //from 33rd &8th to 33rd &9th
          shortStreet(0.1f, 0.075f, -3.0f, 137);
     //33rd &9th
     intersection(0.1f, 0.05f, -3.0f);
          //from 33rd &9th to 33rd &10th
          street(-0.5f, 0.075f, -3.0f, 96);
     //33rd &10th
     intersection(-0.5f, 0.05f, -3.0f);
          //directional triangle West
          directionalWest(-0.9f, 0.05f, -3.0f, 57);
          //from 33rd &10th to 33rd &11th
          street(-1.1f, 0.075f, -3.0f, 57);
     //33rd &11th
     intersection(-1.1f, 0.05f, -3.0f);
     /***********************************************************************************************************************
   Vertical Segments, Avenues between 33rd street and 32nd street
   ************************************************************************************************************************/
   //7th ave between 33rd and 32nd
     avenue(1.1f, -0.065f, -3.0f, 171);
     //8th ave between 33rd and 32nd
     avenue(0.5f, -0.065f, -3.0f, 135);
     //9th ave between 33rd and 32nd
     avenue(0.1f, -0.065f, -3.0f, 95);
     //10th ave between 33rd and 32nd
     avenue(-0.5f, -0.065f, -3.0f, 55);
     //11th ave from 32nd to 33rd
     //avenue(-1.075, -0.065, -3.0, x); omitted segment
     //11th ave from 33rd to 32nd
     avenue(-1.125f, -0.065f, -3.0f, 14);
     /******************************************************************************************************************************/
     //32nd &...
     //32nd &7th
     intersection(1.1f, -0.065f, -3.0f);
     //32nd &8th
     intersection(0.5f, -0.065f, -3.0f);
     //32nd &9th
     intersection(0.1f, -0.065f, -3.0f);
     //32nd &10th
     intersection(-0.5f, -0.065f, -3.0f);
     //32nd &11th
     intersection(-1.1f, -0.065f, -3.0f);
     /***********************************************************************************************************************
   Vertical Segments, Avenues between 32nd street and 31st street
   ************************************************************************************************************************/
     //7th ave between 32nd and 31st
     avenue(1.1f, -0.18f, -3.0f, 170);
     //8th ave between 32nd and 31st
     avenue(0.5f, -0.18f, -3.0f, 133);
     //9th ave between 32nd and 31st
     avenue(0.1f, -0.18f, -3.0f, 94);
     //10th ave between 32nd and 31st
     avenue(-0.5f, -0.18f, -3.0f, 54);
     //11th ave from 31st to 32nd
     //avenue(-1.075f, -0.18f, -3.0f, x); omitted
     //11th ave from 32nd to 31st
     avenue(-1.125f, -0.18f, -3.0f, 13);
     /******************************************************************************************************************************/
     //31st &...
     //31st &7th
     intersection(1.1f, -0.18f, -3.0f);
          //from 31st &7th to 31st &8th
          street(0.5f, -0.155f, -3.0f, 169);
     //31st &8th
     intersection(0.5f, -0.18f, -3.0f);
          //from 31st &8th to 31st &9th
          shortStreet(0.1f, -0.155f, -3.0f, 134);
     //31st &9th
     intersection(0.1f, -0.18f, -3.0f);
          //directional triangle West
          directionalWest(-0.3f, -0.18f, -3.0f, 93);
          //from 31st &9th to 31st &10th
          street(-0.5f, -0.155f, -3.0f, 93);
     //31st &10th
     intersection(-0.5f, -0.18f, -3.0f);
          //No street between 31st &10th  and 31st &11th
     //31st &11th
     intersection(-1.1f, -0.18f, -3.0f);
     /***********************************************************************************************************************
   Vertical Segments, Avenues between 31st street and 30th street
   ************************************************************************************************************************/
     //7th ave between 31st and 30th
     avenue(1.1f, -0.295f, -3.0f, 168);
     //8th ave between 31st and 30th
     avenue(0.5f, -0.295f, -3.0f, 131);
     //9th ave between 31st and 30th
     avenue(0.1f, -0.295f, -3.0f, 92);
     //10th ave between 31st and 30th
     avenue(-0.5f, -0.295f, -3.0f, 52);
     //11th ave from 30th to 31st
          //avenue(-1.075f, -0.295f, -3.0f, x); omitted
     //11th ave from 31st to 30th
     avenue(-1.125f, -0.295f, -3.0f, 12);
     /******************************************************************************************************************************/
     //30th &...
     //30th &7th
     intersection(1.1f, -0.295f, -3.0f);
          //directional triangle East
          directionalEast(0.9f, -0.295f, -3.0f, 132);
          //from 30th &8th to 30th &7th
          street(0.5f, -0.27f, -3.0f, 132);
     //30th &8th
     intersection(0.5f, -0.295f, -3.0f);
          //from 30th &9th to 30th &8th
          shortStreet(0.1f, -0.27f, -3.0f, 91);
     //30th &9th
     intersection(0.1f, -0.295f, -3.0f);
          //from 30th &10th to 30th &9th
          street(-0.5f, -0.27f, -3.0f, 53);
     //30th &10th
     intersection(-0.5f, -0.295f, -3.0f);
          //from 30th &11th to 30th &10th
          street(-1.1f, -0.27f, -3.0f, 11);
     //30th &11th
     intersection(-1.1f, -0.295f, -3.0f);
     /***********************************************************************************************************************
  Vertical Segments, Avenues between 30th street and 29th street
  ************************************************************************************************************************/
     //7th ave between 30th and 29th
     avenue(1.1f, -0.41f, -3.0f, 167);
     //8th ave between 30th and 29th
     avenue(0.5f, -0.41f, -3.0f, 129);
     //9th ave between 30th and 29th
     avenue(0.1f, -0.41f, -3.0f, 90);
     //10th ave between 30th and 29th
     avenue(-0.5f, -0.41f, -3.0f, 50);
     //11th ave from 29th to 30th
     //avenue(-1.075f, -0.41f, -3.0f, x); omitted segment
     //11th ave from 30th to 29th
     avenue(-1.125f, -0.41f, -3.0f, 10);
     /******************************************************************************************************************************/
     //29th &...
     //29th &7th
     intersection(1.1f, -0.41f, -3.0f);
          //from 29th &7th to 29th &8th
          street(0.5f, -0.385f, -3.0f, 166);
     //29th &8th
     intersection(0.5f, -0.41f, -3.0f);
          //from 29th &8th to 29th &9th
          shortStreet(0.1f, -0.385f, -3.0f, 130);
     //29th &9th
     intersection(0.1f, -0.41f, -3.0f);
          //from 29th &9th to 29th &10th
          street(-0.5f, -0.385f, -3.0f, 89);
     //29th &10th
     intersection(-0.5f, -0.41f, -3.0f);
          //directional triangle West
          directionalWest(-0.9f, -0.41f, -3.0f, 51);
          //from 29th &10th to 29th &11th
          street(-1.1f, -0.385f, -3.0f, 51);
     //29th & 11th
     intersection(-1.1f, -0.41f, -3.0f);
     /***********************************************************************************************************************
  Vertical Segments, Avenues between 29th street and 28th street
  ************************************************************************************************************************/
  //7th ave between 29th and 28th
     avenue(1.1f, -0.525f, -3.0f, 165);
     //8th ave between 29th and 28th
     avenue(0.5f, -0.525f, -3.0f, 127);
     //9th ave between 29th and 28th
     avenue(0.1f, -0.525f, -3.0f, 88);
     //10th ave between 29th and 28th
     avenue(-0.5f, -0.525f, -3.0f, 48);
     //11th ave from 28th to 29th
     //avenue(-1.075f, -0.525f, -3.0f, x);   omitted segment
     //11th ave from 29th to 28th
     avenue(-1.125f, -0.525f, -3.0f, 9);
     /******************************************************************************************************************************/
     //28th &...
     //28th &7th
     intersection(1.1f, -0.525f, -3.0f);
          //directional triangle East
          directionalEast(0.9f, -0.525f, -3.0f, 128);
          //from 28th &8th to 28th &7th
          street(0.5f, -0.5f, -3.0f, 128);
     //28th &8th
     intersection(0.5f, -0.525f, -3.0f);
          //from 28th &9th to 28th &8th
          shortStreet(0.1f, -0.5f, -3.0f, 87);
     //28th &9th
     intersection(0.1f, -0.525f, -3.0f);
          //from 28th &10th to 28th &9th
          street(-0.5f, -0.5f, -3.0f, 49);
     //28th &10th
     intersection(-0.5f, -0.525f, -3.0f);
          //from 28th &11th to 28th &10th
          street(-1.1f, -0.5f, -3.0f, 8);
     //28th &11th
     intersection(-1.1f, -0.525f, -3.0f);
     /***********************************************************************************************************************
  Vertical Segments, Avenues between 28th street and 27th street
  ************************************************************************************************************************/
     //7th ave between 28th and 27th
     avenue(1.1f, -0.64f, -3.0f, 164);
     //8th ave between 28th and 27th
     avenue(0.5f, -0.64f, -3.0f, 126);
     //9th ave between 28th and 27th
     avenue(0.1f, -0.64f, -3.0f, 86);
     //10th ave between 28th and 27th
     avenue(-0.5f, -0.64f, -3.0f, 46);
     //11th ave from 27th to 28th
     //avenue(-1.075f, -0.64f, -3.0f, x); omitted segment
     //11th ave from 28th to 27th
     avenue(-1.125f, -0.64f, -3.0f, 7);
     /******************************************************************************************************************************/
     //27th &...
     //27th &7th
     intersection(1.1f, -0.64f, -3.0f);
          //from 27th &7th to 27th &8th
          street(0.5f, -0.615f, -3.0f, 163);
     //27th &8th
     intersection(0.5f, -0.64f, -3.0f);
     //27th &9th
     intersection(0.1f, -0.64f, -3.0f);
     //27th &10th
     intersection(-0.5f, -0.64f, -3.0f);
          //directional triangle West
          directionalWest(-0.9f, -0.64f, -3.0f, 47);
          //from 27th &10th to 27th &11th
          street(-1.1f, -0.615f, -3.0f, 47);
     //27th &11th
     intersection(-1.1f, -0.64f, -3.0f);
     /***********************************************************************************************************************
  Vertical Segments, Avenues between 27th street and 26th street
  ************************************************************************************************************************/
     //7th ave between 27th and 26th
     avenue(1.1f, -0.755f, -3.0f, 162);
     //8th ave between 27th and 26th
     avenue(0.5f, -0.755f, -3.0f, 124);
     //9th ave between 27th and 26th
     avenue(0.1f, -0.755f, -3.0f, 85);
     //10th ave between 27th and 26th
     avenue(-0.5f, -0.755f, -3.0f, 44);
     //11th ave from 26th to 27th
     //avenue(-1.075f, -0.755f, -3.0f, x); omitted segment
     //11th ave from 27th to 26th
     avenue(-1.125f, -0.755f, -3.0f, 6);
     /******************************************************************************************************************************/
     //26th &...
     //26th &7th
     intersection(1.1f, -0.755f, -3.0f);
     //directional triangle East
     directionalEast(0.9f, -0.755f, -3.0f, 125);
     //from 26th &8th to 26th &7th
     street(0.5f, -0.73f, -3.0f, 125);
     //26th &8th
     intersection(0.5f, -0.755f, -3.0f);
     //from 26th &9th to 26th &8th
     shortStreet(0.1f, -0.73f, -3.0f, 84);
     //26th &9th
     intersection(0.1f, -0.755f, -3.0f);
     //from 26th &10th to 26th &9th
     street(-0.5f, -0.73f, -3.0f, 45);
     //26th &10th
     intersection(-0.5f, -0.755f, -3.0f);
     //from 26th &11th to 26th &10th
     street(-1.1f, -0.73f, -3.0f, 5);
     //26th &11th
     intersection(-1.1f, -0.755f, -3.0f);
     /***********************************************************************************************************************
  Vertical Segments, Avenues between 26th street and 25th street
  ************************************************************************************************************************/
  //7th ave between 26th and 25th
     avenue(1.1f, -0.87f, -3.0f, 161);
     //8th ave between 26th and 25th
     avenue(0.5f, -0.87f, -3.0f, 122);
     //9th ave between 26th and 25th
     avenue(0.1f, -0.87f, -3.0f, 83);
     //10th ave between 26th and 25th
     avenue(-0.5f, -0.87f, -3.0f, 42);
     //11th ave from 25th to 26th
     //avenue(-1.075f, -0.87f, -3.0f, x);    omitted segment
     //11th ave from 26th to 25th
     avenue(-1.125f, -0.87f, -3.0f, 4);
     /******************************************************************************************************************************/
     //25th &...
     //25th &7th
     intersection(1.1f, -0.87f, -3.0f);
          //from 25th &7th to 25th &8th
          street(0.5f, -0.845f, -3.0f, 160);
     //25th &8th
     intersection(0.5f, -0.87f, -3.0f);
          //from 25th &8th to 25th &9th
          shortStreet(0.1f, -0.845f, -3.0f, 123);
     //25th &9th
     intersection(0.1f, -0.87f, -3.0f);
          //from 25th &9th to 25th &10th
          street(-0.5f, -0.845f, -3.0f, 82);
     //25th &10th
     intersection(-0.5f, -0.87f, -3.0f);
          //directional triangle West
          directionalWest(-0.9f, -0.87f, -3.0f, 43);
          //from 25th &10th to 25th &11th
          street(-1.1f, -0.845f, -3.0f, 43);
     //25th &11th
     intersection(-1.1f, -0.87f, -3.0f);
     /***********************************************************************************************************************
  Vertical Segments, Avenues between 25th street and 24th street
  ************************************************************************************************************************/
     //7th ave between 25th and 24th
     avenue(1.1f, -0.985f, -3.0f, 159);
     //8th ave between 25th and 24th
     avenue(0.5f, -0.985f, -3.0f, 120);
     //9th ave between 25th and 24th
     avenue(0.1f, -0.985f, -3.0f, 81);
     //10th ave between 25th and 24th
     avenue(-0.5f, -0.985f, -3.0f, 40);
     //11th ave from 24th to 25th
     //avenue(-1.075f, -0.985f, -3.0f, x); omitted segment
     //11th ave from 25th to 24th
     avenue(-1.125f, -0.985f, -3.0f, 3);
     /******************************************************************************************************************************/
     //24th &...
     //24th &7th
     intersection(1.1f, -0.985f, -3.0f);
          //directional triangle East
          directionalEast(0.9f, -0.985f, -3.0f, 121);
          //from 24th &8th to 24th &7th
          street(0.5f, -0.96f, -3.0f, 121);
     //24th &8th
     intersection(0.5f, -0.985f, -3.0f);
          //from 24th &9th to 24th &8th
          shortStreet(0.1f, -0.96f, -3.0f, 80);
     //24th &9th
     intersection(0.1f, -0.985f, -3.0f);
          //from 24th &10th to 24th &9th
          street(-0.5f, -0.96f, -3.0f, 41);
     //24th &10th
     intersection(-0.5f, -0.985f, -3.0f);
          //from 24th &11th to 24th &10th
          street(-1.1f, -0.96f, -3.0f, 2);
     //24th &11th
     intersection(-1.1f, -0.985f, -3.0f);
     /***********************************************************************************************************************
  Vertical Segments, Avenues between 24th street and 23rd street
  ************************************************************************************************************************/
     //7th ave between 24th and 23rd
     avenue(1.1f, -1.1f, -3.0f, 158);
     //directional triangle South
     directionalSouth(1.1f, -1.005f, -3.0f, 158);
     //8th ave between 24th and 23rd
     avenue(0.5f, -1.1f, -3.0f, 117);
     //9th ave between 24th and 23rd
     avenue(0.1f, -1.1f, -3.0f, 79);
     //directional triangle South
     directionalSouth(0.1f, -1.005f, -3.0f, 79);
     //10th ave between 24th and 23rd
     avenue(-0.5f, -1.1f, -3.0f, 37);
     //11th ave from 23rd to 24th
     //avenue(-1.075, -1.1, -3.0); omitted segment
     //directional triangle South
     directionalSouth(-1.125f, -1.005f, -3.0f, 1);
     //11th ave from 24th to 23rd
     avenue(-1.125f, -1.1f, -3.0f, 1);
     /******************************************************************************************************************************/
     //23rd &...
     //23rd &7th
     intersection(1.1f, -1.1f, -3.0f);
          //from 23rd &7th to 23rd &8th
          street(0.5f, -1.065f, -3.0f, 157);
          //directional triangle East
          directionalEast(0.9f, -1.115f, -3.0f, 119);
          //from 23rd &8th to 23rd &7th
          street(0.5f, -1.09f, -3.0f, 119);
     //23rd &8th
     intersection(0.5f, -1.1f, -3.0f);
          //from 23rd &8th to 23rd &9th
          shortStreet(0.1f, -1.065f, -3.0f, 118);
          //from 23rd &9th to 23rd &8th
          shortStreet(0.1f, -1.09f, -3.0f, 78);
     //23rd &9th
     intersection(0.1f, -1.1f, -3.0f);
          //from 23rd &9th to 23rd &10th
          street(-0.5f, -1.065f, -3.0f, 77);
          //from 23rd &10th to 23rd &9th
          street(-0.5f, -1.09f, -3.0f, 39);
     //23rd &10th
     intersection(-0.5f, -1.1f, -3.0f);
          //directional triangle West
          directionalWest(-0.9f, -1.09f, -3.0f, 38);
          //from 23rd &10th to 23rd &11th
          street(-1.1f, -1.065f, -3.0f, 38);
          //from 23rd &11th to 23rd &10th
          street(-1.1f, -1.09f, -3.0f, 0);
     //23rd &11th
     intersection(-1.1f, -1.1f, -3.0f);

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
