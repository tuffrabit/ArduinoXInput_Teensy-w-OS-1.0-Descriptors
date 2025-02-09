/* Teensyduino Core Library
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2017 PJRC.COM, LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * 2. If the Software is incorporated into a build system that allows
 * selection among a list of target devices, then similar target
 * devices manufactured by PJRC.COM must be included in the list of
 * target devices and selectable in the same manner.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _usb_desc_h_
#define _usb_desc_h_

// This header is NOT meant to be included when compiling
// user sketches in Arduino.  The low-level functions
// provided by usb_dev.c are meant to be called only by
// code which provides higher-level interfaces to the user.

#include <stdint.h>
#include <stddef.h>

#define ENDPOINT_UNUSED			0x00
#define ENDPOINT_TRANSMIT_ONLY		0x15
#define ENDPOINT_RECEIVE_ONLY		0x19
#define ENDPOINT_TRANSMIT_AND_RECEIVE	0x1D
#define ENDPOINT_RECEIVE_ISOCHRONOUS	0x18
#define ENDPOINT_TRANSMIT_ISOCHRONOUS	0x14

/*
Each group of #define lines below corresponds to one of the
settings in the Tools > USB Type menu.  This file defines what
type of USB device is actually created for each of those menu
options.

Each "interface" is a set of functionality your PC or Mac will
use and treat as if it is a unique device.  Within each interface,
the "endpoints" are the actual communication channels.  Most
interfaces use 1, 2 or 3 endpoints.  By editing only this file,
you can customize the USB Types to be any collection of interfaces.

To modify a USB Type, delete the XYZ_INTERFACE lines for any
interfaces you wish to remove, and copy them from another USB Type
for any you want to add.

Give each interface a unique number, and edit NUM_INTERFACE to
reflect the total number of interfaces.

Next, assign unique endpoint numbers to all the endpoints across
all the interfaces your device has.  You can reuse an endpoint
number for transmit and receive, but the same endpoint number must
not be used twice to transmit, or twice to receive.

Most endpoints also require their maximum size, and some also
need an interval specification (the number of milliseconds the
PC will check for data from that endpoint).  For existing
interfaces, usually these other settings should not be changed.

Edit NUM_ENDPOINTS to be at least the largest endpoint number used.

Edit NUM_USB_BUFFERS to control how much memory the USB stack will
allocate.  At least 2 should be used for each endpoint.  More
memory will allow higher throughput for user programs that have
high latency (eg, spending time doing things other than interacting
with the USB).

Edit the ENDPOINT*_CONFIG lines so each endpoint is configured
the proper way (transmit, receive, or both).

If you are using existing interfaces (making your own device with
a different set of interfaces) the code in all other files should
automatically adapt to the new endpoints you specify here.

If you need to create a new type of interface, you'll need to write
the code which sends and receives packets, and presents an API to
the user.  Usually, a pair of files are added for the actual code,
and code is also added in usb_dev.c for any control transfers,
interrupt-level code, or other very low-level stuff not possible
from the packet send/receive functons.  Code also is added in
usb_inst.c to create an instance of your C++ object.  This message
gives a quick summary of things you will need to know:
https://forum.pjrc.com/threads/49045?p=164512&viewfull=1#post164512

You may edit the Vendor and Product ID numbers, and strings.  If
the numbers are changed, Teensyduino may not be able to automatically
find and reboot your board when you click the Upload button in
the Arduino IDE.  You will need to press the Program button on
Teensy to initiate programming.

Some operating systems, especially Windows, may cache USB device
info.  Changes to the device name may not update on the same
computer unless the vendor or product ID numbers change, or the
"bcdDevice" revision code is increased.

If these instructions are missing steps or could be improved, please
let me know?  http://forum.pjrc.com/forums/4-Suggestions-amp-Bug-Reports
*/


#if defined(USB_SERIAL)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0483
  #define DEVICE_CLASS		2	// 2 = Communication Class
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'U','S','B',' ','S','e','r','i','a','l'}
  #define PRODUCT_NAME_LEN	10
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS		4
  #define NUM_USB_BUFFERS	12
  #define NUM_INTERFACE		2
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1
  #define CDC_ACM_ENDPOINT	2
  #define CDC_RX_ENDPOINT       3
  #define CDC_TX_ENDPOINT       4
  #define CDC_ACM_SIZE          16
  #define CDC_RX_SIZE           64
  #define CDC_TX_SIZE           64
  #define ENDPOINT2_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY

