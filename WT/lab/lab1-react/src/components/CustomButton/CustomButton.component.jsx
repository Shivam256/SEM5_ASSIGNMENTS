import React from 'react';
import './CustomButton.styles.css'

const CustomButton = ({children,...props}) => {
  return (
    <button {...props} className='cutom_button' >{children}</button>
  )
}

export default CustomButton