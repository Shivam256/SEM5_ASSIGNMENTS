import { Box } from "@mui/material";
import React from "react";

const CustomArray = ({ array }) => {
  return (
    <Box
      sx={{
        width: "100%",
        display: "flex",
        flexDirection: "row",
        alignItems: "end",
        // height: "50%",
        flex:1,
        gap: "2px",
      }}
    >
      {array
        ? array.map((elem) => (
            <Box
              sx={{
                height: `${elem}%`,
                flex: 1,
                backgroundColor: "#ffffffc8",
                display: "flex",
                flexDirection: "column",
                alignItems: "center",
                transition:"all 0.2s ease-in-out"
              }}
            >
              {elem}
            </Box>
          ))
        : null}
    </Box>
  );
};

export default CustomArray;
