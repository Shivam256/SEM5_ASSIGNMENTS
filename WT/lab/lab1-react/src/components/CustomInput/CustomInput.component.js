import React from "react";
import "./CustomInput.styles.css";

const CustomInput = ({ label, ...props }) => {
  return (
    <div className="input_container">
      <label htmlFor="">{label}:</label>
      <input type="text" {...props} />
    </div>
  );
};

export default CustomInput;
