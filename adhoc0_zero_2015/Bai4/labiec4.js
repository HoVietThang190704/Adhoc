//Viết chương trình đọc vào một dãy số nguyên 
//và in ra dãy số nguyên đó cho đến khi gặp một số chia hết cho 10 
//(giả định dãy chắc chắn có một số chia hết cho 10)
let n = parseInt(prompt("Nhập số lượng phần tử của dãy: "));
let arr = [];
for (let i = 0; i < n; i++) {
  let num = parseInt(prompt(`Nhập phần tử thứ ${i + 1}: `));
  arr.push(num);
}

let result = [];
for (let i = 0; i < arr.length; i++) {
  if (arr[i] % 10 === 0) break;
  result.push(arr[i]);
}
console.log(result.join(", "));