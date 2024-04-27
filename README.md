# Skip_list
<P>In this project we are going to implement Skip List Data Structure</P>

<h2>TABLE OF CONTENTS:</h2>
  -->Insert Operation
<br>
  -->Search Operation
<br>
  -->Delete Operation


<h2>INTRODUCTION TO SKIP LIST</h2>
<p>Skip List is a probabilistic data structure that provides an alternative to balanced trees for insertion, search and deletion of elements.It is essentially an ordered linked list that allows for efficient searching with different levels of linked lists, each acting as an express lane to navigate through the data quickly.
It combines the advantages of Arrays and linked lists.</p>

![OIP](https://github.com/CybersecurityDSA/skip_list/assets/167642797/1abf7b55-0966-4d74-aab8-dfedc2556d17)

<h2>Key Features of skip list are as follows:</h2>
==>Simple implementation
<br>
==>Efficient Search
<br>
==>Concurrent Operations

<p><br>Skip Lists have some important applications in various areas, such as distributed systems, databases, sorting algorithms
  and data compression algorithms.</p>

  <h2>Time complexity analysis of Skip List: </h2>
<h3>Insertion Analysis -</h3>
<p>Average case time complexity for insertion is O(log n) because insertion process involves traversing the levels of the skip list to find the correct position for the new element. Where worst case analysis, when all the elements are in base level is O(n).</p>

<h3>Search Analysis -</h3>
<p>It is also similar to the Insertion analysis where the average case analysis is O(logn) as because ,on average, the no.of levels during the search operation is proportional to log n and Worst case analysis is O(n).</p>

<h3>Deletion Analysis -</h3>
<p>For deletion also the average time complexity for deleting an element from a skip list is O(log n) because, it's process involves searching for the element and then removing it from all the levels of the Skip List. Worst case analysis is O(n) like all other operations.</p>

![image](https://github.com/CybersecurityDSA/skip_list/assets/167642797/6dbc61f7-7699-4474-971f-5312986063ad)
