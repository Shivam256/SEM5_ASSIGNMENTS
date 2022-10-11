import { init, send } from "@emailjs/browser";

init(process.env.USER_ID);

const templateParams = {
  to_name: "",
  from_name: "",
  message: "",
};

export const generateOTP = () => {
  let digits = "0123456789";
  let otp = "";
  for (let i = 0; i < 8; i++) {
    otp += digits[Math.floor(Math.random() * 10)];
  }
  return otp;
};

export const sendEmail = async (data) => {
  const { otp } = data;
  templateParams.from_name = "TEST WEBSITE";
  templateParams.to_name = "Shivam Gavandi";
  templateParams.message = `
    Login OTP: ${otp}
    `;

  const res = await send(
    "service_x54h5se",
    "template_3rhisiy",
    templateParams,
    "HMevCBDA-78DWixkt"
  );

  console.log(res);
  if (res.status === 200 && res.text == "OK") {
    return true;
  }
  return false;
};
