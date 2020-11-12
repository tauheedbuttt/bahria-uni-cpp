# Data Structures — Mid Term Exam

**Type:** Exam — Data Structures
**Concepts:** Linked List Reversal, Stack, Circular Queue, Common Elements

Three timed exam questions covering core DS concepts.

## Questions

### Q1 — Reverse Linked List Using Stack
`q1/` — Builds a linked list of 10 nodes, uses a `Stack` to reverse it in O(n) by pushing all nodes then popping into a new list.

| File | Description |
|------|-------------|
| `main.cpp` | `reverseList()` function + test driver |
| `Node.h` | Singly linked node |
| `Stack.h / .cpp` | Stack of `Node*` pointers |
| `List.h / .cpp` | Linked list with `insert()` |

### Q2 — Hot Potato with Circular Queue
`q2/` — 6 players in a circular queue. Each round, a random number of passes happen, then one player is eliminated. Last remaining player wins.

| File | Description |
|------|-------------|
| `main.cpp` | Game loop using `CircQueue` |
| `Queue.h / .cpp` | Circular queue implementation |

### Q3 — Common Elements in Two Linked Lists
`q3/` — Two linked lists of student names. Finds intersection (common names) by comparing all pairs.

| File | Description |
|------|-------------|
| `main.cpp` | `common()` function + setup |
| `Node.h` | Node with `string` data |
| `List.h / .cpp` | Linked list with `insert()` and `traverse()` |
