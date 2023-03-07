# Linked Lists

* Q: What is a data structure?

   A: A collection of values (stored in a specific manner) and the operations that can be applied on the said data collection.

* Q: What is an API?

   A: Application Programming Interface: an interface (or recipe), that tells us, the user, what we can do with a program.
   Does't require us to know the internals of the app, but what its main characteristics are.

   <img src="https://media.sproutsocial.com/uploads/2022/10/API_defined3-02.png"
     alt="API"
     style="float: center; margin-right: 10px;" />

* Q: What is an ArrayList? What about a LinkedList?

   A: An ArrayList is a data structurs that stores its values in a contiguous manner, by occupying consecutive blocks of memory.
   A LinkedList is a data structure thar stores its elements at random, noncontiguous pieces of memory.

* Q: ArrayList vs LinkedList

   A:
   | Operation | ArrayList | LinkedList |
   |-----------|-----------|------------|
   | Memory Map| contiguous| random |
   |Get Element| O(1) | O(n) |
   | Insert Element **start** | O(n)| O(1) |
   | Insert Element **end** | O(1) | O(n) / O(1) if we store the tail |
   | Insert Element **random**| O(n) | O(n) |
   | Delete Element **start**| O(n) | O(1) |
   | Delete Element **end**| O(1) | O(n) / O(1) if we store the tail |
   | Delete Element **random**| O(n) | O(n) |

* [Further Reading](https://stackoverflow.com/questions/2429217/under-what-circumstances-are-linked-lists-useful)
