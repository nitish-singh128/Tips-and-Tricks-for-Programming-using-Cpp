# STL Containers and Algorithms - Complete Guide

## Overview

The Standard Template Library (STL) is one of the most important aspects of C++ and is heavily tested in technical interviews. This comprehensive guide covers all STL containers, algorithms, iterators, and common interview problems with practical examples and performance analysis.

## Why STL is Critical for Interviews

### Technical Importance
- **Ubiquitous Usage**: STL is used in virtually every C++ codebase
- **Efficiency**: Pre-optimized, tested implementations
- **Productivity**: Reduces development time significantly
- **Standard Knowledge**: Expected skill for any C++ developer

### Interview Focus Areas
- **Container Selection**: Knowing which container to use when
- **Time Complexity**: Understanding Big O for different operations
- **Memory Efficiency**: How containers manage memory
- **Algorithm Application**: Using STL algorithms effectively
- **Custom Implementations**: Sometimes asked to implement container functionality

## Container Categories

### Sequence Containers
Store elements in a linear sequence, maintaining insertion order.

#### std::vector
- **Use Case**: Dynamic array with random access
- **Time Complexity**: 
  - Access: O(1)
  - Insertion (end): Amortized O(1)
  - Insertion (middle): O(n)
  - Deletion (end): O(1)
  - Deletion (middle): O(n)
