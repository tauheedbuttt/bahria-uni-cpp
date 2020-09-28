# Bank Account OOP — Multi-File

**Type:** Assignment — Object Oriented Programming
**Concepts:** OOP, Inheritance, Pure Virtual Functions, Multi-File Compilation, Abstract Classes

Bank account system split across multiple header/source files. `account` is an abstract base class with pure virtual `credit()` and `debit()`. `saving` and `currentAccount` implement the interface with different rules (e.g. saving has minimum balance enforcement).

## Files
| File | Description |
|------|-------------|
| `account.h / .cpp` | Abstract base class with protected balance/name/acc fields |
| `saving.h / .cpp` | Saving account — enforces minimum balance on debit |
| `currentAccount.h / .cpp` | Current account — deducts transaction fee on credit/debit |
| `main.cpp` | Entry point (includes all headers) |

## Note
Earlier iteration of the same design also exists as `bank-account-inheritance.cpp` in the root — that one is a consolidated single-file version with interest and year-end calculations.
