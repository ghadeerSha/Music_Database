##  Database

In this project, your task is to create a **database**, containing data of
your choice, that can search, sort, and add/delete data. All the data in the
database consists of **records**, and each record consists of **fields** of
different types. For example, if your database is storing songs, then its
records might have fields for the song name (a string), the artist (a string),
and the year of publication (a whole number).

Your record must have **at least three fields**, and at least one field must
be a string, and at least one field must be a number. Please note this is the
minimal size of a record, and more fields are encouraged.

You should make your database about something you're interested in. For
example, your records could be songs, movies, books, games, celebrities,
sports teams, etc.


## General Implementation Constraints

Please use standard C++ techniques as discussed in the course.  

**Important!** You *cannot* use `vector`, or any other C++ "container" class
from the STL or elsewhere. Instead, we want you to re-use and modify your
dynamic array class from assignment 3 to work with this assignment.


Not being allowed to use `vector` or similar classes might seem like a strange
constraint. In "real life" you would definitely use `vector`, or any other
class that makes sense. But the purpose of this course is to understand the
low-level details that go into coding classes such as `vector`. We want to see
that you can do this, not just call pre-made code.



## Basic Requirements

- It must compile on Ubuntu Linux. If the marker can't compile your code, your
  mark for this project will be 0.

- It must have no memory leaks or memory errors, according to `valgrind`,
  e.g.:


### Source Code Readability 

- All names of variables, functions, structs, classes, etc. are sensible,
  self-descriptive, and consistent.

- Indentation and spacing is perfectly consistent and matches the structure of
  the program. All blank lines and indents should have a reason.

- All lines are 100 characters in length, or less.

- Comments are used when appropriate, e.g to describe code that is tricky or
  very important. There are no unnecessary comments, and no commented-out
  code.

- Overall, the source code is easy to read and understand.


### Design Features (8 marks)

- A class that stores a single database record. The name of this
class is up to you, but it should describe what it stores. For instance, if
your database is storing songs, then a good name for this class is `Song`.

 - A class called `Database` that stores all the records. The
methods of this class are probably where you want to implement the searching
and sorting functions.

- A class called `Menu` that represents a menu of choices that the
user can choose from. See below for more details.

<img width="293" alt="start program" src="https://github.com/ghadeerSha/Music_Database/assets/167367841/f791595b-374a-44dc-9ba4-6a64a69ebbcd">


### The Database Class 


### Menus 

```
Welcome to the Song Database!
-----------------------------

(A)dd a song.
(F)ind a song.
(D)elete a song.
(L)ist songs.
(Q)uit

Enter the letter of your choice: 
```

### Adding a Record 

- When the user chooses to enter a record, then your program asks
them to enter each piece of data in the record. After the user enters valid
data, then your program should say the record has been added, and go back to
the main menu.

<img width="179" alt="Database_Add" src="https://github.com/ghadeerSha/Music_Database/assets/167367841/38d0197d-c397-4a5e-9ae8-9b4920cf39b9">


### Finding a Record 

- When the user chooses this option they are shown a sub-menu that
lists the different ways they can search for a record. The user should be
allowed to search for any kind of data in the record. For example, in a song
database where song records consist of a name, artist, and year, the sub-menu
might look like this:

```
Find a Song
-----------

You can search by:

(N)ame of song
(A)rtist who performed the song
(Y)ear of song

(R)eturn to main menu

Enter the letter of your choice: 
```

- When searching for strings, one kind of search should print all
records where the typed-in string from the user exactly matches the
appropriate field of a record.

- When searching for strings, one kind of search should print all
records where the typed-in string from the user occurs as a *substring* in the
appropriate field of a record.

- When searching for numbers, one kind of search should print all
records where the typed-in number from the user exactly matches the
appropriate field of a record.

- When searching for numbers, one kind of search should print all
records where the number of the appropriate field of a record is in a range,
from low to high. This would, for example, let the user see all songs in a
song database from the year 2005 to 2015.


<img width="197" alt="Database_Find" src="https://github.com/ghadeerSha/Music_Database/assets/167367841/e4a7032a-fe4c-416d-b49c-108f5fb9b870">


### Deleting a Record 

- When deleting a record, one way to do this is to search by the
*exact* string that occurs in a field of the record. 

- When deleting a record, one way to do this is to search for a
*substring* that occurs in a field of the record.

- When deleting a record, one way to do this is to search by the
*exact* number that occurs in a field of the record.

<img width="268" alt="Database_Delete" src="https://github.com/ghadeerSha/Music_Database/assets/167367841/ae683708-5a94-4d26-bf82-cc5e094e2667">


**(1 mark)** When deleting a record, one way to do this is to search for
numbers in a field that appear in a low to high range of numbers.

In all cases of deleting records:

- display the searched-for records to the user, and then ask them if they are
  sure they want to delete them

- if no matching records are found, then print a helpful message to the screen
  telling the user this


### Listing Records

- For each string field in your record, allow the user to list all
records in *alphabetical order*.

- For each string field in your record, allow the user to list all
records in *reverse alphabetical order*.

- For each numeric field in your record, allow the user to list all
records in *ascending order*.

- For each numeric field in your record, allow the user to list all
records in *descending order*.


<img width="249" alt="Database_List" src="https://github.com/ghadeerSha/Music_Database/assets/167367841/b40444cb-3939-4318-a92e-8cc816388457">

<img width="214" alt="Database_ListName" src="https://github.com/ghadeerSha/Music_Database/assets/167367841/fbfdad64-9219-4e57-a1a6-4b663dbc588b">


### Starting and Quitting the Database 

- When your program starts it reads the records from a text file
`database.txt` into memory.

- In the main menu, there is an option for the user to quit the
database. When the user chooses it the program ends.

