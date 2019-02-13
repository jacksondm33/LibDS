/*
 * The Driver Station Library (LibDS)
 * Copyright (c) 2015-2017 Alex Spataru <alex_spataru@outlook>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef _LIB_DS_PROTOCOL_H
#define _LIB_DS_PROTOCOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "DS_Socket.h"
#include "DS_String.h"

typedef struct _protocol {
    DS_String name;
    DS_String (*radio_address) (void);
    DS_String (*robot_address) (void);
    DS_String (*fms_address) (void);

    DS_String (*create_radio_packet) (void);
    DS_String (*create_robot_udp_packet) (void);
    DS_String (*create_robot_tcp_packet) (void);
    DS_String (*create_fms_udp_packet) (void);
    DS_String (*create_fms_tcp_packet) (void);

    int (*read_radio_packet) (const DS_String*);
    int (*read_robot_udp_packet) (const DS_String*);
    int (*read_robot_tcp_packet) (const DS_String*);
    int (*read_fms_udp_packet) (const DS_String*);
    int (*read_fms_tcp_packet) (const DS_String*);

    void (*reset_radio) (void);
    void (*reset_robot) (void);
    void (*reset_fms) (void);

    void (*reboot_robot) (void);
    void (*restart_robot_code) (void);

    int radio_interval;
    int robot_interval;
    int fms_interval;

    int max_joysticks;
    int max_axis_count;
    int max_hat_count;
    int max_button_count;
    float max_battery_voltage;

    DS_Socket radio_socket;
    DS_Socket robot_udp_socket;
    DS_Socket robot_tcp_socket;
    DS_Socket fms_udp_socket;
    DS_Socket fms_tcp_socket;
} DS_Protocol;

extern void Protocols_Init();
extern void Protocols_Close();
extern void DS_ConfigureProtocol (const DS_Protocol* ptr);

extern unsigned long DS_SentRadioBytes();
extern unsigned long DS_SentRobotUDPBytes();
extern unsigned long DS_SentRobotTCPBytes();
extern unsigned long DS_SentFMSUDPBytes();
extern unsigned long DS_SentFMSTCPBytes();

extern unsigned long DS_ReceivedRadioBytes();
extern unsigned long DS_ReceivedRobotUDPBytes();
extern unsigned long DS_ReceivedRobotTCPBytes();
extern unsigned long DS_ReceivedFMSUDPBytes();
extern unsigned long DS_ReceivedFMSTCPBytes();

extern int DS_SentRadioPackets();
extern int DS_SentRobotUDPPackets();
extern int DS_SentRobotTCPPackets();
extern int DS_SentFMSUDPPackets();
extern int DS_SentFMSTCPPackets();

extern int DS_ReceivedRadioPackets();
extern int DS_ReceivedRobotUDPPackets();
extern int DS_ReceivedRobotTCPPackets();
extern int DS_ReceivedFMSUDPPackets();
extern int DS_ReceivedFMSTCPPackets();

extern void DS_ResetRadioPackets();
extern void DS_ResetRobotUDPPackets();
extern void DS_ResetRobotTCPPackets();
extern void DS_ResetFMSUDPPackets();
extern void DS_ResetFMSTCPPackets();

extern DS_Protocol* DS_CurrentProtocol();

#ifdef __cplusplus
}
#endif

#endif
