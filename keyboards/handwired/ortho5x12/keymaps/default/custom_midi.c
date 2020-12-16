#include "qmk_midi.h"

enum midi_keycodes {
  MID_1 = SAFE_RANGE,
  MID_2,
  MID_3,
  MID_4,
  MID_5,
  MID_6,
  MID_7,
  MID_8,
  MID_9,
  MID_10,
  MID_11,
  MID_12,
  MID_13,
  MID_14,
  MID_15,
  MID_16,
  MID_17,
  MID_18,
  MID_19,
  MID_20,
  MID_21,
  MID_EN,
  MID_CU,
  MID_CD,
  MID_OU,
  MID_OD,
  MID_VR
};

/*
    1 = A
    2 = As
    3 = B
    4 = C
    5 = Cs
    6 = D
    7 = Ds
    8 = E
    9 = F
   10 = Fs
   11 = G
   12 = Gs
*/

bool    midi_layer = false;
uint8_t midi_vel = 64;
uint8_t midi_enc_1 = 64;
uint8_t midi_enc_2 = 64;
uint8_t midi_channel = 0;
uint8_t midi_octave = 4;

void handle_midi_layer(uint8_t note, uint8_t velocity, uint8_t channel, uint8_t octave, uint8_t status){
    note = note + (12 * octave) + 20;   // The note and octave combined
    if(note > 127){                     // Testing for out of range
        return;                         // End because error
    }
    switch (status){
        case 0:
            midi_send_noteon(&midi_device, channel, note, velocity);
            break;
        case 1:
            midi_send_noteoff(&midi_device, channel, note, velocity);
            break;
        case 2:
            midi_send_cc(&midi_device,  channel, 86, velocity);
            break;
        case 3:
            midi_send_cc(&midi_device,  channel, 87, velocity);
            break;
    }

}
