#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
GLint n, count = 0, s, i, y, j, z = -1, flag = 0,tt=0,f=1,sum=0;
GLint p[10], at[10], bt[10], c[10], l[10];
GLint u[10], v[10];
GLfloat ap[10],avgwt,avgtat;
char st[10];
GLfloat color[][3] = {{0.0, 1.0, 1.0}, {0.0, 1.0, 0.0}, {0.8, 1.0, 0.3}, {1.5, 0.0, 1.0}, {1.0, 0.0, 0.0}, {0.4, 1.0, 0.2}, {0.6, 0.8, 1.0}, {1.0, 0.9, 0.1},{0.4, 0.6, 0.2}};


void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 1200, -1700, 1000);
    glMatrixMode(GL_MODELVIEW);
    //glutPostRedisplay();
}

//prints char
void print(int x, int y, int z, int p)
{
    glRasterPos2f(x, y);

    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, p + 48);
}

//prints string
void prints(int x, int y, char *string)
{
    glRasterPos2f(x, y);
    int len = (int)strlen(string);
    for (i = 0; i < len; i++)
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
}

//prints heading
void printss(int x, int y, char *string)
{
    glRasterPos2f(x, y);
    int len = (int)strlen(string);
    for (i = 0; i < len; i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
}


void tab()
{
    //table
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 300);
    glVertex2f(0, 370);
    glVertex2f(225, 370);
    glVertex2f(225, 300);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(225, 300);
    glVertex2f(225, 370);
    glVertex2f(450, 370);
    glVertex2f(450, 300);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(450, 300);
    glVertex2f(450, 370);
    glVertex2f(650, 370);
    glVertex2f(650, 300);
    glEnd();

    //
    s = 300 - (n * 70);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 300);
    glVertex2f(225, 300);
    glVertex2f(225, s);
    glVertex2f(0, s);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(225, 300);
    glVertex2f(450, 300);
    glVertex2f(450, s);
    glVertex2f(225, s);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(450, 300);
    glVertex2f(650, 300);
    glVertex2f(650, s);
    glVertex2f(450, s);
    glEnd();
    //position();
}

void numberline()
{
    //numberline
    glBegin(GL_LINES);
    glVertex2f(0, s - 750);
    glVertex2f(1000, s - 750);
    glEnd();

    y = s - 740;
    GLint i;
    for (i = 0; i <= 1000; i += 50)
    {
	glBegin(GL_LINES);
	glVertex2f(i, s - 750);
	glVertex2f(i, y);
	glEnd();
    }

    y = s - 760;
    for (i = 0; i <= 1000; i += 50)
    {
	glBegin(GL_LINES);
	glVertex2f(i, s - 750);
	glVertex2f(i, y);
	glEnd();
    }

    glColor3f(1.0, 1.0, 0.0);
    for (i = 0; i <= 9; i++)
	print(0 + i * 48, s - 790, 0, i);

    char m[3] = {""};
    int count = 10;
    while (count <= 20)
    {
	m[0] = count / 10 + 48;
	m[1] = count % 10 + 48;
//	m[2] =count  % 100+48;
	prints(0 + count * 49, s - 790, m);
	count++;
    }
    //for(i=10;i<=20;i++)
    //gprints(0+i*47,s-540,0,i);
}

void arrow(GLfloat x, GLfloat y)
{
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x, y + 40);
    glVertex2f(x + 5, y + 40);
    glVertex2f(x + 5, y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(x - 10, y);
    glVertex2f(x + 2.5, y - 20);
    glVertex2f(x + 15, y);
    glEnd();
}

void input()
{
    int i, j, temp;
    printf("enter no of processes ");
    scanf("%d", &n);
    if (n > 9)
    {
	printf("too many processes");
	exit(0);
    }
    printf("enter arrival time");
    for (i = 0; i < n; i++)
    {
	scanf("%d", &at[i]);
	u[i] = at[i];
    }
    printf("enter burst time");
    for (i = 0; i < n; i++)
    {
	scanf("%d", &bt[i]);
	v[i] = bt[i];
    }
    for (i = 0; i < n; i++)
    {
	p[i] = i;
	//	l[i]=p[i];
    }

    for (i = 0; i < n; i++)
	for (j = 0; j < n - 1; j++)
	{
	    if (at[j] > at[j + 1])
	    {
		temp = at[j];
		at[j] = at[j + 1];
		at[j + 1] = temp;

		temp = bt[j];
		bt[j] = bt[j + 1];
		bt[j + 1] = temp;

		temp = p[j];
		p[j] = p[j + 1];
		p[j + 1] = temp;
	    }
	}
	
	for(i=0;i<n;i++)
	sum=sum+bt[i];
	
}

