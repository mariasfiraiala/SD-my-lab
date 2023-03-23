# Hashtable  
 
* Q: What is an hashtable and how it is implemented?

   A: It is a data structure that maps keys to values for highly efficient lookup. A simple but common implementation of hashtables uses an array of linked lists and a hash code function

   <img src=https://upload.wikimedia.org/wikipedia/commons/thumb/7/7d/Hash_table_3_1_1_0_1_0_0_SP.svg/2560px-Hash_table_3_1_1_0_1_0_0_SP.svg.png
     alt="API"
     style="float: center; margin-right: 10px; " />

* Q: What is a hash function?

   A: A hash function is a mathematical function that takes in an input of arbitrary size and  produces a fixed-length string of characters or bits, known as a hash. (usually this value is a positive integer)

* Q: What is the API for the hashtable?

   A:
   | Operation | Complexity | 
   |-----------|-----------|
   | Insert element| O(1)|
   | Find element| O(1)| 
   | Search element| O(1)| 
   | Remove element| O(1)| 

[Further Reading](https://stackoverflow.com/questions/4664521/understanding-hash-tables)