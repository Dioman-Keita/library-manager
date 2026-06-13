#!/usr/bin/env bash
# reset_data.sh - clear data files used by tests
DATA_DIR="../data"
FILES=("books.txt" "users.txt" "loans.txt")
for f in "${FILES[@]}"; do
  fullpath="$DATA_DIR/$f"
  if [ -f "$fullpath" ]; then
    : > "$fullpath"
  else
    mkdir -p "$DATA_DIR"
    : > "$fullpath"
  fi
done

echo "Data files reset: ${FILES[*]}"