#elif defined(USB_DUAL_SERIAL)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x048B
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'D','u','a','l',' ','S','e','r','i','a','l'}
  #define PRODUCT_NAME_LEN	11
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS		7
  #define NUM_USB_BUFFERS	22
  #define NUM_INTERFACE		4
  #define CDC_IAD_DESCRIPTOR	1	// Serial
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1
  #define CDC_ACM_ENDPOINT	2
  #define CDC_RX_ENDPOINT	3
  #define CDC_TX_ENDPOINT	4
  #define CDC_ACM_SIZE		16
  #define CDC_RX_SIZE		64
  #define CDC_TX_SIZE		64
  #define CDC2_STATUS_INTERFACE	2	// SerialUSB1
  #define CDC2_DATA_INTERFACE	3
  #define CDC2_ACM_ENDPOINT	5
  #define CDC2_RX_ENDPOINT	6
  #define CDC2_TX_ENDPOINT	7
  #define CDC2_ACM_SIZE		16
  #define CDC2_RX_SIZE		64
  #define CDC2_TX_SIZE		64
  #define ENDPOINT2_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT6_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT7_CONFIG	ENDPOINT_TRANSMIT_ONLY

#elif defined(USB_TRIPLE_SERIAL)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x048C
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','r','i','p','l','e',' ','S','e','r','i','a','l'}
  #define PRODUCT_NAME_LEN	13
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS		10
  #define NUM_USB_BUFFERS	32
  #define NUM_INTERFACE		6
  #define CDC_IAD_DESCRIPTOR	1	// Serial
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1
  #define CDC_ACM_ENDPOINT	2
  #define CDC_RX_ENDPOINT	3
  #define CDC_TX_ENDPOINT	4
  #define CDC_ACM_SIZE		16
  #define CDC_RX_SIZE		64
  #define CDC_TX_SIZE		64
  #define CDC2_STATUS_INTERFACE	2	// SerialUSB1
  #define CDC2_DATA_INTERFACE	3
  #define CDC2_ACM_ENDPOINT	5
  #define CDC2_RX_ENDPOINT	6
  #define CDC2_TX_ENDPOINT	7
  #define CDC2_ACM_SIZE		16
  #define CDC2_RX_SIZE		64
  #define CDC2_TX_SIZE		64
  #define CDC3_STATUS_INTERFACE	4	// SerialUSB2
  #define CDC3_DATA_INTERFACE	5
  #define CDC3_ACM_ENDPOINT	8
  #define CDC3_RX_ENDPOINT	9
  #define CDC3_TX_ENDPOINT	10
  #define CDC3_ACM_SIZE		16
  #define CDC3_RX_SIZE		64
  #define CDC3_TX_SIZE		64
  #define ENDPOINT2_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT6_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT7_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT8_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT9_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT10_CONFIG	ENDPOINT_TRANSMIT_ONLY

#elif defined(USB_KEYBOARDONLY)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x04D0
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'K','e','y','b','o','a','r','d'}
  #define PRODUCT_NAME_LEN	8
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         4
  #define NUM_USB_BUFFERS	14
  #define NUM_INTERFACE		3
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define KEYBOARD_INTERFACE    0	// Keyboard
  #define KEYBOARD_ENDPOINT     3
  #define KEYBOARD_SIZE         8
  #define KEYBOARD_INTERVAL     1
  #define KEYMEDIA_INTERFACE    2	// Keyboard Media Keys
  #define KEYMEDIA_ENDPOINT     4
  #define KEYMEDIA_SIZE         8
  #define KEYMEDIA_INTERVAL     4
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT6_CONFIG	ENDPOINT_TRANSMIT_ONLY

#elif defined(USB_HID)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0482
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'K','e','y','b','o','a','r','d','/','M','o','u','s','e','/','J','o','y','s','t','i','c','k'}
  #define PRODUCT_NAME_LEN	23
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         6
  #define NUM_USB_BUFFERS	24
  #define NUM_INTERFACE		5
  #define SEREMU_INTERFACE      2	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define KEYBOARD_INTERFACE    0	// Keyboard
  #define KEYBOARD_ENDPOINT     3
  #define KEYBOARD_SIZE         8
  #define KEYBOARD_INTERVAL     1
  #define KEYMEDIA_INTERFACE    4	// Keyboard Media Keys
  #define KEYMEDIA_ENDPOINT     6
  #define KEYMEDIA_SIZE         8
  #define KEYMEDIA_INTERVAL     4
  #define MOUSE_INTERFACE       1	// Mouse
  #define MOUSE_ENDPOINT        5
  #define MOUSE_SIZE            8
  #define MOUSE_INTERVAL        1
  #define JOYSTICK_INTERFACE    3	// Joystick
  #define JOYSTICK_ENDPOINT     4
  #define JOYSTICK_SIZE         12	//  12 = normal, 64 = extreme joystick
  #define JOYSTICK_INTERVAL     2
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT6_CONFIG	ENDPOINT_TRANSMIT_ONLY

