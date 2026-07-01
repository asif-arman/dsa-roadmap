# 102. Binary Tree Level Order Traversal

> **Platform:** LeetCode  
> **Difficulty:** Medium  
> **Topic:** BFS, Binary Tree

---

## Goal

Return the values of the binary tree **level by level**.

Example:

```
        3
      /   \
     9     20
          /  \
         15   7

↓

[
  [3],
  [9,20],
  [15,7]
]
```

---

## Core Idea

Instead of visiting nodes one by one, process **one entire level at a time**.

A **queue** naturally maintains this order.

```
Queue

[3]
 ↓
Process Level 0

[9,20]
 ↓
Process Level 1

[15,7]
 ↓
Process Level 2
```

---

## Why `q.size()`?

At the start of every iteration,

```
Queue
──────────────
9   20
──────────────

q.size() = 2
```

That means exactly **2 nodes belong to the current level**.

While processing them, we add

```
15
7
```

to the queue.

These are **NOT** processed immediately.

They become the next level.

---

## Algorithm

```
Push root into queue

While queue is not empty

    size = queue.size()

    Repeat size times

        Pop node

        Store value

        Push left child

        Push right child

    Store current level
```

---

## Complexity

| Operation | Complexity |
|-----------|------------|
| Time | **O(n)** |
| Space | **O(n)** |

---

## Key Takeaways

- BFS = Level Order Traversal on a tree.
- Queue preserves visiting order.
- `q.size()` separates one level from the next.
- Every node is visited exactly once.
- Standard BFS solution for binary tree level order traversal.