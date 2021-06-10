///////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT List μέσω συνδεδεμένης λίστας.
//
///////////////////////////////////////////////////////////

#include <iostream>
#include "ADTList.h"

using namespace std;


// Ενα List είναι pointer σε αυτό το struct
struct List {
	ListNode* dummy;				// χρησιμοποιούμε dummy κόμβο, ώστε ακόμα και η κενή λίστα να έχει έναν κόμβο.
	ListNode* last;				// δείκτης στον τελευταίο κόμβο, ή στον dummy (αν η λίστα είναι κενή)
	int size;					// μέγεθος, ώστε η list_size να είναι Ο(1)

};

struct ListNode {
	ListNode* next;		// Δείκτης στον επόμενο
	int* value;		// Η τιμή που αποθηκεύουμε στον κόμβο
};


List* list_create() {
	// Πρώτα δημιουργούμε το stuct
	List* list = new List*;
	list->size = 0;

	// Χρησιμοποιούμε dummy κόμβο, ώστε ακόμα και μια άδεια λίστα να έχει ένα κόμβο
	// (απλοποιεί τους αλγορίθμους). Οπότε πρέπει να τον δημιουργήσουμε.
	//
	list->dummy = new ListNode;
	list->dummy->next = NULL;		// άδεια λίστα, ο dummy δεν έχει επόμενο

	// Σε μια κενή λίστα, τελευταίος κόμβος είναι επίσης ο dummy
	list->last = list->dummy;

	return list;
}

int list_size(List* list) {
	return list->size;
}

void list_insert_next(List* list, ListNode* node, int* value) {
	// Αν το node είναι NULL απλά εισάγουμε μετά τον dummy κόμβο!
	// Αυτή ακριβώς είναι η αξία του dummy, δε χρειαζόμαστε ξεχωριστή υλοποίηση.
	if (node == NULL)
		node = list->dummy;

	// Δημιουργία του νέου κόμβου
	ListNode* n = new ListNode*;
	n->value = value;

	// Σύνδεση του new ανάμεσα στο node και το node->next
	n->next = node->next;
	node->next = n;

	// Ενημέρωση των size & last
	list->size++;
	if (list->last == node)
		list->last = n;
}

void list_remove_next(List* list, ListNode* node) {
	// Αν το node είναι NULL απλά διαγράφουμε μετά τον dummy κόμβο!
	// Αυτή ακριβώς είναι η αξία του dummy, δε χρειαζόμαστε ξεχωριστή υλοποίηση.
	if (node == NULL)
		node = list->dummy;

	// Ο κόμβος προς διαγραφή είναι ο επόμενος του node, ο οποίος πρέπει να υπάρχει
	ListNode* removed = node->next;
	// assert(removed != NULL);		// LCOV_EXCL_LINE

	// Σύνδεση του node με τον επόμενο του removed
	node->next = removed->next;		// πριν το free!

	// free(removed);

	// Ενημέρωση των size & last
	list->size--;
	if (list->last == removed)
		list->last = node;
}

// Pointer list_find(List* list, int* value, CompareFunc compare) {
// 	ListNode node = list_find_node(list, value, compare);
// 	return node == NULL ? NULL : node->value;
// }

void list_destroy(List* list) {
	// Διασχίζουμε όλη τη λίστα και κάνουμε free όλους τους κόμβους,
	// συμπεριλαμβανομένου και του dummy!
	//
	ListNode* node = list->dummy;
	while (node != NULL) {				// while αντί για for, γιατί θέλουμε να διαβάσουμε
		ListNode* next = node->next;		// το node->next _πριν_ κάνουμε free!
            delete node;
		// free(node);
		node = next;
	}

	// Τέλος free το ίδιο το struct
	delete list;
}


// Διάσχιση της λίστας /////////////////////////////////////////////

ListNode* list_first(List* list) {
	// Ο πρώτος κόμβος είναι ο επόμενος του dummy.
	//
	return list->dummy->next;
}

ListNode* list_last(List* list) {
	// Προσοχή, αν η λίστα είναι κενή το last δείχνει στον dummy, εμείς όμως θέλουμε να επιστρέψουμε NULL, όχι τον dummy!
	//
	if (list->last == list->dummy)
		return LIST_EOF;		// κενή λίστα
	else
		return list->last;
}

ListNode* list_next(List* list, ListNode* node) {
	// assert(node != NULL);	// LCOV_EXCL_LINE (αγνοούμε το branch από τα coverage reports, είναι δύσκολο να τεστάρουμε το false γιατί θα κρασάρει το test)
	return node->next;
}

int* list_node_value(List* list, ListNode* node) {
	// assert(node != NULL);	// LCOV_EXCL_LINE
	return node->value;
}

// ListNode* list_find_node(List list, Pointer value, CompareFunc compare) {
// 	// διάσχιση όλης της λίστας, καλούμε την compare μέχρι να επιστρέψει 0
// 	//
// 	for (ListNode node = list->dummy->next; node != NULL; node = node->next)
// 		if (compare(value, node->value) == 0)
// 			return node;		// βρέθηκε

// 	return NULL;	// δεν υπάρχει
// }