#elif defined(USB_SERIAL_HID)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0487
  #define DEVICE_CLASS		0xEF
  #define DEVICE_SUBCLASS	0x02
  #define DEVICE_PROTOCOL	0x01
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'S','e','r','i','a','l','/','K','e','y','b','o','a','r','d','/','M','o','u','s','e','/','J','o','y','s','t','i','c','k'}
  #define PRODUCT_NAME_LEN	30
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS		7
  #define NUM_USB_BUFFERS	30
  #define NUM_INTERFACE		6
  #define CDC_IAD_DESCRIPTOR	1
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1	// Serial
  #define CDC_ACM_ENDPOINT	2
  #define CDC_RX_ENDPOINT       3
  #define CDC_TX_ENDPOINT       4
  #define CDC_ACM_SIZE          16
  #define CDC_RX_SIZE           64
  #define CDC_TX_SIZE           64
  #define KEYBOARD_INTERFACE    2	// Keyboard
  #define KEYBOARD_ENDPOINT     1
  #define KEYBOARD_SIZE         8
  #define KEYBOARD_INTERVAL     1
  #define KEYMEDIA_INTERFACE    5	// Keyboard Media Keys
  #define KEYMEDIA_ENDPOINT     7
  #define KEYMEDIA_SIZE         8
  #define KEYMEDIA_INTERVAL     4
  #define MOUSE_INTERFACE       3	// Mouse
  #define MOUSE_ENDPOINT        5
  #define MOUSE_SIZE            8
  #define MOUSE_INTERVAL        2
  #define JOYSTICK_INTERFACE    4	// Joystick
  #define JOYSTICK_ENDPOINT     6
  #define JOYSTICK_SIZE         12	//  12 = normal, 64 = extreme joystick
  #define JOYSTICK_INTERVAL     1
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT6_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT7_CONFIG	ENDPOINT_TRANSMIT_ONLY

#elif defined(USB_TOUCHSCREEN)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x04D3
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'K','e','y','b','o','a','r','d','/','T','o','u','c','h','s','c','r','e','e','n'}
  #define PRODUCT_NAME_LEN	20
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         5
  #define NUM_USB_BUFFERS	15
  #define NUM_INTERFACE		4
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define KEYBOARD_INTERFACE    0	// Keyboard
  #define KEYBOARD_ENDPOINT     3
  #define KEYBOARD_SIZE         8
  #define KEYBOARD_INTERVAL     1
  #define KEYMEDIA_INTERFACE    2	// Keyboard Media Keys
  #define KEYMEDIA_ENDPOINT     4
  #define KEYMEDIA_SIZE         8
  #define KEYMEDIA_INTERVAL     4
  #define MULTITOUCH_INTERFACE  3	// Touchscreen
  #define MULTITOUCH_ENDPOINT   5
  #define MULTITOUCH_SIZE       16
  #define MULTITOUCH_FINGERS    10
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSMIT_ONLY

#elif defined(USB_HID_TOUCHSCREEN)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x04D4
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'K','e','y','b','o','a','r','d','/','M','o','u','s','e','/','T','o','u','c','h','s','c','r','e','e','n'}
  #define PRODUCT_NAME_LEN	26
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         6
  #define NUM_USB_BUFFERS	20
  #define NUM_INTERFACE		5
  #define SEREMU_INTERFACE      2	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define KEYBOARD_INTERFACE    0	// Keyboard
  #define KEYBOARD_ENDPOINT     3
  #define KEYBOARD_SIZE         8
  #define KEYBOARD_INTERVAL     1
  #define KEYMEDIA_INTERFACE    3	// Keyboard Media Keys
  #define KEYMEDIA_ENDPOINT     4
  #define KEYMEDIA_SIZE         8
  #define KEYMEDIA_INTERVAL     4
  #define MOUSE_INTERFACE       1	// Mouse
  #define MOUSE_ENDPOINT        6
  #define MOUSE_SIZE            8
  #define MOUSE_INTERVAL        2
  #define MULTITOUCH_INTERFACE  4	// Touchscreen
  #define MULTITOUCH_ENDPOINT   5
  #define MULTITOUCH_SIZE       16
  #define MULTITOUCH_FINGERS    10
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT6_CONFIG	ENDPOINT_TRANSMIT_ONLY

#elif defined(USB_MIDI)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0485
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','M','I','D','I'}
  #define PRODUCT_NAME_LEN	11
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         4
  #define NUM_USB_BUFFERS	16
  #define NUM_INTERFACE		2
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define MIDI_INTERFACE        0	// MIDI
  #define MIDI_NUM_CABLES       1
  #define MIDI_TX_ENDPOINT      3
  #define MIDI_TX_SIZE          64
  #define MIDI_RX_ENDPOINT      4
  #define MIDI_RX_SIZE          64
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ONLY

