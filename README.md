# Object Occlusion Optimization (Occlusion Culling)

This project implements a robust **Occlusion Culling** system in **C++**, designed to optimize the rendering pipeline of 2D games. The system utilizes a one-dimensional Scanline approach combined with depth priority sorting to efficiently determine which object segments should be drawn.

## About the Project

In game engines, processing and rendering objects hidden behind others wastes computational resources. This system addresses this issue by implementing an algorithm that:
1. Receives objects with 2D coordinates (X and Y) and depth.
2. Sorts them by priority (depth/Y-coordinate).
3. Calculates visibility along the X-axis, discarding fully or partially obstructed segments.

The project was developed as part of the Data Structures course at UFMG, simulating a real-world optimization demand for the fictitious company "Jolambs".

## Features

* **Scene Construction Algorithm:** Optimized implementation with **$O(N^2 \log N)$** complexity.
* **Manual Memory Management:** Implemented **without STL containers** (Standard Template Library), focusing on safe dynamic allocation and direct memory manipulation.
* **Dynamic Updates:** Object insertion and movement with linear cost **$O(N)$** (utilizing *Insertion Sort* for nearly sorted lists).
* **Robustness:** Handles buffer overflows, input validation, and employs defensive programming.

## Method and Algorithm

The core of the solution lies in the `Scene` class and the `ConstructScene` method:

1. **Prioritization:** Objects are processed from closest to farthest (based on the Y-coordinate).
2. **Scanline Sweep:** For each object, a "cursor" traverses the X-axis, checking for gaps between items that are already visible ("blockers").
3. **Segmentation:** If an object is partially visible, it is sliced into segments (`VisibleItem`) that fill the gaps not occupied by previous objects.

### Data Structures
* **Object:** Entity with ID, position (start/end X), and depth (Y).
* **VisibleItem:** Represents a continuous visible segment of an object.
* **Static/Dynamic Vectors:** Manually allocated arrays to ensure performance and memory control.

## Complexity Analysis

| Operation | Time Complexity | Description |
| :--- | :--- | :--- |
| **Construct Scene** | $O(N^2 \log N)$ | Dominated by sorting (*Merge Sort*) within the segment insertion loop. |
| **New Object ('O')** | $O(N)$ | Insertion into a nearly sorted vector. |
| **Move Object ('M')** | $O(N)$ | Removal and re-insertion while maintaining order. |
| **Space (Memory)** | $O(N)$ | Linear growth due to auxiliary memory used by *Merge Sort*. |
