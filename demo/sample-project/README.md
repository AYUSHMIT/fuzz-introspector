# Sample Fuzzing Project - Demo

## Overview

This sample project demonstrates the power of **Fuzz Introspector** in identifying and improving fuzzing coverage. It contains a simple C library (`sample.c`) with intentional coverage gaps to showcase how fuzz-introspector helps developers write better fuzzers.

## Project Structure

```
sample-project/
├── src/
│   ├── sample.c           # Target library with various complexity levels
│   ├── fuzzer.c           # Initial fuzzer (poor coverage ~50%)
│   └── improved-fuzzer.c  # Enhanced fuzzer (excellent coverage ~90%+)
├── reports/
│   ├── before/            # Fuzz-introspector analysis of initial fuzzer
│   └── after/             # Fuzz-introspector analysis of improved fuzzer
└── Makefile               # Build system
```

## The Problem: Coverage Gaps

### Target Library (`sample.c`)

The sample library contains 5 main functions with increasing complexity:

1. **`validate_input()`** - Easy to reach (basic validation)
2. **`parse_header()`** - Easy to reach (header parsing)
3. **`process_complex_data()`** - Harder to reach (requires specific magic bytes)
4. **`advanced_feature()`** - Very hard to reach (requires multiple magic patterns)
5. **`hidden_vulnerability()`** - Almost unreachable (deeply nested conditions)

### Initial Fuzzer (`fuzzer.c`) - ~50% Coverage ❌

The initial fuzzer has several problems:

- Only tests functions individually
- Doesn't use the main entry point `process_data()`
- Lacks proper seed corpus
- Misses coordinated function calls
- **Result: Only reaches 2-3 out of 5 functions**

```c
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    validate_input(data, size);
    parse_header(data, size);
    process_complex_data(data, size);  // Rarely reaches deep paths
    return 0;
}
```

### Improved Fuzzer (`improved-fuzzer.c`) - ~90%+ Coverage ✅

After analyzing with fuzz-introspector, we discovered:

- `process_data()` is the optimal entry point
- Need specific input patterns to reach deep code
- Should leverage coverage-guided fuzzing naturally

```c
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    process_data(data, size);  // Single optimal entry point
    return 0;
}
```

**Result: Reaches 4-5 out of 5 functions including the hidden vulnerability!**

## Building and Running

### Prerequisites

```bash
# Install clang with fuzzer support
sudo apt-get install clang

# Verify clang version
clang --version  # Should be 12.0+
```

### Build Both Fuzzers

```bash
make all
```

### Run Initial Fuzzer

```bash
mkdir -p corpus
make run-fuzzer
```

### Run Improved Fuzzer

```bash
make run-improved
```

## Analyzing with Fuzz Introspector

### Step 1: Install Fuzz Introspector

See the [main documentation](https://fuzz-introspector.readthedocs.io) for installation instructions.

### Step 2: Generate Analysis Report

```bash
# For initial fuzzer
fuzz-introspector --target=./fuzzer --output=reports/before/

# For improved fuzzer
fuzz-introspector --target=./improved-fuzzer --output=reports/after/
```

### Step 3: Compare Reports

Open the generated HTML reports in your browser:

- **Before**: `reports/before/fuzz_report.html`
- **After**: `reports/after/fuzz_report.html`

## Key Metrics Comparison

| Metric | Initial Fuzzer | Improved Fuzzer | Improvement |
|--------|---------------|-----------------|-------------|
| **Code Coverage** | ~50% | ~90%+ | +40% |
| **Functions Reached** | 2-3 / 5 | 4-5 / 5 | +2 functions |
| **Cyclomatic Complexity Covered** | Low | High | Significant |
| **Vulnerabilities Found** | 0 | 1 (buffer overflow) | Critical! |

## What Fuzz Introspector Revealed

### 🔍 Analysis Insights

1. **Call Tree Analysis**
   - Showed that `process_data()` coordinates all other functions
   - Identified it as the optimal fuzzing target

2. **Reachability Analysis**
   - Revealed `advanced_feature()` and `hidden_vulnerability()` were unreachable
   - Showed the input patterns needed to reach them

3. **Complexity Analysis**
   - Highlighted `hidden_vulnerability()` as high-complexity and untested
   - This is where bugs are most likely!

4. **Coverage Gaps**
   - Visualized exactly which code paths were missing
   - Provided actionable recommendations

## Lessons Learned

### ✅ Best Practices

1. **Use Main Entry Points**: Call coordinated functions, not individual ones
2. **Trust Coverage-Guided Fuzzing**: LibFuzzer will find the paths
3. **Start with Seed Corpus**: Provide examples of valid inputs
4. **Analyze Regularly**: Run fuzz-introspector during development

### ❌ Common Mistakes

1. **Testing functions in isolation**: Misses interactions
2. **Ignoring complexity metrics**: High complexity = high bug risk
3. **Not analyzing coverage**: Flying blind without metrics
4. **Assuming 100% coverage**: Focus on critical paths first

## Real-World Impact

This toy example mirrors real security issues:

- **OpenSSL Heartbleed**: Deep code path, poor coverage
- **ImageMagick**: Complex parsers, insufficient fuzzing
- **SQLite**: Hidden edge cases in deeply nested logic

With fuzz-introspector, these vulnerabilities could have been found earlier!

## Next Steps

1. **Try modifying `sample.c`**: Add more complexity
2. **Experiment with seed corpus**: Create inputs that reach deep paths
3. **Compare coverage**: Use `llvm-cov` to validate improvements
4. **Apply to real projects**: Use these techniques on your own code

## Resources

- [Fuzz Introspector Documentation](https://fuzz-introspector.readthedocs.io)
- [LibFuzzer Tutorial](https://llvm.org/docs/LibFuzzer.html)
- [OSS-Fuzz](https://github.com/google/oss-fuzz)
- [Interactive Demo](../index.html)

---

**Ready to improve your fuzzing? Check out the [Interactive Tutorial](../tutorial/01-setup.md)!**
