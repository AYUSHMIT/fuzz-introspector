// Copyright 2024 Fuzz Introspector Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdint.h>
#include <stddef.h>

// External functions from sample.c
extern int validate_input(const uint8_t *data, size_t size);
extern void parse_header(const uint8_t *data, size_t size);
extern int process_complex_data(const uint8_t *data, size_t size);
extern int process_data(const uint8_t *data, size_t size);

// Basic fuzzer that only reaches surface-level functions
// This demonstrates POOR fuzzing coverage (~50%)
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    // Only test basic validation and header parsing
    // This misses most of the complex code paths!
    
    if (size < 4) {
        return 0;
    }
    
    // Test validation
    validate_input(data, size);
    
    // Test header parsing
    if (size >= 8) {
        parse_header(data, size);
    }
    
    // Test complex processing, but without proper seed corpus
    // This will rarely reach deep code paths
    if (size >= 20) {
        process_complex_data(data, size);
    }
    
    // Note: We don't call process_data() which is the main entry point
    // This means we miss coordinated testing of multiple functions
    
    return 0;
}
