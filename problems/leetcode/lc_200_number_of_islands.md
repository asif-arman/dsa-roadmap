# Number of Islands

## Problem Summary

Given an `m × n` grid containing `'1'` (land) and `'0'` (water), count how many separate islands exist.

An island is formed by connecting adjacent land cells horizontally or vertically.

---

## Key Observation

Think of every land cell (`'1'`) as a graph node.

```
1 1 0
0 1 0
1 0 1
```

Each land cell is connected to its **up, down, left, and right** neighbors.

Instead of an adjacency list, the graph is represented by the grid itself.

---

## Main Idea

If we start BFS from any land cell, BFS will visit **every land cell belonging to the same island**.

After finishing that BFS, the entire island has been explored.

So,

* Find an unvisited land cell.
* Run BFS.
* Mark every reachable land cell as visited.
* Increase the island count by 1.
* Continue scanning the grid.

Each BFS corresponds to **one island**.

---

## Algorithm

```
Initialize islands = 0

Create a visited matrix

For every cell in the grid

    If the cell is land ('1') and not visited

        Start BFS

        Mark all connected land cells as visited

        islands++

Return islands
```

---

## BFS Algorithm

```
Push starting land cell into the queue

Mark it visited

While queue is not empty

    Pop a cell

    Check its four neighbours

        Up
        Down
        Left
        Right

    If neighbour

        • is inside the grid
        • is land ('1')
        • is not visited

            Mark visited

            Push into queue
```

---

## Why Does This Work?

Suppose the grid is

```
1 1 0
0 1 0
0 0 1
```

Start scanning.

First land found:

```
1 1
  1
```

BFS visits all three cells.

Now they are marked visited.

Continue scanning.

Later we find

```
1
```

This starts another BFS.

So

```
Island 1 → first BFS

Island 2 → second BFS

Answer = 2
```

---

## Complexity

Let

* Rows = m
* Columns = n

Every cell is visited at most once.

**Time Complexity**

```
O(m × n)
```

**Space Complexity**

```
O(m × n)
```

(visited matrix + BFS queue)

---

## Pattern Learned

This problem teaches the **Connected Components** pattern.

Whenever a graph (or grid) contains multiple disconnected groups,

```
for every node

    if not visited

        BFS / DFS

        answer++
```

Examples:

* Number of Islands
* Number of Provinces
* Max Area of Island
* Count Connected Components

---

## Key Takeaways

* Convert the grid into a graph mentally.
* `'1'` = node, `'0'` = ignore.
* Use 4-direction movement.
* One BFS explores one complete island.
* Number of BFS runs = Number of islands.

