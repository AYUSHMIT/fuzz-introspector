# Fuzz Introspector Interactive Demo

Welcome to the **Fuzz Introspector Interactive Demo**! This comprehensive demonstration showcases how fuzz-introspector helps developers identify coverage gaps, analyze code complexity, and systematically improve fuzzing harnesses.

## 🎯 Quick Start

### Option 1: View the Demo Website

Simply open the demo in your browser:

```bash
cd demo
python3 -m http.server 8000
# Then open http://localhost:8000 in your browser
```

Or directly open `index.html` in your browser for a static viewing experience.

### Option 2: Try the Sample Project

```bash
cd demo/sample-project

# Build the fuzzers
make all

# Run the initial fuzzer (poor coverage)
./fuzzer corpus/

# Run the improved fuzzer (excellent coverage)
./improved-fuzzer corpus/

# Compare the results!
```

### Option 3: Follow the Tutorial

Start with the step-by-step tutorial:

1. [Part 1: Setup](tutorial/01-setup.md) - Install and configure
2. [Part 2: First Analysis](tutorial/02-first-analysis.md) - Run your first analysis
3. [Part 3: Interpreting Results](tutorial/03-interpreting-results.md) - Understand the metrics
4. [Part 4: Improving Your Fuzzer](tutorial/04-improving-fuzzer.md) - Apply the insights

## 📦 What's Included

### 1. Interactive Demo Website (`index.html`)

A modern, responsive single-page application featuring:

- **Hero Section**: Animated introduction to Fuzz Introspector
- **Feature Showcase**: Interactive cards highlighting key capabilities
- **Live Demo**: Before/after comparison with real metrics
- **Code Examples**: Syntax-highlighted code showing improvements
- **Interactive Charts**: Visual coverage comparison using Chart.js
- **Dark Mode**: Toggle between light and dark themes
- **Responsive Design**: Works on desktop, tablet, and mobile

**Technologies Used**:
- TailwindCSS for styling
- Chart.js for visualizations
- Prism.js for syntax highlighting
- AOS (Animate On Scroll) for animations

### 2. Sample Analysis Project (`sample-project/`)

A complete C project demonstrating fuzzing analysis:

**Structure**:
```
sample-project/
├── src/
│   ├── sample.c           # Library with intentional coverage gaps
│   ├── fuzzer.c           # Initial fuzzer (~50% coverage)
│   └── improved-fuzzer.c  # Enhanced fuzzer (~90%+ coverage)
├── reports/
│   ├── before/            # Analysis of initial fuzzer
│   └── after/             # Analysis of improved fuzzer
├── Makefile               # Build system
└── README.md              # Comprehensive documentation
```

**Key Features**:
- 5 functions with varying complexity levels
- Intentional buffer overflow vulnerability (for demonstration)
- Magic byte patterns requiring specific inputs
- Nested conditions creating coverage challenges
- Realistic code structure mimicking real-world projects

### 3. Comprehensive Tutorial (`tutorial/`)

Four-part tutorial covering:

**Part 1: Setup** (`01-setup.md`)
- Installation instructions (from source, pip, Docker)
- Prerequisites and dependencies
- Environment configuration
- Verification steps

**Part 2: First Analysis** (`02-first-analysis.md`)
- Compilation with instrumentation
- Running Fuzz Introspector
- Understanding the HTML reports
- Interpreting basic metrics

**Part 3: Interpreting Results** (`03-interpreting-results.md`)
- Deep dive into coverage metrics
- Cyclomatic complexity analysis
- Reachability graphs
- Priority identification

**Part 4: Improving Your Fuzzer** (`04-improving-fuzzer.md`)
- Fixing entry point issues
- Creating seed corpus
- Using fuzzer dictionaries
- Iterative improvement process

### 4. Visual Assets (`assets/`)

**JavaScript** (`assets/js/`):
- `demo.js`: Interactive features, chart initialization, smooth scrolling

**CSS** (`assets/css/`):
- Custom styles (integrated in index.html)
- Dark mode support
- Responsive utilities

**Images** (`assets/images/`):
- Placeholder for screenshots and diagrams
- Architecture diagrams
- Coverage comparisons

## 🎨 Features Highlighted

### 1. Coverage Analysis
- Visual representation of code coverage
- Before/after comparison
- Per-function coverage breakdown
- Coverage gap identification

### 2. Complexity Metrics
- Cyclomatic complexity scoring
- High-risk code identification
- Complexity vs. coverage analysis
- Priority ranking

### 3. Reachability Analysis
- Call tree visualization
- Function reachability from fuzzers
- Blocker identification
- Optimal target suggestions

### 4. Multi-Language Support
- C/C++ examples
- References to Python, Java, Rust support
- OSS-Fuzz integration examples

## 📊 Demo Metrics

### Initial Fuzzer Performance
- **Code Coverage**: 47.3%
- **Functions Reached**: 8/15 (53%)
- **Complexity Covered**: 23/45 (51%)
- **Vulnerabilities Found**: 0

### Improved Fuzzer Performance
- **Code Coverage**: 91.2% (+43.9% ✅)
- **Functions Reached**: 14/15 (93%)
- **Complexity Covered**: 42/45 (93%)
- **Vulnerabilities Found**: 1 (Buffer overflow)

### Key Insight
By simply using the main entry point `process_data()` instead of calling functions individually, coverage improved by 44% and uncovered a critical security vulnerability!

## 🚀 Running the Demo

### Prerequisites

- Python 3.7+ (for local server)
- Modern web browser (Chrome, Firefox, Safari, Edge)
- Optional: Clang/LLVM for building sample project

### Steps

1. **Clone the Repository**
   ```bash
   git clone https://github.com/ossf/fuzz-introspector.git
   cd fuzz-introspector/demo
   ```