#elif defined(USB_MIDI4)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0485
  #define BCD_DEVICE		0x0211
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','M','I','D','I','x','4'}
  #define PRODUCT_NAME_LEN	13
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         4
  #define NUM_USB_BUFFERS	16
  #define NUM_INTERFACE		2
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define MIDI_INTERFACE        0	// MIDI
  #define MIDI_NUM_CABLES       4
  #define MIDI_TX_ENDPOINT      3
  #define MIDI_TX_SIZE          64
  #define MIDI_RX_ENDPOINT      4
  #define MIDI_RX_SIZE          64
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ONLY

#elif defined(USB_MIDI16)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0485
  #define BCD_DEVICE		0x0212
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','M','I','D','I','x','1','6'}
  #define PRODUCT_NAME_LEN	14
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         4
  #define NUM_USB_BUFFERS	16
  #define NUM_INTERFACE		2
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define MIDI_INTERFACE        0	// MIDI
  #define MIDI_NUM_CABLES       16
  #define MIDI_TX_ENDPOINT      3
  #define MIDI_TX_SIZE          64
  #define MIDI_RX_ENDPOINT      4
  #define MIDI_RX_SIZE          64
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ONLY

#elif defined(USB_MIDI_SERIAL)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0489
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','M','I','D','I'}
  #define PRODUCT_NAME_LEN	11
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         5
  #define NUM_USB_BUFFERS	30
  #define NUM_INTERFACE		3
  #define CDC_IAD_DESCRIPTOR	1
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1	// Serial
  #define CDC_ACM_ENDPOINT	1
  #define CDC_RX_ENDPOINT       2
  #define CDC_TX_ENDPOINT       3
  #define CDC_ACM_SIZE          16
  #define CDC_RX_SIZE           64
  #define CDC_TX_SIZE           64
  #define MIDI_INTERFACE        2	// MIDI
  #define MIDI_NUM_CABLES       1
  #define MIDI_TX_ENDPOINT      4
  #define MIDI_TX_SIZE          64
  #define MIDI_RX_ENDPOINT      5
  #define MIDI_RX_SIZE          64
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_RECEIVE_ONLY

#elif defined(USB_MIDI4_SERIAL)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0489
  #define BCD_DEVICE		0x0211
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','M','I','D','I','x','4'}
  #define PRODUCT_NAME_LEN	13
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         5
  #define NUM_USB_BUFFERS	30
  #define NUM_INTERFACE		3
  #define CDC_IAD_DESCRIPTOR	1
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1	// Serial
  #define CDC_ACM_ENDPOINT	1
  #define CDC_RX_ENDPOINT       2
  #define CDC_TX_ENDPOINT       3
  #define CDC_ACM_SIZE          16
  #define CDC_RX_SIZE           64
  #define CDC_TX_SIZE           64
  #define MIDI_INTERFACE        2	// MIDI
  #define MIDI_NUM_CABLES       4
  #define MIDI_TX_ENDPOINT      4
  #define MIDI_TX_SIZE          64
  #define MIDI_RX_ENDPOINT      5
  #define MIDI_RX_SIZE          64
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_RECEIVE_ONLY

#elif defined(USB_MIDI16_SERIAL)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0489
  #define BCD_DEVICE		0x0212
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','M','I','D','I','x','1','6'}
  #define PRODUCT_NAME_LEN	14
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         5
  #define NUM_USB_BUFFERS	30
  #define NUM_INTERFACE		3
  #define CDC_IAD_DESCRIPTOR	1
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1	// Serial
  #define CDC_ACM_ENDPOINT	1
  #define CDC_RX_ENDPOINT       2
  #define CDC_TX_ENDPOINT       3
  #define CDC_ACM_SIZE          16
  #define CDC_RX_SIZE           64
  #define CDC_TX_SIZE           64
  #define MIDI_INTERFACE        2	// MIDI
  #define MIDI_NUM_CABLES       16
  #define MIDI_TX_ENDPOINT      4
  #define MIDI_TX_SIZE          64
  #define MIDI_RX_ENDPOINT      5
  #define MIDI_RX_SIZE          64
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_RECEIVE_ONLY

