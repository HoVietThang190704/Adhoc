//Viết chương trình nhập vào một số nguyên lớn hơn 1 rồi in ra tất cả các ước số của số đó
let n = parseInt(prompt("Nhập vào một số nguyên lớn hơn 1: "));
while (n <= 1) {
  n = parseInt(prompt("Số bạn nhập không hợp lệ. Vui lòng nhập lại một số nguyên lớn hơn 1: "));
}
for (let i = 1; i <= n; i++) {
  if (n % i === 0) {
    console.log(i);
  }
}