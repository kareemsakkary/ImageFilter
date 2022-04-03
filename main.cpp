// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: ImageFilters.cpp
// Last Modification Date: xx/xx/xxxx
// Kareem ElSakkary  and 20210301 and Group: xxxxx xxxxx
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
unsigned char download[SIZE][SIZE];
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
                invertImage();
                break;
            case '3':
                mergeImage();
                break;
            case '4':
                flipImage();
                break;
            case '5':
                rotateImage();
                break;
            case '6':
                darkenLightenImage();
                break;
            case '7':
                detectImageEdges();
                break;
            case '8':

                break;
            case '9':

                break;
            case 'a':
                mirrorHalf();
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
        saveImage();
        cout<<"done"<<endl;
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
          "5- Rotate Image             \t"
          "6- Darken and Lighten Image\n"
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
    int avg = sum/(SIZE*SIZE);
    cout << "avg: " << avg;
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
void invertImage(){
    for (int i=0; i<256;i++){
        for (int j=0;j<256;j++){
            image[i][j] = 255 - image[i][j];
        }
    }
}
void mergeImage(){
    unsigned char to_merge[SIZE][SIZE];
    char upload_image2[200];
    cout << "please enter the name of the image you want to upload:\n ";
    cin >> upload_image2;
    strcat(upload_image2, ".bmp");
    readGSBMP(upload_image2, to_merge);
    for (int i = 0; i <= SIZE; i++) {
        for (int j = 0; j <= SIZE; j++) {
            download[i][j] = (image[i][j] + to_merge[i][j]) / 2;
            image[i][j] = download[i][j];
        }}
}
void flipImage(){
    char dir='n';
    while (dir!='h'&&dir!='v'){
        cout << "Flip horizontally(h) or vertically(v)";
        cin>>dir;
    }
    if(dir == 'h'){
        unsigned char temp;
        for(int i =0;i<SIZE/2;i++){
            for(int j =0;j<SIZE;j++){
                temp = image[i][j];
                image[i][j]=image[SIZE-i-1][SIZE-j-1];
                image[SIZE-i-1][SIZE-j-1]=temp;
            }
        }
        imageName+=" flip (h)";
    }else{
        unsigned char temp;
        for(int i =0;i<SIZE;i++){
            for(int j =0;j<SIZE/2;j++){
                temp = image[i][j];
                image[i][j]=image[i][SIZE-j-1];
                image[i][SIZE-j-1]=temp;
            }
        }
        imageName+=" flip (v)";
    }
}//done
// for Darken&lighten filter
void  filter6() {
    unsigned char white[SIZE][SIZE];
    unsigned char black[SIZE][SIZE];
    char white_image[200] = "white";
    strcat(white_image, ".bmp");
    readGSBMP(white_image, white);
    char black_image[200] = "black";
    strcat(black_image, ".bmp");
    readGSBMP(black_image, black);
}
void darkenLightenImage(){
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

            }}
    }else if (action == "lighten"){
        for(int i = 0;i<=SIZE;i++){
            for(int j = 0; j<=SIZE;j++){
                download[i][j]=(image[i][j]+white[i][j])/2;
                image[i][j] = download[i][j];
            }}}
}
void rotate() {
    unsigned char tempMat[256][256];
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            tempMat[j][256 - i] = image[i][j];
        }
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            image[i][j] = tempMat[i][j];
        }
    }
}
void rotateImage(){
    int degree, c{0};
    cout << "Which degree do you want to rotate by ? (90 - 180 - 270)" << endl;
    cin >> degree;
    if (degree == 90) {
        while (c < 1) {
            rotate();
            c++;
        }
    }
    if (degree == 180) {
        while (c < 2) {
            rotate();
            c++;
        }
    }
    if (degree == 270) {
        while (c < 3) {
            rotate();
            c++;
        }
    }
}
void detectImageEdges(){
    blackWhite();
    unsigned char newImage[SIZE][SIZE];;
    for(int i =0;i<SIZE;i++){
        for(int j =0;j<SIZE;j++){
            if(image[i][j]==image[i+1][j]&&image[i][j]==image[i-1][j]&&image[i][j]==image[i][j+1]&&image[i][j-1]==image[i][j+1]){
                newImage[i][j]=255;
            }
        }
    }
    for(int i =0;i<SIZE;i++){
        for(int j =0;j<SIZE;j++) {
            image[i][j]=newImage[i][j];
        }
    }
}//done
void enlargeImage(){}
void shrinkImage(){}
void mirrorHalf(){
    char half='n';
    while (half!='l'&&half!='r'&&half!='u'&&half!='d'){
        cout << "Mirror left(l), right(r), upper(u), down(d) side? ";
        cin>>half;
    }
    switch (half) {
        case 'l':
            for(int i =0;i<SIZE;i++){
                for(int j =0;j<SIZE/2;j++){
                    image[i][SIZE-j-1]=image[i][j];
                }
            }
            imageName+=" mirror (l)";
            break;
        case 'r':
            for(int i =0;i<SIZE;i++){
                for(int j =0;j<SIZE/2;j++){
                    image[i][j]=image[i][SIZE-j-1];
                }
            }
            imageName+=" mirror (r)";
            break;
        case 'd':
            for(int i =0;i<SIZE/2;i++){
                for(int j =0;j<SIZE;j++){
                    image[255-i][j]=image[i][j];
                }
            }
            imageName+=" mirror (d)";
            break;
        case 'u':
            for(int i =0;i<SIZE/2;i++){
                for(int j =0;j<SIZE;j++){
                    image[i][j]=image[SIZE-i-1][j];
                }
            }
            imageName+=" mirror (u)";
            break;
    }
}//done
void shuffleImage(){}
void blurImage(){
    for(int i = 0;i<=SIZE;i= i=i+2){
        for(int j = 0; j<=SIZE;j=j+2) {
            char value = (image[i+1][j]+image[i][j+1]+image[i+1][j+1]+image[i][j+2]+ image[i+2][j]+image[i][j+3]+image[i+3][j]+ image[i+3][j+3]+image[i][j+4]+image[i+4][j]+image[i+4][j+4])/12;
            image[i+1][j] = value;
            image[i][j+1] = value;
            image[i+1][j+1] = value;
            image[i][j+2] = value;
            image[i+2][j] = value;
            image[i][j+3] = value;
            image[i+3][j] = value;
            image[i+3][j+3] = value;
            image[i][j+4]= value;
            image[i+4][j]= value;
            image[i+4][j+4] = value;
            image[i][j] = download[i][j];

        }}
}
void saveImage(){
    char imageNameNew[100];
    cout << "Please enter the new image name you want to save as:";
    cin >> imageNameNew;
    strcat(imageNameNew, ".bmp");
    writeGSBMP(imageNameNew, image);
}