#elif defined(USB_RAWHID)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0486
  #define RAWHID_USAGE_PAGE	0xFFAB  // recommended: 0xFF00 to 0xFFFF
  #define RAWHID_USAGE		0x0200  // recommended: 0x0100 to 0xFFFF
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y','d','u','i','n','o',' ','R','a','w','H','I','D'}
  #define PRODUCT_NAME_LEN	18
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         4
  #define NUM_USB_BUFFERS	12
  #define NUM_INTERFACE		2
  #define RAWHID_INTERFACE      0	// RawHID
  #define RAWHID_TX_ENDPOINT    3
  #define RAWHID_TX_SIZE        64
  #define RAWHID_TX_INTERVAL    1
  #define RAWHID_RX_ENDPOINT    4
  #define RAWHID_RX_SIZE        64
  #define RAWHID_RX_INTERVAL    1
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ONLY

#elif defined(USB_FLIGHTSIM)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0488
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','F','l','i','g','h','t',' ','S','i','m',' ','C','o','n','t','r','o','l','s'}
  #define PRODUCT_NAME_LEN	26
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         4
  #define NUM_USB_BUFFERS	20
  #define NUM_INTERFACE		2
  #define FLIGHTSIM_INTERFACE	0	// Flight Sim Control
  #define FLIGHTSIM_TX_ENDPOINT	3
  #define FLIGHTSIM_TX_SIZE	64
  #define FLIGHTSIM_TX_INTERVAL	1
  #define FLIGHTSIM_RX_ENDPOINT	4
  #define FLIGHTSIM_RX_SIZE	64
  #define FLIGHTSIM_RX_INTERVAL	1
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ONLY

#elif defined(USB_FLIGHTSIM_JOYSTICK)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0488
  #define BCD_DEVICE		0x0211
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','F','l','i','g','h','t',' ','S','i','m',' ','C','o','n','t','r','o','l','s'}
  #define PRODUCT_NAME_LEN	26
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         5
  #define NUM_USB_BUFFERS	20
  #define NUM_INTERFACE		3
  #define FLIGHTSIM_INTERFACE	0	// Flight Sim Control
  #define FLIGHTSIM_TX_ENDPOINT	3
  #define FLIGHTSIM_TX_SIZE	64
  #define FLIGHTSIM_TX_INTERVAL	1
  #define FLIGHTSIM_RX_ENDPOINT	4
  #define FLIGHTSIM_RX_SIZE	64
  #define FLIGHTSIM_RX_INTERVAL	1
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define JOYSTICK_INTERFACE    2	// Joystick
  #define JOYSTICK_ENDPOINT     5
  #define JOYSTICK_SIZE         12	//  12 = normal, 64 = extreme joystick
  #define JOYSTICK_INTERVAL     1
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSMIT_ONLY


#elif defined(USB_MTPDISK)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x04D1
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','M','T','P',' ','D','i','s','k'}
  #define PRODUCT_NAME_LEN	15
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         4
  #define NUM_USB_BUFFERS	20
  #define NUM_INTERFACE		2
  #define MTP_INTERFACE		0	// MTP Disk
  #define MTP_TX_ENDPOINT	3
  #define MTP_TX_SIZE		64
  #define MTP_RX_ENDPOINT	3
  #define MTP_RX_SIZE		64
  #define MTP_EVENT_ENDPOINT	4
  #define MTP_EVENT_SIZE	16
  #define MTP_EVENT_INTERVAL	10
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_AND_RECEIVE
  // TODO: Should ENDPOINT4_CONFIG be ENDPOINT_TRANSMIT_ONLY ???
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ONLY

#elif defined(USB_AUDIO)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x04D2
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','A','u','d','i','o'}
  #define PRODUCT_NAME_LEN	12
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         5
  #define NUM_USB_BUFFERS	16
  #define NUM_INTERFACE		4
  #define SEREMU_INTERFACE      0	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define AUDIO_INTERFACE	1	// Audio (uses 3 consecutive interfaces)
  #define AUDIO_TX_ENDPOINT     3
  #define AUDIO_TX_SIZE         180
  #define AUDIO_RX_ENDPOINT     4
  #define AUDIO_RX_SIZE         180
  #define AUDIO_SYNC_ENDPOINT	5
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ISOCHRONOUS
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ISOCHRONOUS
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSMIT_ISOCHRONOUS

