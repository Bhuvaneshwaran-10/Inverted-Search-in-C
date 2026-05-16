Inverted Search using Data Structure in C

A powerful Inverted Search System implemented in C programming using Hash Tables and Linked Lists.
This project indexes words from multiple text files and allows fast searching of words along with their occurrence count and file information.

Project Overview

The main objective of this project is to create an Inverted Search Engine similar to the indexing mechanism used in search engines.

The program reads multiple text files, extracts words, stores them efficiently using hashing, and allows users to:

Create a database
Display indexed data
Search words instantly
Save database to a file
Update database from saved file
Features
Read multiple text files
Fast word searching using hashing
Collision handling using linked lists
Display word count and file count
Save database into backup file
Restore database from backup file
Efficient indexing mechanism
Menu-driven application
Technologies Used
Programming Language: C
Concepts Used:
Hashing
Linked Lists
File Handling
Dynamic Memory Allocation
Structures
Pointers
Project Structure
├── main.c
├── main.h
├── Create_DB.c
├── Display_DB.c
├── Search_DB.c
├── Save_DB.c
├── Update_DB.c
├── Validate_args.c
├── functions.c
├── insert_first.c
├── Print_list.c
├── f1.txt
├── f2.txt
├── f3.txt
└── bkt.txt
Working Principle
Read input text files
Extract words one by one
Generate hash index using first character
Store words in hash table
Maintain:
File count
Word count
File names
Allow searching and displaying database
Sample Output
Index      Word         File_Count      File_Name       Word_Count
------------------------------------------------------------------
0          am           1               f1.txt          1
7          hi           3               f1.txt          2
                                           f2.txt       3
                                           f3.txt       1
19         today        1               f1.txt          1
How to Compile and Run
Compile
gcc *.c
Run
./a.out f1.txt f2.txt f3.txt
Example Input Files
f1.txt
Hi hello how are you
i am fine
today is tuesday
f2.txt
hi
hi
hi
f3.txt
mom
dad
sister
hi
Learning Outcomes
Improved understanding of hashing techniques
Learned implementation of inverted indexing
Gained hands-on experience in file handling
Understood linked list manipulation
Enhanced debugging and problem-solving skills
Learned modular programming in C
Future Enhancements
Case-insensitive searching
Support for large datasets
GUI-based search engine
Stop-word removal
Ranking mechanism for search results
Author

Bhuvaneshwaran
