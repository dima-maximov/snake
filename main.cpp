#include <stdlib.h>
#include <stdio.h>
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <vector> // подключаем модель Векторов
#include <iterator> // заголовочный файл итераторов

using namespace std;

void drawField(IplImage *field, int cell, int box_x, int box_y)
{

    CvPoint point_1;
    CvPoint point_2;
    point_1.x = 0;
    point_1.y = 0;
    point_2.x = cell;
    point_2.y = cell;

    for (int i = 0; i < box_y; i++)
    {
        for (int j = 0; j < box_x; j++)
        {
            cvRectangle(field, cvPoint( point_1.x, point_1.y), cvPoint( point_2.x, point_2.y), cvScalar(1, 1, 1));
            point_1.x = point_1.x + cell;
            point_2.x = point_2.x + cell;
        }

        point_1.x = 0;
        point_2.x = cell;
        point_1.y = point_1.y + cell;
        point_2.y = point_2.y + cell;
    }

}

void drawFood(IplImage *img,int cell, int box_x , int box_y,CvPoint &appel, int r,int g,int b, int &ran)
{
    for (int i = 0; i < ran; i++)
    {
        r = (rand() % 200) + 25;
        g = (rand() % 200) + 25;
        b = (rand() % 200) + 25;
        int appel_x = rand() % box_x;
        int appel_y = rand() % box_y;
        appel.x = appel_x * cell+cell/2;
        appel.y = appel_y * cell+cell/2;
    }

    cvCircle(img, appel, 10, CV_RGB(r, g, b), -1, 8);
}

void drawSnake(vector<CvPoint> &body, IplImage *currFrame, int &number_of_apples)
{
    //перемещение тела на место тела кот. было перед ним
    body.at(23) = body.at(22);
    body.at(22) = body.at(21);
    body.at(21) = body.at(20);
    body.at(20) = body.at(19);
    body.at(19) = body.at(18);
    body.at(18) = body.at(17);
    body.at(17) = body.at(16);
    body.at(16) = body.at(15);
    body.at(15) = body.at(14);
    body.at(14) = body.at(13);
    body.at(13) = body.at(12);
    body.at(12) = body.at(11);
    body.at(11) = body.at(10);
    body.at(10) = body.at(9);
    body.at(9) = body.at(8);
    body.at(8) = body.at(7);
    body.at(7) = body.at(6);
    body.at(6) = body.at(5);
    body.at(5) = body.at(4);
    body.at(4) = body.at(3);
    body.at(3) = body.at(2);
    body.at(2) = body.at(1);
    body.at(1) = body.at(0);

    cvCircle( currFrame, body.at(1), 20, CV_RGB( 250, 250, 0), -1, 8);
    cvCircle( currFrame, body.at(2), 20, CV_RGB( 250, 250, 0), -1, 8);

    // создаем тело после съеденного яблока
    if (number_of_apples > 0)
    {
        cvCircle( currFrame, body.at( 3 ), 20, CV_RGB( 10, 110, 110), -1, 8);
    }
    if (number_of_apples > 1)
    {
        cvCircle( currFrame, body.at( 4 ), 20, CV_RGB( 10, 210, 210), -1, 8);
    }
    if (number_of_apples > 2)
    {
        cvCircle( currFrame, body.at( 5 ), 20, CV_RGB( 210, 10, 110), -1, 8);
    }
    if (number_of_apples > 3)
    {
        cvCircle( currFrame, body.at( 6 ), 20, CV_RGB( 150, 10, 110), -1, 8);
    }
    if (number_of_apples > 4)
    {
        cvCircle( currFrame, body.at( 7 ), 20, CV_RGB( 210, 20, 10), -1, 8);
    }
    if (number_of_apples > 5)
    {
        cvCircle( currFrame, body.at( 8 ), 20, CV_RGB( 210, 10, 210), -1, 8);
    }
    if (number_of_apples > 6)
    {
        cvCircle( currFrame, body.at( 9 ), 20, CV_RGB( 10, 210, 110), -1, 8);
    }
    if (number_of_apples > 7)
    {
        cvCircle( currFrame, body.at( 10 ), 20, CV_RGB( 160, 150, 110), -1, 8);
    }
    if (number_of_apples > 8)
    {
        cvCircle( currFrame, body.at( 11 ), 20, CV_RGB( 70, 160, 210), -1, 8);
    }
    if (number_of_apples > 9)
    {
        cvCircle( currFrame, body.at( 12 ), 20, CV_RGB( 100, 10, 210), -1, 8);
    }
    if (number_of_apples > 10)
    {
        cvCircle( currFrame, body.at( 13 ), 20, CV_RGB( 0, 210, 210), -1, 8);
    }
    if (number_of_apples > 11)
    {
        cvCircle( currFrame, body.at( 14 ), 20, CV_RGB( 210, 210, 20), -1, 8);
    }
    if (number_of_apples > 12)
    {
        cvCircle( currFrame, body.at( 15 ), 20, CV_RGB( 70, 80, 110), -1, 8);
    }
    if (number_of_apples > 13)
    {
        cvCircle( currFrame, body.at( 16 ), 20, CV_RGB( 150, 10, 110), -1, 8);
    }
    if (number_of_apples > 14)
    {
        cvCircle( currFrame, body.at( 17 ), 20, CV_RGB( 210, 20, 210), -1, 8);
    }
    if (number_of_apples > 15)
    {
        cvCircle( currFrame, body.at( 18 ), 20, CV_RGB( 250, 110, 10), -1, 8);
    }
    if (number_of_apples > 16)
    {
        cvCircle( currFrame, body.at( 19 ), 20, CV_RGB( 10, 200, 240), -1, 8);
    }
    if (number_of_apples > 17)
    {
        cvCircle( currFrame, body.at( 20 ), 20, CV_RGB( 100, 250, 200), -1, 8);
    }
    if (number_of_apples > 18)
    {
        cvCircle( currFrame, body.at( 21 ), 20, CV_RGB( 0, 250, 170), -1, 8);
    }
    if (number_of_apples > 19)
    {
        cvCircle( currFrame, body.at( 22 ), 20, CV_RGB( 90, 0, 120), -1, 8);
    }

}

