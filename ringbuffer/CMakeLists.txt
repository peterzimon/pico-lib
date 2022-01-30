file(GLOB FILES *.cpp *.h)

add_library(ringbuffer ${FILES})

target_link_libraries(ringbuffer 
                        pico_stdlib
                        hardware_spi)

target_include_directories(ringbuffer PUBLIC ./)