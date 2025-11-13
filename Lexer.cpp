#ifndef LEXER_H
#define LEXER_H
// #include "llvm/ADT/StringRef.h"
// #include "llvm/Support/MemoryBuffer.h"

class Lexer;
class Token {
 friend class Lexer;
public:
  enum TokenKind : unsigned short {
    eoi, unknown, ident, number, comma, colon, plus,
    minus, star, slash, l_paren, r_paren, KW_with
  };
private:
 TokenKind Kind;
 llvm::StringRef Text;
public:
  TokenKind getKind() const { return Kind; }
  llvm::StringRef getText() const { return Text; }