void moveSnake( char &dir, vector<CvPoint> &body, int cell)
{
    //cout << "cc = " << (int)cc << " c = " << (int)c << endl;
    //cout.flush();

    //если нажата стрелка вправо то двигаемся вправо
    if ( dir == 83 )
        body.at(0).x = body.at(0).x + cell;

    //если нажата стрелка вниз то двигаемся вниз
    if ( dir == 84)
        body.at(0).y = body.at(0).y + cell;

    //если нажата стрелка влево то двигаемся влево
    if ( dir == 81)
        body.at(0).x = body.at(0).x - cell;

    //если нажата стрелка вверх то двигаемся вверх
    if ( dir == 82)
        body.at(0).y = body.at(0).y - cell;

}
void end_snake(char &direc, int &finish, int &number_of_apples, vector<CvPoint> &body, int &width_field, int &height_field, int &exit)
{
    // условия выхода из цикла
    if (direc == 27 || finish == number_of_apples || body.at(0).x < 0 || body.at(0).x  == width_field || body.at(0).x > width_field || body.at(0).y < 0 || body.at(0).y == height_field || body.at(0).y > height_field)
    {
        exit=1;
    }
    //проигрыш в случае если голова повернет в сторону тела
    if (( body.at(2).x == body.at(0).x  && body.at(2).y == body.at(0).y )||( body.at(1).x == body.at(0).x  && body.at(1).y == body.at(0).y))
    {
        exit=1;
    }
    //выходим если созданное  тело после съеденного яблока пересечется с головой
    if ((( number_of_apples > 1 )&&( body.at ( 4 ).x == body.at(0).x  && body.at ( 4).y == body.at(0).y )) ||
            ((number_of_apples > 2)&&(body.at ( 5 ).x == body.at(0).x  && body.at ( 5 ).y == body.at(0).y))||
            ((number_of_apples > 3)&&(body.at ( 6 ).x == body.at(0).x  && body.at ( 6 ).y == body.at(0).y))||
            ((number_of_apples > 4)&&(body.at ( 7 ).x == body.at(0).x  && body.at ( 7 ).y == body.at(0).y))||
            ((number_of_apples > 5)&&(body.at ( 8 ).x == body.at(0).x  && body.at ( 8 ).y == body.at(0).y))||
            ((number_of_apples > 6)&&(body.at ( 9 ).x == body.at(0).x  && body.at ( 9 ).y == body.at(0).y))||
            ((number_of_apples > 7)&&(body.at ( 10 ).x == body.at(0).x  && body.at ( 10 ).y == body.at(0).y))||
            ((number_of_apples > 8)&&(body.at ( 11 ).x == body.at(0).x  && body.at ( 11 ).y == body.at(0).y))||
            ((number_of_apples > 9)&&(body.at ( 12).x == body.at(0).x  && body.at ( 12 ).y == body.at(0).y))||
            ((number_of_apples > 10)&&(body.at ( 13 ).x == body.at(0).x  && body.at ( 13 ).y == body.at(0).y))||
            ((number_of_apples > 11)&&(body.at ( 14 ).x == body.at(0).x  && body.at ( 14 ).y == body.at(0).y))||
            ((number_of_apples > 12)&&(body.at ( 15 ).x == body.at(0).x  && body.at ( 15 ).y == body.at(0).y))||
            ((number_of_apples > 13)&&(body.at ( 16 ).x == body.at(0).x  && body.at ( 16 ).y == body.at(0).y))||
            ((number_of_apples > 14)&&(body.at ( 17 ).x == body.at(0).x  && body.at ( 17 ).y == body.at(0).y))||
            ((number_of_apples > 15)&&(body.at ( 18 ).x == body.at(0).x  && body.at ( 18 ).y == body.at(0).y))||
            ((number_of_apples > 16)&&(body.at ( 19 ).x == body.at(0).x  && body.at ( 19).y == body.at(0).y))||
            ((number_of_apples > 17)&&(body.at ( 20 ).x == body.at(0).x  && body.at ( 20 ).y == body.at(0).y))||
            ((number_of_apples > 18)&&(body.at ( 21).x == body.at(0).x  && body.at ( 21 ).y == body.at(0).y))||
            ((number_of_apples > 19)&&(body.at ( 22 ).x == body.at(0).x  && body.at ( 22 ).y == body.at(0).y))||
            ((number_of_apples > 0)&&(body.at ( 3 ).x == body.at(0).x  && body.at ( 3 ).y == body.at(0).y)))

    {
        exit=1;
    }
}
int main()
{
    ushort pause = 200;         // задержка между кадрами
    IplImage *currFrame = 0;
    IplImage *field = 0;
    CvPoint appel;
    vector<CvPoint> body;           // для хранения элементов тела змеи
    CvPoint head;

    int finish = 20;
    char direction = 83;
    int width_field = 500;
    int height_field = 500;
    int cell = 50;
    int box_x = width_field/cell;
    int box_y = height_field/cell;
    int exit = 0;

    cout << "количество квадратов: "    << box_x*box_y <<endl;
    cout << "количество в 1-м столбе: " << box_y << endl;
    cout << "количество в 1-й строке: " << box_x << endl;
    cout << "ширина и высота квадрата : " << cell <<endl;

    field = cvCreateImage( cvSize ( width_field, height_field) , 8, 3);
    cvSet( field, cvScalar( 255, 255, 255));
    currFrame = cvCreateImage( cvSize ( width_field, height_field) , 8, 3);

    drawField( field, cell, box_x, box_y );// должен возвращать картинку

    const char * nwPlayField = "Змейка";
    cvNamedWindow( nwPlayField );

    //Рисуем стену, и задаем случайные координаты головы и заносим их в вектор
    cvRectangle( field, cvPoint( 0,0), cvPoint( width_field, height_field), cvScalar(0, 0, 0),5);
    head.x = ( rand() % box_x/2)+2;
    head.x =head.x * cell/2;
    head.y = ( rand() % box_y/2)+2;
    head.y = head.y * cell/2;
    body.push_back( head );

    //создаем начальное тело змейки и пустые вектора
    for (int i = 0; i < finish + 5; i++)
    {
        head.x = head.x - cell;
        body.push_back( head );
    }

    //рисуем  1-е яблоко
    int appel_x = rand() % box_x;
    int appel_y = rand() % box_y;
    appel.x = appel_x * cell+cell/2;
    appel.y = appel_y * cell+cell/2;

    //r, g, b - цвет, number_of_apples - кол-во съединых яблок, рисуем 1-е яблоко
    int r, g, b;
    int number_of_apples = 0;
    cvCircle( field, appel, 10, CV_RGB(11, 111, 222), -1, 8);
    cout << appel.x << " " << appel.y << "          " << number_of_apples << "/" << finish << endl;

    //создаем рандом
    int ran=1;

    while(1)
    {
        cvCopyImage( field, currFrame );

        //создаем рандом для яблок
        ran++;
        if (ran == 100)ran = 1;

        // это условие выполняется, когда голова съедает яблоко
        if (appel.x == body.at(0).x  && appel.y == body.at(0).y  )
        {
            //присваиваем новому телу координаты яблока
            // body.push_back( appel );
            //body.push_back(body.at(t));

            //закрашиваем съеденное яблоко
            cvFloodFill(field, appel, cvScalar(255, 255, 255));

            // прибавить к туловищу змеи единицу
            //body
            // рисуем яблоко
            drawFood( field, cell, box_x, box_y, appel, r, g, b, ran);
            // считаем количество съеденных яблок
            number_of_apples++;
            // уменьшаем задержку(ускоряем змейку)
            pause = pause - 5;
            cout << appel.x << " " << appel.y << "          " <<number_of_apples << "/" << finish << endl;
        }
        // обводим последнее яблоко
        if ( number_of_apples == finish - 1)
        {
            cvCircle(currFrame, cvPoint (appel.x, appel.y), 16, CV_RGB( 0, 250, 0), 2, 8);
            cvCircle(currFrame, cvPoint (appel.x, appel.y), 13, CV_RGB( 0, 0, 250), 2, 8);
            cvCircle(currFrame, cvPoint (appel.x, appel.y), 10, CV_RGB( 225, 0, 0), 2, 8);
        }
        // управление змеей
        char direc = cvWaitKey( pause );
        if ( direc == 81 || direc == 82 || direc == 84 || direc == 83 )
            direction = direc;

        // перемещение змейки
        drawSnake( body, currFrame, number_of_apples);
        moveSnake( direction, body, cell);
        cvCircle(currFrame, body.at(0), 25, CV_RGB( 250, 0, 0), -1, 8);
        // конец змеи
        end_snake(direc, finish, number_of_apples, body, width_field, height_field, exit);
        if (exit == 1) break;

        cvShowImage( nwPlayField, currFrame );
    }

    // пишем текст взависимости от результата
    CvPoint pt = cvPoint( height_field/4, width_field/2 );
    CvFont font;

    if  (number_of_apples == finish )
    {
        cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX,3.0, 2.0, 0, 2, CV_AA);
        cvPutText(currFrame, "W I N", pt, &font, CV_RGB(255, 255, 0) );
    }
    else
    {
        cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX,2.0, 1.0, 0, 2, CV_AA);
        cvPutText(currFrame, "Game Over", pt, &font, CV_RGB(150, 0, 150) );
    }

    cvShowImage( nwPlayField, currFrame );
    cvWaitKey(10000);

    // освобождаем ресурсы
    cvReleaseImage(&field);
    cvReleaseImage(&currFrame);
    cvDestroyWindow(nwPlayField);

    return 0;
}
