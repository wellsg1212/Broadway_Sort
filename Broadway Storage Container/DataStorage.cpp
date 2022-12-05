#include <iomanip>
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <map>

using namespace std::chrono;

class Production {
private:
	int year;
	std::string title;
	std::string theater;
	std::string type;
	int attendance;
	int revenue;
public:
	Production();
	Production(int year, std::string title, std::string theater, std::string type, int attendance, int revenue);
	
	

	//getters
	int getYear() { return year; }
	std::string getTitle() { return title; }
	std::string getTheater() { return theater; }
	std::string getType() { return type; }
	int getAttendance() { return attendance; }
	int getRevenue() { return revenue; }
};

//IMPLEMENTATION

//Default constructor
Production::Production() {
	this->year = 0;
	this->title = "NULL";
	this->theater = "NULL";
	this->type = "NULL";
	this->attendance = 0;
	this->revenue = 0;
};

//Constructor
Production::Production(int year, std::string title, std::string theater, std::string type, int attendance, int revenue) {
	this->year = year;
	this->title = title;
	this->theater = theater;
	this->type = type;
	this->attendance = attendance;
	this->revenue = revenue;
}

void dataLoader(std::string filePath, std::vector<Production>& dataSet) {
	std::ifstream inFile(filePath);

	if (inFile.is_open()) {
		//read the heading data from the file
		std::string lineFromFile;
		std::getline(inFile, lineFromFile);

		//get all entries from the file, one line at a time
		while (getline(inFile, lineFromFile)) {

			std::istringstream stream(lineFromFile); //stream of data from a string

			int year;
			std::string title;
			std::string theater;
			std::string type;
			int attendance;
			int revenue;

			std::string tempYear;
			std::string tempAttendance;
			std::string tempRevenue;

			getline(stream, tempYear, '|');
			year = stoi(tempYear);
			getline(stream, title, '|');
			getline(stream, theater, '|');
			getline(stream, type, '|');
			getline(stream, tempAttendance, '|');
			attendance = stoi(tempAttendance);
			getline(stream, tempRevenue, '|');
			revenue = stoi(tempRevenue);

			Production tempRow(year, title, theater, type, attendance, revenue);
			dataSet.push_back(tempRow);
		}
	}
	else {
		std::cout << filePath << " is not open!" << std::endl;
	}
}

void printSelected(Production show) {
	std::cout << "Year: " << show.getYear() << std::endl;
	std::cout << "Title: " << show.getTitle() << std::endl;
	std::cout << "Theater: " << show.getTheater() << std::endl;
	std::cout << "Type: " << show.getType() << std::endl;
	std::cout << "Attendance: " << show.getAttendance() << std::endl;
	std::cout << "Revenue: $" << show.getRevenue() << std::endl;
}


