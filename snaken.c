#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int height=20,width=60,x,y,fruitx,fruity,gameover=1,lives=3,lenthin=1,snakelx[100],snakely[100];
int prevx,prevy,prev2x,prev2y,count=0,q=0,b,prevfl,bfruit=60,fc=0;
static int score;
enum keys
{
    left=1,right,down,up
};

enum keys flag;
void delay(unsigned int mseconds)
{
    long int goal=mseconds+clock();
    while(goal>clock());

}
void ostruct()         //outer structure
{
    system("cls");
    printf("score : %d ",score);
    printf("                                     lives :%d \n",lives);

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(i>0&&i<(height-1))
            {
                if(j==0||j==(width-1))
                    printf("*");
                    else
                    {
                        if(i==y&&j==x)
                            printf("@");
                        else if(i==fruity&&j==fruitx)
                        {
                            if(score==bfruit)
                            {
                                printf("O");
                            }
                            else
                            printf("+");
                        }
                        else
                        {     int q=0;
                            for(int a=0;a<count;a++)
                            {
                                if(i==snakely[a]&&j==snakelx[a])
                                {
                                    printf("+");
                                   q=1;
                                }
                            }
                            if(q==0)
                                printf(" ");

                        }
                    }
           }
        else
            printf("*");
        }
        printf("\n");
    }
}

void randomf()    // generating random fruits
{
     label1:
     fruitx=rand()%60;
    if(fruitx==0||fruitx==59)
            goto label1;
    label2:
        fruity=rand()%20;
        if(fruity==0||fruity==19)
                goto label2;

}
void setup()      //function to intialize position of snake head and fruit;
{
    x=width/2;
    y=height/2;
    randomf();

}

void input()
{
    prevfl=flag;
    if(kbhit())  //condition for input
    {
        switch(getch())
        {
        case 'a':
            flag=left;
            break;
        case 'd':
            flag=right;
            break;
        case 's':
            flag=down;
            break;
        case 'w':
            flag=up;
            break;
        case 'x':
            gameover=1;
            break;
        }
    }

}
void logic()
{
    prevx=snakelx[0];   //logic for snake tail increment
    prevy=snakely[0];
    snakelx[0]=x;
    snakely[0]=y;
    for(int q=1;q<=count;q++)
    {
        prev2x=snakelx[q];
        prev2y=snakely[q];
        snakelx[q]=prevx;
        snakely[q]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
if(prevfl==left&&flag==right)             //conditions for the snake to dont move in its opposite direction if input is given by user                                         // ex 000000->if snake moving in right direction then if input is left then snake has to move on right
    flag=left;
else if(prevfl==right&&flag==left)
    flag=right;
else if(prevfl==up&&flag==down)
    flag=up;
else
{
    if(prevfl==down&&flag==up)
        flag=down;
}
 labell:
    switch(flag) //cases for snake movement
    {
        case left:
            x--;
            break;
        case right:
            x++;
            break;
        case down:
            y++;
            break;
        case up:
            y--;
            break;
        default:
            break;
    }
    if(x==0||y==0||x==59||y==19) //condition for gameover
    {
        lives--;
        if(lives==-1)
            printf("your score is %d"  ,score);
            gameover=0;
    }
    if(x==fruitx&&y==fruity) //condition for score increment
    {
        Beep(1000,50);
        count++;
        if(count==(fc+7))
        {
        score+=60;
        fc+=7;
        bfruit+=120;
        }
        else
            score+=10;
        randomf();



    }
   for(int i=0;i<count;i++) // logic for gameover when snake touches itself
    {
        if(x==snakelx[i]&&y==snakely[i])
        {
            gameover=0;
            lives--;
        }
    }
    if(score>=0&&score<50)
       delay(100);
    else if(score>=50&&score<90)
        delay(80);
    else if(score>=90&&score<140)
        delay(60);
    else if(score>=210&&score<300)
        delay(40);
    else
       delay(30);

}
int main()
{
    labell:
    setup();
    while(gameover)
    {
    ostruct();
    input();
    logic();
    }
    if(lives>-1)
    {
        gameover=1;
        goto labell;
    }
    else{
        Beep (330,100);Sleep(100);
        Beep (330,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (330,100);Sleep(300);
        Beep (392,100);Sleep(700);
        Beep (196,100);Sleep(700);
        Beep (262,300);Sleep(300);
        Beep (196,300);Sleep(300);
        Beep (164,300);Sleep(300);
        Beep (220,300);Sleep(100);
        Beep (246,100);Sleep(300);
        Beep (233,200);
        Beep (220,100);Sleep(300);
        Beep (196,100);Sleep(150);
        system ("pause");

       }
    return 0;
}
