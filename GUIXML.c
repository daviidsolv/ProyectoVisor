#include "GUIXML.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xml.c/src/xml.h"

FILE * stream;
struct xml_node* root;

int readFile(char* filename){
    //Read file
    stream = fopen(filename, "r");
    struct xml_document* document = xml_open_document(stream);
    if (!document) {
		printf("Could parse document\n");
		exit(-1);
	}

	root = xml_document_root(document);
}

char* ReadNodeContent(int nodeIndex) {
    //aqui sucede el parseo
    struct xml_node* nodo0 = xml_node_child(root, nodeIndex);  //el segundo parametro (el numero) es el nodo que queremos leer, probar con 1, 2...
	struct xml_string* contenidoNodo0 = xml_node_content(nodo0);

	char* contenidoNodo0_S = calloc(xml_string_length(contenidoNodo0) + 1, sizeof(char));

	xml_string_copy(contenidoNodo0, contenidoNodo0_S, xml_string_length(contenidoNodo0));

    //liberar memoria
	free(contenidoNodo0);

    return contenidoNodo0_S;
}

char* ReadNodeAttribute(int index, int attrIndex) {
    struct xml_node* nodo = xml_node_child(root, index);

    struct xml_string* atributoContentNodo = xml_node_attribute_content(nodo, attrIndex);

    char* atributoContentNodo_S = calloc(xml_string_length(atributoContentNodo) + 1, sizeof(char));

    xml_string_copy(atributoContentNodo, atributoContentNodo_S, xml_string_length(atributoContentNodo));

    free(atributoContentNodo);

    return atributoContentNodo_S;
}

int GetTotalIcons() {
    return xml_node_children(root);
}

struct Icon ReadIcon(int index) {
    struct Icon i;

    i.file = ReadNodeContent(index);
    i.text = ReadNodeAttribute(index, 2);
    i.posx = atoi(ReadNodeAttribute(index, 0));
    i.posy = atoi(ReadNodeAttribute(index, 1));

    return i;
}