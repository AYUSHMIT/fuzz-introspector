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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Simple string validation function - EASILY REACHABLE
int validate_input(const uint8_t *data, size_t size) {
    if (size < 4) {
        return 0;
    }
    
    // Check for valid magic bytes
    if (data[0] == 'F' && data[1] == 'U' && data[2] == 'Z' && data[3] == 'Z') {
        return 1;
    }
    
    return 0;
}

// Parse basic header - EASILY REACHABLE
void parse_header(const uint8_t *data, size_t size) {
    if (size < 8) {
        return;
    }
    
    printf("Parsing header...\n");
    
    // Simple header parsing
    uint16_t version = (data[4] << 8) | data[5];
    uint16_t flags = (data[6] << 8) | data[7];
    
    printf("Version: %u, Flags: %u\n", version, flags);
}

// Complex processing function - HARDER TO REACH
int process_complex_data(const uint8_t *data, size_t size) {
    if (size < 20) {
        return -1;
    }
    
    // This requires specific input pattern to reach
    if (data[0] == 'F' && data[1] == 'U' && data[2] == 'Z' && data[3] == 'Z') {
        if (data[8] == 0xDE && data[9] == 0xAD) {
            if (data[10] == 0xBE && data[11] == 0xEF) {
                printf("Complex data pattern found!\n");
                
                // Nested complexity
                int sum = 0;
                for (size_t i = 12; i < size && i < 20; i++) {
                    sum += data[i];
                }
                
                if (sum > 500) {
                    printf("High complexity processing...\n");
                    return sum;
                }
            }
        }
    }
    
    return 0;
}

// Advanced feature - VERY HARD TO REACH
void advanced_feature(const uint8_t *data, size_t size) {
    if (size < 30) {
        return;
    }
    
    // Requires very specific pattern
    if (memcmp(data, "FUZZ", 4) == 0) {
        if (data[8] == 0xDE && data[9] == 0xAD) {
            if (data[10] == 0xBE && data[11] == 0xEF) {
                // Check for additional magic pattern
                if (data[20] == 0xCA && data[21] == 0xFE) {
                    if (data[22] == 0xBA && data[23] == 0xBE) {
                        printf("Advanced feature unlocked!\n");
                        
                        // Complex computation
                        uint32_t value = 0;
                        for (size_t i = 24; i < size && i < 30; i++) {
                            value = (value << 8) | data[i];
                        }
                        
                        if (value == 0x12345678) {
                            printf("Secret value found: 0x%08X\n", value);
                        }
                    }
                }
            }
        }
    }
}

// Hidden vulnerability - ALMOST UNREACHABLE
void hidden_vulnerability(const uint8_t *data, size_t size) {
    if (size < 50) {
        return;
    }
    
    // This function has a buffer overflow vulnerability
    // but it's very hard to reach without good fuzzing
    if (memcmp(data, "FUZZ", 4) == 0) {
        if (data[8] == 0xDE && data[9] == 0xAD) {
            if (data[10] == 0xBE && data[11] == 0xEF) {
                if (data[20] == 0xCA && data[21] == 0xFE) {
                    if (data[22] == 0xBA && data[23] == 0xBE) {
                        if (data[30] == 0x99 && data[31] == 0x88) {
                            printf("Deep code path reached!\n");
                            
                            // Intentional vulnerability for demonstration
                            char buffer[16];
                            size_t copy_size = data[32];  // User-controlled size
                            
                            // This is dangerous!
                            if (copy_size < 100) {  // Weak validation
                                memcpy(buffer, data + 33, copy_size);
                                printf("Copied %zu bytes\n", copy_size);
                            }
                        }
                    }
                }
            }
        }
    }
}

// Main processing entry point
int process_data(const uint8_t *data, size_t size) {
    if (!validate_input(data, size)) {
        return -1;
    }
    
    parse_header(data, size);
    
    int result = process_complex_data(data, size);
    
    if (result > 100) {
        advanced_feature(data, size);
    }
    
    // Hidden vulnerability is only called under specific conditions
    if (size > 40 && result > 200) {
        hidden_vulnerability(data, size);
    }
    
    return 0;
}
