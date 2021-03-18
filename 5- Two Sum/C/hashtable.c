#include <malloc.h>

#include "hashtable.h"

unsigned long hash_function(long key) {
    return key * 2654435761 % 2 ^ 32;
}

hashtable *hashtable_create(int initialSize) {
    hashtable *table = (hashtable *) malloc(sizeof(hashtable));
    table->size = initialSize;
    table->count = 0;
    table->items = (hashtable_item **) calloc(table->size, sizeof(hashtable_item *));
    for (int i = 0; i < initialSize; ++i) {
        table->items[i] = NULL;
    }
    return table;
}

void hashtable_insert(hashtable *table, int key, int value) {
    unsigned long hashValue = hash_function(key);

    hashtable_item *estimate = table->items[hashValue];

    if (estimate == NULL) {
        if (table->count == table->size) {
            printf("\nInsertion Error: Hash Table is full.");
            free(estimate);
        } else {
            table->items[hashValue] = hashtable_create_item(&key, &value);
            table->count++;
        }
    } else {
        if (estimate->key == &key) {
            table->items[hashValue]->value = &value;
        } else {
            // TODO: add collision handling method
        }
    }
}

hashtable_item *hashtable_get(hashtable *table, int key) {
    unsigned long hashValue = hash_function(key);
    return table->items[hashValue];
}

hashtable_item *hashtable_remove(hashtable *table, int key) {
    unsigned long hashValue = hash_function(key);

    hashtable_item *estimate = table->items[hashValue];
    if (estimate != NULL) {
        table->items[hashValue] = NULL;
        table->count--;
        return estimate;
    }
    return NULL;
}

int hashtable_contains(hashtable *table, int key) {
    return hashtable_get(table, key) == NULL ? 0 : 1;
}

hashtable_item *hashtable_create_item(int *key, int *value) {
    hashtable_item *item = (hashtable_item *) malloc(sizeof(hashtable_item));
    item->key = key;
    item->value = value;
    return item;
}

void hashtable_free(hashtable *table) {
    hashtable_item **items = table->items;
    for (int i = 0; i < table->size; ++i) {
        hashtable_item *current = items[i];
        if (current != NULL) {
            hashtable_item_free(current);
        }
    }
    free(table->items);
    free(table);
}

void hashtable_item_free(hashtable_item *item) {
    free(item->key);
    free(item->value);
    free(item);
}