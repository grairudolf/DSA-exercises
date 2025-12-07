# DSA-exercises

Practice implementations of common Data Structures and Algorithms (DSA) in C, organized by topic.

The goal of this repo is to be a hands-on playground where you can:
- Try out individual problems (each as a small C program)
- Experiment with different implementations
- Contribute new exercises or improve existing ones

---

## Repository structure

Top-level layout:

- `exercises/`
  - `stacks/` – Array-based stack implementation and related exercises
  - `queues/` – Queue and circular queue implementations
  - `arrays_two_pointers/` – Classic array / two-pointer problems
  - `binary_search/` – Problems solved with binary search (including search on answers)
  - `dynamic_programming/` – DP problems (1D DP, 2D DP, classic patterns)
  - `trees_graphs/` – Binary tree and graph traversal / topology problems
  - `heaps_greedy/` – Heap/greedy-style problems (e.g. frequency-based)
- `build/` – Optional build output directory (ignored by git)
- `.vscode/` – Editor configuration
- `.gitignore` – Ignore patterns for C builds and OS clutter

Each exercise is a single C file with:
- One or more core functions implementing the algorithm
- A small `main` function that reads input from `stdin` and prints results

You can compile and run each file independently.

---

## Prerequisites

You need a C toolchain, for example:

- On Linux/macOS: `gcc` or `clang`
- On Windows: MinGW, MSYS2, or Visual Studio build tools

Make sure your compiler can find standard headers like `stdio.h` and `stdlib.h`.

---

## Running the exercises

### General pattern

From the repo root:

```bash
gcc exercises/<category>/<file>.c -o <binary_name>
./<binary_name>
```

Examples (you can adapt these patterns to any exercise):

- Arrays & Two Pointers:
  - Two Sum

    ```bash
    gcc exercises/arrays_two_pointers/two_sum.c -o two_sum
    ./two_sum
    ```

  - Best Time to Buy and Sell Stock

    ```bash
    gcc exercises/arrays_two_pointers/best_time_to_buy_sell_stock.c -o best_stock
    ./best_stock
    ```

- Binary Search:
  - Search in Rotated Sorted Array

    ```bash
    gcc exercises/binary_search/search_in_rotated_sorted_array.c -o rotated_search
    ./rotated_search
    ```

  - Koko Eating Bananas

    ```bash
    gcc exercises/binary_search/koko_eating_bananas.c -o koko
    ./koko
    ```

- Dynamic Programming:
  - Climbing Stairs

    ```bash
    gcc exercises/dynamic_programming/climbing_stairs.c -o climb
    ./climb
    ```

  - Coin Change

    ```bash
    gcc exercises/dynamic_programming/coin_change.c -o coin_change
    ./coin_change
    ```

- Trees & Graphs:
  - Binary Tree Level Order Traversal

    ```bash
    gcc exercises/trees_graphs/binary_tree_level_order_traversal.c -o level_order
    ./level_order
    ```

  - Number of Islands

    ```bash
    gcc exercises/trees_graphs/number_of_islands.c -o islands
    ./islands
    ```

- Heaps / Greedy:
  - Top K Frequent Elements

    ```bash
    gcc exercises/heaps_greedy/top_k_frequent_elements.c -o topk
    ./topk
    ```

Feel free to create your own binaries/names when compiling; the above are just suggestions.

---

## Adding a new exercise

1. **Pick a category**
   - If a suitable category already exists (e.g. `dynamic_programming`), add your file there.
   - If not, create a new folder under `exercises/` with a clear, lowercase, underscore-separated name.

2. **Create a C file**
   - Implement the core algorithm in one or more functions.
   - Add a small `main` that:
     - Reads a simple textual input format (from `stdin`)
     - Calls your algorithm
     - Prints a clear, concise result

3. **Build and test locally**
   - Compile using `gcc`/`clang` (see examples above).
   - Try a few edge cases (empty inputs, small sizes, large sizes, etc.) to verify behavior.

4. **Keep style consistent**
   - Use straightforward, readable C (no unnecessary macros or complex abstractions).
   - Prefer fixed-size arrays with reasonable limits for learning purposes.

---

## Contribution guidelines

Contributions are welcome. To keep the repo clean and easy to navigate, please follow these guidelines:

1. **Issue / idea first (optional but helpful)**
   - If you plan a larger addition (new categories or many problems), open an issue describing:
     - The topic (e.g. "Graph algorithms: Dijkstra, BFS, DFS")
     - Which problems you want to add

2. **Branching and commits**
   - Create a feature branch from `main` (for example, `feature/new-dp-problems`).
   - Keep commits focused and descriptive, e.g.:
     - `add binary search exercises`
     - `implement coin change dp`
     - `update readme with run instructions`

3. **File and folder naming**
   - Use lowercase with underscores: `longest_increasing_subsequence.c`, `trees_graphs/`.
   - Keep one main problem per file where possible.

4. **Code expectations**
   - Stick to C (no external libraries beyond the standard C library).
   - Avoid global state unless it clearly simplifies a learning example.
   - Aim for clarity over micro-optimizations.

5. **Testing**
   - Make sure your code compiles without errors or warnings on at least one C compiler.
   - Manually test a few non-trivial cases (especially edge cases).

6. **Documentation in code**
   - Keep inline comments minimal and focused on non-obvious logic.
   - If you add more complex algorithms, a short comment at the top of the file summarizing the approach is appreciated.

---

## Roadmap / ideas

Potential future additions:

- More linked list, tree, and graph problems
- Sorting and searching variants
- Additional DP patterns (knapsack, intervals, digit DP)
- More heap / greedy / scheduling problems

If you have ideas, feel free to open an issue or a PR.
