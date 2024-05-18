#include <iostream>
#include <time.h>


using namespace std;
void shuffleArray(int *data, int lenD)
{
    srand(time(NULL));
    int j;

    int tmp;
    for (int i=0; i<lenD; i++)
    {
        j = rand() % lenD;
        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;

    }
}
void selectionSort(int * data, int lenD)
{
  int j = 0;
  int tmp = 0;
  int C = 0;
  for(int i=0; i<lenD; i++)
  {
      j = i;
      for ( int k = i; k < lenD; k++)
      {
          C ++;
          if ( data[j] > data[k])
          {
              j = k;
          }
      }
      tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;

  }

}
void bubbleSort(int* data, int lenD)
{
  int c = 0;
  int tmp = 0;
  for(int i = 0;i<lenD;i++)
  {
    for(int j = (lenD-1);j>=(i+1);j--)
    {
      c++;
      if(data[j]<data[j-1])
      {
        tmp = data[j];
        data[j]=data[j-1];
        data[j-1]=tmp;
      }
    }
  }
  cout << "Пузырьковая сортировка: " << c <<endl;
}
void insertionSort(int* data, int lenD)
{
  int key = 0;
  int i = 0;
  int C = 0;
  for(int j = 1;j<lenD;j++)
  {
    key = data[j];
    i = j - 1;
    while ( i >= 0 && data[i] > key)
    {
        C ++;
        data [ i + 1] = data[i];
        i = i - 1;
        data [ i + 1] = key;
    }
  }
  cout << "In: "<< C << endl;
}

void showArray(int* data, int lenD)
{
    cout << "Array: ";
    for( int i = 0; i < lenD; i ++)
    {
        cout << data[i];
        if (i < lenD - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << "." << endl;
        }
    }
}


int main()
{

    int data[] = {50, 45, 34, 17, 22, 1, 10, 99, 22, 0};
    showArray(data, 10);
    bubbleSort(data, 10);
    shuffleArray(data, 10);
    showArray(data, 10);
    bubbleSort(data, 10);
    selectionSort(data, 10);
    showArray(data, 10);
    insertionSort(data, 10);
    showArray(data, 10);
    return 0;
}
