#include<windows.h>
#include<GL/glut.h>
#include<iostream>//for strlen
#include<conio.h>



int i,q;
int score = 0;//for score counting
int screen = 0;
bool collide = false;//check if car collide to make game over
char buffer[10];

int vehicleX = 200, vehicleY = 100;  // drawing point
int ovehicleX[4], ovehicleY[4];
int divx = 250, divy = 4, movd;
int ox = 250, oy = 250;

//why this
void drawText(char ch[],int xpos, int ypos)//draw the text for score and game over
{
    int numofchar = strlen(ch);
    glLoadIdentity (); //replace the current matrix with the identy matrix
    glRasterPos2f( xpos , ypos); // it define the screen position
    for (i = 0; i <= numofchar - 1; i++)
    {

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);//font used here, may use other font also
    }
}


void drawTextNum(char ch[],int numtext,int xpos, int ypos)//counting the score
{
    int len;
    int k;
    k = 0;
    len = numtext - strlen (ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <=numtext - 1; i++)
    {
    if ( i < len )
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'0');
    else
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[k]);
        k++;
    }

    }
}

//Back Screen
void ovpos()
{
    glClearColor(  0.560784, 0.737255,0.560784,0);
for(i = 0; i < 4; i++)
{
    if(rand() % 2 == 0)
    {
        ovehicleX[i] = 200;
    }
    else
    {
        ovehicleX[i] = 300;
    }
    ovehicleY[i] = 1100 - i * 240;
}
}

//Road
void drawRoad()
{
    glBegin(GL_QUADS);
        glColor3f(0.50,0.50,0.50);
        glVertex2f(ox - 100, 500);
        glVertex2f(ox - 100, 0);
        glVertex2f(ox + 100, 0);
        glVertex2f(ox + 100, 500);
    glEnd();


}


void drawDivider()//black patch drawn in middle of road
{
    glLoadIdentity();
    glTranslatef(0, movd, 0); // multiply the current matrix by translation matrix x,y,z
    for(i = 1; i <= 10; i++)
    {
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(divx  - 5, divy * 15 * i + 18);
        glVertex2f(divx  - 5, divy * 15 * i - 18);
        glVertex2f(divx  + 5, divy * 15 * i - 18);
        glVertex2f(divx  + 5, divy * 15 * i + 18);
    glEnd();
    }


    for(i = 1; i <= 3; i++){
    glPointSize(5.0);
    glBegin(GL_POINTS);//road dots
        glColor3f(1,1,1);
        glVertex2f(vehicleX  - 25, divy * 5 * i + 16);
        glVertex2f(vehicleX  + 25, divy * 5 * i + 16);
        glVertex2f(vehicleX  - 25, divy * 5 * i - 16);
        glVertex2f(vehicleX  + 25, divy * 5 * i - 16);
    glEnd();

    }
    glLoadIdentity();
}


void drawVehicle()//car for racing
{
    glPointSize(10.0);
    glBegin(GL_POINTS);//tire
        glColor3f(0,0,0);
        glVertex2f(vehicleX - 25, vehicleY + 16);//l up
        glVertex2f(vehicleX + 25, vehicleY + 16);//R up
        glVertex2f(vehicleX - 25, vehicleY - 46);//l down
        glVertex2f(vehicleX + 25, vehicleY - 46);//R down
    glEnd();

    glBegin(GL_QUADS);
        glColor3f( 0.8 ,0.2222 ,0);//middle body
        glVertex2f(vehicleX - 25, vehicleY + 20);//l up
        glVertex2f(vehicleX - 25, vehicleY - 50);//l down
        glVertex2f(vehicleX + 25, vehicleY - 50);//r down
        glVertex2f(vehicleX + 25, vehicleY + 20);//r up
    glEnd();

    glBegin(GL_QUADS);//up body
        glColor3f(0,0.1,1);
        glVertex2f(vehicleX - 23, vehicleY + 20);
        glVertex2f(vehicleX - 19, vehicleY + 40);
        glVertex2f(vehicleX + 19, vehicleY + 40);
        glVertex2f(vehicleX + 23, vehicleY + 20);
    glEnd();

    glBegin(GL_QUADS);//down body
        glColor3f(0,0.1,1);
        glVertex2f(vehicleX - 25, vehicleY - 40);
        glVertex2f(vehicleX - 25, vehicleY - 55);
        glVertex2f(vehicleX + 25, vehicleY - 55);
        glVertex2f(vehicleX + 25, vehicleY - 40);
    glEnd();
 }

void drawOVehicle()//other cars
{

    for(i = 0; i < 3; i++)
    {
    glPointSize(10.0);
    glBegin(GL_POINTS);//tire
        glColor3f(0,0,0);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] + 16);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] + 16);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] - 16);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] - 16);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.6,0.8 ,0.196078  );//middle body
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] + 20);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] - 20);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] - 20);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] + 20);
    glEnd();

    glBegin(GL_QUADS);//up body
        glColor3f(0.309804  ,0.184314 , 0.309804);
        glVertex2f(ovehicleX[i] - 23, ovehicleY[i] + 20);
        glVertex2f(ovehicleX[i] - 19, ovehicleY[i] + 40);
        glVertex2f(ovehicleX[i] + 19, ovehicleY[i] + 40);
        glVertex2f(ovehicleX[i] + 23, ovehicleY[i] + 20);
    glEnd();

    glBegin(GL_QUADS);//down body
        glColor3f(0.309804  ,0.184314 , 0.309804);
        glVertex2f(ovehicleX[i] - 23, ovehicleY[i] - 20);
        glVertex2f(ovehicleX[i] - 19, ovehicleY[i] - 35);
        glVertex2f(ovehicleX[i] + 19, ovehicleY[i] - 35);
        glVertex2f(ovehicleX[i] + 23, ovehicleY[i] - 20);
    glEnd();

    ovehicleY[i] = ovehicleY[i] - 8;

    if(ovehicleY[i] > vehicleY - 25 - 25 && ovehicleY[i] < vehicleY + 25 + 25 && ovehicleX[i] == vehicleX)
    {
        collide = true;
    }

    if(ovehicleY[i] < -25)
    {
        if(rand() % 2 == 0)
        {
            ovehicleX[i] = 200;
        }
        else
        {
            ovehicleX[i] = 300;
        }
        ovehicleY[i] = 600;
    }
    }
}

void Specialkey(int key, int x, int y)//allow to use navigation key for movement of car
{
switch(key)
{
case GLUT_KEY_LEFT:vehicleX = 200;
             break;
case GLUT_KEY_RIGHT:vehicleX = 300;
             break;

}
glutPostRedisplay();
}
void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 500, 0, 500);
glMatrixMode(GL_MODELVIEW);
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawRoad();
    drawDivider();
    drawVehicle();
    drawOVehicle();
    movd = movd - 14;
    if(movd < - 60)
    {
        movd = 0;
    }
    score = score + 1;
    if(score>1000){            //Congratulations!
        glColor3f(1,1,1);
        drawText("Congratulations!", 200,250);
        glutSwapBuffers();
        getch();
    }

    glColor3f(1,1,1);
    drawText("Score:", 360,455);
    itoa (score, buffer, 10);
    drawTextNum(buffer, 6, 420,455);
    glutSwapBuffers();
    for(q = 0; q<= 10000000; q++){;}
    if(collide == true)
    {
        glColor3f(1,1,1);
        drawText("Game Over", 200,250);
        glutSwapBuffers();
        getch();
    }
}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,500);
    glutCreateWindow("Racing game");
    ovpos();
    init();
    glutDisplayFunc(display);
	glutSpecialFunc(Specialkey);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
