// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: ImageFilters.cpp
// Last Modification Date: xx/xx/xxxx
// Kareem ElSakkary  and 20210301 and Group: xxxxx xxxxx
// Hoda Samir and 20210443 and Group: xxxxx xxxxx
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
                enlargeImage();
                break;
            case '9':
                 shrinkImage();
                break;
            case 'a':
                mirrorHalf();
                break;
            case 'b':
                shuffleImage();
                break;
            case 'c':
                blurImage();
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
//        saveImage();
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
    cout<<"please enter the name of the image you want to upload: \n";cin>>upload_image;
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
            image[i][j] = 255 - image[i][j]; // invert each pixel by subtracting 255 from each pixel value
        }
    }
    imageName+=" invert";
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
    imageName+= strcat(" merged with ",upload_image2);
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
        imageName+= " darken";
    }else if (action == "lighten"){
        for(int i = 0;i<=SIZE;i++){
            for(int j = 0; j<=SIZE;j++){
                download[i][j]=(image[i][j]+white[i][j])/2;
                image[i][j] = download[i][j];
            }
        }
        imageName+= " lighten";
    }
}
// for rotateImage
void rotate() {
    // function to rotate by 90 degree only
    unsigned char tempMat[256][256]; // rotate clockwise rotation by replacing each row with opposite column from the end
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
    cin >> degree; // take the degree that the user wants to rotate the image by it
    if (degree == 90) {
        rotate();
    }
    if (degree == 180) { // 180 - rotate by 90 degree twice
        while (c < 2) {
            rotate();
            c++;
        }
    }
    if (degree == 270) { // 270 - rotate by 90 degree 3 times
        while (c < 3) {
            rotate();
            c++;
        }
    }
    imageName+= " rotate "+to_string(degree)+" degree";
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
    imageName+= "`s objects edges";
}//done
void enlargeImage(){
    // take the number of the quarter that the user wants to enlarge it
    cout << "Please enter the number of the quarter you want to enlarge: " << endl;
    int nQuarter, startX, startY, countX = 0, countY = 0; ;
    cin >> nQuarter;
    while (nQuarter < 0 || nQuarter > 4){
        cout << "Invalid! Please enter a number from [1, 2, 3, 4]" << endl;
        cin >> nQuarter;
    } // set the starting point depending on which quarter the user will choose
    if (nQuarter == 1)
        startX = startY = 0;
    if (nQuarter == 2){
        startX = 0;
        startY = 128;
    }
    if (nQuarter == 3){
        startX = 128;
        startY = 0;
    }
    if (nQuarter == 4)
        startX = startY = 128;
    unsigned char enlargedImage[256][256], tmp;
    for (int x = startX; x < startX + 128; x++){
        for (int y = startY; y < startY + 128; y++){
            tmp = image[x][y];
            for (int i = countX; i < countX + 2; i++){ // enlarge the quarter image by duplicating each pixel 4 times
                for (int j = countY; j < countY + 2; j++){
                    enlargedImage[i][j] = tmp;
                }
            }
            countY += 2;
        }
        countY = 0;
        countX += 2;
    } // move the enlarged image matrix back to the original image
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            image[i][j] = enlargedImage[i][j];
        }
    }
    imageName+= " enlarge "+to_string(nQuarter)+"th quarter";

}
void shrinkImage(){
 cout << "please enter the value you want to shrink with from the list[1/2,1/3,1/4]\n";
    string shrink_value;
    cin >> shrink_value;
    if (shrink_value == "1/2") {
        int c = 0;
        for (int i = 0; i < SIZE; i += 2) {
            int d = 0;
            for (int j = 0; j < SIZE; j += 2) {
                image[c][d] = ((image[i][j] + image[i + 1][j] + image[i][j + 1] + image[i + 1][j + 1]) / 4);
                d++;
            }
            c++;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i >= (SIZE / 2) || j >= (SIZE / 2)) {
                    image[i][j] = SIZE - 1;
                }
            }
        }
    }
    else if (shrink_value == "1/3"){
        int c = 0;
        for (int i = 0; i < SIZE; i += 3) {
            int d = 0;
            for (int j = 0; j < SIZE; j += 3) {
                image[c][d] = ((image[i][j]+image[i+1][j]+image[i][j+1]+image[i+1][j+1]+image[i][j+2]+image[i+2][j]+image[i+2][i+2]+image[i+1][j+2]+image[i+2][j+1])/9);
                d++;
            }
            c++;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i >= (SIZE / 3) || j >= (SIZE / 3)) {
                    image[i][j] = SIZE - 1;
                }
            }
        }
    }else if (shrink_value == "1/4"){
        int c = 0;
        for (int i = 0; i < SIZE; i += 4) {
            int d = 0;
            for (int j = 0; j < SIZE; j += 4) {
                image[c][d] = ((image[i][j]+image[i+1][j]+image[i][j+1]+image[i+1][j+1]+image[i][j+2]+image[i+2][j]+image[i+2][i+2]+image[i+1][j+2]+image[i+2][j+1]+image[i+3][j]+image[i][j+3]+image[i+1][j+3]+image[i+3][j+1]+image[i+3][j+2]+image[i+2][j+3])/16);
                d++;
            }
            c++;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i >= (SIZE / 4) || j >= (SIZE / 4)) {
                    image[i][j] = SIZE - 1;
                }
            }
    }
}
    imageName+= " shrink with "+shrink_value;

}
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
void shuffleImage(){
    string order;
    // take the order from the user
    cout << "Please enter the order you want to the quarters in the new image: " << endl;
    cin.ignore();
    getline(cin, order);
    unsigned char tempMatrix[256][256];
    int q{1};
    for (char k: order) {
        if(k == ' '){
            continue;
        }
        for (int i = 0; i < 256 / 2; i++) {
            for (int j = 0; j < 256 / 2; j++) {
                // fill the quarters in the temp matrix by the given order
                if (q == 1) {  // first quarter
                    if (k == '1') {
                        tempMatrix[i][j] = image[i][j];
                    }
                    if (k == '2') {
                        tempMatrix[i][j] = image[i][j+128];
                    }
                    if (k == '3') {
                        tempMatrix[i][j] = image[i+128][j];
                    }
                    if (k == '4') {
                        tempMatrix[i][j] = image[i+128][j+128];
                    }
                }
                if (q == 2) {  // second quarter
                    if (k == '1') {
                        tempMatrix[i][j + 128] = image[i][j];
                    }
                    if (k == '2') {
                        tempMatrix[i][j + 128] = image[i][j + 128];
                    }
                    if (k == '3') {
                        tempMatrix[i][j + 128] = image[i+128][j];
                    }
                    if (k == '4') {
                        tempMatrix[i][j + 128] = image[i+128][j+128];
                    }
                }
                if (q == 3) {  // third quarter
                    if (k == '1') {
                        tempMatrix[i + 128][j] = image[i][j];
                    }
                    if (k == '2') {
                        tempMatrix[i + 128][j] = image[i][j + 128];
                    }
                    if (k == '3') {
                        tempMatrix[i + 128][j] = image[i + 128][j];
                    }
                    if (k == '4') {
                        tempMatrix[i + 128][j] = image[i + 128][j + 128];
                    }
                }
                if (q == 4) {  // fourth quarter
                    if (k == '1') {
                        tempMatrix[i + 128][j + 128] = image[i][j];
                    }
                    if (k == '2') {
                        tempMatrix[i + 128][j + 128] = image[i][j + 128];
                    }
                    if (k == '3') {
                        tempMatrix[i + 128][j + 128] = image[i + 128][j];
                    }
                    if (k == '4') {
                        tempMatrix[i + 128][j + 128] = image[i + 128][j + 128];
                    }
                }
            }
        }
        q++;
    } // move the temp matrix back to the original image
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            image[i][j] = tempMatrix[i][j];
        }
    }
    imageName+= " shuffle by order "+order;

}
void blurImage(){
  int value;
        for (int i=0 ; i<253 ; i+=2){
            for (int j=0 ; j<253 ; j+=2){
                value =((image[i][j]+image[i+1][j]+image[i][j+1]+image[i+1][j+1]+image[i][j+2]+image[i+2][j]+image[i+2][i+2]+image[i+1][j+2]+image[i+2][j+1]+image[i+3][j]+image[i][j+3]+image[i+3][j+3]+image[i+2][j+3]+image[i+3][j+2])/14);
                image[i][j]=value;
                image[i+1][j]=value;
                image[i][j+1]=value;
                image[i+1][j+1]=value;
                image[i][j+2]=value;
                image[i+2][j]=value;
                image[i+2][i+2]=value;
                image[i+1][j+2]=value;
                image[i+2][j+1]=value;
                image[i+3][j]=value;
                image[i][j+3]=value;
                image[i+3][j+3]=value;
                image[i+2][j+3]= value;
                image[i+3][j+2]=value;

            }}
    imageName+= " blur";

}
void saveImage(){
    char imageNameNew[100];
    cout << "Please enter the new image name you want to save as:";
    cin >> imageNameNew;
    strcat(imageNameNew, ".bmp");
    writeGSBMP(imageNameNew, image);
    imageName = imageNameNew;

}
