#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"
#include <windows.h>
#include <stdlib.h>
#include <mmsystem.h>
#define COLUMNS 40
#define ROWS 40
#define FPS 10

bool Map1=true;
bool Map2=false;
bool Map3=false;
bool start=true;
int MapSelector=1;
int SnakeColor=1;
int diffuclty=1;
extern short snakeDirection;                    //a variable to know where is the snake heading
                                                //default right
extern int snake_length;
extern int posY[60],posX[60];
extern int lives;
extern bool damage2;
extern bool damage3;
bool gameOver = false;                          //game over is default at false so when the snake hits the border it turns into true and then the pop up message appears

int score=0;                                    //each time you eat food the score increases by one and appears at the pop up message

void timer_callback(int);
void display_callback();                        //Sets the display callback for the current window.
void reshape_callback(int,int);                 //gets the size of the window (Width,Height)
void main_menu();
void keys(int,int,int);

void initiateColor(){
    glClearColor(0.0,0.0,0.0,1.0);              //Background color of the program (Red,Green,Blue,Alpha)
    initGrid(COLUMNS,ROWS);                     //A stands for Alpha which defines the opacity
}

int main(int argc , char **argv){

    glutInitDisplayMode(GLUT_RGB | GL_DOUBLE);  //An alias for GLUT_RGBA
                                                //GL_DOUBLE: you can picture having two buffers. One of them is always visible, the other one is not. You always render to the buffer that is not currently visible.
    glutInitWindowSize(500,500);                //Initialize window size
    glutCreateWindow("SNAKE");                  //Snake is the name of the window
    glutDisplayFunc(main_menu);                 //Sets the display callback for the current window.
    glutReshapeFunc(reshape_callback);          //The reshape callback is triggered when the window is reshaped
    glutTimerFunc(0,timer_callback,0);          //registers the timer callback function to be triggered in a specified number of milliseconds
    glutSpecialFunc(keys);
    initiateColor();                            //initiating color function
    glutMainLoop();                             //all the processing starts when this function is called it starts the
    return 0;

}

