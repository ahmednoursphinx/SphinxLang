#ifndef LEXER_H
#define LEXER_H

#include "llvm/ADT/StringRef.h" // llvm::StringRef class encapsulates a pointer to a C string and its length
#include "llvm/Support/MemoryBuffer.h" // llvm::MemoryBuffer class provides read-only access to a block of memory, filled with the content of a file

class Token {

public:
  enum TokenKind : unsigned short {
    eoi, // end of input and is returned when all characters of the input are processed
    unknown, // used in the event of an error at the lexical level
    ident,
    number,
    comma,
    colon,
    plus,
    minus,
    star,
    slash,
    l_paren,
    r_paren,
    KW_with
  };
}