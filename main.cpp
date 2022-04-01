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
unsigned char download[SIZE][SIZE];

int main() {
    char op;
    while(true){
        loadImage();
        op = getOption();
        if(op=='0'){
            break;
        }
        switch (op) {
            case '1':

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
            default:
                break;
        }
    }

    return 0;
}


char getOption() {
    char op;
    cout <<"Please select a filter to apply or 0 to exit:\n"
          "1- Black & White Filter\n"
          "2- Invert Filter\n"
          "3- Merge Filter \n"
          "4- Flip Image\n"
          "5- Darken and Lighten Image \n"
          "6- Rotate Image\n"
          "7- Detect Image Edges \n"
          "8- Enlarge Image\n"
          "9- Shrink Image\n"
          "a- Mirror 1/2 Image\n"
          "b- Shuffle Image\n"
          "c- Blur Image\n"
          "s- Save the image to a file\n"
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
}
void BlackWhite(){}
void Invert(){}
void Merge(){
    unsigned char to_merge[SIZE][SIZE];
    char upload_image2[200];
    cout << "please enter the name of the image you want to merge:\n ";
    cin >> upload_image2;
    strcat(upload_image2, ".bmp");
    readGSBMP(upload_image2, to_merge);
    for (int i = 0; i <= SIZE; i++) {
        for (int j = 0; j <= SIZE; j++) {
            download[i][j] = (image[i][j] + to_merge[i][j]) / 2;
            image[i][j] = download[i][j];
        }}
}
void FlipImage(){}

// for Darken and Lighten Image
void  filter6() {
    unsigned char white[SIZE][SIZE];
    unsigned char black[SIZE][SIZE];
    char white_image[200] = "white";
    strcat(white_image, ".bmp");
    readGSBMP(white_image, white);
    char black_image[200] = "black";
    strcat(black_image, ".bmp");
    readGSBMP(black_image, black);}
void DarkenLighten(){
    string action;
    unsigned char white[SIZE][SIZE];
    unsigned char black[SIZE][SIZE];
    cout<<"Darken or lighten?"; cin>>action;
    filter6();
    if (action == "Darken"){
        for(int i = 0;i<=SIZE;i++) {
            for (int j = 0; j <= SIZE; j++) {
                download[i][j]=(image[i][j]+black[i][j])/2;
                image[i][j] = download[i][j];
            }}}else if (action == "lighten"){
        for(int i = 0;i<=SIZE;i++){
            for(int j = 0; j<=SIZE;j++){
                download[i][j]=(image[i][j]+white[i][j])/2;
                image[i][j] = download[i][j];
            }}}}
void Rotate(){}
void DetectImageEdges(){}
void EnlargeImage(){}
void ShrinkImage(){}
void MirrorHalf(){}
void ShuffleImage(){}
void BlurImage(){}
void saveImage(){
    char imageName[100];
    cout << "Please enter the new image name you want to save as:";
    cin >> imageName;
    strcat(imageName, ".bmp");
    writeGSBMP(imageName, image);
}
