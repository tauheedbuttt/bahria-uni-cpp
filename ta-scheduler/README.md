# Teaching Assistant Lab Scheduler

**Type:** Semester Assignment — Data Structures
**Concepts:** Queue, Stack, Linked Nodes, File I/O, Operator Overloading, Custom Time Class, Sorting

Simulates a university computer lab managed by Teaching Assistants (TAs). Students arrive at different times, queue at the door (LDM), borrow laptops from a stack, get help from TAs, and eventually leave happy or frustrated. Reads input from `input.txt`, writes detailed minute-by-minute log to `output.txt`.

## Files
| File | Description |
|------|-------------|
| `main.cpp` | Driver — reads input, runs 3-day simulation per program |
| `Node.h` | Generic linked node |
| `Stack.h / .cpp` | Stack for laptop serial numbers |
| `Queue.h / .cpp` | Queue for Door, LDM, and TA lines |
| `Time.h / .cpp` | 24hr time class with operator overloading (`++`, `<=`, `-`) |
| `teachingAssistant.h / .cpp` | TA class — availability schedule, current student |
| `DataStructuresStudent.h / .cpp` | Student class — name, arrival time, question count, satisfaction |

## Simulation Flow
1. Laptops loaded onto `Stack` from file
2. Students enqueued in `Door` at their arrival time
3. Each minute: students move Door → LDM → TA → back to LDM → exit
4. TA spends 5 minutes per student question; student may re-queue if unsatisfied
5. Lab closes when last TA's shift ends; daily summary written to file
