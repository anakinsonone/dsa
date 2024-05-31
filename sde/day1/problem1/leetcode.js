const matrix = [
  [0, 1, 2, 0],
  [3, 4, 5, 2],
  [1, 3, 1, 5],
];

const setZeroes = (matrix) => {
  const columns = new Set();
  for (let i = 0; i < matrix.length; i++) {
    if (matrix[i].includes(0)) {
      matrix[i].forEach((val, index) => {
        if (val === 0) columns.add(index);
        return (matrix[i][index] = 0);
      });
    }
  }
  columns.forEach((index) => {
    for (let i = 0; i < matrix.length; i++) {
      matrix[i][index] = 0;
    }
  });
  return matrix;
};

console.time("performance");
console.log(setZeroes(matrix));
console.timeEnd("performance");
