/**************************************************************************//**
* COPYRIGHT 2022 CONNECTED DEVELOPMENT, A DIVISION OF TTI INC.
*
* ALL RIGHTS RESERVED BY AND FOR THE EXCLUSIVE BENEFIT OF
* CONNECTED DEVELOPMENT, A DIVISION OF TTI INC.
*
* CONNECTED DEVELOPMENT, A DIVISION OF TTI INC - CONFIDENTIAL AND PROPRIETARY
* INFORMATION AND/OR TRADE SECRET.
*
* NOTICE: ALL CODE, PROGRAM, INFORMATION, SCRIPT, INSTRUCTION,
* DATA, AND COMMENT HEREIN IS AND SHALL REMAIN THE CONFIDENTIAL
* INFORMATION AND PROPERTY OF CONNECTED DEVELOPMENT, A DIVISION OF TTI INC.
* USE AND DISCLOSURE THEREOF, EXCEPT AS STRICTLY AUTHORIZED IN A
* WRITTEN AGREEMENT SIGNED BY CONNECTED DEVELOPMENT, A DIVISION OF TTI INC.
* IS PROHIBITED.
*
*******************************************************************************
* @file
* @brief  Design for AED Camera Interface Communication
******************************************************************************/
#ifndef AED_CAMERA_IF_AED_CAMERA_IF_H_
#define AED_CAMERA_IF_AED_CAMERA_IF_H_

#include <stdint.h>

// Main control to camera sub-system command.
#define AED_CAMERA_CMD_PROTOCOL              (0x52)
// Camera sub-system to main control response.
#define AED_CAMERA_RSP_PROTOCOL              (0x72)

// Set the image gathering mode (LCD/LED).
#define AED_CAMERA_CMD_SET_AED_MODE          (0x21)
// Get LED status.
#define AED_CAMERA_CMD_GET_LED_STATUS        (0x22)
// Get the image length in frame buffer.
#define AED_CAMERA_CMD_GET_FBUF_LEN          (0x23)
// Read the image in frame buffer.
#define AED_CAMERA_CMD_READ_FBUF             (0x24)
// Set the torch LED - DBG only.
#define AED_CAMERA_CMD_SET_TORCH             (0x25)

#define AED_CAMERA_CMD_HDR_LENGTH            (3)

#define AED_CAMERA_DATA_LENGTH_MAX           (16)

// Code is executing correctly.
#define AED_CAMERA_STATUS_OK                 (0x0)
// Command cannot execute right now.
#define AED_CAMERA_STATUS_BUSY               (0x1)
// Command is empty or incorrect.
#define AED_CAMERA_STATUS_EMPTY              (0x2)
// Error in the data length received compared to data received
#define AED_CAMERA_STATUS_LENGTH_ERROR       (0x3)
// Data is formatted incorrectly.
#define AED_CAMERA_STATUS_FORMAT             (0x4)
// Command received correctly, error in execution.
#define AED_CAMERA_STATUS_EXEC_ERROR         (0x5)
// LED status not determined in machine learning.
#define AED_CAMERA_STATUS_UNKNOWN            (0x6)


// TBD
#define AED_CAMERA_CMD_FBUF_CTRL             (0x26)
#define AED_CAMERA_CMD_GET_FBUF_LEN_DATA_LEN (1)
#define AED_CAMERA_CMD_READ_FBUF_DATA_LEN    (12)
#define AED_CAMERA_CMD_CTRL_FBUF_DATA_LEN    (1)


// Camera command structure.
typedef struct
{
   uint8_t protocolSign;
   uint8_t command;
   uint8_t length;
   uint8_t data[AED_CAMERA_DATA_LENGTH_MAX];

} CameraCommand_t;

#endif /* AED_CAMERA_IF_AED_CAMERA_IF_H_ */
