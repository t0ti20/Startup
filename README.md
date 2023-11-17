# Microcontroller Startup & Linker Scripts for ARM Cortex-M3

## Overview

This repository contains custom startup and linker scripts written from scratch for ARM Cortex-M3 microcontrollers. Developed by Khaled El-Sayed (@t0ti20), these scripts are optimized for efficient code execution and memory usage.

## Contents

The repository is organized as follows:
```BASH
.
├── Cortex M-3
│ ├── Linker_Script.ld
│ ├── Startup.c
│ └── Startup.s
└── README.md
```

### [Linker_Script.ld](Cortex%20M-3/Linker_Script.ld)

- Custom linker script for ARM Cortex-M3.
- Defines memory layout for ROM and RAM.
- Optimized for efficient code execution.

### [Startup.c](Cortex%20M-3/Startup.c)

- Written in C.
- Implements startup code for ARM Cortex-M3.
- Initializes data and BSS sections.
- Includes vector table and interrupt handlers.

### [Startup.s](Cortex%20M-3/Startup.s)

- Written in ARM assembly with Thumb instructions.
- Contains the vector table and interrupt handlers.
- Branches to the main reset section and interrupt service routine.

## Usage

1. Clone the repository to your local machine:

```bash
git clone https://github.com/your-username/microcontroller-startup-scripts.git
```
2. Explore the Cortex M-3 directory for ARM Cortex-M3 scripts.
3. Integrate the scripts into your ARM Cortex-M3 microcontroller projects for optimized performance.

## Author
Khaled El-Sayed (@t0ti20)
Created on: 05.02.2023