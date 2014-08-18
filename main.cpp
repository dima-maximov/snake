#include <stdlib.h>
#include <stdio.h>
#include "opencv/cv.h"
#include "opencv/highgui.h"

using namespace std;

void field()
{
    IplImage* field = 0;
    IplImage* output = 0;

    int width_field = 500;
    int height_field = 500;
    int cell = 50;
    int box_x = width_field/cell;
    int box_y = height_field/cell;

    cout<<"количество квадратов: " <<box_x*box_y <<std::endl<<"количество в 1-м столбе: " <<box_y <<endl<<"количество в 1-й строке: " <<box_x <<endl <<"ширина и высота квадрата : " << cell <<endl;

    field = cvCreateImage(cvSize(width_field, height_field), 8, 3);

    cvSet(field, cvScalar(255, 255, 255));
    output = cvCloneImage(field);

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

    while(1)
    {
        char c = cvWaitKey(10);
        if (c == 27)        // если нажата ESC - выходим
        {
            break;
        }

        cvCopyImage( field, output );
        cvShowImage( "field", output );
    }

    // освобождаем ресурсы
    cvReleaseImage(&field);
    cvReleaseImage(&output);
    cvDestroyWindow("field");

}

void food()
{

}

void snake()
{

}

int main()
{
    field();
    return 0;
}

