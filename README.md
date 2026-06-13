# Library Manager

A simple library management system built in C++ to manage books, users, loans, and data persistence.

## Features

### User Features

* 👤 User registration and authentication
* 📚 Browse and search books
* 🔄 Borrow available books
* ↩️ Return borrowed books
* 📋 View personal loan history
* 🔍 Check book availability

### Administrator Features

* 📚 Add books
* 🗑️ Remove books
* 👥 List registered users
* 📋 View active loans
* 🔍 Search books
* ✅ Check book availability

### Technical Features

* 💾 Data persistence using local files
* 🛠️ Backup utilities
* 🆔 Sequential ID generation
* ⚙️ CMake and Make support
* ✅ Unit tests

## Application Workflow

### Initial Setup

On first launch, create the administrator account using:

```text
Email: admin@admin.com
```

Once connected as administrator:

1. Add books to the library catalog.
2. Log out.
3. Register regular users.
4. Sign in as a user.
5. Borrow and return books.

### Administrator Workflow

```text
Login (admin@admin.com)
        │
        ▼
Add Books
        │
        ▼
Manage Catalog
        │
        ▼
List Users
        │
        ▼
View Active Loans
        │
        ▼
Logout
```

### User Workflow

```text
Register
    │
    ▼
Login
    │
    ▼
Browse Books
    │
    ▼
Borrow Book
    │
    ▼
View My Loans
    │
    ▼
Return Book
    │
    ▼
Logout
```

### Example Scenario

#### 1. Create the Administrator

```text
Email: admin@admin.com
```

#### 2. Populate the Library

Login as administrator and add books:

```text
Title: The Hobbit
Author: J.R.R. Tolkien
ISBN: 9780547928227
Year: 1937
```

#### 3. Register a User

```text
Name: John Doe
Email: john@example.com
Member Number: 001
```

#### 4. Borrow a Book

```text
Login as User
Borrow Book by ID
```

#### 5. Return a Book

```text
Login as User
Return Book by ID
```

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
│   │   └── utils/        # Utilities (Backup, ID generation)
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

* C++11 or later
* GNU Make (optional)
* CMake 3.10+

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

Launch the generated executable:

```bash
./library_app
```

The `data/` directory is automatically copied next to the executable so the application can access its files at runtime.

## Testing

Run the test suite with:

```bash
cd app
make test
```

## Documentation

Additional documentation is available in the `docs/` directory.

## License

This project is provided for educational purposes.
