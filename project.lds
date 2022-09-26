SECTIONS {
    . = 0x87800000;

    .text : {
        obj/start.o
        *.o
    }
}