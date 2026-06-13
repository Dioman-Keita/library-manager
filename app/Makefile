CXX = g++
CXXFLAGS = -std=c++17 -Wall -I$(SRCDIR)
TARGET = library_app
SRCDIR = src
OBJDIR = obj

SOURCES = $(SRCDIR)/main.cpp \
          $(SRCDIR)/models/Book.cpp \
          $(SRCDIR)/models/User.cpp \
          $(SRCDIR)/services/Library.cpp \
          $(SRCDIR)/services/BookManager.cpp \
          $(SRCDIR)/services/UserManager.cpp \
          $(SRCDIR)/services/LoanManager.cpp \
          $(SRCDIR)/utils/Backup.cpp \
          $(SRCDIR)/utils/IdGenerator.cpp

OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(TARGET)

test: reset_data all test_loan test_user

test_loan:
	$(CXX) $(CXXFLAGS) -I./src -o test_loan tests/test_loan.cpp src/models/Book.cpp src/models/User.cpp src/services/BookManager.cpp src/services/UserManager.cpp src/services/LoanManager.cpp src/services/Library.cpp src/utils/IdGenerator.cpp src/utils/Backup.cpp
	./test_loan

test_user:
	$(CXX) $(CXXFLAGS) -I./src -o test_user tests/test_user_registration.cpp src/models/Book.cpp src/models/User.cpp src/services/BookManager.cpp src/services/UserManager.cpp src/services/LoanManager.cpp src/services/Library.cpp src/utils/IdGenerator.cpp src/utils/Backup.cpp
	./test_user

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)
	
.PHONY: all clean
.PHONY: test reset_data test_loan test_user

reset_data:
	@bash tests/reset_data.sh