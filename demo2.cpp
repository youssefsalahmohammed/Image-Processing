// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;


unsigned char image[SIZE][SIZE];
unsigned char image_NewArray[SIZE][SIZE];


unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char image4[SIZE][SIZE];



unsigned char image_RGB[SIZE][SIZE][RGB];
unsigned char image_RGB_NewArray[SIZE][SIZE][RGB];

unsigned char image1_RGB[SIZE][SIZE][RGB];
unsigned char image2_RGB[SIZE][SIZE][RGB];
unsigned char image3_RGB[SIZE][SIZE][RGB];
unsigned char image4_RGB[SIZE][SIZE][RGB];





//functions for gray picture :

void loadImage ();
void loadImage_NewArray ();
void i_did_SomethingForImage ();
void saveImage_NewArray ();

//functions for colored picture :

void loadImage_RGB ();
void loadImage_RGB_NewArray ();
void i_did_SomethingForImage_RGB ();
void saveImage_RGB_NewArray ();



int main()
{
    int grayOrcolor;
    cout<<"what do you want ya user ya habibi \n (1)colored picture \n (2)gray picture"<<endl;
    cin>>grayOrcolor;
    if(grayOrcolor==1)
    {

        loadImage_RGB ();
        loadImage_RGB_NewArray ();
        i_did_SomethingForImage_RGB ();
        saveImage_RGB_NewArray ();
    }



    if(grayOrcolor==2)
    {
        loadImage ();
        loadImage_NewArray ();
        i_did_SomethingForImage ();
        saveImage_NewArray ();
    }

    return 0;
}




//for gray picture:
void loadImage ()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}


void loadImage_NewArray()
{
    char image_NewArrayFileName[100];

    // Get gray scale image file name

    // Add to it .bmp extension and load image

    readGSBMP(image_NewArrayFileName, image_NewArray);
}



void saveImage_NewArray ()
{
    char image_NewArrayFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> image_NewArrayFileName;

    // Add to it .bmp extension and load image
    strcat (image_NewArrayFileName, ".bmp");

    writeGSBMP(image_NewArrayFileName, image_NewArray);
}



