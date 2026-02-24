# Game Waiting System (C++ OOP Implementation)

## Overview

This project implements a Game Waiting System using Object-Oriented Programming (OOP) in C++.

The system manages:

- VIP Players (priority-based handling)
- Normal Players (FIFO-based handling)
- Undo functionality
- Player registration and withdrawal
- Player boosting (priority update)
- Game play handling

### Constraints Followed

- STL `queue` is NOT used
- STL `stack` is NOT used
- `unordered_map` is NOT used
- Custom data structures are implemented
- Proper OOP principles are applied

---

# System Design

## 1. Player Class

The `Player` class represents each player in the system.

### Private Members

# Game Waiting System (C++ OOP Implementation)

## Overview

This project implements a Game Waiting System using Object-Oriented Programming (OOP) in C++.

The system manages:

- VIP Players (priority-based handling)
- Normal Players (FIFO-based handling)
- Undo functionality
- Player registration and withdrawal
- Player boosting (priority update)
- Game play handling

### Constraints Followed

- STL `queue` is NOT used
- STL `stack` is NOT used
- `unordered_map` is NOT used
- Custom data structures are implemented
- Proper OOP principles are applied

---

# System Design

## 1. Player Class

The `Player` class represents each player in the system.

### Private Members
int id;
string name;
int level;
string type; // "VIP" or "NORMAL"
int arrivalOrder;




### Features

- Constructor overloading
- Getter methods for all attributes
- Setter for `level` (used in BOOST operation)
- Proper encapsulation (all data members are private)

---

## 2. Data Structures Used

Since STL `queue`, `stack`, and `unordered_map` are not allowed, custom structures were implemented.

### Normal Queue (FIFO)

- Implemented using a dynamic array
- First In First Out behavior
- Used for NORMAL players

### VIP Priority Queue

- Implemented using a Max Heap
- Priority rules:
  1. Higher level first
  2. If levels are equal → earlier arrivalOrder first

This guarantees correct VIP ordering.

### Undo Stack

- Custom stack implementation
- Stores only state-changing operations:
  - REGISTER
  - PLAY
  - BOOST
  - WITHDRAW
- Ignored or no-op commands are NOT recorded

### ID Lookup

- Linear search is used instead of `unordered_map`
- Ensures compliance with constraints

---

# Supported Commands

## REGISTER id name level type

- Adds a player to:
  - VIP queue (if type = VIP)
  - Normal queue (if type = NORMAL)
- Player is stored internally
- Operation recorded in Undo stack

---

## PLAY

- VIP player plays first (highest priority)
- If no VIP → first Normal player plays
- Removed from waiting structure
- Operation recorded in Undo stack

---

## BOOST id newLevel

- Updates the player's level
- Reorders VIP heap if necessary
- Operation recorded in Undo stack

---

## WITHDRAW id

- Removes player from waiting list
- If player does not exist → command ignored
- Operation recorded in Undo stack

---

## UNDO

Reverts the most recent state-changing operation.

Supported undo operations:

- REGISTER → removes the registered player
- PLAY → restores the removed player
- BOOST → restores previous level
- WITHDRAW → restores the removed player

UNDO operations are guaranteed to be valid.

---

## STATUS

Prints the complete system state:
VIP_count Normal_count

VIP Waiting Area
...

Normal Waiting Area
...

Ping-Pong Table
...

UNDO Stack
...



Displays:

- Number of VIP players
- Number of Normal players
- Current waiting lists
- Current player playing
- Undo stack history

---

# Time Complexity

| Operation | Time Complexity |
|------------|----------------|
| REGISTER   | O(log N) (VIP) / O(1) (Normal) |
| PLAY       | O(log N) |
| BOOST      | O(log N) |
| WITHDRAW   | O(N) |
| UNDO       | Depends on operation |
| STATUS     | O(N) |

### Constraints
1 ≤ Q ≤ 10^5
All valid IDs are unique.
UNDO operations are always valid.


---

# File Structure
Player.hpp
Player.cpp
GameSystem.hpp
GameSystem.cpp
NormalQueue.hpp
NormalQueue.cpp
UndoStack.hpp
UndoStack.cpp
VipQueue.hpp
VipQueue.cpp
main.cpp
README.md



---

# OOP Concepts Used

- Encapsulation
- Abstraction
- Constructor Overloading
- Modular Design
- Class Separation
- Custom Data Structure Implementation
- Heap Implementation
- Stack Implementation
- Queue Implementation

---

# Why Custom Structures Were Implemented

Because STL `queue`, `stack`, and `unordered_map` were not allowed:

- Queue implemented manually
- Stack implemented manually
- Heap implemented manually
- Linear search used instead of hash map

This improves understanding of:

- Heap operations
- Manual memory management
- Data structure design
- Algorithmic efficiency

---

# Compilation Instructions
g++ main.cpp Player.cpp GameSystem.cpp NormalQueue.cpp VipQueue.cpp UndoStack.cpp -o game
./game


---

# Conclusion

This project demonstrates:

- Proper Object-Oriented Programming in C++
- Manual implementation of core data structures
- Efficient priority handling using a heap
- Full undo functionality
- Support for up to 10^5 operations

The system strictly follows all given constraints and provides a scalable and modular solution.