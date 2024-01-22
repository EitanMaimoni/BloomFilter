# Project-ONE-ex1

running and compiling the code:
in order to compile and run our code you'll have to download c++ compiler, follow the instruction on this link-
https://code.visualstudio.com/docs/cpp/config-mingw

after the compiler is installed, navigate to the src folder in command line and type the following command:
g++ ./main.cpp ./AddUrl.cpp ./App.cpp ./BloomFilter.cpp ./CheckUrl.cpp ./CommandValidator.cpp ./HFunc.cpp ./OneHashValidator.cpp ./TwoHashValidator.cp
./a.out

thats it!

first thing we went over the whole exrecise and divided it into tasks, putting them all on jira and assign some of them to each member of our team(not all of them we wanted to see how each of us is advancing and base on that to divide the rest).

we started all by creating the calc files and test, after we understood how gtest is working we moved on and changed the files names and add some basic tests for the bloom filter, than we wrote some code that should have passed the tests, and than we understood the tests arent good(thing that happend a lot but we got better with the time) we fixed the basic tests and passed them.
we have done so several times, in the refactor stage we added classes and writed tests for those classes and than linked all files to make all the tests run toghther.
at the final stage after we passed all the tests weve done major refactoring,using the command design pattern like in the lecture, we wrote tests for the classes that should be created and than created them, we went back and forth untill we got the result that passed all of the tests.
main refactors:
-creating hash function class
-creating the command pattern slowly one step at a time which include:
  creating validator interface and classes
  creating the command interface and classes(add and check)
  creating the app class and run() fucntion that runs the app


while doing so, one of the team members watched the proffessors video about docker and did the assigment,
first one was easy, one would say as there are many exmaples over the web for that part, the other one needed some thogth and understanding what the professor want, opening a dockerhub account and using the git hub secrets to make the workflow work, and after that checking the folder in dockerhub tos see that its indeed working.

well that was it, it was challenging exrecise and weve really enjoyed it!