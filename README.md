# TDD for HAL example

A 'minimum' makefile based project which demonstrates TDD design for a crude usart driver and send buffer utility. Uses [doctest](https://github.com/onqtam/doctest) for unit tests and [trompeloeil](https://github.com/rollbear/trompeloeil) for Mocks.

The driver is set-up to support the NUCLEO-F767ZI but is stand-alone and the only build dependency should be [arm-none-eabi-gcc](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
