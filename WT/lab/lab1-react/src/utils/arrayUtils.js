export const generateArray = (num) => {
  let arr = [];
  console.log("hehehehehehe");
  const limit = 100;
  for (let i = 0; i < num; i++) {
    let rand = Math.floor(Math.random() * limit);
    arr.push(rand);
  }
  console.log(arr);

  return arr;
};

export const reverseArray = (arr) => {
  let rev = [];
  for (let i = arr.length - 1; i >= 0; i--) {
    rev.push(arr[i]);
  }
  return rev;
};

export const sortArray = (arr) => {
  const newarray = [...arr];
  for (var i = 0; i < newarray.length; i++) {
    for (var j = 0; j < newarray.length - i - 1; j++) {
      if (newarray[j] > newarray[j + 1]) {
        var temp = newarray[j];
        newarray[j] = newarray[j + 1];
        newarray[j + 1] = temp;
      }
    }
  }

  return newarray;
};
