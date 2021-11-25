# MyGym — Gym Management System

**Type:** Project — Object Oriented Programming
**Concepts:** OOP, Inheritance, Abstract Classes, Operator Overloading, File I/O, Composition

Console-based gym management application. Supports two user roles — Member (Standard/Premium) and Owner. Members can sign up, log in, track fees, calculate BMI/macros, and get workout suggestions. Owner can manage gym equipment inventory. Data persisted to file.

## Files
| File | Description |
|------|-------------|
| `MyGym.cpp` | Main driver — role selection, login/signup flow, menu |
| `Member.h / .cpp` | Abstract member base class — name, ID, password, fees, dates |
| `StandardMember.h / .cpp` | Standard membership (2000 fee) |
| `PremiumMember.h / .cpp` | Premium membership (4000 fee) with wallet |
| `Owner.h / .cpp` | Owner class — login/signup, equipment management |
| `BasicGym.h / .cpp` | Utility class — BMI and macro calculators |
| `Machine.h / .cpp` | Gym machine inventory (Chest, Back, Leg, Cardio) |
| `Chest/Back/Leg/Cardio.h / .cpp` | Equipment category classes |
| `Name.h / .cpp` | First/last name wrapper |
| `Date.h / .cpp` | Date class for registration and due dates |
| `ID.h / .cpp` | ID utility class |

## Features
- Login / Signup with password confirmation
- Fee submission with date tracking
- BMI calculator (weight/height)
- Macro calculator (protein/carb/fat targets)
- Equipment inventory check by owner
- File persistence for member and machine data