void gantt(int z)
{
    int p = s - (600);
    int q = p + 25;
    int r = p - 25;
    c[0] = 0 + at[0] * 50;

    for (i = 1; i <= n; i++)
    {
	c[i] = c[i - 1] + (50 * bt[i - 1]);
    }
    for (i = 0; i < n; i++)
	ap[i] = ((c[i] + c[i + 1]) - 10) / 2;

    for (i = 0; i <= z; i++)
    {
	glColor3fv(color[i]);
	glBegin(GL_QUADS);
	glVertex2f(c[i], q);
	glVertex2f(c[i + 1], q);
	glVertex2f(c[i + 1], r);
	glVertex2f(c[i], r);
	glEnd();
    }

    glColor3f(1.0, 1.0, 0.0);
    for (i = 0; i <= z; i++)
    {
	arrow(ap[i], p + 50);
	//	pnos();
	print(ap[i] - 10, p + 180, 0, p);
	//	for(j=0;j<n;j++)
	//	prints(ap[i]-10,p+185,"pj");
    }

    //	glFlush();
    //delay();
}

//delay
/* void delay()
{
  	for(i=0;i<100;i++)
  	for(j=0;j<100;j++);
}

*/

void time()
{
	float wt[10],tat[10],a=0,b=0;
	wt[0]=0;
	tat[0]=wt[0];
	for(i=0;i<n;i++)
	{
	wt[i]=wt[i-1]+v[i-1];
	tat[i]=wt[i]+v[i];
    }
    
    for(i=0;i<n;i++)
    {
    	a=a+wt[i];
    	b=b+tat[i];
    }
	
	avgwt=a/n;
	avgtat=b/n;

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
	glColor3f(1.0,1.0,0.0);
	prints(-70,900,"Left Click - Next Process");
	prints(800,900,"Right Click - Menu");
	prints(500,s-1000,"E-exit");
	prints(100,s-100,"total time: ");
	sprintf(st,"%d",sum);
    prints(200,s-100,st);
	
	glColor3f(1.0, 0.0, 0.0);
	tab();
	numberline();
	glColor3f(0.0, 1.0, 0.0);
	printss(0, 600, "DISPLAY  OF  GANTT  CHART  FOR  FCFS");
	glColor3f(0.5, 0.8, 0.8);
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0, 570);
	glVertex2f(520, 570);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	prints(50, 325, "PROCESS NO");
	prints(260, 325, "ARRIVAL TIME");
	prints(480, 325, "BURST TIME");
	//
	glColor3f(0.0, 1.0, 0.0);
	printss(0, s - 300, "GANTT-CHART");
	glColor3f(0.5, 0.8, 0.8);
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0, s - 320);
	glVertex2f(170, s - 320);
	glEnd();

//	glColor3f(1.0, 0.0, 0.6);
	/*for(i=0;i<n;i++)
	{
		while(i==at[i])
		arrow(i,s-470);
	}
	*/
	glColor3f(1.0, 1.0, 0.0);
	//	arrow(100,-170);
	for (i = 0; i < n; i++)
	{
	    print(113, (450 + s / n) / 2 - i * 58, 0, i);
	    print(338, (450 + s / n) / 2 - i * 58, 0, u[i]);
	    print(550, (450 + s / n) / 2 - i * 58, 0, v[i]);
	}
	if (z >= 0)
	    gantt(z);

	///added here
	int tu[n];
	for (i = 0; i <= n; i++)
	    tu[i] = u[i];
	char p[3] = {"P"};
	int g, h;
	for (g = 0; g <= z; g++)
	    for (h = 0; h <= n; h++)
	    {

		if (at[g] == tu[h])
		{

		    p[1] = h + 48;
		    p[2] = '\0';
		    prints(ap[g], s - 480, p);
		    tu[h] = -1;

		    break;
		}
	    }

        
	if (z >= n - 1)
	{
		time();
	    prints(40, s-900, "Average Waiting Time: ");
	    sprintf(st,"%f",avgwt);
	    prints(220,s-900,st);
	    prints(640, s-900, "Average Turnaround Time: ");
	    sprintf(st,"%f",avgtat);
	    prints(860,s-900,st);
	}

	
    glFlush();
}

// mouse

void mouse(int btn, int state, int x, int y)
{
    
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
	if (z < n - 1)
	    z++;
    }
    glutPostRedisplay();
}

void menu_handler(int id)
{
    switch (id)
    {
    case 1:	count = 0;
			z = -1;
			display();
			break;

    case 2:	exit(0);
    }
}

void keyboard(unsigned char key ,int x,int y)
{
	if(key=='E'||'e')
	exit(0);
}

int main(int argc, char **argv)
{
    input();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1500, 1500);
    //	glutInitWindowPosition(0,0);
    glutCreateWindow("fcfs");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutCreateMenu(menu_handler);
    glutAddMenuEntry("Restart", 1);
    glutAddMenuEntry("Quit", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    init();
    glutMainLoop();
    return 0;
}
