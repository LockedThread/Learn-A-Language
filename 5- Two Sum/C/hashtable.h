//
// Created by warrens on 3/18/21.
//

#ifndef C_HASHTABLE_H
#define C_HASHTABLE_H

/*
 * Holds the key and value pair of the hashtable entry.
 */
typedef struct {
    int *key; // The un-hashed key to the entry
    int *value;
} hashtable_entry;

/*
 * Holds an array of hashtable entries, the max size, and the current count for used indices.
 */
typedef struct {
    hashtable_entry **entries;
    int size;
    int count;
} hashtable;

/*
 * Creates and initializes the hashtable struct.
 */
hashtable *hashtable_create(int initialSize);

/*
 * Inserts or replaces a key-value pair into the hashtable.
 */
void hashtable_insert(hashtable *table, int key, int value);

/*
 * Retrieves a value from the hashtable according to the key.
 */
hashtable_entry *hashtable_get(hashtable *table, int key);

/*
 * Removes and frees a hashtable entry according to it's key.
 */
hashtable_entry *hashtable_remove(hashtable *table, int key);

/*
 * Returns a boolean 1 or 0 in correlation to whether or not an entry is found with the key provided.
 */
int hashtable_contains(hashtable *table, int key);

/*
 * Impl only use. Creates a hashtable_entry object.
 */
hashtable_entry *hashtable_create_entry(int *key, int *value);

/*
 * Frees the hashtable.
 */
void hashtable_free(hashtable *table);

/*
 * Frees a specific hashtable_entry
 */
void hashtable_entry_free(hashtable_entry *entries);

#endif //C_HASHTABLE_H