- **Memory**: Contiguous storage, may reallocate
- **When to Use**: Default choice for most scenarios

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
vec.push_back(6);           // O(1) amortized
vec.insert(vec.begin()+2, 99); // O(n)
vec.reserve(1000);          // Prevent reallocations
```

#### std::array
- **Use Case**: Fixed-size array with random access
- **Time Complexity**: O(1) for all access operations
- **Memory**: Stack-allocated, no dynamic allocation
- **When to Use**: Known fixed size, maximum performance

```cpp
std::array<int, 5> arr = {1, 2, 3, 4, 5};
arr[2] = 10;    // O(1) access
arr.fill(0);    // Fill all elements
```

#### std::deque
- **Use Case**: Double-ended queue with random access
- **Time Complexity**:
  - Access: O(1)
  - Insertion (ends): O(1)
  - Insertion (middle): O(n)
- **Memory**: Segmented storage
- **When to Use**: Need insertion/deletion at both ends

```cpp
std::deque<int> dq = {3, 4, 5};
dq.push_front(2);  // O(1)
dq.push_back(6);   // O(1)
```

#### std::list
- **Use Case**: Doubly-linked list
- **Time Complexity**:
  - Access: O(n)
  - Insertion: O(1) with iterator
  - Deletion: O(1) with iterator
- **Memory**: Non-contiguous, node-based
- **When to Use**: Frequent middle insertion/deletion

```cpp
std::list<int> lst = {1, 2, 3, 4, 5};
auto it = std::next(lst.begin(), 2);
lst.insert(it, 99);  // O(1) insertion
lst.sort();          // List-specific sort
```

### Associative Containers
Store elements in sorted order based on keys.

#### std::set / std::multiset
- **Implementation**: Typically Red-Black tree
- **Time Complexity**: O(log n) for insert, find, erase
- **Ordering**: Sorted by key
- **Use Case**: Unique elements (set) or allow duplicates (multiset)

```cpp
std::set<int> s = {5, 2, 8, 2, 1}; // {1, 2, 5, 8}
s.insert(3);    // O(log n)
auto it = s.find(5);  // O(log n)
```

#### std::map / std::multimap
- **Implementation**: Typically Red-Black tree
- **Time Complexity**: O(log n) for operations
- **Use Case**: Key-value pairs, sorted by key

```cpp
std::map<std::string, int> ages;
ages["Alice"] = 25;     // O(log n)
ages["Bob"] = 30;
auto it = ages.find("Alice"); // O(log n)
```

### Unordered Associative Containers
Hash-based containers with average O(1) operations.

#### std::unordered_set / std::unordered_multiset
- **Implementation**: Hash table
- **Time Complexity**: 
  - Average: O(1) for insert, find, erase
  - Worst case: O(n) if many hash collisions
- **Use Case**: Fast lookup without ordering requirement

```cpp
std::unordered_set<int> us = {5, 2, 8, 1};
us.insert(3);           // O(1) average
auto found = us.find(5); // O(1) average
```

#### std::unordered_map / std::unordered_multimap
- **Implementation**: Hash table
- **Use Case**: Fast key-value lookup

```cpp
std::unordered_map<std::string, int> scores;
scores["Alice"] = 95;   // O(1) average
int alice_score = scores["Alice"]; // O(1) average
```

### Container Adapters
Provide specific interfaces built on other containers.

#### std::stack
- **Interface**: LIFO (Last In First Out)
- **Underlying**: Usually std::deque
- **Use Case**: Function calls, expression evaluation, backtracking

```cpp
std::stack<int> stk;
stk.push(1);
stk.push(2);
int top = stk.top(); // 2
stk.pop();
```

#### std::queue
- **Interface**: FIFO (First In First Out)  
- **Underlying**: Usually std::deque
- **Use Case**: BFS, job scheduling, buffering

```cpp
std::queue<int> q;
q.push(1);
q.push(2);
int front = q.front(); // 1
q.pop();
```

#### std::priority_queue
- **Interface**: Priority-based extraction
- **Implementation**: Usually binary heap
- **Time Complexity**: O(log n) insertion, O(log n) extraction
- **Use Case**: Dijkstra's algorithm, job scheduling

```cpp
std::priority_queue<int> pq; // Max heap by default
pq.push(3);
pq.push(1);
pq.push(4);
int max = pq.top(); // 4
```

## STL Algorithms

### Algorithm Categories

#### Non-Modifying Sequence Operations
- `std::find`, `std::find_if`, `std::find_if_not`
- `std::count`, `std::count_if`
- `std::search`, `std::search_n`
- `std::equal`, `std::mismatch`

#### Modifying Sequence Operations
- `std::copy`, `std::copy_if`, `std::copy_n`
- `std::transform`
- `std::replace`, `std::replace_if`
- `std::remove`, `std::remove_if`
- `std::reverse`, `std::rotate`

#### Sorting Operations
- `std::sort`, `std::stable_sort`, `std::partial_sort`
- `std::nth_element`
- `std::binary_search`, `std::lower_bound`, `std::upper_bound`
- `std::merge`, `std::inplace_merge`

#### Numeric Operations
- `std::accumulate`, `std::inner_product`
- `std::partial_sum`, `std::adjacent_difference`
- `std::iota`

### Algorithm Usage Examples

```cpp
std::vector<int> vec = {5, 2, 8, 1, 9, 3};

// Find first element > 5
auto it = std::find_if(vec.begin(), vec.end(), 
                       [](int x) { return x > 5; });

// Sort the vector
std::sort(vec.begin(), vec.end());

// Transform to squares
std::vector<int> squares(vec.size());
std::transform(vec.begin(), vec.end(), squares.begin(),
               [](int x) { return x * x; });

// Calculate sum
int sum = std::accumulate(vec.begin(), vec.end(), 0);
```

## Iterator Categories

### Iterator Hierarchy
1. **Input Iterator**: Read-only, single pass
2. **Output Iterator**: Write-only, single pass  
3. **Forward Iterator**: Read/write, multi-pass, forward only
4. **Bidirectional Iterator**: Forward + backward movement
5. **Random Access Iterator**: All operations + random access

### Iterator Adapters
- **Reverse Iterator**: `std::reverse_iterator`
- **Insert Iterator**: `std::back_inserter`, `std::front_inserter`
- **Stream Iterator**: `std::istream_iterator`, `std::ostream_iterator`

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};

// Reverse iteration
for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
    std::cout << *it << " ";
}

// Stream iterators
std::copy(vec.begin(), vec.end(), 
          std::ostream_iterator<int>(std::cout, " "));
```

