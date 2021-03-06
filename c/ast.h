#ifndef __AST_H__
#define __AST_H__

typedef enum NodeType {
    eVAR,
    eAND,
    eOR,
    eNOT,
} NodeType;

/* All of the other node types can be type cast to this
 * type because the first member is always the same.
 * This allows for a kind of lightweight polymorphism.
 */
typedef struct Node {
    NodeType type;
} Node;

extern Node* parse_ast(const char* source);
extern void free_ast(Node* node);
extern char last_error_msg[];

typedef struct Var {
    NodeType type;
    char* value;
} Var;

typedef struct And {
    NodeType type;
    Node* left;
    Node* right;
} And;

typedef struct Or {
    NodeType type;
    Node* left;
    Node* right;
} Or;

typedef struct Not {
    NodeType type;
    Node* other;
} Not;

Node* create_var(char* value);
Node* create_and(Node* left, Node* right);
Node* create_or(Node* left, Node* right);
Node* create_not(Node* other);

#endif
