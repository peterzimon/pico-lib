/**
 * @file mcp48x2.h
 * @author Zimo (peterzimon.com)
 * @brief  
 * 
 * Raspberry Pi Pico driver for Microchip MCP4802/MCP4812/MCP4822
 * Docs: https://github.com/peterzimon/pico-lib/tree/main/mcp48x2
 * 
 * @version 0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _PICO_LIB_MCP48X2_H
#define _PICO_LIB_MCP48X2_H

#include <pico/stdlib.h>
#include <hardware/spi.h>

enum MCP48X2_Channel { dacA, dacB };
enum MCP48X2_Gain { x2, x1 };

class MCP48X2 {
public:
    void init(spi_inst_t *spi, uint8_t pin_cs, uint8_t pin_sck, uint8_t pin_tx);
    void config(MCP48X2_Channel channel, MCP48X2_Gain gain, bool active);
    void set_channel(MCP48X2_Channel channel);
    void set_gain(MCP48X2_Gain gain);
    void set_active(bool active);
    void write(uint16_t value);

private: 
    uint8_t m_config;
    spi_inst_t *m_spi_port;
    uint8_t m_pin_cs;
    
    void m_cs_select();
    void m_cs_deselect();
};

#endif