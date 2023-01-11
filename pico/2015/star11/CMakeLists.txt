add_executable(star11
        star11.c
        )

# pull in common dependencies
target_link_libraries(star11 pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(star11 1)
pico_enable_stdio_uart(star11 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(star11)

# add url via pico_set_program_url
example_auto_set_url(star11)
