#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
void draw(void)
{
    // // for negative slope along x axis.
    // GLfloat x1 = 170, y1 = 130, x2 = 00, y2 = 00;

    // // |m| > 1
    // // positive slope.
    // GLfloat x1 = 100, y1 = 100, x2 = 200, y2 = 500;

    // // |m| = 1.
    // GLfloat x1 = 100, y1 = 100, x2 = 500, y2 = 500;

    // // |m| = 1. negative slope.
    // GLfloat x1 = 500, y1 = 500, x2 = 100, y2 = 100;

    // // |m| > 1. negative slope.
    // GLfloat x1 = 100, y1 = 500, x2 = 100, y2 = 100;

    // // |m| > 1. positive slope.
    // GLfloat x1 = 100, y1 = 100, x2 = 200, y2 = 500;

    GLfloat x1 = 100, y1 = 500, x2 = 100, y2 = 100;


    GLfloat dx, dy, temp, x, y, p, m;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);

    if((x2-x1) == 0)
    {
        m = y2 - y1;
    }
    else
    {
        m = (y2 - y1) / (x2 - x1);
    }
    printf("slope m: %f", fabs(m));
    // if slope less than 1
    if(fabs(m) < 1)
    {
        if(x1 > x2)
        {
            temp = x1;
            x1 = x2;
            x2 = temp;

            temp = y1;
            y1 = y2;
            y2 = temp;
        }

        dx = fabs(x2 - x1);
        dy = fabs(y2 - y1);

        p = 2 * dy - dx;

        x = x1;
        y = y1;

        glBegin(GL_POINTS);
            while(x <= x2)
            {
                glVertex2f(x, y);
                x = x + 1;
                if(p >= 1)
                {
                    if(m < 1)
                    {
                        y = y + 1;
                    }
                    else
                    {
                        y = y - 1;
                    }
                    p = p + 2 * dy - 2 * dx;
                }
                else
                {
                    y = y;
                    p = p + 2 * dy;
                }
            }
        glEnd();
    }

    // if slope greater than equal 1
    if(fabs(m) >= 1)
    {
        if(y1 > y2)
        {
            temp = x1;
            x1 = x2;
            x2 = temp;

            temp = y1;
            y1 = y2;
            y2 = temp;
        }

        dx = fabs(x2 - x1);
        dy = fabs(y2 - y1);

        p = 2 * dx - dy;

        x = x1;
        y = y1;

        glBegin(GL_POINTS);
            while(y <= y2)
            {
                glVertex2f(x, y);
                y = y + 1;
                if(p >= 1)
                {
                    if(m >= 1)
                    {
                        x = x + 1;
                    }
                    else
                    {
                        x = x - 1;
                    }
                    // x = x + 1;
                    p = p + 2 * dx - 2 * dy;
                }
                else
                {
                    x = x;
                    p = p + 2 * dx;
                }
            }
        glEnd();
    }
    glFlush();
}
void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Bresenhams Line Algo");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}