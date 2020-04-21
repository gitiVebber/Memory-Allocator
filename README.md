Memory-Allocator

simulate the OS memory allocator.

This exercise simulates the operation of the memory system in a program instance. It has an initial at the start of the run, and during the program the user can allocate and release memory clices of memories in various sizes. The user can also optimize the system by uniting free memory blocks into one continuous memory.

The idea is like this: In every block of memory, the first byte marks its size, and its LSB bit indicates whether it is free or allocated yet. LSB 0 = THE BLOCK IS FREE

NOTE: Like the true OS, my system only works with aligment memory slices to the BUSS of the computer.