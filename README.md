## Converter-json

A fast and efficient converter that transform YAML into JSON format ⚡.

## Features 🌌:

- YAML to JSON conversion
- Pretty-printed JSON output
- UTF-8 support
- CLI

## Build Requirements 🔎:

- C++23 compiler (clang/gcc)
- CMake 3.15 or higher
- If library don't download automatically, you need to download it manually:
- [yaml-cpp](https://github.com/jbeder/yaml-cpp)
- [nlohmann-json](https://github.com/nlohmann/json/)

## Installation/Building 🔧:

```bash
git clone https://github.com/Hkmori15/converter-json.git
cmake -B build
cmake --build build
```
## Usage 📄:

Convert YAML to JSON:
```bash
z/cd build && ./convert input.yaml output.json
```
