# Broadway_Sort
DSA final project - sorting broadway shows pulled from a CSV based on a variety of user inputs.

Included are a .cpp file with code that pulls data from any .csv file you select (filename is hardcoded) as long as the file uses pipes (|)
as delimiters. It also contains a print function that prints out all information from a user-selected production.

Basically, a vector is created where each node is an object of type 'Production', a class that contains info about year, title, theater, type of production, 
attendance, and revenue. All of this data is stored privately and hidden from main().

Also included is a .csv file with 100,001 rows, the first of which is skimmed as header data. It uses pipes as delimiters to account for the fact that
some plays have commas in their titles, and thus, a comma delimiter does not work.
