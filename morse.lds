SECTIONS {
    . = 0x87800000;

    .text : {
        start.o
        *.o
    }
}