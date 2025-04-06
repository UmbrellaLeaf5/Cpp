#include <iostream>

using namespace std;
class Table{
public:
    void setSize(int R, int C){
        if(R > 0){
            countRows = R;
        }
        if(C > 0){
            countCols = C;
        }
    }
    void show(){
        currentRow = 0;
        currentCol = 0;
        getColsSize();
        showTop();
        for (int i=0;i<countRows;i++) {
            showMiddle();
            if(i < (countRows-1)){
                showCenter();
            }
            currentRow ++;
        }
        showBottom();
    }
    void showRow(){
        showTop();
        showMiddle();
        showCenter();
        showMiddle();
        showBottom();
    }
    void addHeader(string S){
        headers[header] = S;
        header ++;
    }
    void addText(string S,int r, int c){
        text[r][c] = S;
    }
private:
    int countRows = 1;
    int countCols = 1;
    string text[100][20];
    string headers[20];
    int colsSize[20];
    int header = 0;
    int currentRow = 0;
    int currentCol = 0;
    int leftTop = 218;
    int leftBot = 192;
    int rightTop = 191;
    int rightBot = 217;
    int tLeft = 195;
    int tRight = 180;
    int tTop = 194;
    int tBot = 193;
    int center = 197;
    int vert = 179;
    int horz = 196;
    void showTop(){
        cout << char(leftTop);
        for (int i=0;i<countCols;i++) {
            for (int c=0;c<colsSize[i];c++) {
                cout << char(horz);
            }

            if(i < (countCols-1)){
                cout << char(tTop);
            }
        }
        cout << char (rightTop)
             << endl;
    }
    void showMiddle(){
        currentCol = 0;
        cout << char(vert);
        for (int i=0;i<countCols;i++) {
            if(currentRow==0){
                cout << headers[currentCol];
            }else{
                for (int c=0;c<colsSize[i];c++) {
                    cout << " ";
                }
            }
            cout << char(vert);
            currentCol ++;

        }
        cout << endl;
    }
    void showBottom(){
        cout << char(leftBot);
        for (int i=0;i<countCols;i++) {
            for (int c=0;c<colsSize[i];c++) {
                cout << char(horz);
            }
            if(i < (countCols-1)){
                cout << char(tBot);
            }
        }
        cout << char (rightBot)
             << endl;
    }
    void showCenter(){
        cout << char(tLeft);
        for (int i=0;i<countCols;i++) {
            for (int c=0;c<colsSize[i];c++) {
                cout << char(horz);
            }
            if(i < (countCols-1)){
                cout << char(center);
            }
        }
        cout << char (tRight)
             << endl;
    }
    void getColsSize(){
        for (int i=0;i<header;i++) {
            colsSize[i] = headers[i].length();
        }
    }

};

int main()
{
    Table T;
    T.setSize(5,4);
    T.addHeader("№");
    T.addHeader("Фамилия");
    T.addHeader("Имя");
    T.addHeader("Отчество");
    T.addText("Иванов",1,1);

    T.show();
    /*
    for (int i=1;i<255;i++) {
        cout << i
             << " "
             << char(i)
             << endl
             << endl;
    }
    */
    return 0;
}