## Common Interview Questions

### Container Selection Questions

**Q: When would you use std::list over std::vector?**
**A:** Use std::list when you need frequent insertion/deletion in the middle of the container and don't need random access. List provides O(1) insertion/deletion at any position if you have an iterator, while vector requires O(n) for middle operations due to element shifting.

**Q: What's the difference between std::set and std::unordered_set?**
**A:** 
- **std::set**: Tree-based, O(log n) operations, sorted order, lower memory overhead
- **std::unordered_set**: Hash-based, O(1) average operations, no ordering, higher memory overhead

**Q: When would you prefer std::array over std::vector?**
**A:** Use std::array when:
- Size is known at compile time and fixed
- Want stack allocation (no dynamic memory)
- Need maximum performance (no capacity checks, no reallocations)
- Working with small, fixed collections

### Algorithm Questions

**Q: How would you find the intersection of two sorted vectors?**
```cpp
std::vector<int> intersection(const std::vector<int>& v1, 
                             const std::vector<int>& v2) {
    std::vector<int> result;
    std::set_intersection(v1.begin(), v1.end(),
                         v2.begin(), v2.end(),
                         std::back_inserter(result));
    return result;
}
```

**Q: How do you remove duplicates from a vector while preserving order?**
```cpp
// Using unordered_set for O(n) time complexity
std::vector<int> removeDuplicates(std::vector<int> vec) {
    std::unordered_set<int> seen;
    auto it = std::remove_if(vec.begin(), vec.end(),
        [&seen](int x) {
            if (seen.count(x)) return true;
            seen.insert(x);
            return false;
        });
    vec.erase(it, vec.end());
    return vec;
}
```

### Performance Questions

**Q: What causes iterator invalidation?**
**A:** Iterator invalidation occurs when the container's internal structure changes:

- **Vector**: Insertion/deletion may cause reallocation, invalidating all iterators
- **Deque**: Insertion/deletion at ends preserves middle iterators
- **List**: Only iterators to erased elements are invalidated
- **Set/Map**: Only iterators to erased elements are invalidated

**Q: Explain the performance characteristics of different containers for various operations.**

| Container | Access | Insert (end) | Insert (middle) | Find | Memory |
|-----------|--------|--------------|-----------------|------|--------|
| vector | O(1) | O(1)* | O(n) | O(n) | Contiguous |
| list | O(n) | O(1) | O(1)** | O(n) | Scattered |
| deque | O(1) | O(1) | O(n) | O(n) | Chunked |
| set | O(log n) | O(log n) | O(log n) | O(log n) | Tree nodes |
| unordered_set | N/A | O(1)* | N/A | O(1)* | Hash table |

*Amortized  **With iterator

## Best Practices

### Container Selection Guidelines

1. **Default Choice**: Use `std::vector` unless you have specific requirements
2. **Fixed Size**: Use `std::array` for compile-time known sizes
3. **Both End Access**: Use `std::deque` for insertion/deletion at both ends
4. **Middle Insertion**: Use `std::list` for frequent middle operations
5. **Sorted Unique**: Use `std::set` for sorted unique elements
6. **Fast Lookup**: Use `std::unordered_set` for fastest lookups
7. **Key-Value**: Use `std::map` or `std::unordered_map` for associations

### Performance Tips

```cpp
// Reserve space to avoid reallocations
std::vector<int> vec;
vec.reserve(1000);

// Use emplace instead of push for complex objects
vec.emplace_back(args...); // Better than vec.push_back(T(args...))

// Use const references in range-based loops
for (const auto& item : container) { /* ... */ }

// Prefer algorithms over hand-written loops
std::sort(vec.begin(), vec.end());  // Better than manual sort

// Use appropriate iterator types
auto it = vec.cbegin(); // const_iterator when not modifying
```

### Safety-First Programming Practices

