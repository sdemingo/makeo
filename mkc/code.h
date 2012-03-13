
FILE *out;

void encode(const char *fmt,...);
void pushcode(const char *fmt,...);
void dumpcode();

void load_il(char *mod);
void link_il(char *mod);

void error(char *msg);
void iferror();
