#ifndef _PICO_LIB_MIDI_H
#define _PICO_LIB_MIDI_H

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"
#include <midi_parser.h>
#include <ringbuffer.h>

#define MIDI_BUFFER_SIZE 32
#define NOTE_STACK_SIZE 25
#define NO_OF_MIDI_NOTES 128
#define MIDI_UART_INSTANCE uart1
#define GP_MIDI_RX 9
#define MIDI_BAUDRATE 31250
#define PITCH_BEND_CENTER 0x2000

class Midi: public MidiParser {
public:
    bool pitch_bend_dirty;
    bool note_playing;
    int note_stack[NOTE_STACK_SIZE];
    uint16_t bend;
    
    void init(void);
    void read();
    void note_on(uint8_t channel, uint8_t note, uint8_t velocity);
    void note_off(uint8_t channel, uint8_t note, uint8_t velocity);
    void pitch_bend(uint8_t channel, uint16_t bend);
    int last_note();

private:
    int m_gate;
    uint8_t m_buffer_var[MIDI_BUFFER_SIZE];
    uint8_t m_last_note;
    uint16_t m_cv;
    uint16_t m_last_pitch_bend;
    RingBuffer m_input_buffer;

    void m_parse_midi();
    void m_push_note(uint8_t note);
    void m_pop_note(uint8_t note);
    int m_find_note(uint8_t note);
};

#endif