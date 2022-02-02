John is a diver and a treasure hunter. He has just found the location of a pirate ship full of treasures.
The sofisticated sonar system on board his ship allows him to identify the location, depth and quantity
of gold in each suken treasure. Unfortunatelly, John forgot to bring a GPS device and the chances of
ever finding this location again are very slim so he has to grab the gold now. To make the situation
worse, John has only one compressed air bottle.
John wants to dive with the compressed air bottle to recover as much gold as possible from the
wreck. Write a program John can use to select which treasures he should pick to maximize the quantity
of gold recovered.
The problem has the following restrictions:
• There are n treasures {(d1, v1),(d2, v2), . . .(dn, vn)} represented by the pair (depth, quantity of
gold). There are at most 30 treasures.
• The air bottle only allows for t seconds under water. t is at most 1000 seconds.
• In each dive, John can bring the maximum of one treasure at a time.
• The descent time is tdi = w ∗ di
, where w is an integer constant.
• The ascent time is tai = 2w ∗ di
, where w is an integer constant.
• Due to instrument limitations, all parameters are integer.
Input
The input to this program consists of a sequence of integer values. Input contains several test cases.
The first line of each dataset should contain the values t and w. The second line contains the number
of treasures. Each of the following lines contains the depth di and quantity of gold vi of a different
treasure.
A blank line separates each test case.
Note:
In this sample input, the bottle of compressed air has a capacity of 200 seconds, the constant w has
the value 4 and there are 3 treasures, the first one at a depth of 10 meters and worth 5 coins of gold,
the second one at a depth of 10 meters and worth 1 coin of gold, and the third one at 7 meters and
worth 2 coins of gold.
Output
The first line of the output for each dataset should contain the maximum amount of gold that John
can recover from the wreck. The second line should contain the number of recovered treasures. Each of
the following lines should contain the depth and amount of gold of each recovered treasure. Treasures
should be presented in the same order as the input file.
Print a blank line between outputs for different datasets.
Sample Input
210 4
3
10 5
10 1
7 2
Sample Output
7
2
10 5
7 2