void i_did_SomethingForImage()
{

    int whichFliter;
    cout<<"which filter do you want ya user ya habibi?? \n (1) Rotate \n (2) Invert Image \n (3) Enlarge Image \n 4)shuffle "<<endl;
    cin>>whichFliter;
    if(whichFliter==1)
    {
        //note that : for 180 enter 3, for 90 enter 2, for 270 enter 1
        int num;
        cout<<"Bos ya user ya habibi note that : \n (1) for 270 daraga Rotate \n (2) for 90 daraga Rotate \n (3) for 180 daraga Rotate "<<endl;
        cin>>num;

        if(num==1)
        {
            for (int i = 0; i <SIZE; i++)
            {
                for (int j = 0; j<SIZE; j++)
                {

                    image_NewArray[i][j]=image[j][255-i];
                }
            }
        }

        if(num==2)
        {
            for (int i = 0; i <SIZE; i++)
            {
                for (int j = 0; j<SIZE; j++)
                {

                    image_NewArray[i][j]=image[255-j][i];
                }
            }

        }

        if(num==3)
        {
            for (int i = 0; i <SIZE; i++)
            {
                for (int j = 0; j<SIZE; j++)
                {

                    image_NewArray[i][j]=image[255-i][255-j];
                }
            }

        }

    }





    if(whichFliter==2)
    {
        for (int i = 0; i <SIZE; i++)
        {
            for (int j = 0; j<SIZE; j++)
            {

                image_NewArray[i][j]=255-image[i][j];
            }
        }

    }


    if(whichFliter==3)
    {
        int which_part;
        cout<<"ahlan ya user ya habibi which part you want to enlarge : \n 1) part 1 \n 2) part 2 \n 3) part 3 \n 4) part 4 "<<endl;
        cin>>which_part;
        if(which_part==1)
        {

            for(int i=0,k=0 ; i<SIZE/2,k<SIZE/2 ; k++,i++)
            {
                for(int j=0,x=0 ; j<SIZE/2,x<SIZE/2 ; x++, j++)
                {
                    image[k][x]=image[i][j];
                }
            }


            for(int i=0 ; i<SIZE ; i++)
            {
                for(int j=0 ; j<SIZE; j++)
                {
                    image_NewArray[i][j]=image[i/2][(j-1)/2];
                    image_NewArray[i][j+1]=image[i][j-1];
                }
            }
        }





        if(which_part==2)
        {
            for(int i=0,k=0 ; i<SIZE/2,k<SIZE/2 ; k++,i++)
            {
                for(int j=SIZE/2,x=0 ; j<SIZE,x<SIZE/2 ; x++, j++)
                {
                    image[k][x]=image[i][j];
                }
            }


            for(int i=0 ; i<SIZE ; i++)
            {
                for(int j=0 ; j<SIZE; j++)
                {
                    image_NewArray[i][j]=image[i/2][(j-1)/2];
                    image_NewArray[i][j+1]=image[i][j-1];
                }
            }



        }
        if(which_part==3)
        {

            for(int i=SIZE/2,k=0 ; i<SIZE,k<SIZE/2 ; k++,i++)
            {
                for(int j=0,x=0 ; j<SIZE/2,x<SIZE/2 ; x++, j++)
                {
                    image[k][x]=image[i][j];
                }
            }


            for(int i=0 ; i<SIZE ; i++)
            {
                for(int j=0 ; j<SIZE; j++)
                {
                    image_NewArray[i][j]=image[i/2][(j-1)/2];
                    image_NewArray[i][j+1]=image[i][j-1];
                }
            }





        }
        if(which_part==4)
        {

            for(int i=SIZE/2,k=0 ; i<SIZE,k<SIZE/2 ; k++,i++)
            {
                for(int j=SIZE/2,x=0 ; j<SIZE,x<SIZE/2 ; x++, j++)
                {
                    image[k][x]=image[i][j];
                }
            }


            for(int i=0 ; i<SIZE ; i++)
            {
                for(int j=0 ; j<SIZE; j++)
                {
                    image_NewArray[i][j]=image[i/2][(j-1)/2];
                    image_NewArray[i][j+1]=image[i][j-1];
                }
            }
        }
    }
    if(whichFliter==4)
    {
        for(int i=0,k=0 ; i<SIZE/2,k<SIZE/2 ; k++,i++)
        {
            for(int j=0,x=0 ; j<SIZE/2,x<SIZE/2 ; x++, j++)
            {
                image[k][x]=image[i][j];
            }
        }



        for(int i=0 ; i<SIZE ; i++)
        {
            for(int j=0 ; j<SIZE; j++)
            {
                image1[i][j]=image[i][j];

            }
        }





//for part 2:


        for(int i=0,k=0 ; i<SIZE/2,k<SIZE/2 ; k++,i++)
        {
            for(int j=SIZE/2,x=0 ; j<SIZE,x<SIZE/2 ; x++, j++)
            {
                image[k][x]=image[i][j];
            }
        }


        for(int i=0 ; i<SIZE ; i++)
        {
            for(int j=0 ; j<SIZE; j++)
            {
                image2[i][j]=image[i][j];

            }
        }

//for part 3 :



        for(int i=SIZE/2,k=0 ; i<SIZE,k<SIZE/2 ; k++,i++)
        {
            for(int j=0,x=0 ; j<SIZE/2,x<SIZE/2 ; x++, j++)
            {
                image[k][x]=image[i][j];
            }
        }


        for(int i=0 ; i<SIZE ; i++)
        {
            for(int j=0 ; j<SIZE; j++)
            {
                image3[i][j]=image[i][j];

            }
        }


        //for part 4 :



        for(int i=SIZE/2,k=0 ; i<SIZE,k<SIZE/2 ; k++,i++)
        {
            for(int j=SIZE/2,x=0 ; j<SIZE,x<SIZE/2 ; x++, j++)
            {
                image[k][x]=image[i][j];
            }
        }


        for(int i=0 ; i<SIZE ; i++)
        {
            for(int j=0 ; j<SIZE; j++)
            {
                image4[i][j]=image[i][j];

            }
        }

        //for filter :

        for(int i=0 ; i<SIZE/2 ; i++)
        {
            for(int j=0 ; j<SIZE/2; j++)
            {
                image_NewArray[i][j]=image4[i][j];
                image_NewArray[i][j+(SIZE/2)]=image3[i][j];
                image_NewArray[i+(SIZE/2)][j+SIZE]=image2[i][j];
                image_NewArray[i+(SIZE/2)][j+(SIZE/2)]=image1[i][j];

            }
        }


    }
}

//for colored picture:
void loadImage_RGB ()
{
    char image_RGBFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> image_RGBFileName;

    // Add to it .bmp extension and load image
    strcat (image_RGBFileName, ".bmp");
    readRGBBMP(image_RGBFileName, image_RGB);
}

void loadImage_RGB_NewArray ()
{
    char image_RGB_NewArrayFileName[100];



    readRGBBMP(image_RGB_NewArrayFileName, image_RGB_NewArray);
}