void merge(int arr[], int left, int mid, int right)
{
	// Create X ← arr[left..mid] & Y ← arr[mid+1..right]
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int X[50000], Y[50000];

	for (int i = 0; i < n1; i++) {
		X[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++) {
		Y[j] = arr[mid + 1 + j];
	}
	// Merge the arrays X and Y into arr
	int i, j, k;
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (X[i] <= Y[j])
		{
			arr[k] = X[i];
			i++;
		}
		else
		{
			arr[k] = Y[j];
			j++;
		}
		k++;
	}
	// When we run out of elements in either X or Y append the remaining elements
	while (i < n1)
	{
		arr[k] = X[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = Y[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		// m is the point where the array is divided into two subarrays
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// Merge the sorted subarrays
		merge(arr, left, mid, right);
	}
}










int main() {
	std::vector<Production> dataSet;
	std::map<int, std::string> unsorted;
	std::map<int, std::string> unsorted2;
	std::map<int, std::string> unsorted3;


	


	dataLoader("C:/Users/Owner/Downloads/Broadway_Data_Pipe.CSV", dataSet);

	int input = 0;

	std::cout << "Broadway Database Menu" << std::endl;
	std::cout << "Choose an option" << std::endl;
	std::cout << "1. Print a show's stats" << std::endl;
	std::cout << "2. Sort data using Quick Sort" << std::endl;
	std::cout << "3. Sort data using Merge Sort" << std::endl;
	std::cout << "4. Sort data using Bubble Sort" << std::endl;

	std::cin >> input;
	int numInFile;

	if (input == 1) {
		std::cout << "Pick a data point" << std::endl;
		std::cin >> numInFile;
		printSelected(dataSet[numInFile]);
	}
	else if (input == 2) {
		std::cout << "Choose an option" << std::endl;
		std::cout << "1. Print all shows sorted by revenue" << std::endl;
		std::cout << "2. Print all shows sorted by attendance" << std::endl;
		std::cout << "3. Print all shows sorted by year" << std::endl;
		std::cin >> input;

		if (input == 1) {
			//quicksort revenue
		}
		else if (input == 2) {
			//quicksort attendance
		}
		else if (input == 3) {
			//quicksort year
		}
		else {
			std::cout << "Please select a valid menu option" << std::endl;
		}

	}
	else if (input == 3) {
		std::cout << "Choose an option" << std::endl;
		std::cout << "1. Print all shows sorted by revenue" << std::endl;
		std::cout << "2. Print all shows sorted by attendance" << std::endl;
		std::cout << "3. Print all shows sorted by year from 1990 - 2015" << std::endl;
		std::cin >> input;
		if (input == 1) {
			for (int i = 0; i < 100000; i++) {
				unsorted[dataSet.at(i).getRevenue()] = dataSet.at(i).getTitle();
			}
			int* revenue = new int[100000];

			for (int i = 0; i < 100000; i++) {
				revenue[i] = dataSet.at(i).getRevenue();
			}

			auto start = high_resolution_clock::now();	//time calculation
			mergeSort(revenue, 0, unsorted.size() - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);

			for (int i = 0; i < 97280 - 1; i++) {
				std::cout << unsorted.find(revenue[i])->second;
				std::cout << " $" << revenue[i];
				if (revenue[i] != 2947172) {
					std::cout << ", ";
				}

			}
			std::cout << std::endl;
			std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
		}
		else if (input == 2) {
			for (int i = 0; i < 100000; i++) {
				unsorted2[dataSet.at(i).getAttendance()] = dataSet.at(i).getTitle();
			}
			int* attendance = new int[100000];
			for (int i = 0; i < 100000; i++) {
				attendance[i] = dataSet.at(i).getAttendance();
			}

			auto start = high_resolution_clock::now();	//time calculation
			mergeSort(attendance, 0, unsorted2.size() - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);

			for (int i = 0; i < 97280 - 1; i++) {
				std::cout << unsorted2.find(attendance[i])->second;
				std::cout << attendance[i] << " " << " in attendance";
				if (attendance[i] != 9652) {
					std::cout << ", ";
				}

			}
			std::cout << std::endl;
			std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
		}

		else if (input == 3) {
			for (int i = 0; i < 100000; i++) {
				unsorted3[dataSet.at(i).getYear()] = dataSet.at(i).getTitle();
			}
			int* year = new int[100000];
			for (int i = 0; i < 100000; i++) {
				year[i] = dataSet.at(i).getYear();
			}

			auto start = high_resolution_clock::now();	//time calculation
			mergeSort(year, 0, unsorted3.size() - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);

			for (int i = 0; i < 97280 - 1; i++) {
				std::cout << unsorted3.find(year[i])->second;
				std::cout << " " << year[i];
				if (year[i] != 2015) {
					std::cout << ", ";
				}
				if (year[i] == 2015) {
					break;
				}

			}
			std::cout << std::endl;
			std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
		}
	}
		else if (input == 4) {
		    std::cout << "Choose an option" << std::endl;
			std::cout << "1. Print all shows sorted by revenue" << std::endl;
			std::cout << "2. Print all shows sorted by attendance" << std::endl;
			std::cout << "3. Print all shows sorted by year" << std::endl;
			std::cin >> input;

			if (input == 1) {
				//bubble sort revenue
			}
			else if (input == 2) {
				//bubble sort attendance
			}
			else if (input == 3) {
				//bubble sort year
			}
			else {
				std::cout << "Please select a valid menu option" << std::endl;
			}

		}

		else {
			std::cout << "Please select a valid menu option" << std::endl;
		}

		
	return 0;
}
