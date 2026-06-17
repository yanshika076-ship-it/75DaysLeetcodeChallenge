

// Hash map entry
typedef struct Entry {
    int key;    // prefix sum
    int value;  // frequency
    struct Entry* next;
} Entry;

// Simple hash map for prefix sums
#define TABLE_SIZE 10007  // prime number for distribution

Entry* table[TABLE_SIZE];

// Hash function
int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

// Insert or update key in hash map
void put(int key, int val) {
    int h = hash(key);
    Entry* curr = table[h];
    while (curr) {
        if (curr->key == key) {
            curr->value += val;
            return;
        }
        curr = curr->next;
    }
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = val;
    newEntry->next = table[h];
    table[h] = newEntry;
}

// Get frequency of a key
int get(int key) {
    int h = hash(key);
    Entry* curr = table[h];
    while (curr) {
        if (curr->key == key) return curr->value;
        curr = curr->next;
    }
    return 0;
}

int subarraySum(int* nums, int numsSize, int k) {
    // Clear table
    for (int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;

    int count = 0;
    int prefixSum = 0;

    // Initialize with prefixSum = 0
    put(0, 1);

    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];

        // Check if (prefixSum - k) exists
        count += get(prefixSum - k);

        // Store/update prefixSum
        put(prefixSum, 1);
    }

    return count;
}
