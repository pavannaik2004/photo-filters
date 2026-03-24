# Image Filter CLI

A C-based command-line application that applies image filters to 24-bit uncompressed BMP files.

## Project Summary

This project was developed as part of CS50x to practice low-level programming in C, including binary file handling, memory management, and pixel-level image processing.

The application reads a BMP image, applies one filter selected by command-line flag, and writes the transformed image to a new BMP file while preserving valid bitmap structure.

## Implemented Filters

- Grayscale (`-g`)
- Sepia (`-s`)
- Horizontal reflection (`-r`)
- Box blur (`-b`)

## Technical Highlights

- Binary parsing of bitmap headers (`BITMAPFILEHEADER`, `BITMAPINFOHEADER`)
- Input validation for supported BMP format (24-bit, uncompressed)
- Pixel operations using 2D RGB arrays
- Boundary-safe neighborhood processing for blur
- Scanline padding handling for valid BMP output
- Defensive CLI and file I/O error handling

## Tech Stack

- Language: C (C11)
- Compiler: Clang
- Build tool: Make

## Build

```bash
make
```

## Usage

```bash
./filter [flag] infile outfile
```

## Example Commands

```bash
./filter -g images/yard.bmp out-gray.bmp
./filter -s images/tower.bmp out-sepia.bmp
./filter -r images/courtyard.bmp out-reflect.bmp
./filter -b images/stadium.bmp out-blur.bmp
```

## Included Sample Images

- images/yard.bmp
- images/tower.bmp
- images/courtyard.bmp
- images/stadium.bmp
