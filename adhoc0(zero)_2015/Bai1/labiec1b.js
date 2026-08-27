//Viết chương trình nhập vào số nguyên n (n<=100). Tính tổng 1 + 2 + … + n 
let n = parseInt(prompt("Nhap so nguyen n (n <= 100): "));
let sum = 0;
for (let i = 1; i <= n; i++) {
  sum += i;
}
console.log("Tong la: " + sum);