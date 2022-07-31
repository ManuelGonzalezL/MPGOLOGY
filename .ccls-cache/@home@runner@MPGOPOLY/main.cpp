#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

#include "heapsort.h"
#include "quicksort.h"


int main() {
  vector<Vehicle> v; //original vector
  vector<Vehicle> h; //heap sort vector
  vector<Vehicle> q; //quick sort vector
  readData("mpg.csv", v);
  h = v;
  q = v;
  bool endLoop = false;
  

  int input;

  while(!endLoop){

    cout << endl << "Car MPG Menu" << endl; 
    cout << "[---------------------------------------------------------]" << endl;
    //1. Best overall mpg
    //2. Best mpg of desired year
    //3. Best mpg for each year
    //4. exit program
    cout << "1. View the best MPG cars (1984 - 2023)" << endl;
    cout << "2. Find the best MPG car for a specific year (1984 - 2023)" << endl;
    cout << "3. View the best MPG carsfor each year (1984 - 2023)" << endl;
    cout << "4. Exit"  << endl;
    cout << "[---------------------------------------------------------]" << endl;
  
    cin >> input;
    cout << endl;
  
    //the time functions should be able to measure the time it takes to run the programs but im not sure if it works 100%
    if(input == 1){
      time_t startQuick, endQuick, startHeap, endHeap;
      
      time(&startQuick);
      //Call the quick sort function
      int n = q.size();
      quickSort(q, n, -1);
      printTop10(q);
      time(&endQuick);
      
      double timeTakenQuick = double(endQuick-startQuick);
      cout << "Quick Sort Time: " << fixed << setprecision(5) << timeTakenQuick << endl << endl;
  
      time(&startHeap);
      //Call the heap sort function
      n = h.size();
      heapSortCombmpg(h,n);
      printTop10(h);
      //cout << h[0].getCombmpg() << h[0].getModel() << endl;
      time(&endHeap);
      
      double timeTakenHeap = double(endHeap-startHeap);
      
      // 2 endl's at on line 69 so that it looks nicer when printing
      cout << "Heap Sort Time: " << fixed << setprecision(5) << timeTakenHeap << endl << endl;
      
    } // end of input 1
    else if(input == 2){

      time_t startQuick, endQuick, startHeap, endHeap;

      int year;
      cout << "Enter a year\n";
      cin >> year;

      time(&startQuick); // Start of the quicksort
      
      int n = q.size();
      //quickSortYear(q, n, year);

      time(&endQuick);// End of quicksort

      double timeTakenQuick = double(endQuick-startQuick);
      cout << "Quick Sort Time: " << fixed << setprecision(5) << timeTakenQuick << endl;

      time(&startHeap);// Start of heapsort

      n = h.size();
      heapSortYear(h, n);
      h = getYear(h, year);
      printTop10(h);
      //heapSortCombmpg(h, n);

      time(&endQuick);//end of heapsort

      double timeTakenHeap = double(endHeap-startHeap);
      // 2 endl's at on line 100 so that it looks nicer when printing
      cout << "Heap Sort Time: " << fixed << setprecision(5) << timeTakenHeap << endl << endl;
      
    }// end of input 2
    else if(input == 3) {
      endLoop = true;
    } // end of input 3
  } // end of while loop
  return 0;
  
} // end of main