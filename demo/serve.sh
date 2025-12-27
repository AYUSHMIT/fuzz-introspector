#!/bin/bash
# Copyright 2024 Fuzz Introspector Authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set -e

# Script to serve the demo locally
echo "🚀 Starting Fuzz Introspector Demo Server..."
echo ""
echo "This will start a local HTTP server to view the demo."
echo ""

# Check if Python is available
if ! command -v python3 &> /dev/null; then
    echo "❌ Error: python3 is required but not installed."
    echo "   Please install Python 3 and try again."
    exit 1
fi

# Get the script directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# Change to demo directory
cd "$SCRIPT_DIR"

# Default port
PORT=${1:-8000}

echo "📂 Serving from: $SCRIPT_DIR"
echo "🌐 Server URL: http://localhost:$PORT"
echo ""
echo "✨ Demo pages available:"
echo "   - Main demo: http://localhost:$PORT/index.html"
echo "   - Tutorial: http://localhost:$PORT/tutorial/01-setup.md"
echo "   - Sample project: http://localhost:$PORT/sample-project/"
echo ""
echo "Press Ctrl+C to stop the server"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""

# Start Python HTTP server
python3 -m http.server "$PORT"
