If you’ve seen television commercials for long-distance phone companies lately, you’ve noticed that
many companies have been spending a lot of money trying to convince people that they provide the
best service at the lowest cost. One company has “calling circles.” You provide a list of people that
you call most frequently. If you call someone in your calling circle (who is also a customer of the same
company), you get bigger discounts than if you call outside your circle. Another company points out
that you only get the big discounts for people in your calling circle, and if you change who you call
most frequently, it’s up to you to add them to your calling circle.
LibertyBell Phone Co. is a new company that thinks they have the calling plan that can put other
companies out of business. LibertyBell has calling circles, but they figure out your calling circle for
you. This is how it works. LibertyBell keeps track of all phone calls. In addition to yourself, your
calling circle consists of all people whom you call and who call you, either directly or indirectly.
For example, if Ben calls Alexander, Alexander calls Dolly, and Dolly calls Ben, they are all within
the same circle. If Dolly also calls Benedict and Benedict calls Dolly, then Benedict is in the same
calling circle as Dolly, Ben, and Alexander. Finally, if Alexander calls Aaron but Aaron doesn’t call
Alexander, Ben, Dolly, or Benedict, then Aaron is not in the circle.
You’ve been hired by LibertyBell to write the program to determine calling circles given a log of
phone calls between people.
Input
The input file will contain one or more data sets. Each data set begins with a line containing two
integers, n and m. The first integer, n, represents the number of different people who are in the data
set. The maximum value for n is 25. The remainder of the data set consists of m lines, each representing
a phone call. Each call is represented by two names, separated by a single space. Names are first names
only (unique within a data set), are case sensitive, and consist of only alphabetic characters; no name
is longer than 25 letters.
For example, if Ben called Dolly, it would be represented in the data file as
Ben Dolly
Input is terminated by values of zero (0) for n and m.
Output
For each input set, print a header line with the data set number, followed by a line for each calling
circle in that data set. Each calling circle line contains the names of all the people in any order within
the circle, separated by comma-space (a comma followed by a space). Output sets are separated by
blank lines.
Sample Input
5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron
14 34
John Aaron
Aaron Benedict
Betsy John
Betsy Ringo
Ringo Dolly
Benedict Paul
John Betsy
John Aaron
Benedict George
Dolly Ringo
Paul Martha
George Ben
Alexander George
Betsy Ringo
Alexander Stephen
Martha Stephen
Benedict Alexander
Stephen Paul
Betsy Ringo
Quincy Martha
Ben Patrick
Betsy Ringo
Patrick Stephen
Paul Alexander
Patrick Ben
Stephen Quincy
Ringo Betsy
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Quincy Martha
0 0
Sample Output
Calling circles for data set 1:
Ben, Alexander, Dolly, Benedict
Aaron
Calling circles for data set 2:
John, Betsy, Ringo, Dolly
Aaron
Benedict
Paul, George, Martha, Ben, Alexander, Stephen, Quincy, Patrick