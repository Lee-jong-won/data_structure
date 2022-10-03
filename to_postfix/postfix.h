enum class precedence
{
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos,
    operand
};

extern int isp[];
extern int icp[];

precedence getToken(const char *infix, int *n);
void postfix(const char *infix, char* postfix);
char change_format(precedence object);