```cpp
// Always validate container state before operations
if (!vec.empty()) {
    std::cout << vec.front() << std::endl;  // Safe front() access
    std::cout << vec.back() << std::endl;   // Safe back() access
}

// Check size before index-based operations
if (vec.size() > 2) {
    vec.insert(vec.begin() + 2, 99);  // Safe insert with bounds check
    vec.erase(vec.begin() + 2);       // Safe erase with bounds check
}

// Use at() for bounds-checked access during development/debugging
try {
    int value = vec.at(index);  // Throws std::out_of_range if invalid
} catch (const std::out_of_range& e) {
    std::cerr << "Index error: " << e.what() << std::endl;
    // Handle error appropriately
}

// Validate find() results before using iterators
auto it = std::find(vec.begin(), vec.end(), target);
if (it != vec.end()) {  // ESSENTIAL check - always validate find results
    std::cout << "Found: " << *it << " at position " << (it - vec.begin()) << std::endl;
} else {
    std::cout << "Element not found" << std::endl;
}

// Safe iterator operations with advance()
auto iter = vec.begin();
if (vec.size() >= 3) {  // Check before advancing
    std::advance(iter, 2);  // Safe advance
    std::cout << "Element at position 2: " << *iter << std::endl;
}
```

### Educational Code Patterns

```cpp
// Visual demonstrations for learning
std::queue<std::string> q;
q.push("First");
q.push("Second");

// Show queue state without destroying original (educational pattern)
std::queue<std::string> temp = q;  // Copy for visualization
std::cout << "Queue contents (front to back): ";
while (!temp.empty()) {
    std::cout << temp.front() << " ";
    temp.pop();
}
std::cout << std::endl;

// Reusable, testable functions instead of inline code
bool isValidParentheses(const std::string& expr) {
    std::stack<char> stk;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty()) return false;
            char top = stk.top();
            stk.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stk.empty();
}

// Test multiple cases to demonstrate robustness
std::vector<std::string> test_cases = {"()", "()[]{}", "([{}])", "(()", ")("};
for (const auto& test : test_cases) {
    std::cout << "\"" << test << "\" is " 
              << (isValidParentheses(test) ? "valid" : "invalid") << std::endl;
}
```

### Container-Specific Safety Patterns

```cpp
// Stack safety
std::stack<int> stk;
while (!stk.empty()) {  // ALWAYS check empty() before top() or pop()
    std::cout << stk.top() << " ";
    stk.pop();
}

// Priority queue safety
std::priority_queue<int> pq;
while (!pq.empty()) {  // ALWAYS check empty() before top() or pop()
    std::cout << pq.top() << " ";
    pq.pop();
}

// Deque safety with both ends
std::deque<int> dq = {1, 2, 3, 4, 5};
if (!dq.empty()) {
    dq.pop_front();  // Safe front removal
}
if (!dq.empty()) {
    dq.pop_back();   // Safe back removal
}

// List safety with iterators
std::list<int> lst = {1, 2, 3, 4, 5};
if (lst.size() >= 2) {  // Check before advancing iterator
    auto splice_pos = lst.begin();
    std::advance(splice_pos, 2);
    std::list<int> other = {99, 100};
    lst.splice(splice_pos, other);  // Safe splice operation
}
```

### Memory Management

```cpp
// Shrink vector capacity after large deletions
vec.erase(/* remove many elements */);
vec.shrink_to_fit();

// Use move semantics when possible
vec.push_back(std::move(expensive_object));

// Clear but keep capacity
vec.clear(); // Size = 0, capacity unchanged

// Clear and release memory
vec.clear();
vec.shrink_to_fit(); // or vec = std::vector<int>();
```

## Advanced Topics

### Custom Comparators
```cpp
// Custom comparator for set
struct PersonAgeComparator {
    bool operator()(const Person& a, const Person& b) const {
        return a.age < b.age;
    }
};

std::set<Person, PersonAgeComparator> people_by_age;

// Lambda comparator for sort
std::sort(people.begin(), people.end(),
          [](const Person& a, const Person& b) {
              return a.name < b.name;
          });
```

