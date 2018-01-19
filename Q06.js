let squares, squares_of_sum, n = 100;
squares = Array.from(new Array(n+1), (val, index) => index ** 2).reduce((a, b) => a+b, 0)
squares_of_sum = Array.from(new Array(n+1), (val, index) => index).reduce((a, b) => a+b, 0) ** 2
console.log(squares_of_sum - squares)
