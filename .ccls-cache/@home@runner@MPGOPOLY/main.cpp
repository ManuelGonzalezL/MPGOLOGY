#include <iomanip>
#include <chrono>
#include <ctime>
#include <ratio>
#include <algorithm>
using namespace std;
using namespace std::chrono;

#include "heapsort.h"
#include "quicksort.h"


int main() {
  vector<Vehicle> v; //original vector
  vector<Vehicle> h; //heap sort vector
  vector<Vehicle> q; //quick sort vector
  vector<Vehicle> t; //inbluilt sort vector
  readData("mpg.csv", v);

  set<int> set;
  unordered_map<int, vector<Vehicle>> map;
  buildMap(map, set, v);
  
  bool endLoop = false;
  int input;

  while(!endLoop){

    h = v;
    q = v;
    t = v;

    cout << endl << "Car MPG Menu" << endl; 
    cout << "[---------------------------------------------------------]" << endl;
    cout << "1. View the cars with the best MPG (1984 - 2023)" << endl;
    cout << "2. View the cars with best MPG for a specific year (1984 - 2023)"<< endl;
    cout << "3. View the car with best MPG for each year (1984 - 2023)" << endl;
    cout << "4. Exit"  << endl;
    cout << "[---------------------------------------------------------]" << endl;
  
    cin >> input;
    cout << endl;

    //1. Best overall mpg
    if (input == 1) {
/*-----------------------------------------*/      
      // start of inbluit sort
      auto startInbuilt = high_resolution_clock::now();
      //call inbuilt sort
      int n = t.size();
      sort(t.begin(), t.end(), [](Vehicle &a, Vehicle &b) {
        return a.getCombmpg() > b.getCombmpg();
      });     
      printTop10(t);
      
      auto endInbuilt = high_resolution_clock::now();
      auto timeTakenInBuilt = duration_cast<milliseconds>(endInbuilt-startInbuilt);
      cout << "Inbuilt Sort Time: " << fixed << setprecision(5) << timeTakenInBuilt.count() << " milliseconds" << endl << endl;
      //end of inbluilt sort
/*-----------------------------------------*/
       // start of quick sort
      auto startQuick = high_resolution_clock::now();
      //Call the quick sort function
      n = q.size();
      quickSort(q, 0, n - 1);
      printTop10(q);
      
      auto endQuick = high_resolution_clock::now();
      auto timeTakenQuick = duration_cast<milliseconds>(endQuick-startQuick);
      cout << "Quick Sort Time: " << fixed << setprecision(5) << timeTakenQuick.count() << " milliseconds" << endl << endl;
      // end of quick sort
/*-----------------------------------------*/
      // start of heap sort
      auto startHeap = high_resolution_clock::now();
      //Call the heap sort function
      n = h.size();
      heapSortCombmpg(h,n);
      printTop10(h);
      //cout << h[0].getCombmpg() << h[0].getModel() << endl;
      
      auto endHeap = high_resolution_clock::now();
      auto timeTakenHeap = duration_cast<milliseconds>(endHeap-startHeap);
      cout << "Heap Sort Time: " << fixed << setprecision(5) << timeTakenHeap.count() << " milliseconds" << endl << endl;
      // end of heap sort
/*-----------------------------------------*/
    } 
    //2. Best mpg of desired year
    else if(input == 2){

      int year;
      cout << "Enter a year\n";
      cin >> year;
/*-----------------------------------------*/
       // start of inbuilt sort
      auto startInbuilt = high_resolution_clock::now(); 
      //call inbuilt sort
      t = map[year];
      int n = t.size();
      sort(t.begin(), t.end(), [](Vehicle &a, Vehicle &b) {
        return a.getCombmpg() > b.getCombmpg();
      });
      printTop10(t);
      
      auto endInbuilt = high_resolution_clock::now();
      auto timeTakenInBuilt = duration_cast<milliseconds>(endInbuilt-startInbuilt);
      cout << "Inbuilt Sort Time: " << fixed << setprecision(5) << timeTakenInBuilt.count() << " milliseconds" << endl << endl;
      // end of inbuilt sort
/*-----------------------------------------*/
      // start of quick sort
      auto startQuick = high_resolution_clock::now(); 
      //call quicksort
      q = map[year];
      n = q.size();
      quickSort(q, 0, n - 1);
      printTop10(q);
      
      auto endQuick = high_resolution_clock::now();
      auto timeTakenQuick = duration_cast<milliseconds>(endQuick-startQuick);
      cout << "Quick Sort Time: " << fixed << setprecision(5) << timeTakenQuick.count() << " milliseconds" << endl << endl;
      //end of quick sort
/*-----------------------------------------*/
      // start of heap sort
      auto startHeap = high_resolution_clock::now();
      // call heapsort
      h = map[year];
      n = h.size();
      heapSortCombmpg(h, n);
      printTop10(h);

      auto endHeap = high_resolution_clock::now();
      auto timeTakenHeap = duration_cast<milliseconds>(endHeap-startHeap);
      cout << "Heap Sort Time: " << fixed << setprecision(5) << timeTakenHeap.count() << " milliseconds" << endl << endl;
      //end of heap sort
/*-----------------------------------------*/
    }
    
      //3. Best mpg for each year  
    else if(input == 3) {
/*-----------------------------------------*/
      // start of inbluit sort
      auto startInbuilt = high_resolution_clock::now(); 
      //call inbuilt sort
      int n = t.size();
      for (auto year : set) {
        t = map[year];
        sort(t.begin(), t.end(), [](Vehicle &a, Vehicle &b) {
          return a.getCombmpg() > b.getCombmpg();
        });
        printTop(t);
      }
      
      auto endInbuilt = high_resolution_clock::now();
      auto timeTakenInBuilt = duration_cast<milliseconds>(endInbuilt-startInbuilt);
      cout << "Inbuilt Sort Time: " << fixed << setprecision(5) << timeTakenInBuilt.count() << " milliseconds" << endl << endl;
      // end of inbluit sort
/*-----------------------------------------*/
      //star of quickSort
      auto startQuick = high_resolution_clock::now();
      //call quicksort
      for (auto year : set) {
        q = map[year];
        int n = q.size();
        quickSort(q, 0, n - 1);
        printTop(q);
      }
      
      auto endQuick = high_resolution_clock::now();
      auto timeTakenQuick = duration_cast<milliseconds>(endQuick-startQuick);
      cout << "Quick Sort Time: " << fixed << setprecision(5) << timeTakenQuick.count() << " milliseconds" << endl << endl;
     // end of quick sort
/*-----------------------------------------*/
      // start of heapSort
      auto startHeap = high_resolution_clock::now();
      //call heapsort 
      for (auto year : set) {
        h = map[year];
        heapSortCombmpg(h, h.size());
        printTop(h);
      }

      auto endHeap = high_resolution_clock::now();
      auto timeTakenHeap = duration_cast<milliseconds>(endHeap-startHeap);
      cout << "Heap Sort Time: " << fixed << setprecision(5) << timeTakenHeap.count() << " milliseconds " << endl << endl;
     //end of heapsort 
/*-----------------------------------------*/
    } 

    //exit program
    else if (input == 4){
      cout << "Exiting the program..." << endl;
      cout << "Good bye!" << endl;
      endLoop = true;
    }
  } // end of while loop
  return 0;
}