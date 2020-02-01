# Corewar. School 42 project.

Programming game from the 80's. Here you can find our's implimentation of this game as an Ecole 42 (School 21) project.

I just have to boast of: All this (except for ncurses visual mode) writed using just following libc functions:
```
malloc(), free(), open(), close(), read(), write(), exit().
```

### Getting Started

```
git clone <repository url>
```

### Installation

```
make
```

### Translating pseudo-ASM .s files into .cor bytecode files

```
./asm <champ_name.s>
```

### Running the game:

```
./corewar [-dump N] [-log] [-a] [-n N] <champion1.cor> [-n N] <...> [-v]
    -dump N		: Dumps memory after N cycles then exits
	-log		: Show logs (you probably want to redirect it to file, use '> file.log' to do so)
	-a			: aff operation output on
	-n			: Assign a number N to the champion
	-v			: Ncurses output mode
```

### Where to get champions?

./champs/*.s (has to be translated with ./asm)

And ofc, you can write your own champions! (If you figure out how :D)

### Where to get reference?

Original ./corewar and ./asm executables (which are specified in 42's project files) is in the ./reference_binaries/ directory. You can see usage instructions, just run them without arguments. It's pretty simillar to that was mentioned above.

## Authors

* **Nikita Timorin** - *VM structure, ncurses output mode* - [timorinn](https://github.com/timorinn)
* **Egor Smirnov** - *VM operations, logging* - [hensnenenej](https://github.com/hensnenenej)
* **Aydar Faskhutdinov** - *ASM* - [swedde](https://github.com/swedde)
