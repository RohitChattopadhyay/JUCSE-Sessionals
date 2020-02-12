function LRC(inp) {
  const iArr = inp.split("").map(Number);
  if (iArr.length == 9) {
    xor = 0;
    iArr.forEach(iBit => {
      xor = xor ^ iBit;
    });
    if (xor == 0) return "PASS    ";
    else return "FAIL    ";
  } else return "Invalid Length";
}

function Bin2Dec(inp) {
  const iArr = inp.split("").map(Number);
  var out = 0;
  for (i = 0; i < iArr.length; i++) out += iArr[i] * 2 ** (inp.length - i - 1);
  return Dec2Bin(out);
}

function Dec2Bin(inp) {
  l = Number(inp).toString(2);
  return l
}

function getCheckSum(ipArr) {
  var oArr = [];
  for (var i = 0; i < ipArr.length; i++) oArr.push((Bin2Dec(ipArr[i])));
  var sum = 0
  var div = 2 ** ipArr[0].length - 1;
  for (var i = 0; i < oArr.length-1; i++){
    var tSum = oArr[i] + oArr[i+1]
    sum += (tSum % div);
    sum += Math.floor(sum / div);
  }
  return Dec2Bin(sum);
}

function VRC_Sum(ipArr) {
  const oArr = [0, 0, 0, 0, 0, 0, 0, 0];
  ipArr.forEach(iAr => {
    const iArr = iAr.split("").map(Number);
    for (i = 0; i < iArr.length; i++) oArr[i] = iArr[i] ^ oArr[i];
  });
  return oArr.join("");
}

function getRandomInt(max) {
  return Math.floor(Math.random() * Math.floor(max + 1));
}

function bitDiffer(inp, out) {
  const iArr = inp.split("");
  const oArr = out.split("");
  if (iArr.length == oArr.length) {
    count = 0;
    for (i = 0; i < iArr.length; i++) if (iArr[i] != oArr[i]) count++;
    return count;
  } else return -1;
}
function addError(inp) {
  var iArr = inp.split("");
  const len = iArr.length;
  for (i = 0; i < getRandomInt(len - 1); i++) {
    idx = getRandomInt(len - 1);
    iArr[idx] = getRandomInt(1);
  }
  var op = iArr.join("");
  return op;
}

var i = 3;
var input = [];
var sumVRC = [0, 0, 0, 0, 0, 0, 0, 0];
while (i--) {
  str = "";
  for (var j = 0; j < 8; j++) {
    k = getRandomInt(1);
    sumVRC[j] = k ^ sumVRC[j];
    str += k;
  }
  input.push(str);
}

tempVRC = sumVRC.join("");
input.push(tempVRC);

tempCheckSum = getCheckSum(input);
input.push(tempCheckSum);
console.log(
  "Method LRC",
  "\nSent\t",
  " Received",
  " Result",
  "  Bit Difference"
);
error = [];
input.forEach(packet => {
  var iArr = packet.split("");
  xor = 0;
  iArr.forEach(iBitS => {
    iBit = parseInt(iBitS);
    xor = xor ^ iBit;
  });
  iArr.push(xor);
  var inp = iArr.join("");
  var err = addError(inp);
  error.push(err.slice(0, -1));
  var res = LRC(err);
  console.log(inp, err, res, bitDiffer(inp, err));
});

console.log(
  "\nMethod VRC",
  "\nSent\t",
  "Received",
  " Result",
  "  Bit Difference"
);
res = false;
count = 0
while (!res && ++count<1000) {
  error = [];
  for(i=0;i<input.length-1;i++){
        var packet = input[i];
        var err = addError(packet);
        error.push(err);
  }
  for (i = 0; i < input.length-2; i++) if(input[i] && error[i]) console.log(input[i], error[i]);
  res = tempVRC == VRC_Sum(error);
  console.log(tempVRC, VRC_Sum(error), res ? "PASS" : "FAIL");
}


console.log(
    "\nMethod CheckSum",
    "\nSent\t",
    "Received",
    " Result",
    "  Bit Difference"
  );
  res = false;
  count = 0
  while (!res && ++count<1000) {
    error = [];
    for(i=0;i<input.length;i++){
          var packet = input[i];
          var err = addError(packet);
          error.push(err);
    }
    for (i = 0; i < input.length-1; i++) console.log(input[i], error[i]);
    res = (getCheckSum(error)==0)
    console.log(tempCheckSum,getCheckSum(error),  res ? "PASS" : "FAIL");
    console.log()
  }