class Sort
{
    // add data members
    int* vector;
    int cate;
    bool sortat = false;
    void quickSort(int* arr, int st, int dr);
    int partition(int* arr, int st, int dr);
public:
    // add constuctors
    Sort(int nr, int minx, int maxx);
    Sort(int* v, int nr);
    Sort(int count, ...);
    Sort(char* c);
    Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};