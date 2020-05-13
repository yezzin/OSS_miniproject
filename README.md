# Students in Handong Dormitory

## Program Description
This is CRUD program you can manipulate information.
```C - Create / R - Read / U - Update / D - Delete```
There are many students in dormitories of Handong God's University.
This program is to **manage information of students in dormitories**.
You can also manipulate the list of students you want.

## Functions of this program
### Create
* Add a new member
You can add a new member from _data.txt_ file or from _standard input_.

### Read
* Print all members
Print all information you working on.

* Student list
Show the list of records according to rc or assigned year.
If there isn't any record as you want to see, notice that.

* Load a new data file
Load the entire data from _data.txt_ file.
Original records you are working on will be deleted and initialized by data in text file.

* Save(export) to a data file
Write(or Save) the current records into report.txt file in a report format.
>__report format__
```
Name: [(str) Name with one space] - [(char) Gender]
Year: [(int) Assigned Year]
RC: [(str) RC]
```
```
+ Additionally, records are divided by '==='.
```
>ex)
```
======================
Name: Ye Jin - f
Year: 18
RC: Torrey
======================
Name: Sam Dasoo - m
Year: 19
RC: Sonyangwon
```

### Update
* Update member details
Update the detail of one member of records list you want.
Change only the part of one record, using __'\n'__ or __'0'__ input for leaving same.

### Delete
* Delete a member - Delete
Delete _a detail_ or _all details_ of one record you want

### Extra
* Defragment
If there is(are) empty record(s), _collect non-empty records_.
It will print the status of defragment success or not.
* Search
Search the name using input a(some) char(s).
This is case-sensitive, the capital.
* Gender ratio
Calculate the number of students according gender.
Non-fixed-gender records are divided separately.
* Sorting
Sorting the list of records according to user input.
According to RC, (assigned)Year, and Gender.

## How to build?
```
make
```

## How to execute?
```
./a.out  
*******
[Menu]
*******

Select a menu> (function number)
```