#elif defined(USB_MIDI_AUDIO_SERIAL)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x048A
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','M','I','D','I','/','A','u','d','i','o'}
  #define PRODUCT_NAME_LEN	17
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         8
  #define NUM_USB_BUFFERS	30
  #define NUM_INTERFACE		6
  #define CDC_IAD_DESCRIPTOR	1
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1	// Serial
  #define CDC_ACM_ENDPOINT	1
  #define CDC_RX_ENDPOINT       2
  #define CDC_TX_ENDPOINT       3
  #define CDC_ACM_SIZE          16
  #define CDC_RX_SIZE           64
  #define CDC_TX_SIZE           64
  #define MIDI_INTERFACE        2	// MIDI
  #define MIDI_NUM_CABLES       1
  #define MIDI_TX_ENDPOINT      4
  #define MIDI_TX_SIZE          64
  #define MIDI_RX_ENDPOINT      5
  #define MIDI_RX_SIZE          64
  #define AUDIO_INTERFACE	3	// Audio (uses 3 consecutive interfaces)
  #define AUDIO_TX_ENDPOINT     6
  #define AUDIO_TX_SIZE         180
  #define AUDIO_RX_ENDPOINT     7
  #define AUDIO_RX_SIZE         180
  #define AUDIO_SYNC_ENDPOINT	8
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT6_CONFIG	ENDPOINT_TRANSMIT_ISOCHRONOUS
  #define ENDPOINT7_CONFIG	ENDPOINT_RECEIVE_ISOCHRONOUS
  #define ENDPOINT8_CONFIG	ENDPOINT_TRANSMIT_ISOCHRONOUS

#elif defined(USB_MIDI16_AUDIO_SERIAL)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x048A
  #define BCD_DEVICE		0x0212
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','M','I','D','I','x','1','6','/','A','u','d','i','o'}
  #define PRODUCT_NAME_LEN	20
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         8
  #define NUM_USB_BUFFERS	30
  #define NUM_INTERFACE		6
  #define CDC_IAD_DESCRIPTOR	1
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1	// Serial
  #define CDC_ACM_ENDPOINT	1
  #define CDC_RX_ENDPOINT       2
  #define CDC_TX_ENDPOINT       3
  #define CDC_ACM_SIZE          16
  #define CDC_RX_SIZE           64
  #define CDC_TX_SIZE           64
  #define MIDI_INTERFACE        2	// MIDI
  #define MIDI_NUM_CABLES       16
  #define MIDI_TX_ENDPOINT      4
  #define MIDI_TX_SIZE          64
  #define MIDI_RX_ENDPOINT      5
  #define MIDI_RX_SIZE          64
  #define AUDIO_INTERFACE	3	// Audio (uses 3 consecutive interfaces)
  #define AUDIO_TX_ENDPOINT     6
  #define AUDIO_TX_SIZE         180
  #define AUDIO_RX_ENDPOINT     7
  #define AUDIO_RX_SIZE         180
  #define AUDIO_SYNC_ENDPOINT	8
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT6_CONFIG	ENDPOINT_TRANSMIT_ISOCHRONOUS
  #define ENDPOINT7_CONFIG	ENDPOINT_RECEIVE_ISOCHRONOUS
  #define ENDPOINT8_CONFIG	ENDPOINT_TRANSMIT_ISOCHRONOUS

#elif defined(USB_EVERYTHING)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0476
  #define RAWHID_USAGE_PAGE	0xFFAB  // recommended: 0xFF00 to 0xFFFF
  #define RAWHID_USAGE		0x0200  // recommended: 0x0100 to 0xFFFF
  #define DEVICE_CLASS		0xEF
  #define DEVICE_SUBCLASS	0x02
  #define DEVICE_PROTOCOL	0x01
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'A','l','l',' ','T','h','e',' ','T','h','i','n','g','s'}
  #define PRODUCT_NAME_LEN	14
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         15
  #define NUM_USB_BUFFERS	31
  #define NUM_INTERFACE		13
  #define CDC_IAD_DESCRIPTOR	1
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1	// Serial
  #define CDC_ACM_ENDPOINT	1
  #define CDC_RX_ENDPOINT       2
  #define CDC_TX_ENDPOINT       2
  #define CDC_ACM_SIZE          16
  #define CDC_RX_SIZE           64
  #define CDC_TX_SIZE           64
  #define MIDI_INTERFACE        2	// MIDI
  #define MIDI_NUM_CABLES       16
  #define MIDI_TX_ENDPOINT      3
  #define MIDI_TX_SIZE          64
  #define MIDI_RX_ENDPOINT      3
  #define MIDI_RX_SIZE          64
  #define KEYBOARD_INTERFACE    3	// Keyboard
  #define KEYBOARD_ENDPOINT     4
  #define KEYBOARD_SIZE         8
  #define KEYBOARD_INTERVAL     1
  #define MOUSE_INTERFACE       4	// Mouse
  #define MOUSE_ENDPOINT        5
  #define MOUSE_SIZE            8
  #define MOUSE_INTERVAL        2
  #define RAWHID_INTERFACE      5	// RawHID
  #define RAWHID_TX_ENDPOINT    6
  #define RAWHID_TX_SIZE        64
  #define RAWHID_TX_INTERVAL    1
  #define RAWHID_RX_ENDPOINT    6
  #define RAWHID_RX_SIZE        64
  #define RAWHID_RX_INTERVAL    1
  #define FLIGHTSIM_INTERFACE	6	// Flight Sim Control
  #define FLIGHTSIM_TX_ENDPOINT	9
  #define FLIGHTSIM_TX_SIZE	64
  #define FLIGHTSIM_TX_INTERVAL	1
  #define FLIGHTSIM_RX_ENDPOINT	9
  #define FLIGHTSIM_RX_SIZE	64
  #define FLIGHTSIM_RX_INTERVAL	1
  #define JOYSTICK_INTERFACE    7	// Joystick
  #define JOYSTICK_ENDPOINT     10
  #define JOYSTICK_SIZE         12	//  12 = normal, 64 = extreme joystick
  #define JOYSTICK_INTERVAL     1