### Custom Hash Functions
```cpp
struct PersonHash {
    std::size_t operator()(const Person& p) const {
        return std::hash<std::string>{}(p.name) ^ 
               (std::hash<int>{}(p.age) << 1);
    }
};

std::unordered_set<Person, PersonHash> person_set;
```

### Enhanced CircularBuffer Implementation
Our implementation includes a production-ready CircularBuffer with comprehensive safety features:

```cpp
template<typename T>
class CircularBuffer {
public:
    // Constructor with validation
    explicit CircularBuffer(size_t size); // Throws if size == 0
    
    // Bounds-safe operations (throw on violation)
    void push(const T& item);              // Throws std::overflow_error if full
    T pop();                               // Throws std::underflow_error if empty
    
    // Peek operations (your request!) - non-modifying access
    const T& front() const;                // View front element safely
    T& front();                           
    const T& back() const;                 // View back element safely  
    T& back();
    
    // Bounds-checked element access
    const T& at(size_t index) const;       // Throws std::out_of_range if invalid
    T& at(size_t index);
    
    // Unchecked access (for performance when bounds are known)
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    
    // True circular behavior (overwrites oldest when full)
    void push_overwrite(const T& item);    // Never throws, circular overwrite
    void push_overwrite(T&& item);
    
    // Buffer management
    void clear();                          // Reset to empty state
    bool empty() const;                    // Check if empty
    bool full() const;                     // Check if full
    size_t size() const;                   // Current element count
    size_t max_size() const;               // Buffer capacity
    
    // Enhanced iterator support with bounds checking
    class iterator { /* bounds-safe implementation */ };
    class const_iterator { /* const bounds-safe implementation */ };
    
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
};
```

#### CircularBuffer Usage Examples
```cpp
// Safe usage with exception handling
try {
    CircularBuffer<int> buffer(5);
    
    // Fill buffer safely
    for (int i = 1; i <= 5; ++i) {
        buffer.push(i);
    }
    
    // Peek at elements without removing
    std::cout << "Front: " << buffer.front() << std::endl;  // 1
    std::cout << "Back: " << buffer.back() << std::endl;    // 5
    
    // Bounds-safe element access
    for (size_t i = 0; i < buffer.size(); ++i) {
        std::cout << buffer.at(i) << " ";  // Throws if out of range
    }
    
    // Iterator support with range-based loops
    for (const auto& elem : buffer) {
        std::cout << elem << " ";
    }
    
    // Circular overwrite behavior
    buffer.push_overwrite(6);  // Overwrites oldest element
    
} catch (const std::overflow_error& e) {
    std::cerr << "Buffer full: " << e.what() << std::endl;
} catch (const std::underflow_error& e) {
    std::cerr << "Buffer empty: " << e.what() << std::endl;
} catch (const std::out_of_range& e) {
    std::cerr << "Index error: " << e.what() << std::endl;
}
```

#### CircularBuffer Features
- **Bounds Checking**: All operations validate preconditions
- **Exception Safety**: Meaningful error messages for all edge cases
- **Peek Operations**: Non-modifying `front()` and `back()` access
- **Dual Push Modes**: Safe `push()` vs circular `push_overwrite()`
- **Iterator Support**: Full STL-compatible iterator interface
- **Performance Options**: `at()` for safety, `operator[]` for speed
- **Memory Efficient**: Pre-allocated buffer, no dynamic allocations during use

### Educational Enhancements in STL Demonstrations

Our STL demonstrations now include beginner-friendly features:

#### Safety-First Approach
```cpp
// Always check bounds before operations
if (!vec.empty()) {
    std::cout << "Front: " << vec.front() << std::endl;  // Safe access
}

if (vec.size() > 2) {
    vec.erase(vec.begin() + 2);  // Safe erase with size check
}

// Use at() for bounds-checked access in learning/debug scenarios
try {
    int value = vec.at(10);  // Throws if index >= size
} catch (const std::out_of_range& e) {
    std::cout << "Safe: " << e.what() << std::endl;
}
```

