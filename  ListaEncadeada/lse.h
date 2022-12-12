struct s_InfoNo{
    char titulo[20];
    char distr[20];
    char diretor[20];
};
typedef struct s_InfoNo TipoInfoNo;

struct s_PtNo{
    TipoInfoNo info;
    struct s_PtNo * prox;
};
typedef struct s_PtNo TipoPtNo;

TipoPtNo* inicializa(void);
void imprime(TipoPtNo* ptLista);
TipoPtNo* insereInicio (TipoPtNo* ptLista, TipoInfoNo dados);
TipoPtNo* insereFim (TipoPtNo* ptLista, TipoInfoNo dados);
TipoPtNo* remover(TipoPtNo* ptLista, char titulo[]);
TipoPtNo* destroi(TipoPtNo* ptLista);

