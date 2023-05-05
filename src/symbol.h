#ifdef __cplusplus
extern "C"
{
#endif

void printSymbolData(struct symbol * symbol);
struct symbol * createSymbol(char* name, char* varType);
void setValue(char * value, struct symbol * sym);
char * getValue(struct symbol * sym);
//void markAsDeclared(struct symbol * symbol);

void addSymbol(char* key, struct symbol* value);
void printSymbolByKey( char* keystr);
void modifySymbolInTable(char* key, char* modification);
void printSymbolTable();

#ifdef __cplusplus
}
#endif

