function updateTwoDimensionalArrayInState<T>(
  array: T[][],
  rowIndex: number,
  colIndex: number,
  newValue: T,
  setArray: React.Dispatch<React.SetStateAction<T[][]>>
): void {
  // 创建二维数组的副本并修改特定的值
  const newArray = array.map((row, rIndex) =>
    row.map((value, cIndex) => {
      if (rIndex === rowIndex && cIndex === colIndex) {
        return newValue; // 更新目标元素
      }
      return value; // 其他元素保持不变
    })
  );

  // 使用 setArray 来更新状态
  setArray(newArray);
}
