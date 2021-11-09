This is an incomplete project for learning C++ by r. togn. rtognoni1@student.gsu.edu, 2021.
The goal is to simulate a database with US stock market data including price history etc. 
Currently it will set up the DB with a list of companys, ticker names and industries. 
If you look at this there is probably a lot of stray junk from me trying to figure out C++. I plan to finish all this and go back for cleanup later. 

To run: compile and run main(). Should be simple as that but you may need to figure out the current working folder situation if there is an error.
Will need SQLlite software to inspect the DB. Currently it will not print anything.


These names and industries are randomly generated but their length and char frequency are done to match the real NASDAQ market. 
An excel file where I got the numbers for this is in the Docs and Images folder see NameFunctions.cpp for the code on that.

SQL info: using CppSQLLite3 by Rob Groves for my connection commands. It is a wrapper for an older C library. This code is included in its original format.
Special thanks:
https://www.redblobgames.com/articles/probability/damage-rolls.html for algorithm for random weights. 
NASDAQ for having public data. 