#### Visual Learning Aids
```cpp
// Demonstrate uninitialized array contents (educational!)
std::array<int, 5> arr2;  // Contains garbage values
printContainer(arr2, "Before fill(42) - uninitialized");  // Shows garbage
arr2.fill(42);
printContainer(arr2, "After fill(42)");  // All elements = 42

// Visual stack/queue state demonstrations
std::stack<int> stk;
// ... populate stack ...
std::cout << "Stack contents (top to bottom): ";
std::stack<int> temp = stk;  // Copy for non-destructive printing
while (!temp.empty()) {
    std::cout << temp.top() << " ";
    temp.pop();
}
```

#### Reusable Function Examples
```cpp
// Balanced parentheses checker - reusable and testable
bool isBalanced(const std::string& expr) {
    std::stack<char> stk;
    for (char c : expr) {
        if (c == '(') {
            stk.push(c);
        } else if (c == ')') {
            if (stk.empty()) return false;
            stk.pop();
        }
    }
    return stk.empty();
}

// Usage with multiple test cases
std::cout << "\"((()))\" is " << (isBalanced("((()))") ? "balanced" : "not balanced") << std::endl;
std::cout << "\"((())\" is " << (isBalanced("((())") ? "balanced" : "not balanced") << std::endl;
```

#### Performance and Complexity Comments
```cpp
vec.push_back(6);        // O(1) amortized (sometimes O(n) when reallocation needed)
vec.reserve(20);         // Pre-allocate capacity - O(n) one-time cost
vec.insert(it, 99);      // Insert at position - O(n) due to shifting elements
vec.shrink_to_fit();     // Release unused capacity - O(n) but saves memory
lst.splice(it, other);   // Move elements from other list - O(1), just relink pointers!
```

### Exception Safety
STL containers provide different exception safety guarantees:
- **Basic guarantee**: Container remains in valid state
- **Strong guarantee**: Operation succeeds or has no effect  
- **No-throw guarantee**: Operation cannot throw

Our enhanced implementations follow these principles:
```cpp
// CircularBuffer provides strong exception guarantee
try {
    buffer.push(item);  // Either succeeds completely or has no effect
} catch (const std::overflow_error&) {
    // Buffer state unchanged, can continue safely
}
```

## Testing and Debugging

### Common Mistakes
1. **Iterator Invalidation**: Using iterators after container modification
2. **Out of Range Access**: Using `operator[]` without bounds checking
3. **Comparing Iterators**: From different containers
4. **Memory Leaks**: With containers of raw pointers

### Debugging Tips
```cpp
// Use at() for bounds checking in debug builds
int value = vec.at(index); // Throws if out of range

// Check container state
assert(!vec.empty());
assert(vec.size() > index);

// Use const when possible to catch modification bugs
const std::vector<int>& const_ref = vec;
```

## Performance Benchmarks

### Insertion Performance (100K elements)
- **Vector (end)**: ~2ms
- **Vector (middle)**: ~800ms
- **List (anywhere)**: ~5ms
- **Set**: ~15ms
- **Unordered_set**: ~8ms

### Search Performance (10K elements)
- **Vector (linear)**: ~50μs
- **Set**: ~2μs
- **Unordered_set**: ~1μs

*Note: Actual performance depends on hardware, compiler, and data patterns*

## Interview Preparation Checklist

### Must Know
- [ ] Time complexity of all container operations
- [ ] When to use each container type
- [ ] Iterator categories and their capabilities
- [ ] Common algorithms (sort, find, transform, accumulate)
- [ ] How to implement basic algorithms using STL

### Should Know
- [ ] Iterator invalidation rules
- [ ] Custom comparators and hash functions
- [ ] Exception safety guarantees
- [ ] Memory layout of different containers
- [ ] Move semantics with containers

### Advanced Topics
- [ ] Custom allocators
- [ ] Template metaprogramming with STL
- [ ] Parallel algorithms (C++17)
- [ ] Ranges library (C++20)
---

Master the STL and you master a huge part of effective C++ programming! 
