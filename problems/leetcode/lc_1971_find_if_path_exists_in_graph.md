# 1971. Find if Path Exists in Graph

> **Platform:** LeetCode  
> **Difficulty:** Easy  
> **Topic:** Graph, BFS

---

## Goal

Determine whether there is **any path** from the `source` node to the `destination` node in an **undirected graph**.

```
0 ─── 1 ─── 2
      │
      3

Source = 0
Destination = 3

Answer = true
```

---

## Core Idea

Treat the graph like a network of connected nodes.

Start a **BFS** from the `source`.

- Visit every reachable node.
- Mark visited nodes to avoid revisiting.
- If the `destination` is reached, return `true`.
- If BFS finishes without reaching it, return `false`.

---

## Graph Representation

The input is an **edge list**.

```
Edges

[0,1]
[1,2]
[1,3]
```

Convert it into an **Adjacency List** for efficient traversal.

```
0 → 1

1 → 0, 2, 3

2 → 1

3 → 1
```

---

## BFS Flow

```
Start

Queue = [source]

        │
        ▼

Take front node

        │
        ▼

Is it destination?

     Yes ───► Return true

      No
       │
       ▼

Visit all unvisited neighbours

       │
       ▼

Push them into queue

       │
       ▼

Repeat until queue becomes empty
```

---

## Algorithm

```
Create adjacency list

Create visited array

Push source into queue

Mark source as visited

While queue is not empty

    Pop front node

    If node == destination
        Return true

    Visit all unvisited neighbours

If BFS ends

Return false
```

---

## Complexity

| Operation | Complexity |
|-----------|------------|
| Time | **O(V + E)** |
| Space | **O(V + E)** |

Where:

- **V** = Number of vertices (nodes)
- **E** = Number of edges

---

## Key Takeaways

- Convert the edge list into an adjacency list.
- BFS explores all nodes reachable from the source.
- The `visited` array prevents revisiting the same node.
- Return immediately when the destination is found.
- If BFS ends without finding the destination, no valid path exists.