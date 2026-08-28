//Viết chương trình nhập vào số nguyên n (n<=100). Tính tổng các giá trị lẻ từ 0 đến n.
let n = parseInt(prompt("Nhập vào số nguyên n (n <= 100):"));
while (n > 100 || n < 0) {
  n = parseInt(prompt("Vui lòng nhập lại số nguyên n (n <= 100):"));
}
let sum = 0;
for (let i = 1; i <= n; i += 2) {
  sum += i;
}
console.log(sum);