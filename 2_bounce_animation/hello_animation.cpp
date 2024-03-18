﻿// hello_cg.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <functional>
#include <iostream>
#include <common/thunks.hpp>
#include <gl/glut.h>

using namespace lunaticpp;

//#define Func2Callback(funcObj) thunk<&decltype(funcObj)::operator()>(&funcObj).func()
#define AThunk(name, funcObj) thunk<&decltype(funcObj)::operator()> ##name(&funcObj)

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("Simple");

    GLfloat x1 = 0.0f;
    GLfloat y1 = 0.0f;
    GLfloat rsize = 25.0f;

    GLfloat xstep = 1.0f;
    GLfloat ystep = 1.0f;

    GLfloat windowWidth;
    GLfloat windowHeight;

    auto funcDisply = [&]()
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(1.0, 0, 0);
            glRectf(x1, y1, x1 + rsize, y1 - rsize);        
            glutSwapBuffers();
        };
    AThunk(thunkDisply, funcDisply);
    glutDisplayFunc(
        thunkDisply.func()
    );

    auto funcReshape = [&](int w, int h)
        {
            glViewport(0, 0, w, h);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            auto aspectRatio = (float)w / (float)h;
            if (w <= h)
                glOrtho(-50, 50, -50 / aspectRatio, 50 / aspectRatio, -1, 1);
            else
                glOrtho(-50 * aspectRatio, 50 * aspectRatio, -50, 50, -1, 1);

            windowWidth = w;
            windowHeight = h;

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
        };
    AThunk(thunkResape, funcReshape);
	glutReshapeFunc(thunkResape.func());

    std::function<void(int)> funcTimer;
    AThunk(thunkTimer, funcTimer);

    funcTimer = [&](int value)
        {
            x1 += xstep;
            y1 += ystep;
    
            if (x1 > 50 - rsize || x1 < -50)
                xstep = -xstep;
            if (y1 > 50 || y1 < -50 + rsize)
                ystep = -ystep;
    
            glutPostRedisplay();
            glutTimerFunc(100, thunkTimer.func() , 1);
        };    
    glutTimerFunc(100, thunkTimer.func(), 1);

    glClearColor(0, 0, 1.0, 1);
    glFlush();

    glutMainLoop();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
