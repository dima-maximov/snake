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
    /*
    int width_field = 500;
    int height_field = 500;
    int cell = 50;
    int box_x = width_field/cell;
    int box_y = height_field/cell;

    cout << "количество квадратов: "    << box_x*box_y <<endl;
    cout << "количество в 1-м столбе: " << box_y << endl;
    cout << "количество в 1-й строке: " << box_x << endl;
    cout << "ширина и высота квадрата : " << cell <<endl;

    field = cvCreateImage(cvSize(width_field, height_field), 8, 3);

    cvSet(field, cvScalar(255, 255, 255));
    */


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

void drawFood(IplImage *img,int cell, int box_x , int box_y,CvPoint &appel, int r,int g,int b)
{

    r = (rand() % 200) + 25;
    g = (rand() % 200) + 25;
    b = (rand() % 200) + 25;
    int appel_x = rand() % box_x;
    int appel_y = rand() % box_y;
    appel.x = appel_x * cell+cell/2;
    appel.y = appel_y * cell+cell/2;
    cvCircle(img, appel, 10, CV_RGB(r, g, b), -1, 8);
    //   cout <<appel.x <<" - "<< appel.y<< endl;

    // cvCircle(img, appel, 5, CV_RGB(0, 0, 0), 1, 8);
    // яблоко размещаем рандомом
    // случайным образом назначаем строку и столбик

    // лишь бы на самой змее


}

void drawSnake(vector<CvPoint> *body)
{

}

void moveSnake( char c,int stop,CvPoint cir,int cell, IplImage *currFrame)
{
    char cc = cvWaitKey(stop);

    if(cc==83)
        c=cc;

    if(cc==82)
        c=cc;

    if(cc==81)
        c=cc;

    if(cc==84)
        c=cc;

    //если нажата стрелка вправо то двигаемся вправо
    if ( c == 83 )
    {
        cir.x = cir.x + cell;
    }

    //если нажата стрелка вниз то двигаемся вниз
    if ( c == 84)
    {
        cir.y = cir.y + cell;
    }

    //если нажата стрелка влево то двигаемся влево
    if ( c == 81)
    {
        cir.x = cir.x - cell;
    }

    //если нажата стрелка вверх то двигаемся вверх
    if ( c == 82)
    {
        cir.y = cir.y - cell;
    }
    cvCircle(currFrame, cvPoint (cir.x , cir.y), 3, CV_RGB( 250, 0, 0), -1, 8);



}

int main()
{
    ushort stop = 200;         // задержка между кадрами
    IplImage *currFrame = 0;
    IplImage *field = 0;
    CvPoint appel;
    vector<CvPoint> body;           // для хранения элементов тела змеи
    CvPoint cir;

    int finish = 30;
    char c = 83;
    int width_field = 500;
    int height_field = 500;
    int cell = 50;
    int box_x = width_field/cell;
    int box_y = height_field/cell;

    cout << "количество квадратов: "    << box_x*box_y <<endl;
    cout << "количество в 1-м столбе: " << box_y << endl;
    cout << "количество в 1-й строке: " << box_x << endl;
    cout << "ширина и высота квадрата : " << cell <<endl;

    field = cvCreateImage(cvSize(width_field, height_field), 8, 3);
    cvSet(field, cvScalar(255, 255, 255));
    currFrame = cvCreateImage(cvSize(width_field, height_field), 8, 3);

    drawField( field, cell, box_x, box_y );                    // должен возвращать картинку

    const char * nwPlayField = "Змейка";
    cvNamedWindow( nwPlayField );

    cvRectangle(field, cvPoint( 0,0), cvPoint(width_field, height_field), cvScalar(0, 0, 0),5);
    cir.x = (rand() % box_x/2)+2;
    cir.x =cir.x * cell/2;
    cir.y = (rand() % box_y/2)+2;
    cir.y = cir.y * cell/2;
    int appel_x = rand() % box_x;
    int appel_y = rand() % box_y;
    appel.x = appel_x * cell+cell/2;
    appel.y = appel_y * cell+cell/2;
    int r, g, b;
    int number_of_apples = 0;
    cvCircle(field, appel, 10, CV_RGB(11, 111, 222), -1, 8);
    cout <<appel.x <<" "<< appel.y<<"          "<<number_of_apples<<"/"<<finish <<endl;

    while(1)
    {
        cvCopyImage( field, currFrame );

        if (appel.x == cir.x && appel.y == cir.y  )
        {
            cvFloodFill(field, appel, cvScalar(255, 255, 255));

            drawFood(field,cell,box_x,box_y,appel, r, g, b);
            number_of_apples++;
            stop = stop - 5;
            cout <<appel.x <<" "<< appel.y<<"          "<<number_of_apples<<"/"<<finish <<endl;

        }
        if (number_of_apples == finish - 1)
        {
            cvCircle(currFrame, cvPoint (appel.x , appel.y), 16, CV_RGB( 0, 250, 0), 2, 8);
            cvCircle(currFrame, cvPoint (appel.x , appel.y), 13, CV_RGB( 0, 0, 250), 2, 8);
            cvCircle(currFrame, cvPoint (appel.x , appel.y), 10, CV_RGB( 225, 0, 0), 2, 8);
        }

        char cc = cvWaitKey(stop);

        if(cc==83)
            c=cc;

        if(cc==82)
            c=cc;

        if(cc==81)
            c=cc;

        if(cc==84)
            c=cc;

        //если нажата стрелка вправо то двигаемся вправо
        if ( c == 83 )
        {
            cir.x = cir.x + cell;
        }

        //если нажата стрелка вниз то двигаемся вниз
        if ( c == 84)
        {
            cir.y = cir.y + cell;
        }

        //если нажата стрелка влево то двигаемся влево
        if ( c == 81)
        {
            cir.x = cir.x - cell;
        }

        //если нажата стрелка вверх то двигаемся вверх
        if ( c == 82)
        {
            cir.y = cir.y - cell;
        }

        cvCircle(currFrame, cvPoint (cir.x , cir.y), 25, CV_RGB( 250, 0, 0), -1, 8);
        cvShowImage( nwPlayField, currFrame );

        if (cc == 27||finish == number_of_apples||cir.x < 0 || cir.x  == width_field || cir.x > width_field || cir.y < 0 || cir.y == height_field || cir.y > height_field)
        {
            break;
        }
    }
    //    IplImage* fin = cvCreateImage(cvSize(width_field, height_field), 8, 3);
    //   cvSet(fin, cvScalar(0, 0, 0));

    // задаём точку для вывода текста
    CvPoint pt = cvPoint( height_field/4, width_field/2 );

    // инициализация шрифта
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
