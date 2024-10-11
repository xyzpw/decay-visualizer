# decay-visualizer
Visualize the decay of chemicals in real-time.

This program uses ncurses to visualize the decay of chemicals. It prints ascii characters to the screen which represent chemicals, they will disappear from the display as they decay.

## Building Executable
To build executable, use `make` command while in the repo's root directory:
```bash
$ make
```

## Usage
Execute the script:
```bash
$ ./decay-visualizer
```

After executing you will be prompted for information to run the simulation.<br>
After inputting the required info, the simulation will begin. When all the chemicals have been eliminated, the display will exit and the duration of the simulation will be printed to the terminal.
