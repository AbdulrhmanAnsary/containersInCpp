# Containers in C++

This repository provides a comprehensive exploration of containers in C++. The containers are organized into four main categories:

## 1. Sequence Containers
Sequence containers store elements in a linear arrangement, allowing direct access to elements in a sequence. This folder covers the following:

- **`vector`**: Dynamic array that can grow in size.
- **`deque`**: Double-ended queue allowing fast insertions and deletions at both ends.
- **`list`**: Doubly linked list offering efficient insertions and deletions at any position.
- **`array`**: Fixed-size array encapsulated in a container.

## 2. Container Adaptors
Container adaptors provide a different interface for sequential containers, giving them stack or queue-like behavior. This folder includes:

- **`stack`**: Last-in, first-out (LIFO) data structure.
- **`queue`**: First-in, first-out (FIFO) data structure.
- **`priority_queue`**: A specialized queue that allows retrieval of the largest element.

## 3. Associative Containers
Associative containers store elements in a sorted order, allowing fast retrieval based on keys. The folder includes:

- **`set`**: Collection of unique elements.
- **`map`**: Collection of key-value pairs, where keys are unique.
- **`multiset`**: Collection of elements where duplicates are allowed.
- **`multimap`**: Collection of key-value pairs where keys can have multiple values.

## 4. Unordered Associative Containers
Unordered associative containers store elements in an unordered fashion but provide fast access based on keys using hash tables. This folder covers:

- **`unordered_set`**: Collection of unique elements in an unordered fashion.
- **`unordered_map`**: Collection of key-value pairs with unique keys in an unordered manner.
- **`unordered_multiset`**: Similar to `multiset`, but elements are stored unordered.
- **`unordered_multimap`**: Similar to `multimap`, but key-value pairs are stored unordered.

## Usage
Each folder contains example code demonstrating how to use the specific containers, with explanations to help understand their behavior.

## Contributions
Contributions are welcome! Feel free to fork the repository and submit pull requests. Please make sure your contributions adhere to the C++17 standard.

## License
This project is licensed under the MIT License - see the [LICENSE](/LICENSE) file for details.