/*
  #define MTP_INTERFACE		8	// MTP Disk
  #define MTP_TX_ENDPOINT	11
  #define MTP_TX_SIZE		64
  #define MTP_RX_ENDPOINT	3
  #define MTP_RX_SIZE		64
  #define MTP_EVENT_ENDPOINT	11
  #define MTP_EVENT_SIZE	16
  #define MTP_EVENT_INTERVAL	10
*/
  #define KEYMEDIA_INTERFACE    8	// Keyboard Media Keys
  #define KEYMEDIA_ENDPOINT     12
  #define KEYMEDIA_SIZE         8
  #define KEYMEDIA_INTERVAL     4
  #define AUDIO_INTERFACE	9	// Audio (uses 3 consecutive interfaces)
  #define AUDIO_TX_ENDPOINT     13
  #define AUDIO_TX_SIZE         180
  #define AUDIO_RX_ENDPOINT     13
  #define AUDIO_RX_SIZE         180
  #define AUDIO_SYNC_ENDPOINT	14
  #define MULTITOUCH_INTERFACE  12	// Touchscreen
  #define MULTITOUCH_ENDPOINT   15
  #define MULTITOUCH_SIZE       8
  #define MULTITOUCH_FINGERS    10
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_TRANSMIT_AND_RECEIVE
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_AND_RECEIVE
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT6_CONFIG	ENDPOINT_TRANSMIT_AND_RECEIVE
  #define ENDPOINT7_CONFIG	ENDPOINT_TRANSMIT_AND_RECEIVE
  #define ENDPOINT8_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT9_CONFIG	ENDPOINT_TRANSMIT_AND_RECEIVE
  #define ENDPOINT10_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT11_CONFIG	ENDPOINT_TRANSMIT_AND_RECEIVE
  #define ENDPOINT12_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT13_CONFIG	(ENDPOINT_RECEIVE_ISOCHRONOUS|ENDPOINT_TRANSMIT_ISOCHRONOUS)
  #define ENDPOINT14_CONFIG	ENDPOINT_TRANSMIT_ISOCHRONOUS
  #define ENDPOINT15_CONFIG	ENDPOINT_TRANSMIT_ONLY

// ************************
// Notes
/* ************************

1. XINPUT_INTERFACE must always be the first interface (interface 0)

2. The other 3 interfaces originally defined by Arduino_XInput are not needed. Only the 
    first "control" interface

3. VENDOR_ID/PRODUCT_ID should not match any existing driver so that the device
    is assigned the generic parent driver

4. NUM_COMPAT_IDS should be the same as NUM_INTERFACE unless interfaces are grouped
    using an Interface Association Descriptor (IAD). In which case there should be
    one compatibleID entry for each IAD and each interface not in an IAD. More details
    can be found in the OS 1.0 Descriptor Specifications

5. CONFIG_DESC_SIZE is no longer manually calculated for XInput devices

6. BCD_USB (usb version spec) is set to 0x0200. This is required in order to use OS Feature
    Descriptors. It may cause additional descriptor requests such as the Device Qualifier Descriptor
    but these can be ignored.

7. VENDOR_CODE is used as the .bRequest value in the OS Feature Descriptor request. It matches
    the .bMS_VendorCode supplied in usb_os_string_descriptor. It can be any value so long as it does
    not match any of the standard .bRequest values.

8. If using IADs, the DEVICE_CLASS/SUBCLASS/PROTOCOL should be 0xEF, 0x02 and 0x01 respectively.
    You will also need to either modify the size definitions in usb_desc.c to include the IAD
    or manually #define CONFIG_DESC_SIZE

9. OS_DESC_VERSION is used to enable OS descriptor features but also defines the version in case
    support for OS 2.0 Descriptors is added.


The steps to add a new composite device are mostly the same as before in regards to this file.

1. create a new #elif branch according to the value used in boards.txt

2. Add the appropriate definitions matching the patterns of existing devices

3. Ensure that the XINPUT_INTERFACE is first (0) and uses endpoints 1 and 2

4. Ensure that NUM_COMPAT_IDS matches the number of interfaces or independent interfaces + IADs

5. Ensure that VENDOR_ID and PRODUCT_ID do NOT match a driver (i.e. 0x045e:0x028e used by XBox 360 controllers)



When debugging it may be useful to incrementally change BCD_DEVICE (firmware version) or the PRODUCT_ID. Windows
only queries the OS Descriptors the first time a device is plugged in. You can alternately uinstall the device
in Device Manager (USBDeview is easier since you can list by VID/PID) and delete the registry values found in

Computer\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\usbflags\VID+PID+BCDVERSION

*/

