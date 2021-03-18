//
// Created by warrens on 3/18/21.
//

#ifndef C_HASHTABLE_H
#define C_HASHTABLE_H

typedef struct {
    int *key; // The unhashed key to the entry
    int *value;
} hashtable_item;

typedef struct {
    hashtable_item **items;
    int size;
    int count;
} hashtable;


hashtable *hashtable_create(int initialSize);

void hashtable_insert(hashtable *table, int key, int value);

hashtable_item *hashtable_get(hashtable *table, int key);

hashtable_item *hashtable_remove(hashtable *table, int key);

int hashtable_contains(hashtable *table, int key);

hashtable_item *hashtable_create_item(int *key, int *value);

void hashtable_free(hashtable *table);

void hashtable_item_free(hashtable_item *item);

#endif //C_HASHTABLE_H
