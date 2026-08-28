//Viết chương trình nhập vào số nguyên dương n (n<=100) và sau đó là n số nguyên.
//Tính tổng n số nguyên đó
let n = parseInt(prompt("Nhập vào số nguyên dương n (n <= 100):"));
while (isNaN(n) || n <= 0 || n > 100) {
  n = parseInt(prompt("Vui lòng nhập lại số nguyên dương n (n <= 100):"));
}
let sum = 0;
for (let i = 0; i < n; i++) {
  let num = parseInt(prompt(`Nhập số nguyên thứ ${i + 1}:`));
  console.log(`Số nguyên thứ ${i + 1} là: ${num}`);
  while (isNaN(num)) {
    num = parseInt(prompt(`Vui lòng nhập lại số nguyên thứ ${i + 1}:`));
  }
  sum += num;
}
console.log(`Tổng của ${n} số nguyên đã nhập là: ${sum}`);