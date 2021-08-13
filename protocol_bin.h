/*
  protocol_bin.h - binary protocol for grblhk

  (Wannabe) Part of grblhk

  Copyright (c) 2021 Anichang

  Grblhk is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grblhk is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grblhk.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _PROTOCOL_BIN_H_
#define _PROTOCOL_BIN_H_

#define CTRL_NUL  0x00
#define CTRL_SOH  0x01
#define CTRL_STX  0x02
#define CTRL_ETX  0x03
#define CTRL_EOT  0x04
#define CTRL_ENQ  0x05
#define CTRL_ACK  0x06
#define CTRL_BEL  0x07
#define CTRL_BS   0x08
#define CTRL_TAB  0x09
#define CTRL_LF   0x0A
#define CTRL_VT   0x0B
#define CTRL_FF   0x0C
#define CTRL_CR   0x0D
#define CTRL_SO   0x0E
#define CTRL_SI   0x0F
#define CTRL_DLE  0x10
#define CTRL_DC1  0x11
#define CTRL_DC2  0x12
#define CTRL_DC3  0x13
#define CTRL_DC4  0x14
#define CTRL_NAK  0x15
#define CTRL_SYN  0x16
#define CTRL_ETB  0x17
#define CTRL_CAN  0x18
#define CTRL_EM   0x19
#define CTRL_EOF  0x1A
#define CTRL_ESC  0x1B
#define CTRL_FS   0x1C
#define CTRL_GS   0x1D
#define CTRL_RS   0x1E
#define CTRL_US   0x1F
#define CTRL_DEL  0x7F
#define CTRL_EOL  "\r\n"

#define MSG_TYPE_CMD_RT 0x01 // realtime command
#define MSG_TYPE_CMD_OV 0x02 // override command
#define MSG_TYPE_BUFFER 0x03 // buffer data
#define MSG_TYPE_PLUGIN 0xff // unknown message, might be for plugins

typedef bool (*binary_parser_ptr)(char c);

extern bool binary_mode;

extern binary_parser_ptr cmd_rt_parser;
extern binary_parser_ptr cmd_ov_parser;
extern binary_parser_ptr buffer_parser;
extern binary_parser_ptr unknown_binary_type;

bool protocol_binary_dispatch(char c);

#endif