const generateTriangle = (numRows) => {
  const mainArr = [];
  for (let i = 1; i <= numRows; i++) {
    let currentRow = Array(i).fill(1);
    if (i > 2) {
      const previousRow = mainArr[i - 2];
      currentRow.forEach((num, index) => {
        if (index === 0 || index === currentRow.length - 1) {
          currentRow[index] = 1;
        } else {
          currentRow[index] = previousRow[index] + previousRow[index - 1];
        }
      });
    }
    mainArr.push(currentRow);
  }
  return mainArr;
};

console.log(generateTriangle(10));
