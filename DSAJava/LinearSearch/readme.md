# Linear Search

Linear search is a simple search algorithm that checks every element in a list until the desired element is found or the list ends. It is also known as a sequential search.

## How it Works

1. Start from the first element of the list.
2. Compare the current element with the target element.
3. If the current element matches the target, return the index of the current element.
4. If the current element does not match the target, move to the next element.
5. Repeat steps 2-4 until the target element is found or the list ends.

## Time Complexity

- **Best Case:** O(1) - The target element is the first element in the list.
- **Worst Case:** O(n) - The target element is the last element in the list or not present at all.
- **Average Case:** O(n) - The target element is somewhere in the middle of the list.

## Example

Here is a simple example of linear search in Java:

```java
public class LinearSearch {
    public static int linearSearch(int[] array, int target) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == target) {
                return i;
            }
        }
        return -1; // Target not found
    }

    public static void main(String[] args) {
        int[] numbers = {1, 3, 5, 7, 9, 11};
        int target = 7;
        int result = linearSearch(numbers, target);
        if (result != -1) {
            System.out.println("Element found at index: " + result);
        } else {
            System.out.println("Element not found in the array.");
        }
    }
}
```

This code defines a `linearSearch` method that takes an array and a target value as parameters and returns the index of the target value if found, or -1 if not found.