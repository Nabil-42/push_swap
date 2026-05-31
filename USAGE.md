# Usage — push_swap

```bash
./push_swap 5 3 1 4 2
```

The program outputs the sorted sequence of operations to stdout, one per line.

## Example

```bash
$ ./push_swap 5 3 1 4 2
pb
pb
sa
pa
pa
ra
...
```

## Operations Reference

| Op | Description |
|----|-------------|
| `sa` / `sb` | Swap top 2 of stack a / b |
| `pa` / `pb` | Push top of b to a / a to b |
| `ra` / `rb` | Rotate a / b (top goes to bottom) |
| `rra` / `rrb` | Reverse rotate a / b |

## Error Handling

```bash
./push_swap "a b c"    # Error: non-integer argument
./push_swap 1 1 2      # Error: duplicate value
```

Outputs `Error` to stderr on invalid input.

## Validation with checker (bonus)

```bash
ARG="5 3 1 4 2"; ./push_swap  | ./checker 
# Output: OK
```