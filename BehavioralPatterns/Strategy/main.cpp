#include <iostream>

using namespace std;

class AbstractSort
{
  public:
    void sort(int arr[], int n)
    {
        for (int i = 0; i < n-1; i++)
        {
            int v = i;
            for (int j = i+1; j < n; j++)
              if (compare(arr[j], arr[v])) // to do ascending or descending order
                v = j;
            swap(&arr[v], &arr[i]);
        }
    }
  private:
    virtual bool compare(int, int) = 0;
    void swap(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
};

// different algorithm for sort
// ascending order
class SortUp: public AbstractSort
{
    bool compare(int a, int b)
    {
        return (a < b);
    }
};

// different algorithm for sort
// desending order
class SortDown: public AbstractSort
{
    bool compare(int a, int b)
    {
        return (a > b);
    }
};

// helper function
void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << ' ';
    cout << '\n';
}

//decide which algorithm to call
class SortingAlgorithm
{
  public:
    SortingAlgorithm() {
        algorithm_ = NULL;
    }
    void setOrder(int type) {
      if (algorithm_ != NULL) {
           delete algorithm_; // to dynamically switch to a different implementation, before reassign to a diffent instance
           algorithm_ = NULL;
      }
      algorithm_ = (type > 0) ? (AbstractSort*)new SortUp() : (AbstractSort*)new SortDown();
    }
    void sort(int a[], int n) {
        algorithm_->sort(a, n);
    }
  private:
    AbstractSort *algorithm_;
};

//client code
int main()
{
  int array[10] = {3,8,2,9,1,7,4,10,6,5};
  printArray(array, 10);

  SortingAlgorithm obj; //reference to the interface
  obj.setOrder(1); // which algorithm will be used
  obj.sort(array, 10);
  printArray(array, 10);

  obj.setOrder(-1);
  obj.sort(array, 10);
  printArray(array, 10);
}