#elif defined(USB_XINPUT)
  #define BCD_USB 0x0200
  #define OS_DESC_VERSION 0x0100
  #define DEVICE_CLASS	0x00
  #define DEVICE_SUBCLASS	0x00
  #define DEVICE_PROTOCOL	0x00
  #define DEVICE_ATTRIBUTES 0xA0
  #define VENDOR_ID
  #define PRODUCT_ID
  #define VENDOR_CODE           0xA5
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'X','I','n','p','u','t',' ','C','o','n','t','r','o','l','l','e','r'}
  #define PRODUCT_NAME_LEN	    17
  #define EP0_SIZE	            8
  #define NUM_ENDPOINTS	        2
  #define NUM_USB_BUFFERS	      24
  #define NUM_INTERFACE	        1
  #define NUM_COMPAT_IDS        1
  #define XINPUT_INTERFACE	    0
  #define XINPUT_RX_ENDPOINT	  2
  #define XINPUT_RX_SIZE        8
  #define XINPUT_TX_ENDPOINT	  1
  #define XINPUT_TX_SIZE        20
  #define ENDPOINT1_CONFIG ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG ENDPOINT_RECEIVE_ONLY
#endif // USB_XINPUT

#elif defined(USB_XINPUT_KEYBOARD_MOUSE)
  #define BCD_USB 0x0200
  #define OS_DESC_VERSION 0x0100
  #define DEVICE_CLASS 0x00
  #define DEVICE_SUBCLASS 0x00
  #define DEVICE_PROTOCOL 0x00
  #define DEVICE_ATTRIBUTES 0xA0
  #define VENDOR_ID
  #define PRODUCT_ID
  #define VENDOR_CODE           0xA5
  #define MANUFACTURER_NAME {'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN 11
  #define PRODUCT_NAME {'X', 'I', 'n', 'p', 'u', 't', '+', 'K', 'B', 'M'}
  #define PRODUCT_NAME_LEN 10
  #define EP0_SIZE              64
  #define NUM_ENDPOINTS         4
  #define NUM_USB_BUFFERS       24
  #define NUM_INTERFACE         3
  #define NUM_COMPAT_IDS        3
  #define XINPUT_INTERFACE      0
  #define XINPUT_RX_ENDPOINT    2
  #define XINPUT_RX_SIZE        8
  #define XINPUT_TX_ENDPOINT    1
  #define XINPUT_TX_SIZE        20
  #define KEYBOARD_INTERFACE    1 // Keyboard
  #define KEYBOARD_ENDPOINT     3
  #define KEYBOARD_SIZE         8
  #define KEYBOARD_INTERVAL     1
  #define MOUSE_INTERFACE       2 // Mouse
  #define MOUSE_ENDPOINT        4
  #define MOUSE_SIZE            8
  #define MOUSE_INTERVAL        1
  #define ENDPOINT1_CONFIG ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT2_CONFIG ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT4_CONFIG ENDPOINT_TRANSMIT_ONLY
#endif // USB_XINPUT_KEYBOARD_MOUSE

#elif defined(USB_XINPUT_SERIAL)

#endif // USB_XINPUT_SERIAL

#elif defined(USB_XINPUT_DIRECTINPUT)

#endif // USB_XINPUT_DIRECTINPUT
  

#endif

#ifdef USB_DESC_LIST_DEFINE
#if defined(NUM_ENDPOINTS) && NUM_ENDPOINTS > 0
// NUM_ENDPOINTS = number of non-zero endpoints (0 to 15)
extern const uint8_t usb_endpoint_config_table[NUM_ENDPOINTS];

typedef struct {
	uint16_t	wValue;
	uint16_t	wIndex;
	const uint8_t	*addr;
	uint16_t	length;
} usb_descriptor_list_t;

extern const usb_descriptor_list_t usb_descriptor_list[];
#endif // NUM_ENDPOINTS
#endif // USB_DESC_LIST_DEFINE

#endif