void main_menu(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(Map1){                                   //drawing the selector around map 1
    glColor3f(1,1,1);                           //the color of the selector is white
    glLineWidth(5);                             //its width is 5
    glBegin(GL_LINE_LOOP);                      //the type of drawing
    glVertex2f(0.5,32.5);                       //point 1
    glVertex2f(0.5,29);                         //point 2
    glVertex2f(10,29);                          //point 3
    glVertex2f(10,32.5);                        //point 4
    glEnd();                                    //end the drawing
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if(Map2){                              //drawing the selector around map 2
    glColor3f(1,1,1);                           //the color of the selector is white
    glLineWidth(5);                             //its width is 5
    glBegin(GL_LINE_LOOP);                      //the type of drawing
    glVertex2f(0.5,22.5);                       //point 1
    glVertex2f(0.5,19);                         //point 2
    glVertex2f(10,19);                          //point 3
    glVertex2f(10,22.5);                        //point 4
    glEnd();                                    //end the drawing
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if(Map3){                              //drawing the selector around map 3
    glColor3f(1,1,1);                           //the color of the selector is white
    glLineWidth(5);                             //its width is 5
    glBegin(GL_LINE_LOOP);                      //the type of drawing
    glVertex2f(0.5,12.5);                       //point 1
    glVertex2f(0.5,9);                          //point 2
    glVertex2f(10,9);                           //point 3
    glVertex2f(10,12.5);                        //point 4
    glEnd();                                    //end the drawing
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    glColor3f(1,1,1);                           //color of text
    glRasterPos3f(30.0,30.0,1);                 //position of text
    char Color[]="Color";                       //what is in the text
    for (int i=0; i<strlen(Color); i++)         //loop to print
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Color[i]);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(SnakeColor==1)                           //Snake color 1
        glColor3f(1,1,1);
    else if (SnakeColor==2)                     //Snake color 2
        glColor3f(1,0,0);
    else if (SnakeColor==3)                     //Snake color 3
        glColor3f(1,1,0);
    else if (SnakeColor==4)                     //Snake color 4
        glColor3f(1,0,1);
    else if (SnakeColor==5)                     //Snake color 5
        glColor3f(0,1,0);
    else if (SnakeColor==6)                     //Snake color 6
        glColor3f(0,1,1);
    else if (SnakeColor==7)                     //Snake color 7
        glColor3f(0,0,1);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    glLineWidth(5);                             //drawing the box of color
    glBegin(GL_POLYGON);                        //the type of drawing
    glVertex2f(25,30);                          //point 1
    glVertex2f(25,32);                          //point 2
    glVertex2f(27,32);                          //point 3
    glVertex2f(27,30);                          //point 4
    glEnd();                                    //ending of the drawing
    //printing Snake at the top of the screen
    glColor3f(1,0,0);
    glRasterPos3f(15.0,35.0,1);
    char SNAKE_GAME[]="SNAKE GAME";
    for (int i=0; i<strlen(SNAKE_GAME); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, SNAKE_GAME[i]);
    //Placing and typing Map 1
    glColor3f(1,1,0.5);
    glRasterPos3f(1.0,30.0,1);
    char Map_1[]="Map 1";
    for (int i=0; i<strlen(Map_1); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Map_1[i]);


    //Placing and typing Map 2
    glColor3f(1,1,0.5);
    glRasterPos3f(1.0,20.0,1);
    char Map_2[]="Map 2";
    for(int i=0; i<strlen(Map_2); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Map_2[i]);


    //Placing and typing Map 3
    glColor3f(1,1,0.5);
    glRasterPos3f(1.0,10.0,1);
    char Map_3[]="Map 3";
    for(int i=0; i<strlen(Map_3); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Map_3[i]);


    glEnd();
    glFlush();
    glutSwapBuffers();                                             //Performs a buffer swap on the layer in use for the current window.

}

void keys(int key,int x,int y){

    switch(key){
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case GLUT_KEY_UP:
        if(start==true){
            if(MapSelector==1){
            Map1=false;
            Map2=false;
            Map3=true;
            MapSelector=3;
                main_menu();
                break;
        }
        else if(MapSelector==2){
            Map1=true;
            Map2=false;
            Map3=false;
            MapSelector--;
            main_menu();
                break;
        }
        else if(MapSelector==3){
            Map1=false;
            Map2=true;
            Map3=false;
            MapSelector--;
            main_menu();
                break;
        }
        }
        else if(start==false){
        if(snakeDirection!=DOWN){
            snakeDirection=UP;
            break;
        }
        }
        break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case GLUT_KEY_DOWN:
            if(start==true){
            if(MapSelector==1){
            Map1=false;
            Map2=true;
            Map3=false;
            MapSelector++;
            main_menu();
                break;
        }
        else if(MapSelector==2){
            Map1=false;
            Map2=false;
            Map3=true;
            MapSelector++;
            main_menu();
                break;
        }
        else if(MapSelector==3){
            Map1=true;
            Map2=false;
            Map3=false;
            MapSelector=1;
            main_menu();
            break;
        }
            }
            else if (start==false){
        if(snakeDirection!=UP){
            snakeDirection=DOWN;
            break;
            }
            }
        break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case GLUT_KEY_PAGE_UP:
        if(start==true){
        if(SnakeColor==7){
            SnakeColor=1;
            break;
        }
        else{
            SnakeColor++;
            main_menu();
            break;
            }
        }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case GLUT_KEY_PAGE_DOWN:
        if(SnakeColor==1){
            SnakeColor=7;
            break;
            }
        else{
            SnakeColor--;
            main_menu();
            break;
        }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case GLUT_KEY_RIGHT:                //when right arrow pressed snake moves right if its not moving left
            if(start==false){
            if(snakeDirection!=LEFT)
                snakeDirection=RIGHT;
                    break;
            }
    case GLUT_KEY_LEFT:                 //when left arrow pressed snake moves left if its not moving right
            if(start==false){
            if(snakeDirection!=RIGHT)
                snakeDirection=LEFT;
                    break;
            }

    case GLUT_KEY_F1:
            glutDisplayFunc(display_callback);
            start=false;
            break;

    }

    glutPostRedisplay();

}


void display_callback(){
    glClear(GL_COLOR_BUFFER_BIT);               //Clears the color buffer because it is better to start each frame with a clean slate
    drawGrid();                                 //drawing the grid from game.cpp
    drawSnake();                                //drawing snake in game.cpp
    drawFood();                                 //drawing food in game.cpp
    drawdamage();                               //drawing damage in game.cpp
    glutSwapBuffers();                          //Performs a buffer swap on the layer in use for the current window.
    if(gameOver){
        char _score[10];                        //the score will not be bigger than 9,999,999,999
        itoa(score,_score,10);                  //transforming the int score into array of char _score
        char text[50]= "Your Score is : ";
        strcat(text,_score);                    //joining the text and _score into a single char array
        MessageBox(NULL,text,"GAME OVER",0);    //pop up message when you lose
        snake_length=5;
                posY[0]=20;
                posY[1]=20;
                posY[2]=20;
                posY[3]=20;
                posY[4]=20;
                posX[0]=20;
                posX[1]=19;
                posX[2]=18;
                posX[3]=17;
                posX[4]=16;
                snakeDirection=RIGHT;
        score=0;
        lives=3;
        gameOver=false;
        start=true;
        glutDisplayFunc(main_menu);

        glutSpecialFunc(keys);



    }
}

void reshape_callback(int width , int height){
    glViewport(0,0,(GLsizei)width,(GLsizei)height); //Viewport specifies the transformation of x and y, Then the new window coordinates (Xw,Yw) are computed
                                                    //x, y Specify the lower left corner of the Viewport rectangle, in pixels. The initial value is (0,0).
                                                    //width, height Specify the width and height of the Viewport. When a GL context is first attached to a window, width and height are set to the dimensions of that window
    glMatrixMode(GL_PROJECTION);                    //There are four matrix modes
                                                    //1-GL_MODELVIEW Applies subsequent matrix operations to the modelview matrix stack.
                                                    //2-GL_PROJECTION Applies subsequent matrix operations to the projection matrix stack.
                                                    //3-GL_TEXTURE Applies subsequent matrix operations to the texture matrix stack.
                                                    //4-GL_COLOR Applies subsequent matrix operations to the color matrix stack.
    glLoadIdentity();                               //replaces the current matrix with the identity matrix. It is semantically equivalent to calling glLoadMatrix with the identity matrix 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);         //left, right Specify the coordinates for the left and right vertical clipping planes.
                                                    //bottom, top Specify the coordinates for the bottom and top horizontal clipping planes.
                                                    //nearVal, farVal Specify the distances to the nearer and farther depth clipping planes.
                                                    //These values are negative if the plane is to be behind the viewer.
    glMatrixMode(GL_MODELVIEW_MATRIX);              //We will need to switch back to modelview matrix to continue with the rest of activities

}

void timer_callback(int){
    glutPostRedisplay();                            //marks the current window as needing to be redisplayed
                                                    //gives opengl urge to call the display function as soon as possible
    glutTimerFunc(1000/FPS,timer_callback,0);
}
