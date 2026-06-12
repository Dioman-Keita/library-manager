# Library Manager

A simple library management system built in C++ to manage books, users, loans, and data persistence.

## Features

* 📚 Book management (add, update, delete, search)
* 👤 User management
* 🔄 Loan and return tracking
* 💾 Data persistence using local files
* 🛠️ Backup utilities
* ✅ Unit tests

## Project Structure

```text
library-manager/
├── app/
│   ├── src/
│   │   ├── models/       # Domain models (Book, User)
│   │   ├── services/     # Business logic
│   │   │   ├── Library
│   │   │   ├── BookManager
│   │   │   ├── UserManager
│   │   │   └── LoanManager
│   │   └── utils/        # Utilities (Backup, helpers)
│   │
│   ├── Makefile
│   ├── CMakeLists.txt
│   └── README.md
│
├── data/                 # Books, users and loan data
├── tests/                # Unit tests
└── docs/                 # Project documentation
```

## Requirements

* C++17 or later
* GNU Make (optional)
* CMake 3.16+

## Build

### Using Make

From the repository root:

```bash
make -C app
```

Or:

```bash
cd app
make
```

### Using CMake

```bash
cd app

cmake -S . -B build
cmake --build build
```

## Running

After compilation, the executable can be launched from the build directory.

The `data/` directory is automatically copied next to the executable so the application can access its files at runtime.

## Testing

```bash
cd tests
# Run test suite
```

## Documentation

Additional documentation is available in the `docs/` directory.

## License

This project is provided for educational purposes.
