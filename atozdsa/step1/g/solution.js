const evenOddSum = (num) => {
  const numArr = num.toString().split("");
  let even = 0;
  let odd = 0;
  numArr.forEach((num) => {
    if (parseInt(num) % 2 === 0) {
      even += parseInt(num);
    } else {
      odd += parseInt(num);
    }
  });
  return [even, odd];
};
console.log(evenOddSum(15326486));
