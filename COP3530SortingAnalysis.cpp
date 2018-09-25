// COP3530SortingAnalysis.cpp
// Leeson Chen (UFID 7907-2212)
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>
// We are an all-inclusive script that embraces diversity
using namespace std;
// void heapSort(int arr[], int n);
// void heapify(int arr[], int n, int i);

// *** READ ME ***
// Alright so I think the only things you need to change when running a new file are:
// int FileSize (ex: 5000, 10000, 20000, or 50000)
// file name (format [#][increasing/decreasing/random].txt example: 5000random.txt)
// Oh and also put/remove comments around the algorithm you're using, because I'm too lazy to make functions

int main() {

using std::chrono::system_clock;
	
// calls system clock first time (before algorithm runs)
std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
system_clock::now().time_since_epoch()
);
std::cout << "Beginning milliseconds is: " << "\n";
std::cout << ms.count();
// new line
std::cout << "\n";

// random counting
//for (long i = 0;i<464645654;i++)
//;

// reading file line-by-line
string line;
int FileSize = 5000; // ***CHANGE THIS NUMBER FOR DIFFERENT SIZES***
ifstream myfile ("5000random.txt"); // ***CHANGE THIS PART FOR DIFFERENT FILES***

if (myfile.is_open()) {
	int arr[FileSize];
	int i = 0;
	//int y = 0; // used for some math, not important COMMENTED TO CLEAN
	while ( getline (myfile,line) ){
		//cout << line << '\n';
		stringstream geek(line); // turns strings into integers
		int x = 0; // placeholder x represents the integer value
		geek >> x; // puts the string into x I guess
		arr[i] = x; // puts integer x into array at position i
		i++; // increase i
		
		//y = y + x; // just some math to make sure it was really an int COMMENTED TO CLEAN
		//std::cout << y-x << "+" << x << "=" << y << "\n"; // see above line COMMENTED TO CLEAN
	
	}
	myfile.close();
	
	/*
	// Commented this part for cleanliness
	// print it out in an array just to make sure still random, unsorted
	// style of [1 2 3 4 5 ]
	std::cout << "[";
	for (int i = 0; i < FileSize; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "] \n";
	*/
	
	// Alright so now all those lines are in an array
	// Time to sort
	// ALGORITHMS GO HERE
	
	
	// *** SELECTION SORT ***
	int min = 0;
	for (int i = 0; i < FileSize; i++) {
		min = arr[i];
		int k = 0;
		for (int j = i; j < FileSize; j++) {
			if (arr[j] < min) {
				min = arr[j];
				k = j;
			}
		}
		if (min != arr[i]) {
			int temp = arr[i];
			arr[i] = min;
			arr[k] = temp;
		}
	} 
	
	
	
	/*
	// *** INSERTION SORT ***
	for (int a = 1; a < FileSize; a++) {
		int b = a;
		while (arr[b] < arr[b-1]) {
			int temp = arr[b];
			arr[b] = arr[b-1];
			arr[b-1] = temp;
			b--;
		}
	}
	*/
	 
	
	/*
	// *** HEAP SORT ***
	int max = 0;
	for (int w = 0; w < FileSize; w++) {
		if (arr[w] > max) {
			max = arr[w];
		}
	}
	void heapify(int arr[], int n, int i) {
		int largest = i;
		int l = 2*i + 1;
		int r = 2*i + 2;

		// if left child > root
		if (l < n && arr[l] > arr[largest]) {
			largest = l;
			* }
		// if right child > largest so far
		if (r < n && arr[r] > arr[largest]) {
			largest = r;
		}
		// if largest != root
		if (largest != i) {
			swap(arr[i], arr[largest]);
 
			// recursively heapify sub-tree
			heapify(arr, n, largest);
		}
	}	
	void heapSort(int arr[], int n) {
		// build heap (rearrange array)
		for (int i = n / 2 - 1; i >= 0; i--) {
			heapify(arr, n, i);
		}
		// one by one extract an element from heap
		for (int i=n-1; i>=0; i--) {
			// move current root to end
			swap(arr[0], arr[i]);
			// call max heapify on the reduced heap
			heapify(arr, i, 0);
		}
	}
	*/ 

	
	
	
	
	/*
	// Commenting this as well to speed up
	// std::cout << arr; // won't work because c++ is stupid, need to do individually
	// prints array in [1 2 3 4 5 ] style
	std::cout << "[";
	for (int i = 0; i < FileSize; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]";
	*/
}
else cout << "Unable to open file. Goddammit Leeson you fucked up."; 
	
	
std::cout << "\n";
// calls system clock second time (after algorithm runs)
std::chrono::milliseconds ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(
system_clock::now().time_since_epoch()
);
std::cout << "Ending milliseconds is: " << "\n";
std::cout << ms2.count();
std::cout << "\n Milliseconds elapsed: " << ms2.count() - ms.count() << "\n";
std::cout << "\n Time is ticking away... \n Should we really be spending it on sorting algorithms, and not finding love?" << "\n";


return 0;
}