void saveImage_RGB_NewArray ()
{
    char image_RGB_NewArrayFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> image_RGB_NewArrayFileName;

    // Add to it .bmp extension and load image
    strcat (image_RGB_NewArrayFileName, ".bmp");
    writeRGBBMP(image_RGB_NewArrayFileName,image_RGB_NewArray );
}


void i_did_SomethingForImage_RGB()
{

    int whichFliter;
    cout<<"which filter do you want ya user ya habibi?? \n (1) Rotate \n (2) Invert Image \n (3) Enlarge Image \n 4)shuffle "<<endl;
    cin>>whichFliter;
    if(whichFliter==1)
    {
        int num;
        cout<<"Bos ya user ya habibi note that : \n (1) for 270 daraga Rotate \n (2) for 90 daraga Rotate \n (3) for 180 daraga Rotate"<<endl;
        cin>>num;

        if(num==1)
        {
            for (int i = 0; i <SIZE; i++)
            {
                for (int j = 0; j<SIZE; j++)
                {
                    for(int k=0 ; k<3 ; k++)
                    {
                        image_RGB_NewArray[i][j][k]=image_RGB[j][255-i][k];

                    }


                }
            }
        }

        if(num==2)
        {
            for (int i = 0; i <SIZE; i++)
            {
                for (int j = 0; j<SIZE; j++)
                {
                    for(int k=0 ; k<3 ; k++)
                    {
                        image_RGB_NewArray[i][j][k]=image_RGB[255-j][i][k];

                    }


                }
            }

        }

        if(num==3)
        {
            for (int i = 0; i <SIZE; i++)
            {
                for (int j = 0; j<SIZE; j++)
                {
                    for(int k=0 ; k<3 ; k++)
                    {
                        image_RGB_NewArray[i][j][k]=image_RGB[255-i][255-j][k];
                    }


                }
            }

        }

    }





    if(whichFliter==2)
    {
        for (int i = 0; i <SIZE; i++)
        {
            for (int j = 0; j<SIZE; j++)
            {
                for(int k=0 ; k<3; k++)
                {
                    image_RGB_NewArray[i][j][k]=255-image_RGB[i][j][k];

                }


            }
        }

    }


    if(whichFliter==3)
    {
        int which_part;
        cout<<"ahlan ya user ya habibi which part you want to enlarge : \n 1) part 1 \n 2) part 2 \n 3) part 3 \n 4) part 4 "<<endl;
        cin>>which_part;

        if(which_part==1)
        {

            for(int i=0,k=0 ; i<SIZE/2,k<SIZE/2 ; k++,i++)
            {
                for(int j=0,x=0 ; j<SIZE/2,x<SIZE/2 ; x++, j++)
                {
                    for(int f=0 ; f<3 ; f++)
                    {
                        image_RGB[k][x][f]=image_RGB[i][j][f];
                    }

                }
            }


            for(int i=0 ; i<SIZE ; i++)
            {
                for(int j=0 ; j<SIZE; j++)
                {
                    for(int f=0 ; f<3 ; f++)
                    {
                        image_RGB_NewArray[i][j][f]=image_RGB[i/2][(j-1)/2][f];
                        image_RGB_NewArray[i][j+1][f]=image_RGB[i][j-1][f];
                    }

                }
            }
        }





        if(which_part==2)
        {
            for(int i=0,k=0 ; i<SIZE/2,k<SIZE/2 ; k++,i++)
            {
                for(int j=SIZE/2,x=0 ; j<SIZE,x<SIZE/2 ; x++, j++)
                {
                    for(int f=0 ; f<3 ; f++)
                    {
                        image_RGB[k][x][f]=image_RGB[i][j][f];
                    }

                }
            }


            for(int i=0 ; i<SIZE ; i++)
            {
                for(int j=0 ; j<SIZE; j++)
                {
                    for(int f=0 ; f<3 ; f++)
                    {
                        image_RGB_NewArray[i][j][f]=image_RGB[i/2][(j-1)/2][f];
                        image_RGB_NewArray[i][j+1][f]=image_RGB[i][j-1][f];
                    }

                }
            }



        }

        if(which_part==3)
        {

            for(int i=SIZE/2,k=0 ; i<SIZE,k<SIZE/2 ; k++,i++)
            {
                for(int j=0,x=0 ; j<SIZE/2,x<SIZE/2 ; x++, j++)
                {
                    for(int f=0 ; f<3 ; f++)
                    {
                        image_RGB[k][x][f]=image_RGB[i][j][f];

                    }

                }
            }


            for(int i=0 ; i<SIZE ; i++)
            {
                for(int j=0 ; j<SIZE; j++)
                {
                    for(int f=0 ; f<3 ; f++)
                    {
                        image_RGB_NewArray[i][j][f]=image_RGB[i/2][(j-1)/2][f];
                        image_RGB_NewArray[i][j+1][f]=image_RGB[i][j-1][f];

                    }



                }
            }





        }
        if(which_part==4)
        {

            for(int i=SIZE/2,k=0 ; i<SIZE,k<SIZE/2 ; k++,i++)
            {
                for(int j=SIZE/2,x=0 ; j<SIZE,x<SIZE/2 ; x++, j++)
                {
                    for(int f=0 ; f<3 ; f++)
                    {
                        image_RGB[k][x][f]=image_RGB[i][j][f];

                    }


                }
            }


            for(int i=0 ; i<SIZE ; i++)
            {
                for(int j=0 ; j<SIZE; j++)
                {
                    for(int f=0 ; f<3 ; f++)
                    {
                        image_RGB_NewArray[i][j][f]=image_RGB[i/2][(j-1)/2][f];
                        image_RGB_NewArray[i][j+1][f]=image_RGB[i][j-1][f];

                    }

                }
            }
        }


    }
    if(whichFliter==4)
    {
        for(int i=0,k=0 ; i<SIZE/2,k<SIZE/2 ; k++,i++)
        {
            for(int j=0,x=0 ; j<SIZE/2,x<SIZE/2 ; x++, j++)
            {
                 for(int f=0 ;f<3 ;f++)
                 {
                    image_RGB[k][x][f]=image_RGB[i][j][f];
                 }
            }
        }



        for(int i=0 ; i<SIZE ; i++)
        {
            for(int j=0 ; j<SIZE; j++)
            {
                 for(int f=0 ;f<3 ;f++)
                 {
                     image1_RGB[i][j][f]=image_RGB[i][j][f];
                 }

            }
        }





//for part 2:


        for(int i=0,k=0 ; i<SIZE/2,k<SIZE/2 ; k++,i++)
        {
            for(int j=SIZE/2,x=0 ; j<SIZE,x<SIZE/2 ; x++, j++)
            {
                 for(int f=0 ;f<3 ;f++)
                 {
                     image_RGB[k][x][f]=image_RGB[i][j][f];
                 }
            }
        }


        for(int i=0 ; i<SIZE ; i++)
        {
            for(int j=0 ; j<SIZE; j++)
            {
                 for(int f=0 ;f<3 ;f++)
                 {
                      image2_RGB[i][j][f]=image_RGB[i][j][f];
                 }

            }
        }

//for part 3 :



        for(int i=SIZE/2,k=0 ; i<SIZE,k<SIZE/2 ; k++,i++)
        {
            for(int j=0,x=0 ; j<SIZE/2,x<SIZE/2 ; x++, j++)
            {
                 for(int f=0 ;f<3 ;f++)
                 {
                     image_RGB[k][x][f]=image_RGB[i][j][f];
                 }
            }
        }


        for(int i=0 ; i<SIZE ; i++)
        {
            for(int j=0 ; j<SIZE; j++)
            {
                 for(int f=0 ;f<3 ;f++)
                 {
                     image3_RGB[i][j][f]=image_RGB[i][j][f];
                 }

            }
        }


        //for part 4 :



        for(int i=SIZE/2,k=0 ; i<SIZE,k<SIZE/2 ; k++,i++)
        {
            for(int j=SIZE/2,x=0 ; j<SIZE,x<SIZE/2 ; x++, j++)
            {
                 for(int f=0 ;f<3 ;f++)
                 {
                     image_RGB[k][x][f]=image_RGB[i][j][f];
                 }
            }
        }


        for(int i=0 ; i<SIZE ; i++)
        {
            for(int j=0 ; j<SIZE; j++)
            {
                 for(int f=0 ;f<3 ;f++)
                 {
                   image4_RGB[i][j][f]=image_RGB[i][j][f];
                 }

            }
        }

        //for filter :

        for(int i=0 ; i<SIZE/2 ; i++)
        {
            for(int j=0 ; j<SIZE/2; j++)
            {
                for(int f=0 ;f<3 ;f++)
                {
                    image_RGB_NewArray[i][j][f]=image4_RGB[i][j][f];
                    image_RGB_NewArray[i][j+(SIZE/2)][f]=image3_RGB[i][j][f];
                    image_RGB_NewArray[i+(SIZE/2)][j+SIZE][f]=image2_RGB[i][j][f];
                    image_RGB_NewArray[i+(SIZE/2)][j+(SIZE/2)][f]=image1_RGB[i][j][f];

                }


            }
        }

    }


}
