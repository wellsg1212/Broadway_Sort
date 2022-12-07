# Broadway_Sort
The Tree Muskateers DSA final project - sorting broadway shows pulled from a CSV based on a variety of user inputs.

================== Break; a Leg! Broadway Sorter =====================

Included are a .cpp file with code that pulls data from any .csv file you select (filename is hardcoded) as long as the file uses pipes (|)
as delimiters. It also contains a print function that prints out all information from a user-selected production. The DataStorage.cpp file can be placed in the same folder as the Broadway_Data_Pipe.csv file (as it is in this repo) and run and it should access the file correctly.

Basically, a vector is created where each node is an object of type 'Production', a class that contains info about year, title, theater, type of production, 
attendance, and revenue. All of this data is stored privately and hidden from main(). Each of the sorting algorithms use this to pull each piece of data from as they need it. Each algorithm uses its own data structures as it runs.

Also included is a .csv file with 100,001 rows as is described above, the first of which is skimmed as header data. It uses pipes as delimiters to account for the fact that some plays have commas in their titles, and thus, a comma delimiter does not work.
