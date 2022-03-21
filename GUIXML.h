struct Icon {
    char* file;
    char* text;
    int posx;
    int posy;
};

int readFile(char* filename);
char* ReadNodeContent(int nodeIndex);
char* ReadNodeAttribute(int index, int attrIndex);
struct Icon ReadIcon(int index);
int GetTotalIcons();