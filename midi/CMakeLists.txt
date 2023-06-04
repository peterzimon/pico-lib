file(GLOB FILES *.cpp *.h)

add_library(midi ${FILES})

target_link_libraries(midi pico_stdlib 
                           hardware_gpio
                           hardware_uart
                           midi_parser
                           ringbuffer)

target_include_directories(midi PUBLIC ./)