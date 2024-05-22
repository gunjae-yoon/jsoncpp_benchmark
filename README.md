# JSON C++ Benchmark

Copyright(c) 2024 Gunjae Yoon (rnswo42b@gmail.com)

## Introduction

This benchmark evaluates the conformance and performance of JSON libraries for C/C++. In this project, performance means parsing and accessing speed, and memory usages for maintaining the SAX structure. JCBM is used as namespace. JCBM means as follows.
- J: JSON
- C: CPP
- B: Benchmark
- M: Measure

## Benchmarks and Measurements

### Functinoal

Benchmark      | Description
---------------|----------------------------------------------------
Ordering       | Verify that the parsing result of JSON document maintains the order of the elements created within the JSON document.

### Performance

Benchmark      | Description
---------------|----------------------------------------------------
DOM Parsing    | Parse JSON text which includes all structure, at once
SAX Parsing    | Parse each JSON elements which compose structure

## Libraries

Currently 3 libraries are successfully benchmarked.
Library | Language | Version | Notes
--------|----------|---------|-------------------
[Nlohmann/json](https://github.com/nlohmann/json) | C++ | v3.11.3
[RapidJSON](https://github.com/miloyip/rapidjson) | C++ | v1.1.0 | 
[taocpp/json](https://github.com/taocpp/json) | C++ | 1.0.0-beta.14 | Uses [PEGTL](https://github.com/taocpp/PEGTL) for parsing

Libraries with Git repository will be automatically downloaded by the build process and referenced after they are built. 

## JSON data

All tested JSON data were written in UTF-8.
JSON file   | Size | Description
------------|------|-----------------------
`json_flat_1mb.json` [source](https://github.com/gunjae-yoon/jsoncpp_benchmark/blob/main/sample/json_flat_1mb.json) | 1,010 KB | 
`json_nested_1mb.json` [source](https://github.com/gunjae-yoon/jsoncpp_benchmark/blob/main/sample/json_nested_1mb.json) | 4,399 KB |

## Build and Run

1. Make `build` directory
2. Move into `build` directory
3. Prepare scripts and environments using cmake
4. Run GNU `make`

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```
