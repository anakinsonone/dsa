const fib = (num) => {
  const arr = [];
  for (let i = 0; i < num; i++) {
    if (i === 0) {
      arr.push(0);
      continue;
    }
    if (i === 1) {
      arr.push(1);
      continue;
    }
    arr.push(arr[i - 1] + arr[i - 2]);
  }
  return arr;
};

console.log(fib(12));
