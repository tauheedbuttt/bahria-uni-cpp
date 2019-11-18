# BINGO Game

**Type:** Lab Project — Computer Programming Lab (BSCS 1st Year)
**Concepts:** 2D Arrays, Random Numbers, Game Loop, Goto

Console-based BINGO game where a player competes against the PC. Both sides get randomly generated 5×5 sheets. Players take turns crossing numbers; first to complete 5 lines (horizontal, vertical, or diagonal) wins. PC picks numbers randomly each turn.

## Files
| File | Description |
|------|-------------|
| `BINGO.cpp` | Full single-file implementation — setup, display, input, win-check for both player and PC |

## How It Works
- `Setup()` fills two 5×5 grids with unique random numbers 1–25
- Each turn: player enters a number, PC picks randomly via `pcinput()`
- `assignvalues()` zeroes out matched cells on both sheets
- `userCheck()` / `pcCheck()` count completed rows/cols/diagonals; first to 5 lines wins
