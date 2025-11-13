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
private:
  TokenKind Kind;
  llvm::StringRef Text; //  start of the text of the token

public:
  TokenKind getKind() const { return Kind; }
  llvm::StringRef getText() const {
    return Text;
  }

  // test whether the token is of a certain kind
  bool is(TokenKind K) const { return Kind == K; }
  bool isOneOf(TokenKind K1, TokenKind K2) const {
    return is(K1) || is(K2);
  }
  template <typename... Ts>
  bool isOneOf(TokenKind K1, TokenKind K2, Ts... Ks) const {
    return is(K1) || isOneOf(K2, Ks...);
  }
};

class Lexer {
  const char *BufferStart;
  const char *BufferPtr;

public:
  Lexer(const llvm::StringRef &Buffer) {
    BufferStart = Buffer.begin();
    BufferPtr = BufferStart;
  }

  void next(Token &token); // return the next token acting as iterator 

private:
  void formToken(Token &Result, const char *TokEnd,
                 Token::TokenKind Kind);
};
#endif