#include <malloc.h>
#include "hashtable.h"

unsigned long hash_function(long key) {
    return key * 2654435761 % 2 ^ 32;
}

hashtable *hashtable_create(int initialSize) {
    hashtable *table = (hashtable *) malloc(sizeof(hashtable));
    table->size = initialSize;
    table->count = 0;
    table->entries = (hashtable_entry **) calloc(table->size, sizeof(hashtable_entry *));
    for (int i = 0; i < initialSize; ++i) {
        table->entries[i] = NULL;
    }
    return table;
}

void hashtable_insert(hashtable *table, int key, int value) {
    unsigned long hashValue = hash_function(key);

    hashtable_entry *estimate = table->entries[hashValue];

    if (estimate == NULL) {
        if (table->count == table->size) {
            printf("\nInsertion Error: Hash Table is full.");
        } else {
            table->entries[hashValue] = hashtable_create_entry(&key, &value);
            table->count++;
        }
    } else {
        if (estimate->key == &key) {
            table->entries[hashValue]->value = &value;
        } else {
            // TODO: add collision handling method
        }
    }
    free(estimate);
}

hashtable_entry *hashtable_get(hashtable *table, int key) {
    unsigned long hashValue = hash_function(key);
    return table->entries[hashValue];
}

hashtable_entry *hashtable_remove(hashtable *table, int key) {
    unsigned long hashValue = hash_function(key);

    hashtable_entry *estimate = table->entries[hashValue];
    if (estimate != NULL) {
        table->entries[hashValue] = NULL;
        table->count--;
        return estimate;
    }
    return NULL;
}

int hashtable_contains(hashtable *table, int key) {
    return hashtable_get(table, key) == NULL ? 0 : 1;
}

hashtable_entry *hashtable_create_entry(int *key, int *value) {
    hashtable_entry *entry = (hashtable_entry *) malloc(sizeof(hashtable_entry));
    entry->key = key;
    entry->value = value;
    return entry;
}

void hashtable_free(hashtable *table) {
    hashtable_entry **entries = table->entries;
    for (int i = 0; i < table->size; ++i) {
        hashtable_entry *current = entries[i];
        if (current != NULL) {
            hashtable_entry_free(current);
        }
    }
    free(table->entries);
    free(table);
}

void hashtable_entry_free(hashtable_entry *entries) {
    free(entries->key);
    free(entries->value);
    free(entries);
}