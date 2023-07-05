/*
gcc cSelfModifying.c -o cSelfModifying -T linker.ld
or
gcc -c cSelfModifying.c -o cSelfModifying.o
ld cSelfModifying.o /usr/lib/x86_64-linux-gnu/libc.so -o cSelfModifying -T linker.ld
*/
    
SECTIONS 
{
	. = SIZEOF_HEADERS;
	.text : {
		*(.text)
	}
	.encrypted : {
		_start_encrypted = .;
		*(.encrypted)
		_end_encrypted = .;
	}
	.rodata : {
		*(.rodata)
	}
	.data : {
		*(.data)
	}
	.bss : {
		*(.bss)
	}
}
