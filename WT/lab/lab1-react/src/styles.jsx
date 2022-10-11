import { Box, Button, styled } from "@mui/material";

export const ArraySection = styled(Box)(() => ({
  height: "100%",
  flex: 1,
  border: "1px solid #c9c9c9",
  borderRadius: "10px",
  padding: "10px",
  display: "flex",
  flexDirection: "column",
  alignItems: "center",
  padding: "10px 30px",
  gap: "20px",
  "& .heading": {
    fontSize: "1.5em",
    fontWeight: 600,
  },
}));

export const WhiteButton = styled(Button)(() => ({
  backgroundColor: "rgba(255, 255, 255, 0.3)",
  color: "white",
  padding: "5px 20px",
  boxShadow: "rgba(149, 157, 165, 0.2) 0px 8px 24px",
  "&:hover": {
    backgroundColor: "rgba(255, 255, 255, 0.3)",
    color: "white",
  },
}));

export const ArraySectionContaienr = styled(Box)(() => ({
  width: "90vw",
  height: "60vh",
  margin: "10vh auto",
  backgroundColor: "rgba(255, 255, 255, 0.3)",
  color: "#000",
  padding: "20px",
  boxShadow: "rgba(149, 157, 165, 0.2) 0px 8px 24px",
  borderRadius: "10px",
  display: "flex",
  flexDirection: "row",
  gap: "10px",
}));
