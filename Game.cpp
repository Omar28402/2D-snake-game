#include <GL/gl.h>
        #include <GL/glut.h>
        #include <windows.h>
        #include <ctime>
        #include <mmsystem.h>
        #include "game.h"
        extern int diffuclty;
        extern int score;                           //score of the game
        extern int SnakeColor;
        int snake_length = 5;                       //starting length of the snake
        int gridX,gridY;                            //the X and Y axis of the game
        bool food = true;                             //Is eaten or not
        int foodX,foodY;                            //Position of the food itself and we will use the random function for it
        int lives=3;
        extern int MapSelector;
        int damage1X,damage1Y;                      //position of damage1
        int damage2X,damage2Y;                      //position of damage2
        int damage3X,damage3Y;                      //position of damage3
        int damage4X,damage4Y;                      //position of damage4


        int posX[60]={20,20,20,20,20},posY[60]={20,19,18,17,16};                    //Position of the snake at the beginning it is at the center and horizontally drawn
        short snakeDirection = RIGHT;               //default direction of the snake
        extern bool gameOver;

        void initGrid(int x, int y){                //initiating the grid
        gridX=x;
        gridY=y;
        }



void snake_bar(){

                                        //drawing the grid from game.cp
 glColor3f(1,0,0);
 glLineWidth(5);
 glColor3f(1,1,0);
 glRasterPos3f(1.5,37.0,1);

                        //the score will not be bigger than 9,999,999,999
    char _live[10];                        //the score will not be bigger than 9,999,999,999
    itoa(lives,_live,10);                  //transforming the int score into array of char _score
    char text[50]= "LIVES : ";
    strcat(text,_live);
    for (int i=0; i<strlen(text); i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);

    glColor3f(1,1,0);
    glRasterPos3f(1.5,35.5,1);

        char _scores[10];                        //the score will not be bigger than 9,999,999,999
        itoa(score,_scores,10);                  //transforming the int score into array of char _score
        char text2[50]= "SCORE : ";
        strcat(text2,_scores);
    for (int i=0; i<strlen(text2); i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text2[i]);


}



        void unit(int,int);
        void drawGrid(){                        //in these 2 loops we loop around each point so we can draw lines for each square available
            for(int x=0;x<gridX;x++){
                for(int y=0;y<gridY;y++){
                    unit(x,y);
                }
            }
        }

        void unit(int x,int y){

            if( x==0 || y==0 || x==gridX-1 || y==gridY-1){
                glLineWidth(5.0);               //specifying the width of the border
                glColor3f(1.0,0.0,0.0);         //Specifying the color of the border is red
            }
            else{
                glColor3f(0.0,0.0,0.0);         //Specifying the color of the inside blocks are black
                glLineWidth(1.0);               //specifying the width of the inside blocks
            }
            glBegin(GL_LINE_LOOP);              //Specifies the primitive
                glVertex2f(x,y);
                glVertex2f(x,y+1);
                glVertex2f(x+1,y+1);
                glVertex2f(x+1,y);
            glEnd();                            //to end drawing
        }



    void drawFood(){
        if(food)
            random(foodX,foodY);                    //it is drawn randomly
        food=false;                                 //then turned into false so it doesn't change position again
        glColor3f(0.0,1.0,0.0);                     //color of the food
        glRectf(foodX,foodY,foodX+1,foodY+1);       //drawing the block of food

    }


        void drawdamage(){
            if(MapSelector==1){
                //randomdamage(damage1X,damage1Y);                       //randomizing the damage position
            glColor3f(1.0,0.0,0.0);                                     //color of the damage
            damage1X=10;
            damage1Y=30;
            damage2X=10;
            damage2Y=10;
            glRectd(damage1X,damage1Y,damage1X+20,damage1Y+1);               //drawing the damage
            glRectd(damage2X,damage2Y,damage2X+20,damage2Y+1);               //drawing the damage


            for(int i=0; i<20;i++){
                if(posX[0] == damage1X+i && posY[0] == damage1Y){
                sndPlaySound("wrongo.wav",SND_ASYNC);
                lives--;
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
                }
            }

            for(int i=0; i<20;i++){
                if(posX[0] == damage2X+i && posY[0] == damage2Y){
                sndPlaySound("wrongo.wav",SND_ASYNC);
                lives--;
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
                }
            }

        }





        if(MapSelector==2){
            glColor3f(1.0,0.0,0.0);                                     //color of the damage
            damage1X=10;
            damage1Y=10;
            damage2X=30;
            damage2Y=10;
            glRectd(damage1X,damage1Y,damage1X+1,damage1Y+20);               //drawing the damage
            glRectd(damage2X,damage2Y,damage2X+1,damage2Y+20);               //drawing the damage


            for(int i=0; i<20;i++){
                if(posX[0] == damage1X && posY[0] == damage1Y+1){
                sndPlaySound("wrongo.wav",SND_ASYNC);
                lives--;
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
                }
            }
            for(int i=0; i<20;i++){
                if(posX[0] == damage2X && posY[0] == damage2Y+i){
                sndPlaySound("wrongo.wav",SND_ASYNC);
                lives--;
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
                }
            }
        }
            if(MapSelector==3){
                //randomdamage(damage1X,damage1Y);                       //randomizing the damage position
            glColor3f(1.0,0.0,0.0);                                     //color of the damage
            damage1X=8;
            damage1Y=8;
            damage2X=28;
            damage2Y=8;
            damage3X=8;
            damage3Y=28;
            damage4X=28;
            damage4Y=28;
            glRectd(damage1X,damage1Y,damage1X+5,damage1Y+5);               //drawing the damage
            glRectd(damage2X,damage2Y,damage2X+5,damage2Y+5);               //drawing the damage
            glRectd(damage3X,damage3Y,damage3X+5,damage3Y+5);               //drawing the damage
            glRectd(damage4X,damage4Y,damage4X+5,damage4Y+5);               //drawing the damage

            for(int i=0; i<5;i++){
                for(int j=0; j<5;j++){
                if(posX[0] == damage1X+i && posY[0] == damage1Y+j){
                sndPlaySound("wrongo.wav",SND_ASYNC);
                lives--;
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
                }
            }
            }
            for(int i=0; i<5;i++){
                for(int j=0; j<5;j++){
                if(posX[0] == damage2X+i && posY[0] == damage2Y+j){
                sndPlaySound("wrongo.wav",SND_ASYNC);
                lives--;
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
                }
            }
            }
            for(int i=0; i<5;i++){
                for(int j=0; j<5;j++){
                if(posX[0] == damage3X+i && posY[0] == damage3Y+j){
                sndPlaySound("wrongo.wav",SND_ASYNC);
                lives--;
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
                }
            }
            }
            for(int i=0; i<5;i++){
                for(int j=0; j<5;j++){
                if(posX[0] == damage4X+i && posY[0] == damage4Y+j){
                sndPlaySound("wrongo.wav",SND_ASYNC);
                lives--;
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
                }
            }
            }
        }
         if(lives == 0){                                          //if the lives equal 0 the game is over
            sndPlaySound("Lose game.wav",SND_ASYNC);
            gameOver = true;
           }                                  //when the snake hit the damage the length of it is going to get smaller
        if(snake_length<MINSNAKE)
            snake_length=MINSNAKE;
        }

        void drawSnake(){
            snake_bar();
            for(int i = snake_length-1;i > 0;i--){
                    posX[i] = posX[i-1];
                    posY[i] = posY[i-1];
            }
            if(snakeDirection==UP)              //movement of the snake up
                posY[0]++;
            else if(snakeDirection==DOWN)       //movement of the snake down
                posY[0]--;
            else if(snakeDirection==RIGHT)      //movement of the snake right
                posX[0]++;
            else if(snakeDirection==LEFT)       //movement of the snake left
                posX[0]--;

                for(int i = 0;i < snake_length ; i++){
                if(i==0)
                    glColor3f(0.0,1.0,0.0);         //color of the head of the snake
                        else if(SnakeColor==1)
                            glColor3f(1,1,1);
                        else if (SnakeColor==2)
                            glColor3f(1,0,0);
                        else if (SnakeColor==3)
                            glColor3f(1,1,0);
                        else if (SnakeColor==4)
                            glColor3f(1,0,1);
                        else if (SnakeColor==5)
                            glColor3f(0,1,0);
                        else if (SnakeColor==6)
                            glColor3f(0,1,1);
                        else if (SnakeColor==7)
                            glColor3f(0,0,1);
                glRectd(posX[i],posY[i],posX[i]+1,posY[i]+1);   //drawing of the full snake
            }

            //if the head and hits the border it is game over
            if(posX[0]==0 || posX[0] == gridX-1 || posY[0]==0 || posY[0] == gridY-1){
                sndPlaySound("Lose sound.wav",SND_ASYNC);
                gameOver=true;

            }


            if(posX[0]==foodX && posY[0]==foodY){      //if food and the head of the snake are at the same position
                score++;
                snake_length++;                         //the snake grows in length
                if (snake_length>MAXSNAKE)              //if the snake is at max health the snake is not going to grow
                    snake_length=MAXSNAKE;
                food=true;                      //then food is true and when drawFood()is called again it will change the food position
                sndPlaySound("audio.wav",SND_ASYNC);
            }
            //this loop checks if the snake hits itself or not
            //and if it does game is over
            for(int i = 1;i < snake_length ; i++){
                if(posX[0]==posX[i] && posY[0] == posY[i]){
                    gameOver=true;
                    sndPlaySound("wrongo.wav",SND_ASYNC);
            }
            }
        }




        void random(int &x,int &y){             //making food appear randomly across the grid
            int _maxX = gridX-2;                //maximum of x-axis
            int _maxY = gridY-2;                //maximum of y-axis
            int _min = 1;                       //minimum of both is 1
            srand(time(NULL));                  //changing the random value
            x = _min + rand() % (_maxX-_min);   //calculating the grid according to its size
            y = _min + rand() % (_maxY-_min);   //calculating the grid according to its size
            if(MapSelector==1){
            for(int i=0; i<20;i++){
                if(x == damage1X+i && y == damage1Y)
                   random(x,y);
            }
            for(int i=0; i<20;i++){
                if(x == damage2X+i && y == damage2Y)
                  random(x,y);
            }
            }
            if(MapSelector==2){
            for(int i=0; i<20;i++){
                if(x == damage1X && y == damage1Y+i)
                   random(x,y);
            }
            for(int i=0; i<20;i++){
                if(x == damage2X && y == damage2Y+i)
                  random(x,y);
            }
            }
            if(MapSelector==3){
            for(int i=0; i<5;i++){
                for(int j=0;j<5;j++){
                if(x == damage1X+i && y == damage1Y+j)
                   random(x,y);
            }
            }
            for(int i=0; i<5;i++){
                for(int j=0;j<5;j++){
                if(x == damage2X+i && y == damage2Y+j)
                  random(x,y);
            }
            }
            for(int i=0; i<5;i++){
                for(int j=0;j<5;j++){
                if(x == damage3X+i && y == damage3Y+j)
                  random(x,y);
            }
            }
            for(int i=0; i<5;i++){
                for(int j=0;j<5;j++){
                if(x == damage4X+i && y == damage4Y+j)
                  random(x,y);
            }
            }


        }
        }
