# Procedural Planets

## Overview

Procedural Planets is a C-based visualization project that generates planets deterministically using procedural generation techniques. Each planet is uniquely defined by its world coordinates (`x`, `y`), which are used to derive a seed value. This ensures that the same coordinates always produce the same planet while allowing an effectively infinite universe of unique worlds.

The project demonstrates deterministic random generation, terrain synthesis, and reproducible content creation commonly used in sandbox and space exploration games.

## Features

* Deterministic procedural planet generation.
* Infinite universe based on coordinate-dependent seeds.
* Unique planets generated from world positions (`x`, `y`).
* Reproducible results across sessions.
* Randomized planetary
* Real-time rendering and exploration.

## How It Works

Each planet is generated using a seed calculated from its coordinates:

```text
Seed = f(x, y)
```

Because the seed depends only on the coordinates, visiting the same location always produces the exact same planet.

Example:

```text
Planet (125, 48)  -> Seed A
Planet (812, -33) -> Seed B
Planet (125, 48)  -> Seed A
```

This allows the application to create an unlimited number of planets without storing them permanently.

## Project Structure

```text
<Project>/
├── src/                # Source code directory
│   └── Main.c          # Entry point file
├── Makefile.linux      # Linux build configuration
├── Makefile.windows    # Windows build configuration
├── Makefile.wine       # Wine build configuration
├── Makefile.web        # Emscripten build configuration
└── README.md           # This file
```

## Prerequisites

* GCC or Clang
* Make
* Standard development tools

### Required Libraries

* **Linux:** X11, PNG, JPEG
* **Windows:** WINAPI
* **WebAssembly:** Emscripten

## Build & Run

### Build on Linux

```sh
cd <Project>
make -f Makefile.linux all
```

### Build on Windows

```sh
cd <Project>
make -f Makefile.windows all
```

### Build for WebAssembly

```sh
cd <Project>
make -f Makefile.web all
```

The generated files will be placed inside the `build` directory.

## Execute

### Linux

```sh
make -f Makefile.linux exe
```

### Windows

```sh
make -f Makefile.windows exe
```

### WebAssembly

Serve the generated `index.html` using a web server and open it in a browser.

## Planet Generation Parameters

The procedural generator may use the coordinate-derived seed to create:

* Planet radius
* Color

All generated values are deterministic and reproducible.
Changing the coordinates automatically results in a different planet.

## Future Improvements

* Procedural moons
* Planetary rings
* Star systems
* Galaxy generation
* Biome simulation
* Resource mining
* Space navigation
* Planet persistence and saving

## Clean Build

To remove all generated build files:

```sh
make -f Makefile.linux clean
```

## License

This project is intended for educational purposes and experimentation with procedural generation techniques. Refer to the project's license file for distribution and usage terms.
