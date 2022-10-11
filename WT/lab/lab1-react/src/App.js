import React, { useState, useEffect } from "react";
import "./App.css";

import CustomInput from "./components/CustomInput/CustomInput.component";
import CustomButton from "./components/CustomButton/CustomButton.component";

import { useSnackbar } from "notistack";
import { Button, Box, TextField } from "@mui/material";

import { generateOTP, sendEmail } from "./utils/email";
import { generateArray, reverseArray, sortArray } from "./utils/arrayUtils";

// import vid from "./assets/wallpaper3.mp4";
import { Icon } from "@iconify/react";

import * as S from "./styles";
import CustomArray from "./components/CustomArray/CustomArray.component";

function App() {
  const [audioState, setAudioState] = useState({
    status: false,
  });
  const [arrayMode, setArrayMode] = useState(true);
  const [otpState, setOtpState] = useState(false);
  const [myAudio, setAudio] = useState(new Audio("/audios/spring.mp3"));
  const [data, setData] = useState({
    username: "",
    password: "",
  });
  const [otpData, setOtpData] = useState({
    emailOTP: "",
  });
  const [arrayNum, setArrayNum] = useState(0);
  const [arr, setArr] = useState([]);
  const [reversedArray, setReversedArray] = useState([]);
  const [sortedArray, setSortedArray] = useState([]);

  const { enqueueSnackbar } = useSnackbar();

  const handleChange = (e) => {
    setData({
      ...data,
      [e.target.name]: e.target.value,
    });
  };

  const toggleAudioMode = () => {
    setAudioState({ status: !audioState.status });
  };

  const toggleArrayMode = () => {
    setArrayMode(!arrayMode);
  };

  useEffect(() => {
    if (audioState.status) {
      myAudio.play();
    } else {
      myAudio.pause();
    }
  }, [audioState]);

  const handleSendOtpClick = (e) => {
    e.preventDefault();
    if (localStorage.getItem(data.username) == data.password) {
      const otp = generateOTP();
      sendEmail({ otp });
      localStorage.setItem("emailOTP", otp);
      enqueueSnackbar("Otp have been sent to your email!", {
        variant: "success",
      });
      setOtpState(true);
    } else {
      enqueueSnackbar("Incorrect password", { variant: "error" });
    }
  };

  const handleOTPVerification = (e) => {
    e.preventDefault();
    if (localStorage.getItem("emailOTP") == otpData.emailOTP) {
      enqueueSnackbar("OTP veriried successfully!", { variant: "success" });
    } else {
      enqueueSnackbar("OTP verification failed!", { variant: "error" });
    }
  };

  const handleGenerateArray = () => {
    const b = generateArray(arrayNum);
    setArr(b);
    const c = reverseArray(b);
    const d = sortArray(b);
    setReversedArray(c);
    setSortedArray(d);
  };

  const handleReverseArray = () => {
    const b = reverseArray(arr);
    setReversedArray(b);
  };

  const handleSortArray = () => {
    const b = sortArray(arr);
    setSortedArray(b);
  };

  // useEffect(() => {
  //   setReversedArray(reverseArray(arr));
  //   setSortedArray(sortArray(arr));
  // }, [arr]);

  useEffect(() => {
    console.log(otpState, "hehehehehe");
  }, [otpState]);

  return (
    <div className="App">
      <video autoPlay={true} loop muted>
        <source src="/videos/wallpaper3.mp4" type="video/mp4" />
      </video>
      <div className="layer1">
        <Box sx={{ width: "100%", padding: "30px" }}>
          <S.WhiteButton onClick={toggleArrayMode}>
            {arrayMode ? "FORM MODE" : "ARRAY MODE"}
          </S.WhiteButton>
        </Box>
        {arrayMode ? (
          <S.ArraySectionContaienr>
            <S.ArraySection>
              <div className="heading">INPUT SECTION</div>
              <TextField
                label="Enter number of elements"
                variant="standard"
                fullWidth
                type="number"
                onChange={(e) => {
                  setArrayNum(e.target.value);
                }}
              />
              <S.WhiteButton onClick={handleGenerateArray}>
                GENERATE
              </S.WhiteButton>
              <CustomArray array={arr} />
              <Box sx={{ display: "flex", gap: "20px" }}>
                <S.WhiteButton onClick={handleReverseArray}>
                  REVERSE
                </S.WhiteButton>
                <S.WhiteButton onClick={handleSortArray}>SORT</S.WhiteButton>
              </Box>
            </S.ArraySection>
            <S.ArraySection>
              <div className="heading">REVERSED ARRAY</div>
              <CustomArray array={reversedArray} />
            </S.ArraySection>
            <S.ArraySection>
              <div className="heading">SORTED ARRAY</div>
              <CustomArray array={sortedArray} />
            </S.ArraySection>
          </S.ArraySectionContaienr>
        ) : (
          <form action="">
            <div className="heading_container">
              <h1 className="form_head">Vishwakarma Institute Of Technology</h1>
              <Icon
                icon={!audioState.status ? "bx:volume-mute" : "bx:volume-full"}
                onClick={toggleAudioMode}
              />
            </div>
            {/* <div className="grid">
            <CustomInput label="Full Name" />
            <CustomInput label="Mother Name" />
          </div>
          <div className="grid">
            <CustomInput label="Phone Number" />
            <CustomInput label="Email Id" />
          </div> */}
            <div className="grid">
              <CustomInput
                label="Username"
                onChange={handleChange}
                name="username"
              />
              <CustomInput
                label="Password"
                type="password"
                onChange={handleChange}
                name="password"
              />
            </div>
            {/* <div className="grid">
            <CustomInput
              label="Phone Number"
              onChange={handleChange}
              name="phoneNumber"
            />
            <CustomInput
              label="Email Id"
              onChange={handleChange}
              name="email"
            />
          </div> */}

            {/* <CustomInput label="Address" /> */}
            <CustomButton onClick={handleSendOtpClick}>SENT OTPS</CustomButton>
            {otpState ? (
              <>
                <div className="grid">
                  {/* <CustomInput label="Phone OTP" /> */}
                  <CustomInput
                    label="Email OTP"
                    name="emailOTP"
                    onChange={(e) => {
                      setOtpData({
                        ...otpData,
                        emailOTP: e.target.value,
                      });
                    }}
                  />
                </div>
                <CustomButton onClick={handleOTPVerification}>
                  LOGIN
                </CustomButton>
              </>
            ) : null}
          </form>
        )}
      </div>
    </div>
  );
}

export default App;