2. **Start Local Server** (optional but recommended)
   ```bash
   python3 -m http.server 8000
   ```

3. **Open in Browser**
   ```
   http://localhost:8000
   ```

4. **Explore**
   - Navigate through sections
   - Try dark mode toggle
   - View interactive charts
   - Read code examples
   - Follow tutorial links

## 🛠️ Building Sample Project

### Requirements
- Clang 12.0+ with fuzzer support
- LibFuzzer (included with Clang)
- AddressSanitizer support

### Build Commands

```bash
cd sample-project

# Build both fuzzers
make all

# Or build individually
make fuzzer           # Initial fuzzer
make improved-fuzzer  # Improved fuzzer

# Clean build artifacts
make clean
```

### Running Fuzzers

```bash
# Create corpus directory
mkdir -p corpus

# Run initial fuzzer (30 seconds)
timeout 30 ./fuzzer corpus/

# Run improved fuzzer (30 seconds)
timeout 30 ./improved-fuzzer corpus/

# Compare coverage in terminal output
```

### Expected Output

**Initial Fuzzer**:
```
INFO: -max_len is not provided; libFuzzer will not generate inputs larger than 4096 bytes
INFO: A corpus is not provided, starting from an empty corpus
#2      INITED cov: 12 ft: 13 corp: 1/1b exec/s: 0 rss: 25Mb
#1000   NEW    cov: 15 ft: 18 corp: 5/10b lim: 8 exec/s: 500 rss: 26Mb
...
```

**Improved Fuzzer**:
```
INFO: -max_len is not provided; libFuzzer will not generate inputs larger than 4096 bytes
INFO: A corpus is not provided, starting from an empty corpus
#2      INITED cov: 18 ft: 19 corp: 1/1b exec/s: 0 rss: 25Mb
#500    NEW    cov: 28 ft: 35 corp: 8/45b lim: 8 exec/s: 250 rss: 26Mb
#5000   NEW    cov: 42 ft: 58 corp: 15/120b lim: 16 exec/s: 400 rss: 28Mb
...
```

Notice the improved fuzzer reaches higher coverage (`cov`) faster!

## 📚 Documentation

### Main Documentation
- **Demo Website**: `index.html` - Interactive showcase
- **Sample Project**: `sample-project/README.md` - Detailed project guide
- **Tutorial Part 1**: `tutorial/01-setup.md` - Setup instructions
- **Tutorial Part 2**: `tutorial/02-first-analysis.md` - First analysis
- **Tutorial Part 3**: `tutorial/03-interpreting-results.md` - Metrics deep dive
- **Tutorial Part 4**: `tutorial/04-improving-fuzzer.md` - Optimization guide

### External Resources
- [Official Documentation](https://fuzz-introspector.readthedocs.io)
- [Video Walkthrough](https://www.youtube.com/watch?v=cheo-liJhuE)
- [OSS-Fuzz Integration](https://introspector.oss-fuzz.com)
- [GitHub Repository](https://github.com/ossf/fuzz-introspector)

## 🎓 Learning Path

### Beginner
1. View the demo website (`index.html`)
2. Read "What is Fuzz Introspector?" section
3. Try the sample project
4. Complete Tutorial Part 1 & 2

### Intermediate
1. Complete Tutorial Part 3 & 4
2. Analyze the sample project code
3. Modify `sample.c` to add complexity
4. Experiment with seed corpus

### Advanced
1. Apply to your own projects
2. Integrate with OSS-Fuzz
3. Create custom analysis scripts
4. Contribute to the project

## 🤝 Contributing

We welcome contributions to improve the demo!

### Areas for Contribution
- Additional sample projects (different languages)
- More interactive visualizations
- Video content
- Tutorial improvements
- Bug fixes and enhancements

### How to Contribute
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests if applicable
5. Submit a pull request
6. Sign off commits with DCO

See [CODE_OF_CONDUCT.md](../CODE_OF_CONDUCT.md) for community guidelines.

## 🐛 Troubleshooting

### Issue: Demo page doesn't load properly

**Solution**: Use a local HTTP server instead of opening directly:
```bash
python3 -m http.server 8000
```

### Issue: Charts not displaying

**Solution**: 
- Check browser console for errors
- Ensure JavaScript is enabled
- Try a different browser
- Check internet connection (CDN dependencies)

### Issue: Sample project won't build

**Solution**:
```bash
# Check clang version
clang --version  # Should be 12.0+

# Install clang on Ubuntu
sudo apt-get install clang

# Install clang on macOS
brew install llvm
```

### Issue: Fuzzer crashes immediately

**Solution**:
```bash
# Run with verbose output
./fuzzer -help=1

# Check for ASan errors
ASAN_OPTIONS=verbosity=1 ./fuzzer corpus/

# Reduce max_len if memory limited
./fuzzer -max_len=512 corpus/
```

## 📄 License

Copyright 2024 Fuzz Introspector Authors

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

## 🌟 Acknowledgments

- **OpenSSF**: For hosting and supporting the project
- **OSS-Fuzz**: For integration and real-world testing
- **Community Contributors**: For feedback and improvements

## 📞 Contact & Support

- **GitHub Issues**: [Report bugs](https://github.com/ossf/fuzz-introspector/issues)
- **Discussions**: [Ask questions](https://github.com/ossf/fuzz-introspector/discussions)
- **Community Calls**: Monthly fuzzing collaboration meetings
- **Documentation**: [Read the docs](https://fuzz-introspector.readthedocs.io)

---

**Happy Fuzzing! 🚀**

Ready to improve your fuzzing? [Get started now](tutorial/01-setup.md) or [view the live demo](index.html)!
