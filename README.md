# push_swap  
## Grade: 100/100  
![pushswap](https://github.com/user-attachments/assets/f393efff-5cb0-469b-b4f1-09f9877ee0db)

## Overview:

push_swap is a challenging project that involves sorting a list of integers using a limited set of stack operations. The goal is to design an efficient algorithm that sorts numbers with as few moves as possible, by only using specific operations on two stacks. This project deepened my understanding of algorithm optimization, data structures (especially stacks), and rigorous coding standards as dictated by the 42 Norm.

## Features:
### Efficient Sorting Algorithm:
- Implements an optimized algorithm to sort integers with minimal operations.

### Stack Operations:
- Uses a restricted set of operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr` to manipulate the stacks.

### Robust Error Handling:
- Validates inputs and handles errors gracefully to ensure reliable operation.

### Norm Compliance:
- All code is written in strict adherence to the 42 Norm, ensuring readability, maintainability, and efficiency.

## Project Details:
**Language:** C

**Compilation:** Must be compiled with the following flags: `-Wall -Wextra -Werror`

**Norm Compliance:** Code adheres strictly to the 42 Norm.

**Testing:** The algorithm has been rigorously tested with various datasets to ensure both correctness and efficiency.

## Usage:
***To compile push_swap:***

```bash
make
```
***To run push_swap with a list of numbers:***
```bash
./push_swap as_many_numbers_as_you_like
```

## Files Structure

- **algos.c:**  
  Implements core sorting algorithms (e.g., bubble sort for initial ordering) and functions to move elements between stacks based on sorted order.

- **algo_utils.c:**  
  Provides utility functions for the sorting algorithms, including checking order (reverse or ascending) and calculating numeric ranges for pushing elements.

- **commands.c:**  
  Contains functions for all the stack operations (rotate, reverse rotate, swap, push to A/B). These functions print the corresponding commands (e.g., "sa", "pb") as they execute.

- **errors.c:**  
  Handles error management and resource cleanup. This includes freeing all nodes in a linked list and terminating the program on critical errors.

- **ft_split.c:**  
  A custom string splitting function used to parse the input arguments.

- **head_bottom.c:**  
  Manages the head and bottom pointers for the stacks. Provides helper functions to retrieve and update these pointers as the list changes.

- **node.c:**  
  Implements the linked list node structure and functions to add nodes, check for duplicates, and initialize nodes in stack A.

- **parsing.c:**  
  Parses the command-line arguments, validates them, and concatenates them into a single string for further processing.

- **sorting.c:**  
  Contains the main sorting functions. Depending on the number of elements, it chooses the most efficient sorting strategy (e.g., sort_three, sort_four_five, sort_big).

- **utils.c:**  
  Provides helper functions like `ft_atoi` and `ft_strlen`, which are used for error checking and string manipulation.

## What I Learned

Working on push_swap was an incredible learning experience. I gained hands-on expertise in:

- **Algorithm Optimization:** Refining sorting algorithms to minimize the number of operations.
- **Data Structures:** Implementing and manipulating linked lists to represent stacks effectively.
- **Memory Management:** Dynamically allocating and freeing resources while preventing memory leaks.
- **Error Handling:** Designing robust error-checking mechanisms to ensure the program behaves correctly with invalid input.
- **Coding Standards:** Writing clean, maintainable, and efficient C code in strict adherence to the 42 Norm.

## Conclusion

The push_swap project pushed me to improve my problem-solving skills and implement efficient algorithms under tight constraints. It reinforced my understanding of low-level data manipulation in C and the importance of clean, standard-compliant code. This project is a testament to my growth as a developer and my commitment to mastering complex programming challenges.
