# Fuzz Introspector Demo - Quick Reference Card

## 🎯 Quick Start (30 seconds)

```bash
# View the demo
cd demo
python3 -m http.server 8000
# Open http://localhost:8000 in your browser

# OR use the serve script
./serve.sh
```

## 📦 Try Sample Project (2 minutes)

```bash
cd demo/sample-project

# Build and test
make all
mkdir -p corpus
./fuzzer corpus/          # 47% coverage ❌
./improved-fuzzer corpus/ # 91% coverage ✅

# Clean up
make clean
```

## 📚 Tutorial Path (30 minutes)

1. [Setup](tutorial/01-setup.md) - Install tools (5 min)
2. [First Analysis](tutorial/02-first-analysis.md) - Run analysis (10 min)
3. [Interpret Results](tutorial/03-interpreting-results.md) - Understand metrics (10 min)
4. [Improve Fuzzer](tutorial/04-improving-fuzzer.md) - Apply insights (5 min)

## 📊 Key Metrics Explained

| Metric | Before | After | Why It Matters |
|--------|--------|-------|----------------|
| **Coverage** | 47.3% | 91.2% | More code tested = more bugs found |
| **Functions** | 8/15 | 14/15 | Complete API testing |
| **Complexity** | 23/45 | 42/45 | High complexity = high risk |
| **Bugs Found** | 0 | 1 | Critical buffer overflow discovered! |

## 🎓 Key Concepts

### Coverage Types
- **Line**: Each source line executed?
- **Branch**: Each if/else taken?
- **Edge**: Each code path followed? ← LibFuzzer uses this

### Cyclomatic Complexity
```
Complexity = Decision Points + 1

1-5   : Simple 🟢
6-10  : Moderate 🟡
11-20 : Complex 🟠
21+   : Very Complex 🔴
```

### Reachability
- **Direct**: Called immediately from fuzzer
- **Conditional**: Called under specific conditions
- **Unreachable**: Never called (coverage gap!)

## 💡 The One-Line Fix

```c
// ❌ Before: Testing functions separately
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    validate_input(data, size);
    parse_header(data, size);
    process_complex_data(data, size);
    return 0;
}

// ✅ After: Using coordinated entry point
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    process_data(data, size);  // One call, better coverage!
    return 0;
}
```

**Result**: +44% coverage, 1 critical bug found!

## 🔧 Common Commands

### Building with Instrumentation
```bash
clang -fsanitize=fuzzer,address -g -O1 sample.c fuzzer.c -o fuzzer
```

### Running Fuzzer
```bash
./fuzzer corpus/ \
    -max_total_time=60 \
    -dict=fuzzer.dict \
    -use_value_profile=1
```

### Generating Analysis (OSS-Fuzz)
```bash
python infra/helper.py build_fuzzers \
    --sanitizer introspector \
    your-project
```

## 🎯 Best Practices Checklist

### Before Fuzzing
- [ ] Identify main entry points
- [ ] Create seed corpus with valid inputs
- [ ] Build dictionary with magic values
- [ ] Set appropriate max_len

### During Analysis
- [ ] Check coverage metrics
- [ ] Identify unreached functions
- [ ] Find high-complexity, low-coverage code
- [ ] Review reachability graphs

### After Analysis
- [ ] Use optimal entry points
- [ ] Add targeted seed inputs
- [ ] Iterate and re-measure
- [ ] Document improvements

## 🐛 Troubleshooting

### "Fuzzer won't compile"
```bash
# Check clang version
clang --version  # Need 12.0+

# Install on Ubuntu
sudo apt-get install clang
```

### "Coverage not improving"
```bash
# Add seed corpus
echo "FUZZ" > corpus/seed1.txt

# Use dictionary
cat > fuzzer.dict << EOF
magic_fuzz="FUZZ"
magic_dead="\xDE\xAD"
EOF

# Run with dictionary
./fuzzer corpus/ -dict=fuzzer.dict
```

### "Demo page won't load"
```bash
# Use local server, not file://
python3 -m http.server 8000
# Then open http://localhost:8000
```

## 📈 Success Metrics

Good fuzzing targets:
- ✅ Coverage > 70%
- ✅ All public APIs reached
- ✅ High-complexity code tested
- ✅ Regular bug discoveries

## 🔗 Quick Links

- 🌐 [Demo Website](index.html)
- 📖 [Full Documentation](https://fuzz-introspector.readthedocs.io)
- 🎥 [Video Tutorial](https://www.youtube.com/watch?v=cheo-liJhuE)
- 💬 [Discussions](https://github.com/ossf/fuzz-introspector/discussions)
- 🐛 [Report Issues](https://github.com/ossf/fuzz-introspector/issues)

## 📝 Cheat Sheet

```bash
# Quick demo flow
cd demo/sample-project
make all                    # Build fuzzers
./fuzzer corpus/            # Run initial (poor)
./improved-fuzzer corpus/   # Run improved (great)
make clean                  # Clean up

# Analysis (with OSS-Fuzz)
cd /path/to/oss-fuzz
python infra/helper.py build_fuzzers --sanitizer introspector project-name

# View reports
cd build/out/project-name/inspector-report/
python3 -m http.server 8000
# Open fuzz_report.html
```

## 🎓 Learning Resources

**Beginner**:
1. Watch demo website
2. Try sample project
3. Read Tutorial Part 1-2

**Intermediate**:
4. Complete Tutorial Part 3-4
5. Analyze your own project
6. Experiment with parameters

**Advanced**:
7. OSS-Fuzz integration
8. Custom analysis scripts
9. Contribute to project

---

**Remember**: Bugs hide in untested code. Fuzz Introspector helps you find them! 🎯
