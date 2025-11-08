# Custom Vector Template Class in C++

This project implements a **custom dynamic vector class template** in C++ similar to `std::vector`. It supports various operations such as adding/removing elements, accessing elements, resizing, and utility functions for integers and strings.

---

## Features

The `Vector` class supports:

1. **Basic operations**:
   - `push_back(value)` – Add an element at the end.
   - `pop_back()` – Remove the last element.
   - `push_front(value)` – Add an element at the beginning.
   - `pop_front()` – Remove the first element.
   - `push_at(index, value)` – Insert an element at a specific index.
   - `pop_at(index)` – Remove an element at a specific index.

2. **Capacity management**:
   - Dynamic resizing with `expand()` when full.
   - Shrinking capacity to fit the current size using `shrink_to_fit()`.

3. **Utility functions**:
   - `reverse()` – Print elements in reverse order.
   - `remove_non_unique()` – Remove all duplicate elements.
   - `capitaliz_first_letter()` – Capitalize the first character of each string (works only for `Vector<string>`).
   - `smaller_adijacent()` – Print elements that are smaller than both adjacent neighbors.

4. **Iterators**:
   - Supports iteration with `begin()` and `end()`.

5. **Memory management**:
   - Implements a **copy constructor**, **assignment operator**, and **destructor** to handle dynamic memory safely.

---

## Example Usage

```cpp
#include <iostream>
#include "Vector.h"
#include <string>
using namespace std;

int main() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << "Vector elements: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << "\nReversed elements: ";
    v.reverse();

    Vector<string> vs;
    vs.push_back("red");
    vs.push_back("green");
    vs.capitaliz_first_letter();
    cout << "\nCapitalized strings: ";
    for (int i = 0; i < vs.size(); i++)
        cout << vs[i] << " ";

    return 0;
}
