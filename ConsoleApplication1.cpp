#include<iostream>
#include<conio.h>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
int tailX[100], tailY[100];
int ntail;
void Setup()
{
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    
}
void draw()
{
    system("cls");
    for (int i = 0; i < width + 1; i++)
        std::cout << "#";
    cout << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0) {
                cout << '#';
            }
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "f";
            else {
                for (int k = 0; k < ntail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                    }
                }
                cout << " ";
            }
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;
    cout << score<<endl;

}
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'w':
            dir =UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        default:
            break;


        }
    }
}
void logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int tempX, tempY;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < ntail; i++)
    {
        tempX = tailX[i];
        tempY = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = tempX;
        prevY = tempY;

    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case RIGHT:
        x++;
        break;
    default:
        break;
    }
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
        for(int i=0;i<ntail;i++)
            if(tailX[i]==x && tailY[i]==y)
                gameover = true;
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        ntail++;
    }
    
}
int main()
{
     Setup();
    while (!gameover)
    {
       
        draw();
        input();
        logic();
    }
    if (gameover == true)
    {
        system("cls");
        cout << "\t\t\t\t\tGAMEOVER";

    }
    return 0;
}