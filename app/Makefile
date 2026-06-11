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
          $(SRCDIR)/models/Borrow.cpp \
          $(SRCDIR)/services/BorrowManager.cpp \
          $(SRCDIR)/utils/Backup.cpp

OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean