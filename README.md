# decay-visualizer
Visualize the decay of chemicals in real-time.

![decay-visualizer-preview](https://github.com/user-attachments/assets/585b5fa8-e2c3-44e5-a977-0025a27a00d3)

This program uses ncurses to visualize the decay of chemicals. Each chemical is given a random probability at which decays, when they decay they will no longer be displayed.

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
