//Vẽ hình chữ nhật đặc có chiều cao = x hàng (0<x<=10).
//Hàng thứ 1 = 10 số 0, hàng thứ 2 = 10 số 1, hàng thứ i chứa 10 số (i-1)…. 
let x = parseInt(prompt("Nhập chiều cao của hình chữ nhật (0 < x <= 10):"));
if (x > 0 && x <= 10) {
  for (let i = 0; i < x; i++) {
    let row = "";
    for (let j = 0; j < 10; j++) {
      row += i + " ";
    }
    console.log(row);
  }
}