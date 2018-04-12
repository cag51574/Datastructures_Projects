README.txt
Author: Cameron Garratt
Submission Date: 10/7/16
Purpose: Explains everything you need to know about project
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate
assistance. I have not copied or modified code from any source other than the course webpage or
the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in
accordance with the University of Georgia's Academic Honesty Policy and the policies of this
course. I recognize that my work is based on an assignment created by the Department of
Computer Science at the University of Georgia. Any publishing or posting of source code for this
project is strictly prohibited unless you have written consent from the Department of Computer
Science at the University of Georgia.

Part 1:

It was stated in piazza that it would be okay to include the implementation of the 
priority queue in the .h file. Thus, I do not have a PriorityQueue.cpp because my
implementation of the priority queue is in the .h file.

To compile this program type:

$ g++ priorityqueue.h

$ g++ PriorityTest.cpp -o a.out

To run this program type:

$ ./a.out

To clean the directiory of previous runs type:

$ rm *.gch

$ rm *.out

Once the program is run, blah....


Part 2:

It was stated in piazza that it would be okay to include the implementation of the 
queuetype in the .h file. Thus, I do not have a QueueType.cpp because my
implementation of the queuetype is in the .h file.
Please ignore the warnings when compiling project. They are caused by trying to
deal with empty queues when the function shouldn't be called with an empty queue.
Thus, the function returns NULL and the warning is caused by trying to convert 
NULL into whatever <ItemType> is. This will not affect how the queue works or
cause any errors during runtime.

To compile this program type:

$ g++ *.h

$ g++ BankSimulationTest.cpp -o a.out

To run this program type:

$ ./a.out input.txt

This assumes that the name of your input file is input.txt
If your input file is named something else, to run the program, please type:

$ ./a.out [yourinputfilename]

To clean the directiory of previous runs type:

$ rm *.gch

$ rm *.out

It is very important that the input file used, uses the exact same format
as the example input file in the project description. Upon running the 
project, you will see the output as requested in the project destcription.
I have added to the output the customer names because I believe this helps
with the clarity of the project and the understanding of what is being 
printed to the screen. Each function in the code is commented.


TODO
fill out readme
    -- compile pq.h
fix pqtest.cpp
comment on pqtest.cpp

