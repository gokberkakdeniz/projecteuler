nn = Array.from(new Array(1000-1), (val, index) => index+1);
nn_filtered = nn.filter((x) => {if (x % 3 == 0 || x % 5 == 0) return x})
sum = nn_filtered.reduce((a, b) => {return a+b}, 0)
console.log(sum)
