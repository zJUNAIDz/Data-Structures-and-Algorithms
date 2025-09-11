export default class MinHeap {
  public length: number; // Tracks the number of elements in the heap
  private data: number[]; // Array to store heap elements

  constructor() {
    this.data = []; // Initialize the heap as an empty array
    this.length = 0; // Initialize the length to 0
  }

  insert(value: number) {
    this.data[this.length] = value; // Add the new value at the end of the heap
    this.heapifyup(this.length++); // Restore the heap property by moving the value up
  }

  delete(): number {
    if (this.length === 0) return -1; // Return -1 if the heap is empty

    const out = this.data[0]; // Store the root value to return later
    this.length--; // Decrease the length of the heap
    if (this.length === 0) return out; // If heap is now empty, return the root value

    this.data[0] = this.data[this.length]; // Move the last element to the root
    this.heapifyDown(0); // Restore the heap property by moving the root down
    return out; // Return the removed root value
  }

  private heapifyDown(idx: number): void {
    let smallest = idx; // Assume the current index is the smallest
    const left = this.leftChild(idx); // Get the left child index
    const right = this.rightChild(idx); // Get the right child index

    // Check if the left child is smaller than the current smallest
    if (left < this.length && this.data[left] < this.data[smallest]) {
      smallest = left;
    }
    // Check if the right child is smaller than the current smallest
    if (right < this.length && this.data[right] < this.data[smallest]) {
      smallest = right;
    }
    if (smallest === idx) return; // If the current index is already the smallest, stop

    // Swap the current element with the smallest child
    [this.data[idx], this.data[smallest]] = [
      this.data[smallest],
      this.data[idx],
    ];
    this.heapifyDown(smallest); // Recursively heapify down the affected subtree
  }

  private heapifyup(idx: number): void {
    if (idx === 0) {
      return; // Stop if we reach the root
    }
    const parentIdx = this.parent(idx); // Get the parent index
    // Swap with the parent if the current value is smaller
    if (this.data[idx] < this.data[parentIdx]) {
      [this.data[idx], this.data[parentIdx]] = [
        this.data[parentIdx],
        this.data[idx],
      ];
      this.heapifyup(parentIdx); // Recursively heapify up the parent
    }
    return;
  }

  private parent(idx: number) {
    return Math.floor((idx - 1) / 2); // Calculate the parent index
  }

  private leftChild(idx: number) {
    return 2 * idx + 1; // Calculate the left child index
  }

  private rightChild(idx: number) {
    return 2 * idx + 2; // Calculate the right child index
  }
}

const heap = new MinHeap();
heap.insert(5);
heap.insert(3);
heap.insert(8);
heap.insert(1);

console.log(heap.delete()); // 1
console.log(heap.delete()); // 3
console.log(heap.delete()); // 5
console.log(heap.delete()); // 8
console.log(heap.delete()); // -1
