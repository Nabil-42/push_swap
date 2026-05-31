# push_swap

[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=flat&logo=c)](https://github.com/Nabil-42/push_swap)
[![School](https://img.shields.io/badge/%C3%89cole_42-Paris-00babc?style=flat)](https://42.fr)
[![Norminette](https://img.shields.io/badge/Norminette-compliant-brightgreen?style=flat)](https://github.com/42School/norminette)

Sorting algorithm using two stacks and a constrained set of operations, with the goal of minimizing the number of moves.

## Description

`push_swap` takes a list of integers as arguments and outputs the minimal sequence of instructions to sort them using two stacks (`a` and `b`). The project requires implementing and choosing an efficient algorithm for large inputs (500 integers must be sorted in under ~5500 operations).

## Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` / `sb` | Swap top 2 elements of stack a / b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push top of b to a / top of a to b |
| `ra` / `rb` | Rotate stack a / b (top → bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate a / b (bottom → top) |
| `rrr` | `rra` and `rrb` simultaneously |

## Stack

- **Language**: C
- **Key concepts**: linked lists, algorithm design, complexity optimization, index normalization

## Algorithm

For small inputs (≤ 3): hardcoded optimal sequences.  
For medium inputs (≤ 5): recursive decomposition.  
For large inputs: chunk-based approach — integers are normalized to indices, divided into chunks, and pushed to stack b in order, then pulled back to a in sorted order.

```
stack a: [5, 1, 4, 2, 3]
  → normalize to indices → chunk into groups
  → push chunks to b in order
  → pull back to a in sorted order
  → result: [1, 2, 3, 4, 5]
```

## 42 Project Info

| Field | Value |
|-------|-------|
| **Project** | push_swap |
| **Circle** | 2 |
| **Norminette** | Compliant |

## What I Learned

- Designing and analyzing sorting algorithms with operation-count constraints
- Linked list manipulation in C
- Index normalization and chunk partitioning strategies