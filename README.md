# Image Filter CLI (CS50x)

A command-line image processing program written in C that applies visual filters to 24-bit uncompressed BMP images.

## Overview

This project was built as part of CS50x and focuses on low-level image manipulation, file format handling, and algorithmic problem-solving in C.

The program reads a BMP image, applies one selected filter, and writes the transformed result to a new BMP file while preserving image metadata and formatting requirements.

## Features

- `-g` Grayscale conversion
- `-s` Sepia tone conversion
- `-r` Horizontal reflection
- `-b` Box blur

## Tech Stack

- Language: C (C11)
- Build: Make + Clang
- Domain concepts: bitmap parsing, pixel matrix operations, boundary-safe neighborhood computation

## How It Works

1. Reads BMP headers (`BITMAPFILEHEADER` and `BITMAPINFOHEADER`).
2. Validates input as 24-bit uncompressed BMP 4.0.
3. Loads image pixels into a 2D RGB structure.
4. Applies the selected filter algorithm.
5. Writes updated pixels back to a correctly formatted BMP output file.

## Build

```bash
make
```

## Usage

```bash
./filter [flag] infile outfile
```

Examples:

```bash
./filter -g images/yard.bmp out-gray.bmp
./filter -s images/tower.bmp out-sepia.bmp
./filter -r images/courtyard.bmp out-reflect.bmp
./filter -b images/stadium.bmp out-blur.bmp
```

## Example Input Images

Sample BMP files are included in the `images/` folder:

- `yard.bmp`
- `tower.bmp`
- `courtyard.bmp`
- `stadium.bmp`

## What This Demonstrates

- Strong understanding of pointers, arrays, and memory management in C
- Ability to implement pixel-level image algorithms
- Correct handling of binary file I/O and format constraints
- Clear CLI input validation and error handling

## Resume-Ready Project Description

Built a C-based CLI image processor for BMP files, implementing grayscale, sepia, reflection, and blur filters through pixel-level algorithms. Handled binary bitmap parsing, scanline padding, dynamic memory allocation, and format-safe output generation with robust argument and file validation.

## Possible Next Improvements

- Add automated tests to compare outputs against expected fixtures
- Add performance benchmarks for each filter across image sizes
- Add an edge-detection filter (Sobel) as an advanced extension
- Include before/after sample images in a `docs/` folder

## License

This project is for educational use.
