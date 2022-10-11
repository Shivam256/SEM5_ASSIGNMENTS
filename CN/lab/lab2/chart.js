const inputVal = document.getElementsByClassName('inputTag');
const btn = document.getElementsByClassName('btn');

const createGraph = () => {
  let size = inputVal[0].value.length;
  let t = size;
  let val = parseInt(inputVal[0].value);
  console.log(val % 10);
  const y = [];
  while (size != 0) {
    let remain = val % 10;
    if (remain === 1) {
      y.unshift('ON');
    } else {
      if (remain != 0) {
        alert('please enter binary string!!');
        return;
      }
      y.unshift('OFF');
    }
    val = parseInt(val / 10);
    size = size - 1;
  }

  const x = [];
  size = t;
  let i = 0;
  while (size != 0) {
    x.push(i * 10);
    i++;
    size--;
  }

  console.log(x);
  console.log(y);
  const chartArea = document.querySelector('#chartArea');
  chartArea.innerHTML =
    '<canvas id="myChart" style="width:100%;max-width:500px; height: 20vh"></canvas>';
  const myChart = new Chart('myChart', {
    type: 'line',
    data: {
      labels: x,
      datasets: [
        {
          label: 'test',
          data: y,
          stepped: true,
          yAxisID: 'y2',
        },
      ],
    },
    options: {
      responsive: true,
      plugins: {
        title: {
          display: true,
          text: 'Unipolar Assignment',
        },
      },
      scales: {
        y2: {
          type: 'category',
          labels: ['ON', 'OFF'],
          offset: true,
          position: 'left',
          stack: 'demo',
          stackWeight: 1,
        },
      },
    },
  });
};

btn[0].addEventListener('click', createGraph);
