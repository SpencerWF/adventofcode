add_executable(star12
        star12.c
        )

# pull in common dependencies
target_link_libraries(star12 pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(star12)

# add url via pico_set_program_url
example_auto_set_url(star12)
