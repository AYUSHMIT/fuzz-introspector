# Demo Assets Guidelines

## Images

### Required Images (To Be Created)

1. **architecture-diagram.svg**
   - Visual representation of Fuzz Introspector architecture
   - Components: Source Code → Instrumentation → Analysis → Reports
   - Tools: Can be created with draw.io, Figma, or similar
   - Dimensions: 1200x600px recommended

2. **coverage-comparison.png**
   - Side-by-side bar charts showing before/after coverage
   - Before: 47.3% coverage (red/orange)
   - After: 91.2% coverage (green)
   - Can be created with Python/matplotlib or chart tools

3. **demo-workflow.gif**
   - Animated demonstration of tool in action
   - Sequence: Build → Run → Analyze → Improve
   - Tools: ScreenToGif, LICEcap, or similar screen recorders
   - Duration: 5-10 seconds looping

### Screenshot Guidelines

When taking screenshots for documentation:
- Use 1920x1080 resolution
- Enable high DPI/retina display
- Use professional theme (dark mode preferred)
- Highlight important UI elements
- Add annotations if needed

### Image Optimization

Before committing images:
```bash
# For PNG files
optipng -o7 *.png

# For JPEG files  
jpegoptim --strip-all *.jpg

# For SVG files
svgo *.svg
```

## Placeholder Images

Until actual images are created, the demo uses:
- Inline SVG for icons/emojis
- CSS gradients for backgrounds
- Text-based representations in markdown

## Creating the Architecture Diagram

Suggested content:

```
┌─────────────┐
│ Source Code │
│  (C/C++/etc)│
└──────┬──────┘
       │
       ▼
┌─────────────────┐
│ Instrumentation │
│  (Clang/LLVM)   │
└────────┬────────┘
         │
         ▼
┌────────────────────┐
│  Fuzz Introspector │
│     Analysis       │
└────────┬───────────┘
         │
         ▼
┌────────────────────┐
│  Interactive HTML  │
│     Reports        │
└────────────────────┘
```

## Video Content

For the video walkthrough:
- Record in 1920x1080 or 4K
- Use clear, readable font sizes
- Include voiceover or captions
- Keep under 7 minutes
- Export in H.264 MP4 format

## External Resources

Demo currently uses CDN for:
- TailwindCSS (styling)
- Chart.js (visualizations)
- Prism.js (syntax highlighting)
- AOS (animations)

These are loaded from CDNs for easier deployment.
