#include "toy/AST.h"

#include "llvm/ADT/Twine.h"
#include "llvm/ADT/TypeSwitch.h"
#include "llvm/Support/raw_ostream.h"

using namespace toy;

namespace {
    struct Indent {
        Indent(int &level) : level(level){ ++level; }
        ~Indent(){ --level; }
        int &level;
    };

/// Helper class that implement the AST tree traversal and print the nodes along
/// the way. The only data member is the current indentation level.
    class ASTDumper {
        public:
            void dump(ModuleAST *node);
        
        private:
            void dump(const VarType &type);
            void dump(VarDeclExrAST *varDecl);
            void dump(ExprAST *expr);
            void dump(ExprASTList *exprList);
            void dump(NumberExprAST *num);
            void dump(LiteralExprAST *node);
            void dump(VariableExprAST *node);
            void dump(ReturnExprAST *node);
            void dump(BinaryExprAST *node);
            void dump(CallExprAST *node);
            void dump(PrintExprAST *node);
            void dump(PrototypeAST *node);
            void dump(FunctionAST *node);

            // Actually print spaces matching the current indentation level //indentation 是什么意思？
            void indent(){
                for (int i = 0; i < curIndent; i++)
                    llvm::errs() << "   ";
            }
            int curIndent = 0;
    };
} // namespace

/// Return a formatted string for the location of any node
template <typename T> 
static std::string loc(T *node) {
    const auto &loc = node->loc();
    return (llvm::Twine("@") + *loc.file + ":" + llvm::Twine(loc.line) + ":" +
            llvm::Twine(loc.col))
        .str();
}

// Helper Macro to bump the indentation level and print the leading spaces for
// the current indentations
#define INDENT()
    Indent level_(curIndent);
    indent();


///Dispatch to a generic expressions to the appropriate subclass using RTTI
void ASTDumper::dump(ExprAST *expr){
    llvm::TypeSwitch<ExprAST *>(expr)
        .Case<BinaryExprAST, CallExprAST, LiteralExprAST. NumberExorAST,
              PrintExprAST, ReturnExprAST, VarDeckExprAST, VariablExprAST>(
                  [&](auto *node) { this->dump(node); }) // 传一个 lamda 函数
}

