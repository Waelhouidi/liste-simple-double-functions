#include<stdio.h>
#include<stdlib.h>

// Structure d'un noeud de la liste
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Fonction pour initialiser une liste vide
struct Node* init() {
    return NULL;
}

// Fonction pour ajouter un élément en tête de la liste
struct Node* ajoutTete(struct Node* head, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

// Fonction pour ajouter un élément en queue de la liste
struct Node* ajoutQueue(struct Node* head, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    newNode->data = element;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Fonction pour ajouter un élément à une position donnée
struct Node* ajoutPosition(struct Node* head, int element, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return head;
    }
    if (position == 1) {
        return ajoutTete(head, element);
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    newNode->data = element;
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

// Fonction pour supprimer le premier élément de la liste
struct Node* supprimerTete(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head->next;
    if (temp != NULL) {
        temp->prev = NULL;
    }
    free(head);
    return temp;
}

// Fonction pour supprimer le dernier élément de la liste
struct Node* supprimerQueue(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Fonction pour supprimer un élément à une position donnée
struct Node* supprimerPosition(struct Node* head, int position) {
    if (head == NULL || position < 1) {
        printf("Invalid operation.\n");
        return head;
    }
    if (position == 1) {
        return supprimerTete(head);
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return head;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    if (temp->next != NULL) {
        temp->next->prev = temp;
    }
    free(nodeToDelete);
    return head;
}

// Fonction pour compter le nombre d'occurrences d'une valeur donnée
int occurence(struct Node* head, int val) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

// Fonction pour changer une valeur donnée à une position donnée
void changerValeur(struct Node* head, int position, int newVal) {
    struct Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
    temp->data = newVal;
}

// Fonction pour chercher une valeur par position
int chercherParPosition(struct Node* head, int position) {
    struct Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        return -1;
    }
    return temp->data;
}

// Fonction pour chercher une position par valeur
int chercherParValeur(struct Node* head, int val) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

// Fonction pour afficher la liste
void afficherListe(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* liste = init();
    int choix, element, position, valeur;

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un element en tete\n");
        printf("2. Ajouter un element en queue\n");
        printf("3. Ajouter un element a une position donnee\n");
        printf("4. Supprimer l'element en tete\n");
        printf("5. Supprimer l'element en queue\n");
        printf("6. Supprimer l'element a une position donnee\n");
        printf("7. Nombre d'occurrences d'une valeur donnee\n");
        printf("8. Changer une valeur a une position donnee\n");
        printf("9. Chercher une valeur par position\n");
        printf("10. Chercher une position par valeur\n");
        printf("11. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez l'element a ajouter: ");
                scanf("%d", &element);
                liste = ajoutTete(liste, element);
                break;
            case 2:
                printf("Entrez l'element a ajouter: ");
                scanf("%d", &element);
                liste = ajoutQueue(liste, element);
                break;
            case 3:
                printf("Entrez l'element a ajouter: ");
                scanf("%d", &element);
                printf("Entrez la position: ");
                scanf("%d", &position);
                liste = ajoutPosition(liste, element, position);
                break;
            case 4:
                liste = supprimerTete(liste);
                break;
            case 5:
                liste = supprimerQueue(liste);
                break;
            case 6:
                printf("Entrez la position: ");
                scanf("%d", &position);
                liste = supprimerPosition(liste, position);
                break;
            case 7:
                printf("Entrez la valeur: ");
                scanf("%d", &valeur);
                printf("Nombre d'occurrences de %d: %d\n", valeur, occurence(liste, valeur));
                break;
            case 8:
                printf("Entrez la position: ");
                scanf("%d", &position);
                printf("Entrez la nouvelle valeur: ");
                scanf("%d", &valeur);
                changerValeur(liste, position, valeur);
                break;
            case 9:
                printf("Entrez la position: ");
                scanf("%d", &position);
                printf("La valeur a la position %d est %d\n", position, chercherParPosition(liste, position));
                break;
            case 10:
                printf("Entrez la valeur: ");
                scanf("%d", &valeur);
                printf("La position de la valeur %d est %d\n", valeur, chercherParValeur(liste, valeur));
                break;
            case 11:
                printf("Liste: ");
                afficherListe(liste);
                break;
            case 0:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}

