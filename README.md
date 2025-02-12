# Food Diary

---
## Objectives
Demonstrate knowledge about the following topics:

- Pointers
- Operators
- File Input/Output

### The Problem to Solve
This program will allow the user to monitor their calorie intake by keeping track of the food they eat. The program will use a vector list of pointers for LogItems. 
Your assignment, is to write a program to read information from the file ../data/DailyIntake.csv and store it in a vector.

The file `../data/DailyIntake.csv` contains data for each of the .  Each `LogItem` is contained on one line. The file keeps repeating the format of Food, Calories, Grams, Portion

Here is an example of the file format...

```text
Greek Yogurt, 100, 170, 1
Blueberries, 84, 140, 1
Almonds, 160, 24, 1
```

### Given Files
You will be given in the following files:
- `src/Food.cpp`
- `src/Food.h`
- `src/LogItem.cpp`
- `src/LogItem.h`

The Food and LogItem class are the same files that you used in the Module 3 Learning Activity.  The constructor for the Food class takes in 
parameters for the name of the food item, the calories, and grams.  There are getters and setters for those same variables
and an operator<< to display the information.

The LogItem class constructor takes Food as the first parameter, and the number of servings for the second parameter.



### Files to Work on
You will be working in the following files:

All functions will be part  of the library order. The library consists of these two files:
- `src/Logger.cpp`
- `src/Logger.h`

Our "driver" file will be
- `src/main.cpp`

## Logger class
The logger class is different from the Module 3 Learning activity.  It will still help log the food intake for each day, 
but will read that information from a file.  Create a class of functions to help you read the file and calculate the calorie intake.

### Logger.h
1. Create a class named `Logger`
2. In the private section, create two variables 
    - `vector` of `shared_ptr<LogItem>` to keep track of the food items
    - an `int` variable that will keep track of the total calories
3. Create three functions definitions
   - Function prototypes for the functions described in the next part.

### Logger.cpp
Make sure to add any necessary header files and scope the functions back to the order namespace. 

#### Constructor: Sets the criteria for the FileFilter
_Constructor Setup_
- Named `Logger`.
- Constructors do not contain a return type
- Accepts one parameter for the filename in order to read all the data in, setting the class vector. Then using this data we'll call use this data to set the calories member variable.
The constructor will call both the Load_Data() and GetCalorieCount() functions.


#### Function 1: Load the data into the vector of share_ptr<LogItem>

_Function Setup_
- Named `LoadData()`.
- Returns a void
- Accepts one parameter
    - The parameter is a `std::string` and represent the filename that is to be read.
    
_Function Task_
    Reads the file one line at a time.  Parses the file into foodName, calories, grams, servings.
    For each line, it will create a `Food` object and a `shared_ptr` to a `LogItem`. 
    Each of these should be added into the vector of share_ptr<LogItem>.


#### Function 2: Overloaded [] operator to return value at a given position

_Function Setup_
  - Named `operator[]`. 
  - Returns a `shared_ptr<LogItem>`
  - Accepts one parameter. 
    - The parameter is an int that represents the position in the list to be retrieved.  
    
_Function Task_
This function will return the given position in the vector.  It will throw an std::out_of_range() error if the parameter
given is not within the bounds of the vector.

#### Function 3: Calculates the Calorie count for the day
_Function Setup_
* Named `GetCalorieCount()`. 
* Returns an int value
* Accepts 0 parameters

_Function Task_
Returns the sum of all the calories in the vector.

**Example**:
GetCalorieCount() would return 100 + 84 + (60 * 2) = 304
```text
Greek Yogurt, 100, 170, 1
Blueberries, 84, 140, 1
Honey, 60, 21, 2
```


#### Function 4: operator<< to display the information
_Function Setup_
* Named `operator<<
* Returns std::ostream &
* Accepts two parameters for one review
    * The first parameter is a `std::ostream&` and represents the stream it will write to
    * The second parameter is a `const Logger &` and represents the object to write to the stream.
    * Don't forget to dereference the pointer as you add it to the stream.

_Function Task_
* Writes the LogItem to the stream.  One LogItem per line (Use the operator<< in the LogItem class)

**Example**:
The following example would take the following data and display it like the given output.
```text
Greek Yogurt, 100, 170, 1
Blueberries, 84, 140, 1
Honey, 60, 21, 2
```
Output
```text
Greek Yogurt                   1x    100
Blueberries                    1x     84
Almonds                        1x    160
Honey                          2x    120
```

## Putting it all Together
The criteria for the file reading should be handled in the `main.cpp` file.
### Main.cpp

Create the criteria and read the files in `main.cpp` by doing the following.
1. Ask the user for the file they would like to calculate
2. Display the items in the list using the operator<<
3. Display the calories for that day using the GetTotalCalories() 
4. There are two files you may test with, DailyIntake.csv has a menu for a 2000 calorie day.  DailyIntakeSmall has just a few items to help you debug.
5. You are welcome to test the operator[].  That will be used for testing the smart pointers.  
See example below...

```text
-----------------------------
-- Pointers  ---
-----------------------------
Please enter the filename: DailyIntake.csv

Here is the items for that day:
Greek Yogurt                   1x    100
Blueberries                    1x     84
Almonds                        1x    160
Honey                          2x    120
Sub Roll                       1x    430
Sliced Ham                     2x     68
Sliced Cheese                  1x    104
Lettuce                        1x      5
Sliced Tomatoes                2x      6
Sun Chips                      1x    140
Diet Coke                      1x      0
Apple                          1x     95
Peanut Butter                  1x    188
Chicken                        1x    335
Quinoa                         1x    222
Asparagus                      5x     15
Butter                         2x    204
Calories                            2276

```
