#ifndef __JOVO__AST_H_
#define __JOVO__AST_H_

#include "base.hpp"

namespace jovolang {

struct ASTNode {
  virtual ~ASTNode() = default;
};

struct NumberNode : public ASTNode {
  str value;
  explicit NumberNode(const std::string &val) : value(val) {}
};

struct BinaryOpNode : public ASTNode {
  str op;

  std::unique_ptr<ASTNode> left;
  std::unique_ptr<ASTNode> right;

  BinaryOpNode(std::unique_ptr<ASTNode> l, const str &oper, std::unique_ptr<ASTNode> r)
      : op(oper), left(std::move(l)), right(std::move(r)) {}
};

} // namespace jovolang

#endif