# Library Management System

**Type:** Assignment — Object Oriented Programming
**Concepts:** OOP, Composition, Multi-File Classes, Date Handling, Star Ratings

Models a library system with books, students, and an issue/return system. `Book` stores title, author, issue/return dates, genre, and calculates a star rating based on how many times it has been issued. `Student` tracks borrowed books. `Library` manages the collection.

## Files
| File | Description |
|------|-------------|
| `main.cpp` | Entry point |
| `Book.h / .cpp` | Book class — issue tracking, star rating (1–5 stars by issue count) |
| `Student.h / .cpp` | Student class — name, ID, borrowed books |
| `Library.h / .cpp` | Library container class |
| `Date.h / .cpp` | Date utility class used across Book and Student |
