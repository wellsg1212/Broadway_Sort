#include <iomanip>
#include <iostream>
#include <fstream>

#include <sstream>
#include <vector>
#include <string>

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

int main() {
	std::vector<Production> dataSet;

	dataLoader("Broadway_Data_Pipe.csv", dataSet);

	int input = 0;

	std::cout << "Pick a Data point: " << std::endl;

	std::cin >> input;

	printSelected(dataSet[input]);

	return 0;
}