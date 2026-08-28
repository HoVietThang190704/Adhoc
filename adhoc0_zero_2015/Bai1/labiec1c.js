//Viết chương trình nhập vào hai số nguyên dương a và b (a,b<=100). 
//In ra tất cả các số chẵn trong khoảng từ a đến b, mỗi số trên một dòng .
let a = parseInt(prompt("Nhap so nguyen duong a (a <= 100): "));
let b = parseInt(prompt("Nhap so nguyen duong b (b <= 100): "));
for (let i = a; i <= b; i++) {
  if (i % 2 === 0) {
    console.log(i);
  }
}