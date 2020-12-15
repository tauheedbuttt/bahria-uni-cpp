# Data Structures Lab — Mid Term Exam

**Type:** Lab Exam — Data Structures
**Concepts:** 2D Linked List (next + bottom pointers), Flatten, Bubble Sort, File I/O, Operator Overloading

Two timed lab exam questions.

## Questions

### Q1 — Flatten and Sort 2D Linked List
`q1/` — Reads a 2D linked list from `input.txt` (N lists, each with Mi elements). Nodes connect via `next` (horizontal) and `bottom` (vertical). Flattens into a single `bottom`-linked chain, then sorts in-place with bubble sort.

| File | Description |
|------|-------------|
| `main.cpp` | Driver — read, flatten, sort, display |
| `Node.h / .cpp` | Node with `next` and `bottom` pointers |
| `List.h / .cpp` | List class with file read, overloaded `<<` operator |

### Q2 — Stack Implementation
`q2/` — Custom `Stack` class with array-based storage.

| File | Description |
|------|-------------|
| `main.cpp` | Stack usage driver |
| `Stack.h / .cpp` | Stack with push/pop/peek |
