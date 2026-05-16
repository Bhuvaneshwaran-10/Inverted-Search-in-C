# Inverted Search Engine in C

## Overview

The Inverted Search Engine is a Data Structures and Algorithms (DSA) based project implemented in C programming.
This project creates an indexed database of words from multiple text files using Hash Tables and Linked Lists, enabling fast and efficient word searching.

The system stores:

* Words
* File names
* File count
* Word occurrence count

This project demonstrates the working principle of search engine indexing mechanisms.

---

## Features

* Create database from multiple text files
* Fast word searching using hashing
* Display complete indexed database
* Save database into backup file
* Update database from backup file
* Track file count and word count
* Collision handling using linked lists
* Menu-driven program

---

## Technologies Used

* C Programming
* Hash Tables
* Linked Lists
* File Handling
* Dynamic Memory Allocation
* Structures and Pointers

---

## Project Structure

```bash id="nlm42d"
.
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
```

---

## Working Principle

1. Read all input text files
2. Extract each word from the files
3. Generate hash index using the first character
4. Store data in hash table
5. Maintain:

   * Word
   * File count
   * File names
   * Word count
6. Perform search and display operations efficiently

---

## Hashing Technique

* The hash index is generated based on the first character of the word.
* Each index contains a linked list to handle collisions.
* This improves searching efficiency compared to linear searching.

---

## Sample Input Files

### f1.txt

```text id="w5icm9"
Hi hello how are you
i am fine
today is tuesday
```

### f2.txt

```text id="go1q38"
hi
hi
hi
```

### f3.txt

```text id="b5k0oq"
mom
dad
sister
hi
```

---

## Sample Output

```text id="7b1l6c"
Index      Word         File_Count      File_Name       Word_Count
------------------------------------------------------------------
0          am           1               f1.txt          1

7          hi           3               f1.txt          2
                                        f2.txt          3
                                        f3.txt          1

19         today        1               f1.txt          1
```

---

## Compilation

```bash id="y8qqc0"
gcc *.c
```

---

## Execution

```bash id="o5k9vz"
./a.out f1.txt f2.txt f3.txt
```

---

## Functionalities

### Create Database

Creates the inverted index database from input files.

### Display Database

Displays all indexed words with file details and word count.

### Search Database

Searches a word and displays the file information.

### Save Database

Stores database content into a backup file.

### Update Database

Restores database from saved backup file.

---

## Learning Outcomes

* Understanding of Hash Tables
* Linked List implementation
* File handling in C
* Dynamic memory allocation
* Collision handling techniques
* Modular programming
* Real-world implementation of searching concepts

---

## Future Enhancements

* Case-insensitive search
* Stop-word removal
* Better hashing techniques
* Ranking mechanism
* GUI-based implementation
* Support for large datasets
* Trie-based searching

---

## Author

**Bhuvaneshwaran**

---
