// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: ImageFilters.cpp
// Last Modification Date: xx/xx/xxxx
// karim ElSakkary  and 20210301 and Group: xxxxx xxxxx
// Huda Samir and 20210443 and Group: xxxxx xxxxx
// Nada Mohamed and 20210422 and Group: xxxxx xxxxx
// Teaching Assistant: Nesma
// Purpose: create a program that take an image and add filters to it then save it

#include <iostream>
#include "bmplib.cpp"

void printImage();
char getOption();

void loadImage();
void blackWhite();
void invertImage();
void mergeImage();
void flipImage();
void darkenLightenImage();
void rotateImage();
void detectImageEdges();
void enlargeImage();
void shrinkImage();
void mirrorHalf();
void shuffleImage();
void blurImage();
void saveImage();

unsigned char image[256][256];
string imageName;
int main() {
    char op;
    loadImage();
    while(true){
        op = getOption();
        if(op=='0'){
            break;
        }
        switch (op) {
            case '1':
                blackWhite();
                break;
            case '2':

                break;
            case '3':

                break;
            case '4':

                break;
            case '5':

                break;
            case '6':

                break;
            case '7':

                break;
            case '8':

                break;
            case '9':

                break;
            case 'a':

                break;
            case 'b':

                break;
            case 'c':

                break;
            case 's':
                saveImage();
                break;
            case 'w':
                loadImage();
                break;
            default:
                break;
        }
        cout<<"done"<<endl;
        system("pause");
    }


    return 0;
}

char getOption() {
    char op;
    cout <<"Please select a filter to apply on "<<imageName<<" or 0 to exit:\n"
          "1- Black & White Filter    \t"
          "2- Invert Filter\n"
          "3- Merge Filter            \t"
          "4- Flip Image\n"
          "5- Darken and Lighten Image\t"
          "6- Rotate Image\n"
          "7- Detect Image Edges      \t"
          "8- Enlarge Image\n"
          "9- Shrink Image            \t"
          "a- Mirror 1/2 Image\n"
          "b- Shuffle Image           \t"
          "c- Blur Image\n"
          "s- Save the image to a file\t"
          "w- Change the image\n"
          "0- Exit\n"
          "-->";
          cin >> op;
    return op;
}
void loadImage(){
    char upload_image[200];
    cout<<"please enter the name of the image you want to upload: ";cin>>upload_image;
    strcat(upload_image,".bmp");
    readGSBMP(upload_image,image);
    imageName=upload_image;
}
void blackWhite(){
    int sum = 0;
    for(int i =0;i<SIZE;i++){
        for(int j =0;j<SIZE;j++){
            sum+=(int) image[i][j];
        }
    }
    int avg = sum/(255*255);
    for(int i =0;i<SIZE;i++){
        for(int j =0;j<SIZE;j++){
            if(image[i][j]>=avg){
                image[i][j]=255;
            } else{
                image[i][j]=0;
            }
        }
    }
    imageName+=" B&W";
}//done
void invert(){}
void merge(){}
void flipImage(){}
void darkenLighten(){}
void rotate(){}
void detectImageEdges(){}
void enlargeImage(){}
void shrinkImage(){}
void mirrorHalf(){}
void shuffleImage(){}
void blurImage(){}
void saveImage(){
    char imageName[100];
    cout << "Please enter the new image name you want to save as:";
    cin >> imageName;
    strcat(imageName, ".bmp");
    writeGSBMP(imageName, image);
}
