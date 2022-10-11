let dimensions = {
  height: null,
  width: null,
};

const handleResize = () => {
  dimensions = {
    height: window.innerHeight,
    width: window.innerWidth,
  };
  console.log("height", dimensions.height);
  console.log("width", dimensions.width);
};

window.addEventListener("resize", handleResize);

handleResize();

//button code

const para = document.getElementById("para");

const btn = document.getElementById("btn");

btn.addEventListener("click", () => {
  para.classList.toggle("awesome");
  console.log(para);
});

const mylog = (a) => {
  console.log(Math.log(a));
  return Math.log(a);
};


const n = document.getElementById("num");

const logbtn = document.getElementById("logbtn");

const logans = document.getElementById("logans");

logbtn.addEventListener("click",()=>{
    if(n.value == null || n.value == "" ){
        alert("invalid input");
        return;
    }
    logans.textContent = mylog(Number(n.value));
})
