#!/bin/bash

# Determine directories
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
SOURCE_DIR="$(cd "$BUILD_DIR/.." && pwd)"
MODS_DIR="$SOURCE_DIR/uclang/mods"
TEST_RUNNER="$SCRIPT_DIR/test.ucl"

# Set up environment
export LD_LIBRARY_PATH="$BUILD_DIR"
export PATH="$BUILD_DIR:$PATH"

UCLANG="$BUILD_DIR/uclang"

# Check prerequisites
if [ ! -x "$UCLANG" ]; then
  echo "ERROR: uclang binary not found at $UCLANG"
  echo "Build first: cmake .. && make -j\$(nproc)"
  exit 2
fi

if [ ! -f "$TEST_RUNNER" ]; then
  echo "ERROR: Test runner not found at $TEST_RUNNER"
  exit 2
fi

# No arguments - show usage
if [ $# -eq 0 ]; then
  "$UCLANG" "$TEST_RUNNER" "$MODS_DIR" "$BUILD_DIR"
  exit 0
fi

exec "$UCLANG" "$TEST_RUNNER" "$MODS_DIR" "$BUILD_DIR" "$@"
